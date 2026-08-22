
/* 4-digit airfoil generator for arbitrary lift coefficient specification */
// from https://github.com/jamalam-dev/naca-four-digit/blob/master/four-digit.cpp

/**
  useful for making decimated aerofoils.
  Can be output as scad or .dat format
**/

#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <cmath>
#include <stdio.h>
#include <fstream>

#include <stdlib.h>
#include <cstdint>

namespace {
   enum class OutputFileType{
      DAT, SCAD
   };
}

void linspace(double * vec, double lowVal, double highVal, uint32_t elements);
void cosspace(std::vector<double> & vec, double lowVal, double highVal, const uint32_t elements);

int main(int argc, char** argv) {

    /* constants*/
    const uint32_t maxPoints = 10000;

    const double a[5] = {0.2969, -0.126, -0.3516, 0.2843, -0.1015}; // These values are for a open trailing edge; a[4] = -0.1036 for closed TE

    /* variables */
    double camber;
    double posMaxCamber;
    double thickness;
    uint32_t numPoints ;
    OutputFileType outputFileType = OutputFileType::DAT;

    uint32_t nAlgPoints ;  // loop number

    std::vector<double> x;
    std::vector<double> yc;
    std::vector<double> yt;
    std::vector<double> dycdx;
    std::vector<double> theta;
    std::vector<double> xLower;
    std::vector<double> xUpper;
    std::vector<double> yLower;
    std::vector<double> yUpper;

    /* Parse command line arguments */
    if(argc < 5) {

        std::cout << "ERROR: four-digit requires exactly 4 arguments of the form 'four-digit 0.### 0.### 0.###  n" << std::endl;
        std::cout << "       The first argument is camber as a fraction of the chord" << std::endl;
        std::cout << "       The second argument is location of max camber as a fraction of the chord" << std::endl;
        std::cout << "       The third argument is the thickness of the airfoil, as a fraction of the chord" << std::endl;
        std::cout << "       The fourth argument is the number of points to plot" << std::endl;
        std::cout << "       The optional 5th arg is for dat or scad" << std::endl;
        return -1;

    } else {


        try {
            std::string camberString = argv[1]; // camber
            std::string maxCamberString = argv[2]; // max camber position
            std::string thicknessString = argv[3]; // thickness
            std::string numPointsString = argv[4];

            camber = std::stod(camberString);
            posMaxCamber = std::stod(maxCamberString);
            thickness = std::stod(thicknessString);
            numPoints = std::stoi(numPointsString);

            bool failed = false;

            // check args

            if ( (camber < 0.0) || ( camber >= 1)){
               failed = true;
               std::cout << "ERROR: camber out of range" << std::endl;
            }

            if ( (posMaxCamber < 0.0) || ( posMaxCamber >= 1)){
               failed = true;
               std::cout << "ERROR: pos max camber out of range" << std::endl;
            }

            if ( (thickness< 0.0) || ( thickness >= 1)){
               failed = true;
               std::cout << "ERROR: thickness out of range" << std::endl;
            }

            if ( (numPoints< 5) || ( numPoints > maxPoints)){
               failed = true;
               std::cout << "ERROR: num points out of range" << std::endl;
            }

            if (argc > 5){
               std::string ofileType = argv[5];

               if (ofileType == "scad"){
                   outputFileType = OutputFileType::SCAD;
               }else{
                   if (ofileType != "dat"){
                      failed = true;
                      std::cout << "ERROR: filetype either dat or scad" << std::endl;
                   }
               }
            }

            if ( failed){
               return -1;
            }

            x.resize(numPoints);
            yc.resize(numPoints);
            yt.resize(numPoints);
            dycdx.resize(numPoints);
            theta.resize(numPoints);
            xLower.resize(numPoints);
            xUpper.resize(numPoints);
            yLower.resize(numPoints);
            yUpper.resize(numPoints);
// correction for actual points all around the airfoil

            nAlgPoints = (numPoints +1)/2;

        } catch(...) {
            std::cout << "ERROR: Input arguments formatted incorrectly (stod() failed)" << std::endl;
            return -2;
        }

    }

    /* Do the work */

    cosspace(x, 0.0, 1.0, nAlgPoints);

    // compute the values
    for(uint32_t i = 0; i < nAlgPoints; i++) {
        if(x[i] < posMaxCamber) {
            yc[i] = (camber / pow(posMaxCamber,2.0)) * (2 * posMaxCamber * x[i] - pow(x[i], 2.0));
            dycdx[i] = (2 * camber / pow(posMaxCamber,2.0)) * (posMaxCamber - x[i]);
        } else {
            yc[i] = (camber / pow(1.0 - posMaxCamber, 2.0)) * ((1 - 2 * posMaxCamber) + 2 * posMaxCamber * x[i] - pow(x[i], 2.0));
            dycdx[i] = (2 * camber / pow(1.0 - posMaxCamber, 2.0)) * (posMaxCamber - x[i]);
        }

        yt[i] = (thickness / 0.2) * (a[0]*pow(x[i], 0.5) + a[1]*x[i] + a[2]*pow(x[i],2.0) + a[3]*pow(x[i], 3.0) + a[4]*pow(x[i], 4.0));

        theta[i] = atan(dycdx[i]);

        // assign coordinates
        xUpper[i] = x[i] - yt[i]*sin(theta[i]);
        xLower[i] = x[i] + yt[i]*sin(theta[i]);
        yUpper[i] = yc[i] + yt[i]*cos(theta[i]);
        yLower[i] = yc[i] - yt[i]*cos(theta[i]);

    }

    /* Output to file */
    char filename[512];
    FILE* fp;
// todo add a param for output format
   if(outputFileType == OutputFileType::SCAD){
    // openscad output
        sprintf(filename, "./NACA%d%d%d-NP%d.scad", static_cast<int>(camber*100.0), static_cast<int>(posMaxCamber*10), static_cast<int>(thickness*100),numPoints);

        fp = fopen(filename, "w");

        fprintf(fp, "//NACA%d%d%d-NP%d\n", static_cast<int>(camber*100.0), static_cast<int>(posMaxCamber*10), static_cast<int>(thickness*100),numPoints);

        fprintf(fp, "points = [\n");
        for(int i = nAlgPoints - 1; i >= 0; i--) {
            fprintf(fp, "\t[%1.6f,  %1.6f],\n", xUpper[i], yUpper[i]);
        }

        // start this loop at 1 because the (0, 0) point has already been placed in the file
        for(uint32_t i = 1; i < nAlgPoints; i++) {
           fprintf(fp, "\t[%1.6f,  %1.6f],\n", xLower[i], yLower[i]);
        }

        fprintf(fp, "];\n polygon(points);\n");
    }else{
        // .dat output
        sprintf(filename, "./NACA%d%d%d-NP%d.dat", static_cast<int>(camber*100.0), static_cast<int>(posMaxCamber*10), static_cast<int>(thickness*100),numPoints);

        fp = fopen(filename, "w");

        fprintf(fp, "NACA%d%d%d-NP%d\n", static_cast<int>(camber*100.0), static_cast<int>(posMaxCamber*10), static_cast<int>(thickness*100),numPoints);


        for(int i = nAlgPoints - 1; i >= 0; i--) {
            fprintf(fp,"   %1.6f  %1.6f\n", xUpper[i], yUpper[i]);
        }

        // start this loop at 1 because the (0, 0) point has already been placed in the file
        for(uint32_t i = 1; i < nAlgPoints; i++) {
           fprintf(fp,"   %1.6f  %1.6f\n", xLower[i], yLower[i]);
        }
    }

    fclose(fp);

    /* Exit program */

    std::cout << "Output file saved as " << filename << std::endl;
    return 0;

}


// Simple function for creating linearly spaced vectors, inspired by MATLAB
void linspace(double * vec, double lowVal, double highVal, const uint32_t elements) {

    double dv = (highVal - lowVal) / static_cast<double>(elements - 1);

    for(uint32_t i = 0; i < elements; i++) {
        vec[i] = lowVal + static_cast<double>(i) * dv;
    }

}

// simple function for creating cosine-spaced vectors
void cosspace(std::vector<double>& vec, double lowVal, double highVal, const uint32_t elements) {

    double xLin[elements];
    linspace(xLin, lowVal, highVal, elements);

    for(uint32_t i = 0; i < elements; i++) {
        double frac = (xLin[i] - lowVal) / (highVal - lowVal);
        vec[i] = lowVal + (highVal - lowVal) * (1 - cos(frac * M_PI / 2.0));
    }

}

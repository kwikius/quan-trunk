
#include <quan/config.hpp>
#if defined QUAN_OS_LINUX
// Linux impl
#include <termios.h>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>

#include <quan/key_was_pressed.hpp>
// from
// http://stackoverflow.com/questions/22166074/is-there-a-way-to-detect-if-a-key-has-been-pressed
namespace quan{

   bool key_was_pressed()
   {
     termios oldt;
     tcgetattr(STDIN_FILENO, &oldt);

     termios newt = oldt;
     newt.c_lflag &= ~(ICANON | ECHO);
     tcsetattr(STDIN_FILENO, TCSANOW, &newt);

     int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);

     fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

     int ch = getchar();
     bool input = ch != EOF;

     tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
     fcntl(STDIN_FILENO, F_SETFL, oldf);

     if(input){
        ungetc(ch, stdin);
     }
     return input;
   }
}

#endif


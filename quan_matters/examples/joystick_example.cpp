

#include <cstdio>
#include <unistd.h>
#include <quan/joystick.hpp>
/*
Read a joystick. Tested with a Taranis USB joystick
*/
int main()
{
   try {

      quan::joystick js{"/dev/input/js0"};

      fprintf(stdout, "quan joystick test\n Toggle joysticks...\n\n");

      char timer_chars [] = "|/-\\";
      unsigned int cur_idx = 0;
      for ( ;;){
         fprintf(stdout,"\r");
         fprintf(stdout,"{ (%c) ", timer_chars[cur_idx]);
         for ( uint8_t ch = 0; ch < js.num_channels;++ch){
            fprintf(stdout,"ch%u[%7d]",static_cast<uint16_t>(ch),js.get_channel(ch));
            if ( ch < (js.num_channels -1)){
               fprintf(stdout," ");
            }
         }
         fprintf(stdout," (%c) }", timer_chars[3-cur_idx]);
         fflush(stdout);
         cur_idx  = (cur_idx + 1) % 4;
         usleep(100000);
      }

   }catch( std::exception & e){
       fprintf(stdout,"Exception : %s\n", e.what());
   }
}






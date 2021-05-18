#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <asm/types.h>
#include "sensehat.h"



//Function für zeigen der Zeit auf dem Raspberry 
int display_binary(int zeit, int row, int r, int g, int b)
    {
        
        for (int i = 7; i >= 0; --i) 
        {
		
            int x = zeit % 2;
            zeit = zeit / 2;
		
            if (x == 1)

                led_set_pixel( i, row, r, g, b);
            else
                led_set_pixel( i, row, 0, 0, 0);
		
        }
    }


//Main Function
int main(void)
    {
	
        struct timespec delay;
        delay.tv_sec = 1;

		
        led_clear(0, 0, 0);

        while(1)
        {
		
            time_t tjetzt;
	        struct tm * tmjetzt;

            time(&tjetzt);
            tmjetzt = localtime(&tjetzt);
		
        
            display_binary(tmjetzt->tm_year - 100, 0 , 0, 120, 0);
            display_binary(tmjetzt->tm_mon + 1, 1 , 0, 0, 120);
            display_binary(tmjetzt->tm_mday, 2 , 120, 0, 0);
		
            display_binary(tmjetzt->tm_hour, 4 , 0, 0, 120);
            display_binary(tmjetzt->tm_min, 5 , 120, 0, 0);
            display_binary(tmjetzt->tm_sec, 6 , 0, 120, 0);

            nanosleep(&delay, NULL);
		
        }
    }

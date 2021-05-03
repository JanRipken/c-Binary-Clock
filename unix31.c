

typedef struct 
{
    int rr;
    int gg;
    int bb;
} tuple;

tuple year_color = {0, 255, 0};
tuple month_color = {0, 0, 255};
tuple day_color = {255, 0, 0};
tuple hour_color = {0, 255, 0};
tuple minute_color = {0, 0, 255};
tuple second_color = {255, 0, 0};
tuple off = {0, 0, 0};


//Function für zeigen der Zeit auf dem Raspberry 
void display_binary(value, row, color){
    
    int *colo = color; 

    int i, secs = (diff/value) % 60;
    for (i = 6; i >= 0; --i) {
        if (secs & (1 << i))
            led_set_pixel(i, row, colo[1], colo[2], colo[3]);
        else
            led_set_pixel(i,row,0 ,0, 0);
    }
}


//Main Function
int main(void){

    for (;;){
        struct tm jetzt;
        display_binary(jetzt.tm_sec, 5 , second_color);
        display_binary(jetzt.tm_min, 4 , minute_color);
        display_binary(jetzt.tm_hour, 3 , hour_color);
        display_binary(jetzt.tm_mday, 2 , day_color);
        display_binary(jetzt.tm_mon, 1 , month_color);
        display_binary(jetzt.tm_year, 0 , year_color);
        }
}


#include <stdio.h>
#include <time.h>





int diff = 0;

void show(int unit, char end);

main() {
    struct tm Jetzt;
    time_t start = time(0), now = time(0);

    while (1) {
        diff = (now - start);
        display_binary(Jetzt.tm_sec, ' ');
        display_binary(Jetzt.tm_min, ' ');
        display_binary(Jetzt.tm_hour, ' ');
        display_binary(Jetzt.tm_mday , ' ');
        display_binary(Jetzt.tm_year, '\n ');
        now = time(0);
    }
}

void display_binary(int unit, char end) {
    int i, secs = (diff/unit) % 60;
    for (i = 6; i >= 0; --i) {
        if (secs & (1 << i))
            putchar('+');
        else
            putchar('-');
    }
    putchar(end);
}


#include "mbed.h"
#include "TextLCD.h"
#include<stdlib.h>
#include<time.h>
#include <string.h>
#include <iostream>
using namespace std;

DigitalIn button(PA_0);

const char *phrases[20] = {"Yes", "No", "Maybe","Dont bet on it", "Without a doubt", "You may rely on it", "Looks promising", "I doubt it", "Definitely a yes", "Im not sure", "Oops, thats a big no", "No way", "Try again", "My sources says no", "Dont count on it", "Better not tell you now", "Trust me, you dont want to know.", "Its hard to say.", "Meh", "Dont know. Dont care."};
int output;


TextLCD lcd(PC_0, PC_1, PC_2, PC_3, PC_4, PC_5); //LCD interface


void askAgain(){
    
    wait(10);
    lcd.cls();
    lcd.printf("Ask Magic-8 ball again");
}



int main()
{
    lcd.cls();
    lcd.printf("Ask the Magic-8 ball a question");
    
    
    while(1) {
        if (button == 0) {
            srand(time(NULL));// use the computer internal clock to control the choice of seed
            output = rand()%20;// randomized the output
            lcd.cls();//clear LCD screen
            lcd.locate(0,0);// Position (0,0) of LCD
            lcd.printf("%s", phrases[output]);// print phrases
            askAgain();// prompt to ask again
        }
        wait_ms(20);
    }
}

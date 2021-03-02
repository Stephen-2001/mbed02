#include "mbed.h"

DigitalIn mypin(USER_BUTTON);
DigitalOut myled(LED1);

int main(){
    // check mypin object is initialized and connected to a pin
    if (mypin.is_connected()){
        printf("mypin is connected and initialized! \n\r");
    }

    // Optional: set mode as PullUp / PullDown / PullNone / OpenDrain
    mypin.mode(PullDown);
    // pullnone: push 0, not push 1
    // pulldown: push 0, not push 0
    // pullup: push 0, not push 1
    // press the button and see the console / Led change
    while(1){
        printf("mypin has value : %d \n\r", mypin.read());
        myled = mypin;  // toggle Led based on value of button
        ThisThread::sleep_for(250ms);
    }
}
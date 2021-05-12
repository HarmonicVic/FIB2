#include "thisLCD.h"

thisLCD::thisLCD(QWidget*parent):QLCDNumber(parent){

}

void thisLCD::incnum(){
    int n = intValue();
    n++;
    if (n == 64) n = 0;
    display(n);
}

void thisLCD::resetLCD(){
    display(0);
}
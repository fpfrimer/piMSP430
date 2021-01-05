#include<msp430g2553.h>

#define     RED_LED     BIT0        // P1.0 - BIT0 da P1
#define     GREEN_LED   BIT6        // P1.6 - BIT6 da P1

int main(void){
    volatile int i = 0, cont = 0;
    volatile int delay = 20000;

    WDTCTL = WDTPW | WDTHOLD;       // Parar WDT
    P1DIR |= RED_LED + GREEN_LED;   // LEDs como saída
    P1OUT = 0;

    while(1){
        for(i = 0; i <= delay; i++);// Atraso
        cont += 1;                  // Incrementa contador

        /* Utiliza os dois bits menos significativos do contador */
        P1OUT = ((cont & BIT1) << 5) | (cont & BIT0);
    }
    return 0;
}

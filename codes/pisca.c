#include <msp430g2553.h>

#define LED1 0x01
#define LED2 0x40

int main(void){

    volatile int i = 0;         // Contador

    WDTCTL = WDTPW | WDTHOLD;   // Parar WDT

    P1DIR = LED1 + LED2;        // Pinos como saídas
    P1OUT = 0X00;               // Apaga os LEDs

    while(1){
        // Alterna estado dos LEDs
        P1OUT ^= LED1 | LED2; 
        for(i = 0; i < 10000; i++); // Atraso
    }
}
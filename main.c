#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 2000000  // Frecuencia del oscilador en Hz

int contador = 0;


void main(void) {
    // Configuración de puertos
    
    ADCON1 = 0X0F;
    TRISB=1;
    TRISA=0;
    
   
    PORTB = 0;          // Inicializar todos los pines a 0

    while (1) {
        if(PORTBbits.RB4 == PORTBbits.RB5 ){
            LATAbits.LA0=0;
            contador=0;
        }
        if(PORTBbits.RB0==0||PORTBbits.RB1==0||PORTBbits.RB2==0)
        {
            contador++;
            __delay_ms(10000);
        
        }
        if(contador>=10)
        {
            LATAbits.LA0=1;
            
        }
        
    }

    return;
}
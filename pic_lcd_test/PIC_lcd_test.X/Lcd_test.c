/*
 * File:   Lcd_test.c
 * Author: Preethi
 *
 * Created on 26 December, 2021, 11:48 AM
 */
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/



#include <xc.h>
#define EN RE0
#define RS RE1 
#define LCD PORTD

void delay(int ms)
{
    int i,j;
    for(i=0;i<ms;i++)
    {
        for(j=0;j<1000;j++);
    }
}

void lcd_enable()
{
    EN=1;
    delay(10);
    EN=0;
    delay(10);
}
void lcd_command(char a) //char or int 
{
   RS=0;//command
   LCD=a;
   //delay(10);
   //command
   lcd_enable();
}

void lcd_data(char a) //char or int
{
    RS=1; 
    LCD=a;
    lcd_enable();
}

void lcd_string(char *a)
{
    while(*a!='\0')
    {
        lcd_data(*a);
        a++;
    }
}
void main(void)
{
    PORTD=0x00;
    TRISD=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    PORTE=0x00;
    TRISE=0x00;
    
    while(1)
    {
        lcd_command(0x38);
        lcd_command(0x0E);
        lcd_command(0x80);
        lcd_string("preethi");
    }
    return;
}

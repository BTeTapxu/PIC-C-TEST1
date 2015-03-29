#include "soril1.h"
#define led PIN_D0
#define led1 PIN_D1
#bit tmr1on=0xFCD.0

float data[10],sum=0,average=0;
#int_TIMER1
void TIMER1_isr() 
{
   static char count=0;
   set_timer1(121070);
   data[count]=read_adc()*0.0196078431372549;
   sum=sum+data[count];
   count++;
   if(count==10){
   average=sum/10;
   printf("dundaj=%f\r\n", average);
   sum=0;
   count=0;}
   }



void main()
{

   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_timer_2(T2_DISABLED,0,1);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_2);
   set_timer1(121070);
   set_adc_channel(0);
   tmr1on=1;
   set_tris_d(0x00);
   
   while(true)
   {
      delay_ms(200);
      output_toggle(led);
   }
}


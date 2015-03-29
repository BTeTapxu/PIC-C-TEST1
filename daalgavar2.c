#include "soril1.h"
#define led PIN_D0
int i;
float value[2], temp, dar;
void main()
{
   setup_adc_ports(AN0_AN1_VSS_VREF);
   setup_adc(ADC_CLOCK_INTERNAL);
   set_tris_d(0x00);
   
   while(true)
   {
      for(i=0;i<2;i++){
      set_adc_channel(i);
      value[i]=read_adc()*0.0196078431372549;
      }
      temp=value[0]*25+15.8;
      dar=value[1]*100+20.5;
      if((temp>25&&temp<50)&&(dar>100&&dar<200)){
      printf("normal %f, %f\r\n", temp, dar);
      delay_ms(200);
      }
      else{
      printf("warning %f, %f\r\n", temp, dar);
      output_toggle(led);
      delay_ms(200);
      }
   }
}

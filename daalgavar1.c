#include <soril1.h>
float analog;
void main()
{

   setup_adc_ports(AN0);
   setup_adc(adc_clock_internal);
   set_adc_channel(0);
   while(true){
   analog=read_adc()*0.0196078431372549;
   if(analog>3.0){
      printf("Upper level %f\r\n", analog);
   }
   else if(analog<1.5){
      printf("Lower limit %f\r\n", analog);
   }
   else{
      printf("normal %f\r\n", analog);
   }
   }
}

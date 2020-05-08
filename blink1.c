/* Blink Example
ejemplo de perifericos esp32
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

/* Can use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO CONFIG_BLINK_GPIO

void app_main(void)
{
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    
    gpio_pad_select_gpio(BLINK_GPIO);//la configura como salida
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO,GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio_(GPIO_NUM_12)//SLECCIONAS LA TERMINAL 
gpio_set_direction(GPIO_NUM_12,GPIO_MODE_INTPUT)
gpio_set_pull_mode(GPIO_NUM_12,1)//PULL UP

    gpio_pad_select_gpio_(GPIO_NUM_14);
    gpio_pad_select_gpio(GPIO_NUM_14,GPIO_MODE_OUTPUT);
  
   
  
    
    
    while(1) {
        /* Blink off (output low) */
	//printf("Turning off the LED\n");
        gpio_set_level(BLINK_GPIO, 1);
        gpio_set_level(GPIO_NUM_14, 0);
        for(int contador=0;contador<=10;contador++){
		if(0==gpio_get_level(GPIO_NUM_12))
		contador=0;
		printf("Entrada=%d\n",gpio_get_level(GPIO_NUM_12));	
	  vTaskDelay(1000 / portTICK_PERIOD_MS);
			
			}
			gpio_set_level(BLINK_GPIO,0);
			gpio_set_level(BLINK_GPIO_NUM_14,1);
			vTaskDelay(3000 / portTICK_PERIOD_MS);
			
			gpio_set_level(BLINK_GPIO_NUM_14,0);
		    vTaskDelay(3000 / portTICK_PERIOD_MS);
			while(0==gpio_get_level(GPIO_NUM_12)){
				
			vTaskDelay(1000 / portTICK_PERIOD_MS);
			printf("Entrada=%d\n",gpio_get_level(GPIO_NUM_12));
			
				}
				gpio_set_level(BLINK_GPIO,1);
       // vTaskDelay(1000 / portTICK_PERIOD_MS);
        /* Blink on (output high) */
	//printf("Turning on the LED\n");
        //gpio_set_level(BLINK_GPIO, 1);
        //vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

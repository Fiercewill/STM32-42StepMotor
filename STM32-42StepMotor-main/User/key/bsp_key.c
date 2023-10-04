#include "bsp_key.h"

void Key_GPIO_Config(void){
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK, ENABLE);
	
    GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN;
    GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);
}

//The elimination of trembling is completed in hardware  //这个按键扫描程序没有做软件消抖，因为硬件上做了消抖
uint8_t Key_Scan(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){
    if(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON){
			//detect for reseasing hand
        while(GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON);  //软件上考虑松手检测，按键按下后在松手之前功能是无效的
        return KEY_ON;
    } else
        return KEY_OFF;
}


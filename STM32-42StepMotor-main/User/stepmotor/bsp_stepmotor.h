#ifndef __BSP_STEPMOTOR_H
#define __BSP_STEPMOTOR_H

#include "stm32f10x.h"


#define MOTOR_DIR_PORT      GPIOC
#define MOTOR_DIR_PIN       GPIO_Pin_6
#define MOTOR_DIR_CLK       RCC_APB2Periph_GPIOC

#define MOTOR_PUL_PORT      GPIOC
#define MOTOR_PUL_PIN       GPIO_Pin_7
#define MOTOR_PUL_CLK       RCC_APB2Periph_GPIOC

#define MOTOR_ENA_PORT      GPIOC
#define MOTOR_ENA_PIN       GPIO_Pin_4
#define MOTOR_ENA_CLK       RCC_APB2Periph_GPIOC

//三个操作寄存器的小函数
#define digitalHi(p,i) 			{p->BSRR=i;}  //置高
#define digitalLo(p,i) 			{p->BRR=i;}   //置低
#define digitalToggle(p,i) 	{p->ODR ^= i;} //反转

//使能口
#define MOTOR_ENA_Toggle    digitalToggle(MOTOR_ENA_PORT, MOTOR_ENA_PIN)
#define MOTOR_ON 	    			digitalHi(MOTOR_ENA_PORT, MOTOR_ENA_PIN)
#define MOTOR_OFF	    			digitalLo(MOTOR_ENA_PORT, MOTOR_ENA_PIN)

//方向口
#define MOTOR_PUL_Toggle    digitalToggle(MOTOR_PUL_PORT, MOTOR_PUL_PIN)
#define MOTOR_PUL_ON 	    	digitalHi(MOTOR_PUL_PORT, MOTOR_PUL_PIN)
#define MOTOR_PUL_OFF 	    digitalLo(MOTOR_PUL_PORT, MOTOR_PUL_PIN)

//脉冲口
#define MOTOR_DIR_Toggle    digitalToggle(MOTOR_DIR_PORT, MOTOR_DIR_PIN)
#define MOTOR_DIR_CCW    		digitalHi(MOTOR_DIR_PORT, MOTOR_DIR_PIN)
#define MOTOR_DIR_CW   			digitalLo(MOTOR_DIR_PORT, MOTOR_DIR_PIN)

void Stepper_Pin_Init(void);

#endif



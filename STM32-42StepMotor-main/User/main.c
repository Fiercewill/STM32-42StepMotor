#include "stm32f10x.h"
#include "bsp_key.h"
#include "bsp_stepmotor.h"

void Delay(__IO uint32_t nCount){
	for (; nCount != 0; nCount--)
		;
};

void Step_90_Degrees(){
	// NC = 1600, 800 toggles means 90 degree motor rotation
	for (int i = 0; i < 800; i++)
	{	
		MOTOR_PUL_Toggle;  //翻转800次
		// The delay time determines the motor speed
		Delay(0xfff);  //delay时间的长短决定电机旋转的速度，这个延时是不准确的，若需要精准的延时，可采用定时器
	}
}
//
int main(void)
{
	Key_GPIO_Config();   //按键的配置，初始化
	Stepper_Pin_Init();  //步进电机配置
	Delay(0xfffff);      //进行延时，单片机更好初始化
	// Keep detecting the Key status
	while(1){
		if (Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON){
			// Counter Clock Wise for KEy1
			MOTOR_DIR_CCW;     //设置步进电机为逆时针旋转方向
			Step_90_Degrees(); //控制脉冲端口，使步进电机旋转90度
		}
		if (Key_Scan(KEY2_GPIO_PORT, KEY2_GPIO_PIN) == KEY_ON){
			// Counter Clock Wise for KEy2
			MOTOR_DIR_CW;       //设置步进电机为顺时针旋转方向
			Step_90_Degrees();
		}
	}
}

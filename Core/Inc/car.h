/*
 * car.h
 *
 *  Created on: Jun 20, 2024
 *      Author: Shivam
 */

#ifndef INC_CAR_H_
#define INC_CAR_H_

extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef huart6;

#define m1 TIM1->CCR1
#define m2 TIM1->CCR2
int abc= 500;
uint8_t buff[10];
int x;
int y;

void receive()
 {
 	HAL_UART_Receive(&huart6, buff, sizeof(buff),100);
 	sscanf(buff,"%d , %d",&x, &y);
  }

void speed()
 {
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
 }

void forward()
 {
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
}

void reverse()
{
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);

}

void left()
{
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
}

void right()
{
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
 }

void stop()
 {
 	m1 = 0;
 	m2 = 0;
 }

#endif /* INC_CAR_H_ */

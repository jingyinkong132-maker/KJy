#include "main.h"

#include "usart.h"

unit8 u1_rx_data_temp = 0;
unit8 buff[9]={0};
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART1) {
        buff[0]=u1_rx_data_temp;
			HAL_UART_Receive_IT(&huart1,&u1_rx_data_temp,1);
    }
		if (huart->Instance == USART2) {
        buff[0]=u1_rx_data_temp;
			HAL_UART_Receive_DMA(&huart2,&u1_rx_data_temp,1);
    }
}
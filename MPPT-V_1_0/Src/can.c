/**
  ******************************************************************************
  * @file    can.c
  * @brief   This file provides code for the configuration
  *          of the CAN instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "can.h"
#include "utilities.h"

/* USER CODE BEGIN 0 */
/* USER CODE BEGIN 0 */


CAN_FrameInit frame_SYNC;
uint32_t TxMailbox;
CAN_RxHeaderTypeDef RxHeader;
uint8_t RxData[8];


/* USER CODE END 0 */

CAN_HandleTypeDef hcan1;

/* CAN1 init function */
void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 52;
  hcan1.Init.Mode = CAN_MODE_LOOPBACK;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_13TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = ENABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */

  /* USER CODE END CAN1_Init 2 */

}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspInit 0 */

  /* USER CODE END CAN1_MspInit 0 */
    /* CAN1 clock enable */
    __HAL_RCC_CAN1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**CAN1 GPIO Configuration
    PA11     ------> CAN1_RX
    PA12     ------> CAN1_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_CAN1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN CAN1_MspInit 1 */

  /* USER CODE END CAN1_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspDeInit 0 */

  /* USER CODE END CAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN1_CLK_DISABLE();

    /**CAN1 GPIO Configuration
    PA11     ------> CAN1_RX
    PA12     ------> CAN1_TX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11|GPIO_PIN_12);

  /* USER CODE BEGIN CAN1_MspDeInit 1 */

  /* USER CODE END CAN1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/*******************************************************************************
 FILTER CONFIGURATION
 *******************************************************************************/
void CANFilerConfig(void) {
	filter_0.FilterBank = 0;
	filter_0.FilterMode = CAN_FILTERMODE_IDMASK;
	filter_0.FilterScale = CAN_FILTERSCALE_32BIT;
	filter_0.FilterIdHigh = 0x0000;			//0x321 << 5;
	filter_0.FilterIdLow = 0x0000;				//0x00000000;
	filter_0.FilterMaskIdHigh = 0x0000;		//0x111 << 5;
	filter_0.FilterMaskIdLow = 0x0000;			//0x00000000;
	filter_0.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	filter_0.FilterActivation = ENABLE;
	filter_0.SlaveStartFilterBank = 14;
}

/*******************************************************************************
 	 PERYFERIUM INITIAZLIZATION
 *******************************************************************************/
void CAN1_Init() {
	if (HAL_CAN_ConfigFilter(&hcan1, &filter_0) != HAL_OK) {
		Error_Handler();
	}

	if (HAL_CAN_Start(&hcan1) != HAL_OK) {
		Error_Handler();
	}

	if (HAL_CAN_ActivateNotification(&hcan1,
	CAN_IT_RX_FIFO0_MSG_PENDING | CAN_IT_TX_MAILBOX_EMPTY) != HAL_OK) {
		Error_Handler();
	}
}

/*******************************************************************************
 FRAME CONFIGURATION
 *******************************************************************************/
void prepareFrameData(void){
	uint32_t inputVoltage = averageArrayVoltage;
	uint32_t inputCurrent = averageArrayCurrent;

	frame_SYNC.TxData[0] = 0xFF & inputVoltage;
	frame_SYNC.TxData[1] = (0xFF00 & inputVoltage) >> 8;
	frame_SYNC.TxData[2] = (0xFF0000 & inputVoltage) >> 16;
	frame_SYNC.TxData[3] = (0xFF000000 & inputVoltage) >> 24;
	frame_SYNC.TxData[4] = 0xFF & inputCurrent;
	frame_SYNC.TxData[5] = (0xFF00 & inputCurrent) >> 8;
	frame_SYNC.TxData[6] = (0xFF0000 & inputCurrent) >> 16;
	frame_SYNC.TxData[7] = (0xFF000000 & inputCurrent) >> 24;
}

void sendCAN() {
	frame_SYNC.TxHeader.StdId = 0x080;
	frame_SYNC.TxHeader.RTR = CAN_RTR_DATA;
	frame_SYNC.TxHeader.IDE = CAN_ID_STD;
	frame_SYNC.TxHeader.DLC = 8;
	frame_SYNC.TxHeader.TransmitGlobalTime = DISABLE;

	prepareFrameData();

	if (HAL_CAN_AddTxMessage(&hcan1, &frame_SYNC.TxHeader, frame_SYNC.TxData,
			&TxMailbox) != HAL_OK) {
		Error_Handler();
	} else{
		resetYellowState();
	}

	while (HAL_CAN_GetTxMailboxesFreeLevel(&hcan1) != 3) {
	}
}

void sendCANData(uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4, uint8_t byte5, uint8_t byte6, uint8_t byte7) {
	frame_SYNC.TxHeader.StdId = 0x080;
	frame_SYNC.TxHeader.RTR = CAN_RTR_DATA;
	frame_SYNC.TxHeader.IDE = CAN_ID_STD;
	frame_SYNC.TxHeader.DLC = 8;
	frame_SYNC.TxHeader.TransmitGlobalTime = DISABLE;

	frame_SYNC.TxData[0] = byte0;
	frame_SYNC.TxData[1] = byte1;
	frame_SYNC.TxData[2] = byte2;
	frame_SYNC.TxData[3] = byte3;
	frame_SYNC.TxData[4] = byte4;
	frame_SYNC.TxData[5] = byte5;
	frame_SYNC.TxData[6] = byte6;
	frame_SYNC.TxData[7] = byte7;

	if (HAL_CAN_AddTxMessage(&hcan1, &frame_SYNC.TxHeader, frame_SYNC.TxData,
			&TxMailbox) != HAL_OK) {
		Error_Handler();
	}

	while (HAL_CAN_GetTxMailboxesFreeLevel(&hcan1) != 1) {
	}
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

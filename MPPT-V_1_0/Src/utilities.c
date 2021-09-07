#include "utilities.h"
#include "dma.h"

void setYellowState(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_RESET);
	MPPTState = MPPT_STATE_YELLOW;
}

void resetYellowState(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4, GPIO_PIN_SET);
}

void setRedState(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET);
	disablePWM();
	MPPTState = MPPT_STATE_RED;
}
void resetRedState(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);
}

void setGreenState(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_RESET);
	enablePWM();
	MPPTState = MPPT_STATE_GREEN;
}
void resetGreenState(void){
	HAL_GPIO_WritePin(GPIOE, GPIO_PIN_6, GPIO_PIN_SET);
}

void enablePWM(void){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
}
void disablePWM(void){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
}


void readVoltageAndCurrent(uint32_t * valueContainer){
	//
	//Battery:  318 - 13V, 500 - 20V, 800 - 32V, 1783 - 73,7V, 1907 - 80V, 2500 - 140V
	//Array:  512 - 20V, 816 - 32V


	batteryVoltageADC = valueContainer[3];
	batteryCurrentADC = valueContainer[1];

	arrayVoltageADC = valueContainer[2];
	arrayCurrentADC = valueContainer[0];
}

void getArrayStatus(void)
{
	calculateMeasurementsAverage();

	if(arrayStatus == ARRAY_ERROR)
	{
		if (averageArrayVoltage >= ARRAY_TURN_ON_TH)
				arrayStatus = ARRAY_OK;

		else if (averageArrayVoltage < ARRAY_TURN_ON_TH)
			arrayStatus = ARRAY_ERROR;

	}

	else if (arrayStatus == ARRAY_OK)
	{
		if (averageArrayVoltage >= ARRAY_TURN_OFF_TH)
			arrayStatus = ARRAY_OK;

		else if (averageArrayVoltage < ARRAY_TURN_OFF_TH)
			arrayStatus = ARRAY_ERROR;
	}
}

void getBatteryStatus(void){
	calculateMeasurementsAverage();

	if (batteryStatus == BATTERY_ERROR){
		if (averageBatteryVoltage >= BATTERY_ON_BOTTOM_TH || averageBatteryVoltage <= BATTERY_ON_UPPER_TH)
			batteryStatus = BATTERY_OK;
		if (averageBatteryVoltage < BATTERY_ON_BOTTOM_TH || averageBatteryVoltage > BATTERY_ON_UPPER_TH)
			batteryStatus = BATTERY_ERROR;
		return ;

	} else if (batteryStatus == BATTERY_OK) {
		if (averageBatteryVoltage >= BATTERY_OFF_BOTTOM_TH || averageBatteryVoltage <= BATTERY_OFF_UPPER_TH)
			batteryStatus = BATTERY_OK;
		if (averageBatteryVoltage < BATTERY_OFF_BOTTOM_TH || averageBatteryVoltage > BATTERY_OFF_UPPER_TH)
			batteryStatus = BATTERY_ERROR;
		return;
	}
}


void storeMeasurements(void){
	if (lastMeasurementsIterator + 1 < NUMBER_OF_LAST_MEASUREMENTS)
		lastMeasurementsIterator++;
	else
		lastMeasurementsIterator = 0;

	readVoltageAndCurrent(valueContainerADC);

	lastADCArrayVoltage[lastMeasurementsIterator] = arrayVoltageADC;
	lastADCArrayCurrent[lastMeasurementsIterator] = arrayCurrentADC;
	lastADCBatteryVoltage[lastMeasurementsIterator] = batteryVoltageADC;
	lastADCBatteryCurrent[lastMeasurementsIterator] = batteryCurrentADC;
}

void calculateMeasurementsAverage(void)
{
	averageArrayVoltage = 0;
	averageArrayCurrent = 0;
	averageBatteryVoltage = 0;
	averageBatteryCurrent = 0;

	for(int i = 0; i < NUMBER_OF_LAST_MEASUREMENTS; i++)
	{
		averageArrayVoltage += lastADCArrayVoltage[i];
		averageArrayCurrent += lastADCArrayCurrent[i];
		averageBatteryVoltage += lastADCBatteryVoltage[i];
		averageBatteryCurrent += lastADCBatteryCurrent[i];
	}

	averageArrayVoltage /= NUMBER_OF_LAST_MEASUREMENTS;
	averageArrayCurrent /= NUMBER_OF_LAST_MEASUREMENTS;
	averageBatteryVoltage /= NUMBER_OF_LAST_MEASUREMENTS;
	averageBatteryCurrent /= NUMBER_OF_LAST_MEASUREMENTS;
}

void measurementsInit(void){
	lastMeasurementsIterator = 0;

	startReadingDMA(valueContainerADC);

	HAL_Delay(100); // to get valuable ADC measurements

	for(int i = 0; i < NUMBER_OF_LAST_MEASUREMENTS; i++){
		storeMeasurements();
		HAL_Delay(DELAY_BETWEEN_MEASUREMENTS);
	}

	calculateMeasurementsAverage();
}

void checkArrayConnection(void){

	getArrayStatus();

	if(arrayStatus == ARRAY_ERROR)
	{
		setRedState();
		resetGreenState();
		resetYellowState();
	}

	if(arrayStatus == ARRAY_OK)
	{
		resetRedState();
		setGreenState();
		resetYellowState();
	}

}

void checkBatteryConnection(void){

	getBatteryStatus();

	if(batteryStatus == BATTERY_ERROR)
	{
		setRedState();
		resetGreenState();
		resetYellowState();
	}
	if(batteryStatus == BATTERY_OK)
	{
		resetRedState();
		setGreenState();
		resetYellowState();
	}
}

void calculateInputPower(void){
	inputPower = averageArrayCurrent * averageArrayVoltage;
}
void setDutyCycle(uint32_t dutyCyclePerMille){
	TIM3->CCR4 = MAX_COUNTER_VALUE*dutyCyclePerMille;
}

void increaseDutyCycle(void){
	uint32_t currentValue = TIM3->CCR4;

	currentValue += MAX_COUNTER_VALUE*DUTY_CYCLE_STEP/1000;

	if(currentValue <= MAX_COUNTER_VALUE*90/100)
		TIM3->CCR4 = currentValue;

	prevStepDirection = STEP_UP;
}

void decreaseDutyCycle(void){
	uint32_t currentValue = TIM3->CCR4;

	currentValue -= MAX_COUNTER_VALUE*DUTY_CYCLE_STEP/1000;

	if(currentValue > 0)
		TIM3->CCR4 = currentValue;
	else
		TIM3->CCR4 = 0;

	prevStepDirection = STEP_DOWN;
}


void MPPTInit(void){
	prevStepDirection = STEP_UP;
	// set duty cycle
	setDutyCycle(DUTY_CYCLE_INITIALIZED);

	// reset LED State
	resetYellowState();
	resetRedState();
	resetGreenState();

	// initialize array and battery status
	arrayStatus = ARRAY_ERROR;
	batteryStatus = BATTERY_ERROR;

	disablePWM();

	measurementsInit();
	checkArrayConnection();
	checkBatteryConnection();

	if(MPPTState == MPPT_STATE_GREEN)
	{
		calculateInputPower();
	}
	isMPPTInitialised = 1;

}

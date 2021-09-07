################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/can.c \
../Src/dma.c \
../Src/gpio.c \
../Src/main.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_stm32f4xx.c \
../Src/tim.c \
../Src/utilities.c 

OBJS += \
./Src/adc.o \
./Src/can.o \
./Src/dma.o \
./Src/gpio.o \
./Src/main.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_stm32f4xx.o \
./Src/tim.o \
./Src/utilities.o 

C_DEPS += \
./Src/adc.d \
./Src/can.d \
./Src/dma.d \
./Src/gpio.d \
./Src/main.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_stm32f4xx.d \
./Src/tim.d \
./Src/utilities.d 


# Each subdirectory must supply rules for building sources it contributes
Src/adc.o: ../Src/adc.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/adc.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/can.o: ../Src/can.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/can.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/dma.o: ../Src/dma.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/dma.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/gpio.o: ../Src/gpio.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/gpio.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/main.o: ../Src/main.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/stm32f4xx_hal_msp.o: ../Src/stm32f4xx_hal_msp.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/stm32f4xx_it.o: ../Src/stm32f4xx_it.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/system_stm32f4xx.o: ../Src/system_stm32f4xx.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/tim.o: ../Src/tim.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/tim.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/utilities.o: ../Src/utilities.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DDEBUG -DSTM32F407xx -c -I../Inc -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/utilities.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"


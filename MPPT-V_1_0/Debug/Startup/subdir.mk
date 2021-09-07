################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f407vgtx.s 

OBJS += \
./Startup/startup_stm32f407vgtx.o 

S_DEPS += \
./Startup/startup_stm32f407vgtx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/startup_stm32f407vgtx.o: ../Startup/startup_stm32f407vgtx.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I../ -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/STM32F4xx_HAL_Driver/Inc" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"N:/PUTSolarDynamics/MPPT/MPPT/MPPT-V_1_0/Drivers/CMSIS/Include" -x assembler-with-cpp -MMD -MP -MF"Startup/startup_stm32f407vgtx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"


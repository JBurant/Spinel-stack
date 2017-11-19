################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../protocol/test/main.c 

OBJS += \
./protocol/test/main.o 

C_DEPS += \
./protocol/test/main.d 


# Each subdirectory must supply rules for building sources it contributes
protocol/test/%.o: ../protocol/test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../protocol/src/message_wrapper.c \
../protocol/src/utils.c 

OBJS += \
./protocol/src/message_wrapper.o \
./protocol/src/utils.o 

C_DEPS += \
./protocol/src/message_wrapper.d \
./protocol/src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
protocol/src/%.o: ../protocol/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



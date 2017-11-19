################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../protocol/test/main.c \
../protocol/test/read_test.c \
../protocol/test/write_test.c 

OBJS += \
./protocol/test/main.o \
./protocol/test/read_test.o \
./protocol/test/write_test.o 

C_DEPS += \
./protocol/test/main.d \
./protocol/test/read_test.d \
./protocol/test/write_test.d 


# Each subdirectory must supply rules for building sources it contributes
protocol/test/%.o: ../protocol/test/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/jirka/eclipse-workspace/spinel_stack/protocol/inc" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



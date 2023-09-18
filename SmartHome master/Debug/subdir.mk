################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DIO.c \
../EEROM.c \
../KEY_PAD.c \
../LCD.c \
../LEDs.c \
../Messages.c \
../Timers.c \
../USART.c \
../login.c \
../main.c \
../menu.c 

OBJS += \
./ADC.o \
./DIO.o \
./EEROM.o \
./KEY_PAD.o \
./LCD.o \
./LEDs.o \
./Messages.o \
./Timers.o \
./USART.o \
./login.o \
./main.o \
./menu.o 

C_DEPS += \
./ADC.d \
./DIO.d \
./EEROM.d \
./KEY_PAD.d \
./LCD.d \
./LEDs.d \
./Messages.d \
./Timers.d \
./USART.d \
./login.d \
./main.d \
./menu.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



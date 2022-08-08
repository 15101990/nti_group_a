################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/WDT/WDT_prog.c 

OBJS += \
./MCAL/WDT/WDT_prog.o 

C_DEPS += \
./MCAL/WDT/WDT_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/WDT/%.o: ../MCAL/WDT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\dell\Downloads\DIO_project\LIB" -I"C:\Users\dell\Downloads\DIO_project\HAL\EXT_EEPROM" -I"C:\Users\dell\Downloads\DIO_project\MCAL\TWI" -I"C:\Users\dell\Downloads\DIO_project\MCAL\SPI" -I"C:\Users\dell\Downloads\DIO_project\MCAL\UART" -I"C:\Users\dell\Downloads\DIO_project\MCAL\WDT" -I"C:\Users\dell\Downloads\DIO_project\HAL\SERVO" -I"C:\Users\dell\Downloads\DIO_project\MCAL\TIMER1" -I"C:\Users\dell\Downloads\DIO_project\MCAL\TIMER0" -I"C:\Users\dell\Downloads\DIO_project\HAL\TEMP_SENSOR" -I"C:\Users\dell\Downloads\DIO_project\MCAL\ADC" -I"C:\Users\dell\Downloads\DIO_project\MCAL\EXTI" -I"C:\Users\dell\Downloads\DIO_project\MCAL\GIE" -I"C:\Users\dell\Downloads\DIO_project\HAL\LCD" -I"C:\Users\dell\Downloads\DIO_project\HAL\KeyPad" -I"C:\Users\dell\Downloads\DIO_project\HAL\Buzzer" -I"C:\Users\dell\Downloads\DIO_project\HAL\PB" -I"C:\Users\dell\Downloads\DIO_project\HAL\SSD" -I"C:\Users\dell\Downloads\DIO_project\HAL\LED" -I"C:\Users\dell\Downloads\DIO_project\MCAL\DIO" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../proj/drivers/keyboard.c \
../proj/drivers/rf_pa.c \
../proj/drivers/usb.c 

OBJS += \
./proj/drivers/keyboard.o \
./proj/drivers/rf_pa.o \
./proj/drivers/usb.o 


# Each subdirectory must supply rules for building sources it contributes
proj/drivers/%.o: ../proj/drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"F:\Driver_2Com\Telink\code_demo\Remote\Remote\firmware" -I"F:\Driver_2Com\Telink\code_demo\Remote\Remote\firmware\vendor\common\mi_api\mijia_ble_api" -I"F:\Driver_2Com\Telink\code_demo\Remote\Remote\firmware\vendor\common\mi_api\libs" -D__PROJECT_MESH_SWITCH__=1 -DCHIP_TYPE=CHIP_TYPE_8258 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../vendor/mesh_switch/app.c \
../vendor/mesh_switch/app_att.c \
../vendor/mesh_switch/main.c 

OBJS += \
./vendor/mesh_switch/app.o \
./vendor/mesh_switch/app_att.o \
./vendor/mesh_switch/main.o 


# Each subdirectory must supply rules for building sources it contributes
vendor/mesh_switch/%.o: ../vendor/mesh_switch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 Compiler'
	tc32-elf-gcc -ffunction-sections -fdata-sections -I"F:\Driver_2Com\Telink\code_demo\Remote\Remote\firmware" -I"F:\Driver_2Com\Telink\code_demo\Remote\Remote\firmware\vendor\common\mi_api\mijia_ble_api" -I"F:\Driver_2Com\Telink\code_demo\Remote\Remote\firmware\vendor\common\mi_api\libs" -D__PROJECT_MESH_SWITCH__=1 -DCHIP_TYPE=CHIP_TYPE_8258 -Wall -O2 -fpack-struct -fshort-enums -finline-small-functions -std=gnu99 -fshort-wchar -fms-extensions -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



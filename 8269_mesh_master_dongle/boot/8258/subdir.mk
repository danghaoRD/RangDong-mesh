################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../boot/8258/cstartup_8258.S \
../boot/8258/cstartup_8258_RET_16K.S \
../boot/8258/cstartup_8258_RET_32K.S 

OBJS += \
./boot/8258/cstartup_8258.o \
./boot/8258/cstartup_8258_RET_16K.o \
./boot/8258/cstartup_8258_RET_32K.o 


# Each subdirectory must supply rules for building sources it contributes
boot/8258/%.o: ../boot/8258/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: TC32 CC/Assembler'
	tc32-elf-gcc -Xassembler"C:\Drive_2Com\Telink\code_demo\Remote\Remote\firmware" -DMCU_STARTUP_8267 -D__LOAD_RAM_SIZE__=0x12 -D__PROJECT_8267_MASTER_KMA_DONGLE__=1 -DCHIP_TYPE=CHIP_TYPE_8269 -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



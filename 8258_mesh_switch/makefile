################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include vendor/user_app/subdir.mk
-include vendor/mesh_switch/subdir.mk
-include vendor/mesh_switch/RD_Remote/subdir.mk
-include vendor/mesh_switch/RD_Mess_Data/subdir.mk
-include vendor/mesh_switch/Button/subdir.mk
-include vendor/common/subdir.mk
-include vendor/common/nl_api/subdir.mk
-include vendor/common/mi_api/subdir.mk
-include vendor/common/mi_api/mijia_ble_api/subdir.mk
-include vendor/common/mi_api/mi_vendor/subdir.mk
-include vendor/common/mi_api/libs/third_party/pt/subdir.mk
-include vendor/common/mi_api/libs/third_party/micro-ecc/subdir.mk
-include vendor/common/mi_api/libs/third_party/mbedtls/subdir.mk
-include proj/mcu_spec/subdir.mk
-include proj/mcu/subdir.mk
-include proj/drivers/subdir.mk
-include proj/common/subdir.mk
-include proj/app/subdir.mk
-include drivers/8258/subdir.mk
-include boot/8258/subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LST += \
8258_switch.lst \

FLASH_IMAGE += \

SIZEDUMMY += \
sizedummy \


# All Target
all: pre-build main-build

# Main-build Target
main-build: Remote.elf secondary-outputs

# Tool invocations
Remote.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: TC32 C Linker'
	tc32-elf-ld --gc-sections -L"F:\Driver_2Com\Telink\code_demo\Remote\Remote\firmware\proj_lib" -T ../boot.link -o"Remote.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

8258_switch.lst: Remote.elf
	@echo 'Invoking: TC32 Create Extended Listing'
	tc32-elf-objdump -x -D -l -S Remote.elf  >"8258_switch.lst"
	@echo 'Finished building: $@'
	@echo ' '

: Remote.elf
	@echo 'Create Flash image (binary format)'
	tc32-elf-objcopy -O binary Remote.elf
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Remote.elf
	@echo 'Invoking: Print Size'
	tc32-elf-size -t Remote.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(LST)$(SIZEDUMMY) Remote.elf
	-@echo ' '

pre-build:
	-"F:\Driver_2Com\Telink\code_demo\Remote\Remote\firmware/getver.sh"
	-@echo ' '

post-build:
	-"F:\Driver_2Com\Telink\code_demo\Remote\Remote\firmware/tl_check_fw.sh"   8258_mesh_switch   Remote
	-@echo ' '

secondary-outputs: $(LST) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY: main-build pre-build post-build

-include ../makefile.targets

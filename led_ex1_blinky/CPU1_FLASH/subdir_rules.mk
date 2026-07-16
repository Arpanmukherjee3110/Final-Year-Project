################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/Users/Subham Mandal/workspace_ccstheia/led_ex1_blinky" --include_path="C:/ti/C2000Ware_26_01_00_00" --include_path="C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=DEBUG --define=_FLASH --define=generic_flash_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/Subham Mandal/workspace_ccstheia/led_ex1_blinky/CPU1_FLASH/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-159793238: ../led_ex1_blinky.syscfg
	@echo 'SysConfig - building file: "$<"'
	"C:/ti/ccs2100/ccs/utils/sysconfig_1.28.0/sysconfig_cli.bat" -s "C:/ti/C2000Ware_26_01_00_00/.metadata/sdk.json" --script "C:/Users/Subham Mandal/workspace_ccstheia/led_ex1_blinky/led_ex1_blinky.syscfg" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-159793238 ../led_ex1_blinky.syscfg
syscfg/board.h: build-159793238
syscfg/board.cmd.genlibs: build-159793238
syscfg/board.opt: build-159793238
syscfg/board.json: build-159793238
syscfg/pinmux.csv: build-159793238
syscfg/device.c: build-159793238
syscfg/device.h: build-159793238
syscfg/device_cmd.cmd: build-159793238
syscfg/device_cmd.c: build-159793238
syscfg/device_cmd.h: build-159793238
syscfg/device_cmd.opt: build-159793238
syscfg/device_cmd.cmd.genlibs: build-159793238
syscfg/c2000ware_libraries.cmd.genlibs: build-159793238
syscfg/c2000ware_libraries.opt: build-159793238
syscfg/c2000ware_libraries.c: build-159793238
syscfg/c2000ware_libraries.h: build-159793238
syscfg/clocktree.h: build-159793238
syscfg: build-159793238

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/Users/Subham Mandal/workspace_ccstheia/led_ex1_blinky" --include_path="C:/ti/C2000Ware_26_01_00_00" --include_path="C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=DEBUG --define=_FLASH --define=generic_flash_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/Subham Mandal/workspace_ccstheia/led_ex1_blinky/CPU1_FLASH/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

f28002x_codestartbranch.obj: C:/ti/C2000Ware_26_01_00_00/device_support/f28002x/common/source/f28002x_codestartbranch.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --idiv_support=idiv0 --tmu_support=tmu0 -Ooff --include_path="C:/Users/Subham Mandal/workspace_ccstheia/led_ex1_blinky" --include_path="C:/ti/C2000Ware_26_01_00_00" --include_path="C:/ti/ccs2100/ccs/tools/compiler/ti-cgt-c2000_25.11.1.LTS/include" --define=DEBUG --define=_FLASH --define=generic_flash_lnk --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/Subham Mandal/workspace_ccstheia/led_ex1_blinky/CPU1_FLASH/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



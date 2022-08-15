
echo = C:\msys64\usr\bin\echo.exe


Compiler = ../ti-cgt-c2000_21.6.0.LTS

Source = ${SOURCEPATH}/*.c
CMD = ${SOURCEPATH}/Cmd/*.cmd

TargetPath = ../../Target/bin
ObjPath = ../../Target/obj

ORDERED_OBJS += \
"$(ObjPath)/*.obj" \
"$(CMD)" \
-llibc.a \

all: OBJS_C OBJS_ASM
	@$(MAKE) "Blinkersteuerung.out"
	
OBJS_C:
	@$(echo) 'Compiling C- Files'
	@$(echo) 'Invoking: C2000 Compiler'
	"$(Compiler)/bin/cl2000" -v28 -ml -mt \
	--include_path="$(Compiler)/include" \
	--include_path="${SOURCEPATH}/DeviceHeader/" \
	--obj_directory=$(ObjPath) \
	-g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi \
	"${SOURCEPATH}/*.c"
	@$(echo) 'Finished building C-Files'
	@$(echo) ' '
	
OBJS_ASM:
	@$(echo) 'Compiling Asm- Files'
	@$(echo) 'Invoking: C2000 Compiler'
	"$(Compiler)/bin/cl2000" -v28 -ml -mt \
	--include_path="$(Compiler)/include" \
	--include_path="${SOURCEPATH}/DeviceHeader/" \
	--obj_directory=$(ObjPath) \
	-g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi \
	$(GEN_OPTS__FLAG) "${SOURCEPATH}/*.asm"
	@$(echo) 'Finished building Asm-Files'
	@$(echo) ' '


Blinkersteuerung.out:
	@$(echo) 'Invoking: C2000 Linker'
	"$(Compiler)/bin/cl2000" -v28 -ml -mt -g --diag_warning=225 --diag_wrap=off \
	--display_error_number --abi=coffabi -z -m"$(TargetPath)/Blinkersteuerung.map" \
	--stack_size=0x300 --warn_sections -i"$(Compiler)/lib" \
	-i"$(Compiler)/include" --reread_libs \
	--diag_wrap=off --display_error_number \
	--xml_link_info="$(TargetPath)/Blinkersteuerung_linkInfo.xml" \
	--rom_model -o "$(TargetPath)/Blinkersteuerung.out" $(ORDERED_OBJS)
	@$(echo) 'Finished building target: "$@"'
	@$(echo) ' '


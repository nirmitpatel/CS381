################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_SRCS += \
../asf/material/programs/Example_FresnelPS.asm \
../asf/material/programs/OffsetMapping_specular.asm 

OBJS += \
./asf/material/programs/Example_FresnelPS.o \
./asf/material/programs/OffsetMapping_specular.o 


# Each subdirectory must supply rules for building sources it contributes
asf/material/programs/%.o: ../asf/material/programs/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



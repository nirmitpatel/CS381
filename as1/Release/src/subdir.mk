################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BaseApplication.cpp \
../src/as1.cpp 

OBJS += \
./src/BaseApplication.o \
./src/as1.o 

CPP_DEPS += \
./src/BaseApplication.d \
./src/as1.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/misc/staff2/sushil/workspace/as1/inc" -I/usr/local/include/OGRE/Overlay -I/usr/include/OIS -I/usr/local/include -I/usr/local/include/OGRE -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



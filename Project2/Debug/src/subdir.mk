################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/As2.cpp \
../src/BaseApplication.cpp \
../src/Entity381.cpp \
../src/EntityMgr.cpp 

OBJS += \
./src/As2.o \
./src/BaseApplication.o \
./src/Entity381.o \
./src/EntityMgr.o 

CPP_DEPS += \
./src/As2.d \
./src/BaseApplication.d \
./src/Entity381.d \
./src/EntityMgr.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/nirmitp/workspace/Project2/inc" -I/usr/local/include/OGRE -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



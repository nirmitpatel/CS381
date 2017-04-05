################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/Aspect.cpp \
../Src/Command.cpp \
../Src/Entity381.cpp \
../Src/EntityMgr.cpp \
../Src/GfxMgr.cpp \
../Src/UnitAI.cpp \
../Src/as3.cpp \
../Src/engine.cpp \
../Src/gameMgr.cpp \
../Src/inputMgr.cpp \
../Src/mgr.cpp 

OBJS += \
./Src/Aspect.o \
./Src/Command.o \
./Src/Entity381.o \
./Src/EntityMgr.o \
./Src/GfxMgr.o \
./Src/UnitAI.o \
./Src/as3.o \
./Src/engine.o \
./Src/gameMgr.o \
./Src/inputMgr.o \
./Src/mgr.o 

CPP_DEPS += \
./Src/Aspect.d \
./Src/Command.d \
./Src/Entity381.d \
./Src/EntityMgr.d \
./Src/GfxMgr.d \
./Src/UnitAI.d \
./Src/as3.d \
./Src/engine.d \
./Src/gameMgr.d \
./Src/inputMgr.d \
./Src/mgr.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/nirmitp/workspace/Assignment 4/Inc" -I/usr/local/include/OGRE/Overlay -I/usr/include/OIS -I/usr/local/include/OGRE -O0 -g3 -Wall -c -fmessage-length=0 -std=gnu++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



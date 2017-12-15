################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/convert_root.cpp \
../src/mini_tools.cpp \
../src/mpf.cpp \
../src/tree.cpp 

OBJS += \
./src/convert_root.o \
./src/mini_tools.o \
./src/mpf.o \
./src/tree.o 

CPP_DEPS += \
./src/convert_root.d \
./src/mini_tools.d \
./src/mpf.d \
./src/tree.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++  $(shell root-config --glibs --cflags) -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



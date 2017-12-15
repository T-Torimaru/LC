################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/PedestalCalibrator.cpp \
../src/PedestalSpectrum.cpp \
../src/pedestal_memcell.cpp \
../src/style.cpp 

OBJS += \
./src/PedestalCalibrator.o \
./src/PedestalSpectrum.o \
./src/pedestal_memcell.o \
./src/style.o 

CPP_DEPS += \
./src/PedestalCalibrator.d \
./src/PedestalSpectrum.d \
./src/pedestal_memcell.d \
./src/style.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++  $(shell root-config --glibs --cflags) -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/pedestal_memcell.o: ../src/pedestal_memcell.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++   $(shell root-config --glibs --cflags)  -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/pedestal_memcell.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



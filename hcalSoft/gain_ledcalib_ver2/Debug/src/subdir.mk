################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CalibSpectrum.cpp \
../src/GainRunFolderParser.cpp \
../src/PedestalCalibrator.cpp \
../src/UHHExtractGain.cpp \
../src/gain_ledcalib.cpp \
../src/mpf.cpp \
../src/onepf.cpp \
../src/style.cpp 

OBJS += \
./src/CalibSpectrum.o \
./src/GainRunFolderParser.o \
./src/PedestalCalibrator.o \
./src/UHHExtractGain.o \
./src/gain_ledcalib.o \
./src/mpf.o \
./src/onepf.o \
./src/style.o

CPP_DEPS += \
./src/CalibSpectrum.d \
./src/GainRunFolderParser.d \
./src/PedestalCalibrator.d \
./src/UHHExtractGain.d \
./src/gain_ledcalib.d \
./src/mpf.d \
./src/onepf.d \
./src/style.d 



# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I$(shell root-config --incdir)  -I/opt/root/include -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/gain_ledcalib.o: ../src/gain_ledcalib.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I$(shell root-config --incdir)  -I/opt/root/include -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/gain_ledcalib.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

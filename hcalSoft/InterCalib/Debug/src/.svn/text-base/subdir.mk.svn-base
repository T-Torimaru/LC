################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RunFolderParser.cpp \
../src/PedestalCalibrator.cpp \
../src/HistoGenerator.cpp \
../src/InterCalib.cpp \
../src/style.cpp 

OBJS += \
./src/RunFolderParser.o \
./src/PedestalCalibrator.o \
./src/HistoGenerator.o \
./src/InterCalib.o \
./src/style.o 

CPP_DEPS += \
./src/RunFolderParser.d \
./src/PedestalCalibrator.d \
./src/HistoGenerator.d \
./src/InterCalib.d \
./src/style.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++  -I$(shell root-config --incdir)  -I/opt/root/include -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/InterCalib.o: ../src/InterCalib.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++  -I$(shell root-config --incdir)  -I/opt/root/include -O3 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/InterCalib.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



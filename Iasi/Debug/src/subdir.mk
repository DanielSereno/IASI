################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Casilla.cpp \
../src/Iasi.cpp \
../src/Laberinto.cpp \
../src/timer.cpp 

OBJS += \
./src/Casilla.o \
./src/Iasi.o \
./src/Laberinto.o \
./src/timer.o 

CPP_DEPS += \
./src/Casilla.d \
./src/Iasi.d \
./src/Laberinto.d \
./src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Bloco.cpp \
../src/GerenciadorDeMemoria.cpp \
../src/Parser.cpp \
../src/Processo.cpp \
../src/Relogio.cpp \
../src/main.cpp 

OBJS += \
./src/Bloco.o \
./src/GerenciadorDeMemoria.o \
./src/Parser.o \
./src/Processo.o \
./src/Relogio.o \
./src/main.o 

CPP_DEPS += \
./src/Bloco.d \
./src/GerenciadorDeMemoria.d \
./src/Parser.d \
./src/Processo.d \
./src/Relogio.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -w -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



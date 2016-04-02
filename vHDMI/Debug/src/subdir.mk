################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/asteroids.c \
../src/cf_hdmi.c \
../src/main.c \
../src/transmitter.c 

OBJS += \
./src/asteroids.o \
./src/cf_hdmi.o \
./src/main.o \
./src/transmitter.o 

C_DEPS += \
./src/asteroids.d \
./src/cf_hdmi.d \
./src/main.d \
./src/transmitter.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM gcc compiler'
	arm-xilinx-eabi-gcc -Wall -O0 -g3 -I"C:\Users\Chris\hdmi_workspace\vHDMI\inc" -c -fmessage-length=0 -MT"$@" -I../../standalone_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/BatteryController.c \
../Sources/CameraController.c \
../Sources/Error_management.c \
../Sources/Events.c \
../Sources/ImageProcessing.c \
../Sources/MotorController.c \
../Sources/PID.c \
../Sources/SerialCommunication.c \
../Sources/ServoController.c \
../Sources/SystemController.c \
../Sources/main.c 

OBJS += \
./Sources/BatteryController.o \
./Sources/CameraController.o \
./Sources/Error_management.o \
./Sources/Events.o \
./Sources/ImageProcessing.o \
./Sources/MotorController.o \
./Sources/PID.o \
./Sources/SerialCommunication.o \
./Sources/ServoController.o \
./Sources/SystemController.o \
./Sources/main.o 

C_DEPS += \
./Sources/BatteryController.d \
./Sources/CameraController.d \
./Sources/Error_management.d \
./Sources/Events.d \
./Sources/ImageProcessing.d \
./Sources/MotorController.d \
./Sources/PID.d \
./Sources/SerialCommunication.d \
./Sources/ServoController.d \
./Sources/SystemController.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/guilherme/Documents/SDP/SDP-2016/Static_Code/PDD" -I"/home/guilherme/Documents/SDP/SDP-2016/Static_Code/IO_Map" -I"/home/guilherme/Documents/SDP/SDP-2016/Sources" -I"/home/guilherme/Documents/SDP/SDP-2016/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Error_management.c \
../Sources/Events.c \
../Sources/SystemController.c \
../Sources/battery_lib.c \
../Sources/camera_lib.c \
../Sources/dc_motor_lib.c \
../Sources/image_processing_lib.c \
../Sources/main.c \
../Sources/pid.c \
../Sources/serial_communication_lib.c \
../Sources/servo_lib.c 

OBJS += \
./Sources/Error_management.o \
./Sources/Events.o \
./Sources/SystemController.o \
./Sources/battery_lib.o \
./Sources/camera_lib.o \
./Sources/dc_motor_lib.o \
./Sources/image_processing_lib.o \
./Sources/main.o \
./Sources/pid.o \
./Sources/serial_communication_lib.o \
./Sources/servo_lib.o 

C_DEPS += \
./Sources/Error_management.d \
./Sources/Events.d \
./Sources/SystemController.d \
./Sources/battery_lib.d \
./Sources/camera_lib.d \
./Sources/dc_motor_lib.d \
./Sources/image_processing_lib.d \
./Sources/main.d \
./Sources/pid.d \
./Sources/serial_communication_lib.d \
./Sources/servo_lib.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/guilherme/Documents/SDP/SDP-2016/Static_Code/PDD" -I"/home/guilherme/Documents/SDP/SDP-2016/Static_Code/IO_Map" -I"/home/guilherme/Documents/SDP/SDP-2016/Sources" -I"/home/guilherme/Documents/SDP/SDP-2016/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



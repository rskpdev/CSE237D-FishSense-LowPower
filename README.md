# CSE237D-FishSense-LowPower
FishSense low power mode project web presence for CSE237D
project wiki: https://github.com/rskpdev/CSE237D-FishSense-LowPower/wiki

## Project Overview
The FishSense capsule is an underwater fish activity recording module, implemented with an external low-power system using the NVidia Jetson TX2 and the STM32 board. FishSense was built to automatically detect and estimate the biomass of fish, using both RGB and depth cameras with a YOLO-v5 machine learning algorithm to record fish. This was done to preserve ecosystems and hault unhealthy catch/release methods. The Low-power mode involves an interfacing between the STM and Nvidia to create a clock timer, according to functions written in the HAL documentation, which activates and deactivates clocks according to a defined duration.

## Project Team-Members
Rahul Polisetti
Mohana Seelan
Kyle Yang

## How to Replicate the Project
Low-power system
1. Tx2 sends sleep signal to STM32
2. STM32 turns of entire system
3. STM32 wakes up entire system after set amount of time
4. Tx2 records for certain time and sends sleep signal to STM32 again

### TX2 Firmware

The Tx2 firmware is rewritten in the Nvidia Jetson program using an Ubuntu operating system, and is physically attached to an Orbitty carrier board. This configuration is used inside the module to establish the sleep timer function. 

The modified firmware communicates with the STM board via a GPIO program. The functions are primarily taken from the HAL and low-lever drivers users Manual, cited in the references. Ctime is used to time how long recording should be on, then the GPIO is sent out to the STM. The STM receives the GPIO signal from the TX2, then sends the signal out to the carrier, which is a power IO board provided by the staff. The power IO board is then turned off by the TX2.

### STM32 Firmware + Carrier Board
The STM is a 30mA powered board with a power-draw capacity sufficiently low enough to last for a two week duration in the FishSense. The board uses pin PD9 to connect with an external power-source and connects with an engineered carrier board, shown by this image:

main.c includes user-defined functions written from the commands included in Hal. Line 144 includes command RCC_OscInitStruct.PLL.PLLN = 70 which includes pin #70 to initialize the timer through the STM. 

The pins that were modified include those labelled under ASG003 and part name Orbitty, under files gpio_pq4_pi4, can_gpio2_paa2, gpio_mdm7_py6, and gpio_mdm1_py0 with are connected with pins H13, G14, A22, and A23, respectively. The voltage level is 3.3 with each pin and the header-pin number is P4-7, P4-8, P4-9, and P4-10 for each pin. The identical voltage amount indicate the pins are used for similar functions, and all interrelate in the timer implementation. 

The pins are all used as general purpose inputs/outputs to connect the STM with the Tx2 in order to implement timers that would control the recording of the RealSense. Once the user embeds functions into the STM IDE, the functions will be able to be implemented through the control functions of the orbitty. THE STM32CubeIDE is the interface which programs the board, appearing as such:

<img width="941" alt="ui" src="https://user-images.githubusercontent.com/89044922/172065193-1b86f4bb-f8b0-434a-b26e-b4110fa0a410.png">

Once the user embeds functions into the STM IDE, the ide can communicate with the Nvidia Jetson via a power I/O board used as carrier for the STM32. The only pin on the STM required for the low-power mode is the PD9 pin located on the bottom right hand side of the STM. The carrier board is engineered apart from the embedded systems to use as an external triggering mechanism, appearing as such:

![carrier board](https://user-images.githubusercontent.com/89044922/172065489-e6f3a171-dc7d-4608-b327-f5b894a4790f.png)


## Documentation
[STM32G0 HAL Layer documentation](https://drive.google.com/file/d/1hcKkOyquUUFsUSfPGr3paL8llkbvs7I4/view?usp=sharing)

[STM32G0 MCU Reference Manual](https://drive.google.com/file/d/1D-xi0UJZoFb36BAIgmKhAljadXhTq_ri/view?usp=sharing)





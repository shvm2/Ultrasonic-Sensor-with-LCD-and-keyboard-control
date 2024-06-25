# Embedded Systems Project: Ultrasonic Sensor with Stepper Motor

This project is an embedded systems application using the LPC1768 microcontroller, coded in Keil. It features an HC-SR04 ultrasonic sensor mounted on a stepper motor. The system is controlled via a keyboard button on the LPC board, and it continuously measures and displays the distance to the nearest obstacle on an LCD.

## Table of Contents
- [Overview](#overview)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Project Setup](#project-setup)
- [Usage](#usage)
- [License](#license)

## Overview
This project demonstrates the use of the LPC1768 microcontroller to interface with an HC-SR04 ultrasonic sensor and a stepper motor. The ultrasonic sensor rotates on the stepper motor and measures the distance to the nearest obstacle, displaying the readings on an LCD screen. The rotation of the stepper motor is controlled via a keyboard button on the LPC board.

## Hardware Requirements
- LPC1768 microcontroller
- HC-SR04 ultrasonic sensor
- Stepper motor
- LCD display
- Keyboard (for LPC board)
- Connecting wires
- Breadboard (optional)

## Software Requirements
- Keil uVision IDE
- LPC17xx CMSIS libraries

## Project Setup
1. **Connect the hardware components:**
   - Interface the HC-SR04 ultrasonic sensor with the LPC1768.
   - Connect the stepper motor to the LPC1768.
   - Connect the LCD display to the LPC1768.
   - Connect the keyboard to the LPC board.

2. **Clone this repository:**
   ```sh
   git clone https://github.com/your-username/embedded-systems-ultrasonic-sensor.git
   cd embedded-systems-ultrasonic-sensor
3. **Open the project in Keil uVision:**
   - Load the provided project files into Keil uVision.
   - Compile and build the project.

4. **Flash the compiled code onto the LPC1768 microcontroller:**
   - Connect the LPC1768 to your computer via USB.
   - Use Keil uVision to flash the code onto the microcontroller.

## Usage

    Power on the system:
        Ensure all connections are secure and power on the LPC1768 microcontroller.

    Start the measurement:
        The ultrasonic sensor will start rotating on the stepper motor.
        Press and hold the keyboard button to control the rotation direction.

    View the distance:
        The measured distance to the nearest obstacle will be displayed on the LCD.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

Feel free to contribute to this project by submitting issues or pull requests. For any questions or support, please contact [ucannotdefeattesla@gmail.com](mailto:ucannotdefeattesla@gmail.com).


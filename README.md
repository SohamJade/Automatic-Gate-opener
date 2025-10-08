# Automatic Gate Opener using Arduino

This project demonstrates how to build a model automatic gate or parking barrier using an Arduino. An ultrasonic sensor detects an approaching object (like a toy car), and a servo motor lifts the gate arm to grant access.



## 🚧 Features

-   **Automatic Gate Operation**: The gate arm lifts automatically when an object is detected in front of it.
-   **Contactless Activation**: Provides convenient, automated access without any physical contact.
-   **Adjustable**: The detection distance and gate open/close angles can be easily modified in the code.
-   **Great Prototype**: Serves as an excellent model for real-world systems like parking barriers, toll booths, or railway crossings.

***

## ⚙️ Components Required

| Component                   | Quantity |
| --------------------------- | :------: |
| Arduino Uno (or similar)    |    1     |
| HC-SR04 Ultrasonic Sensor |    1     |
| SG90 Servo Motor            |    1     |
| Jumper Wires                |  Several |
| Materials for gate/base     |    1     |
| Power Supply (USB/Adapter)  |    1     |

***

## 🔌 Wiring Diagram

Connect the components to the Arduino. The wiring is the same for a gate as it is for any other servo/sensor project.

### Servo Motor (SG90)
| Servo Pin | Arduino Pin |
| :-------: | :---------: |
|   Signal (Orange)  |    **Pin 13** |
|     VCC (Red)    |     **5V** |
|    GND (Brown)   |     **GND** |

### Ultrasonic Sensor (HC-SR04)
| Sensor Pin | Arduino Pin |
| :--------: | :---------: |
|    Trig    |    **Pin 11** |
|    Echo    |    **Pin 12** |
|     VCC    |     **5V** |
|     GND    |     **GND** |

***

## 🚀 How It Works

1.  **Initialization**: When the Arduino is powered on, the servo motor moves to the 'closed' position (**180 degrees**), keeping the gate down.
2.  **Sensing**: The ultrasonic sensor continuously sends out sound pulses to scan the area in front of the gate.
3.  **Distance Calculation**: The code measures the time it takes for a pulse to echo back and calculates the distance of the nearest object.
4.  **Detection**: The system checks if the calculated distance is less than or equal to a predefined threshold (in this code, it's **10 cm**).
5.  **Action**:
    * If an object is detected within the threshold, the Arduino commands the servo to rotate to **90 degrees**, lifting the gate arm to the 'open' position.
    * If no object is detected, the servo returns to **180 degrees**, closing the gate.

***

## 🛠️ Setup and Installation

1.  **Hardware Assembly**:
    * Connect all the electronics according to the wiring diagram.
    * Build a small base and mount the servo motor vertically.
    * Attach a lightweight arm (like a popsicle stick or a piece of cardboard) to the servo horn. This will be your gate.
    * Position the ultrasonic sensor so it faces the direction of an approaching object.

2.  **Software Setup**:
    * Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
    * The `Servo.h` library is included with the standard Arduino IDE, so no extra installation is needed.
    * Open the `.ino` file from this repository in the Arduino IDE.

3.  **Upload the Code**:
    * Connect your Arduino board to your computer.
    * In the IDE, go to `Tools > Board` and select your Arduino board (e.g., "Arduino Uno").
    * Go to `Tools > Port` and select the correct port.
    * Click the **Upload** button to send the code to your Arduino.

***

## 🔧 Customization

You can easily modify the code to change the gate's behavior:

-   **Detection Distance**: Change the value `10` in the `if` statement to make the gate open sooner or later.
    ```cpp
    if (distance <= 10) { // Adjust this distance threshold
    ```

-   **Gate Open/Close Angles**: If your gate needs to open to a different angle, change the `servo.write()` values.
    ```cpp
    // Gate open position
    servo.write(90);

    // Gate closed position
    servo.write(180);
    ```

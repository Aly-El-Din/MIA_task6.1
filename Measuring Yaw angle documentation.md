# Measuring Yaw angle

Created by: Aly El Din Mohamed
Created time: September 8, 2023 6:58 PM

# A brief about MPU6050 sensor

---

This sensor is the world’s first integrated 6-axis motion tracking device that combines a 3-axis gyroscope, 3-axis accelerometer, where the gyroscope is responsible for measuring the rotation angle of a certain axis of the 3 axes, while the accelerometer is responsible for measuring the linear acceleration of the body moving in a certain direction.

# Task objective

---

We need to measure the Yaw angle (angle of rotation in z-axis direction) using the gyroscope

# Task approach

---

## 1.Library

---

We adopt I2C communication protocol in communication of the Arduino and the sensor, so we have included **“Wire.h”** library which provides us with different utilize functions.

## 2.Global variabes

---

We have defined also the needed variables which are **GYRO_Z, gyro_error_z, elapsed_time,current_time,previous_time,Yaw**

## 3.Setup block

---

*According to the MPU 6050 Register Map, the PWR_MGMT_1 register allows us to configure the power mode of the MPU.*

*Looking at the register map page 40, PWR_MGMT_1 is located at 0x6B (107 in decimal, 01101011 in binary)*

*Think of each register in the MPU of having 8 bits that can be changed to change the settings.*

*the 8 bits we will send to the MPU are all 0, so we can send any value of zero we want - hex 0x00, decimal= 0*

*This will power on the device and specify the initial power settings.*

*First, we tell the MPU which register we are writing to using the line:*

```c
**Wire.write(0x6B);**
```

*Second, we send the values that we discussed previously*

```c
**Wire.write(0x00);**
```

Talking to the gyroscope needs these lines of code, where we determine the gyroscope senstivity also:

```c
 	**Wire.beginTransmission(MPU);
  Wire.write(0x1B);
  Wire.write(0x18);**
```

Computing error in measurment, we call function **calculate_IMU_error()**

## 4.Loop block

---

We compute time using the function **millis() which returns the time elapsed since we start the program.**

Requests the gyroscope data from the MPU6050 by writing to the appropriate register and reading the values.

Calculating Yaw angle using the defined formulas.
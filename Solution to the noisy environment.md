# Solution to the noisy environment

Created by: Aly El Din Mohamed

# Type of filter recommended to be used

---

I recommend using low pass filter to attenuate the high-frequency components of the signal and passes the low-frequency ones

# Demonstration for the cutoff frequency

---

First, the cutoff frequency is the frequency at which the low pass filter start to attenuate the signal, indeed it’s the frequency at which any frequency higher than it is attenuated or completely eliminated..

we could calculate it using the formula 

cutoff frequency = 1 / (2 * π * R * C)

Where R is the resistance and C is the capacitance of the low pass filter.

For example, if we want to set the cutoff frequency to 1000 Hz and we have a 10 nF capacitor, we can calculate the resistance needed using the formula:

R = 1 / (2 * π * 1000 Hz * 10 nF) = 1.59 kΩ

So, we can use a 1.59 kΩ resistor and a 10 nF capacitor to create a low pass filter with a cutoff frequency of 1000 Hz.

But using the data sheet of the MPU6050 sensor we could say that our cut off frequency equals 5 Hz, so we can calculate the needed values for the resistor and capacitor using the same formula and this value of cutoff frequency but it varies according to DLPF_CFG where the sensor is filtered.

I see that this frequency is appropiat because it does not pass the signals of high frequencies so we guarantee that we have less noise.
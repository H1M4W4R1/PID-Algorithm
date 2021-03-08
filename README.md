# PID-Algorithm
PID Algorithm implementation in C++ (to be used with MCU's). Not tested yet - use at own risk.

# How to use?
```cpp
// Define PID with p, i, d constants in bracket (same order). Constants are multiplied by 0.01f inside algorithm.
PID pid1(90, 30, 80);

// Set target PID value (eg. temperature)
pid1.set(<value>);

// Calculate PID PWM value. Based on provided max PWM value.
pid1.calculatePWM(<current_value>, <time_elapsed_since_last_call_to_calculate_PWM_in_ms>);

// Time elapsed is not implemented in PID class because it is intended to be supported by various MCUs like ATMega, STM32 or RP2040.

// Set offset for error function. Default value: 3 - used to compensate error function in several cases.
setErrorOffset(<offset>);


// Set PWM max value. Default: 256. Use value that is used for running PWM with 100% fill. (Or 0% fill if you are using #PWM (active low)).
setPwmMaxValue(<value>);



```

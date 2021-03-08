//
// Created by nov11 on 3/8/2021.
//

#ifndef PID_H
#define PID_H

#include <cinttypes>


class PID {
private:
    // PID constants
    uint32_t k_p = 90;
    uint32_t k_i = 30;
    uint32_t k_d = 80;
    uint32_t errOffset = 3;

    // Algorithm settings
    int32_t targetValue = 50;
    int32_t pwmMaxValue = 256;

    // Internal variablesy
    int32_t pid_i;
    int32_t last_error;

public:
    // Set PID target value
    PID* set(int32_t value);

    // Set max PWM value based by your MCU
    PID* setPwmMaxValue(int32_t value);

    // Set error offset for your load (default: 3 for heater in mini-oven)
    PID* setErrorOffset(uint32_t offset);

    // Calculate your PID value by read and time delay
    uint32_t calculatePWM(int32_t readValue, int32_t deltaTime_ms);

    // Create virtual PID controller
    PID(uint32_t kp, uint32_t ki, uint32_t kd);
};


#endif //PID_H

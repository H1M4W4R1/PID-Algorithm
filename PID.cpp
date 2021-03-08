//
// Created by nov11 on 3/8/2021.
//

#include "PID.h"

PID* PID::set(int32_t value) {
    targetValue = value;
    return this;
}

PID *PID::setPwmMaxValue(int32_t value) {
    pwmMaxValue = value;
    return this;
}

uint32_t PID::calculatePWM(int32_t readValue, int32_t deltaTime_ms) {
    // Calculate value
    uint32_t error = targetValue - readValue + errOffset;

    // Calculate PID value
    uint32_t pid_p = 0.01f * k_p * error; // P
    pid_i = 0.01f * pid_i + (k_i * error); // I
    uint32_t pid_d = 0.01f * k_d * (((float)error - (float)last_error)/((float)deltaTime_ms/1000.0f)); // D
    uint32_t pid_value = pid_p + pid_i + pid_d; // PID value

    // Limit PID values
    if(pid_value < 0) pid_value = 0;
    if(pid_value > pwmMaxValue) pid_value = pwmMaxValue;

    // Recalculate error
    last_error = error;
    return pid_value;
}

PID::PID(uint32_t kp, uint32_t ki, uint32_t kd) {
    k_p = kp;
    k_d = kd;
    k_i = ki;
}

PID *PID::setErrorOffset(uint32_t offset) {
    errOffset = offset;
    return this;
}

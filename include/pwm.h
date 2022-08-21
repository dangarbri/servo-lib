/** MIT License
 * 
 * Copyright (c) 2022 Daniel Garcia-Briseno
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

#include "pico/stdlib.h"

/**
 * PWM interface.
 * Currently only runs with a PWM frequency of 50Hz
 * TODO: Add calculations to set frequency dynamically
 */
class PWMPin {
public:
    /**
     * Initializes PWM on a pin to the given frequency and enables it.
     * @note In the PWM hardware, each slice is tied to two pins
     *       and they must share a clock frequency. Make sure
     *       to account for this in your design
     *
     * @param[in] pin GPIO pin number
     */
    PWMPin(uint pin);

    /**
     * Free's impl pointer
     * @private
     */
    ~PWMPin();

    /**
     * Sets the duty cycle to the given percentage
     * Cycle will be high for the given percentage
     * @param[in] percentage % of time to stay high
     */
    void SetDutyCycle(float percentage);

    /**
     * Sets the number of ticks for PWM to stay high
     * The PWM counter wraps at uint16_t max (65535)
     * @note May be used instead of SetDutyCycle.
     * @param[in] ticks Number of ticks to stay high
     */
    void SetHighTicks(uint16_t ticks);

    /**
     * Enable PWM hardware
     */
    void Enable();

    /**
     * Disable PWM hardware
     */
    void Disable();
private:
    struct impl;
    impl* _impl;
};

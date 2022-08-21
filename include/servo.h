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

#include "pwm.h"

/**
 * Basic servo driver. Drives a servo by using the
 * built-in PWM controller to send a pulse every
 * 50Hz.
 *
 * This implementation is based on the servo description
 * of this wikipedia article: https://en.wikipedia.org/wiki/Servo_control
 * Key points:
 *   - Uses a clock divider to get the PWM counter to wrap 50 times a second (50Hz)
 *   - PWM counter is 65535.
 *   - Experimentally I found 1400 ticks to be 0 turn and 8000 to be 100% (180degree) turn on the servo
 *   - If these tick values don't work for you'll have to experiment on your own.
 *
 */
class Servo {
public:
    /**
     * Initializes the servo on the given control pin
     * @param[in] pin Servo control pin
     */
    Servo(uint pin);

    /**
     * Sets the rotation of the servo in terms of % turned
     * Limited to 180 degrees. If you specify a value greater than 180
     * then this will only turn to 180 degrees
     * @param[in] degrees Target rotation
     */
    void SetRotation(uint degrees);

private:
    /**
     * Current pin selected for this servo
     */
    PWMPin _pin;
};


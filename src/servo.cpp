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

#include "servo.h"
#include "pwm.h"

#ifdef DEBUG_SERVO
    #include <stdio.h>
#endif

/**
 * Servo minimum ticks rotate fully clockwise is about 1400 ticks
 * Determined experimentally with an SG92R Micro Servo from Adafruit
 */
#define SERVO_START_TICKS 1400

/**
 * At 8000 ticks the servo is fully counter clockwise
 * Determined experimentally with an SG92R Micro Servo from Adafruit
 */
#define SERVO_END_TICKS 8000

/**
 * Number of ticks to go from start to end
 */
#define SERVO_TICK_DELTA (SERVO_END_TICKS - SERVO_START_TICKS)

/**
 * Number of degrees that make up a half turn
 */
#define HALF_TURN_DEGREES 180

Servo::Servo(uint pin) : _pin (pin) {
}

static uint16_t degrees_to_ticks(uint degrees) {
    // Limit to 180 degrees since my servos only turn 180 degrees
    if (degrees > HALF_TURN_DEGREES) {
        degrees = HALF_TURN_DEGREES;
    }

    float percent = (float) degrees / HALF_TURN_DEGREES;
    uint16_t ticks = (uint16_t) (SERVO_TICK_DELTA * percent);
    return SERVO_START_TICKS + ticks;
}

void Servo::SetRotation(uint degrees) {
#ifdef DEBUG_SERVO
    printf("Setting servo to %d degrees\n", degrees);
#endif
    _pin.SetHighTicks(degrees_to_ticks(degrees));
}


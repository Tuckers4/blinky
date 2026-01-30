/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     200ms


void blink_5(DigitalOut led1, DigitalOut led2, DigitalOut led3) {
    for (int counter = 0; counter < 5; counter++) {
        led1 = 1;
        led2 = 1;
        led3 = 1;
        ThisThread::sleep_for(BLINKING_RATE);
        led1 = 0;
        led2 = 0;
        led3 = 0;
        ThisThread::sleep_for(BLINKING_RATE);
    }
    led2 = 0;
    led3 = 0;
    led1 = 1;
}

int main() {
    // Initialise the appropriate digital pins as outputs
#if defined(LED1) && defined(LED2) && defined(LED3)
    DigitalOut led1(LED1);
    DigitalOut led2(LED2);
    DigitalOut led3(LED3);
#else
    bool led1;
    bool led2;
    bool led3;
#endif

    blink_5(led1, led2, led3);
}

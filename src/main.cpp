/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Blinking rate in milliseconds
#define BLINKING_RATE     200ms


void ping_pong(DigitalOut led1, DigitalOut led2, DigitalOut led3) {
    led1 = 1;
    ThisThread::sleep_for(BLINKING_RATE);
    led1 = 0;
    ThisThread::sleep_for(BLINKING_RATE);
    led2 = 1;
    ThisThread::sleep_for(BLINKING_RATE);
    led2 = 0;
    ThisThread::sleep_for(BLINKING_RATE);
    led3 = 1;
    ThisThread::sleep_for(BLINKING_RATE);
    led3 = 0;
    ThisThread::sleep_for(BLINKING_RATE);
    led2 = 1;
    ThisThread::sleep_for(BLINKING_RATE);
    led2 = 0;
    ThisThread::sleep_for(BLINKING_RATE);
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

    while (true) {
        ping_pong(led1, led2, led3);
    }
}

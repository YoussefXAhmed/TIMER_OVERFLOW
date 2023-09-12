/*
 *      temperature_monitor.h
 *      Author: YOUSSEF AHMED
 */

#ifndef TEMPERATURE_MONITOR_H
#define TEMPERATURE_MONITOR_H

#include "STD_TYPES.h"

// Constants and macro definitions
#define CRITICAL_TEMPERATURE_LIMIT 60
#define LAMP_PIN 4



// #define ISR(vector, ...)            \
//     void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
//     void vector (void)
// #  define __INTR_ATTRS used, externally_visible


// Function prototypes
void TIMER0_OVF_vect(void);

u16 ADC_u16ReadChannelSyn(u8 Copy_u8Channel);
u16 ADC_u16ToTemperature(u16 sensorValue);

#endif /* TEMPERATURE_MONITOR_H */

#include "dio.h"
#include "BIT_MATHS.h"
#include "temperature_monitor.h"
#include <util/delay.h>
#include "STD_TYPES.h"
#include "Timer_private.h"
#include "avr/io.h"

#define F_CPU 8000000UL

u16 CHECK_Temperature = 70;

ISR(TIMER0_OVF_vect)
{
    // READ TEMPERATURE FROM THE SENSOR
    CHECK_Temperature = 70;

    // CHECK IF TEMPERATURE EXCEEDS THE CRITICAL LIMIT
    if (CHECK_Temperature > CRITICAL_TEMPERATURE_LIMIT)
    {
        // TURN ON THE LAMP (SET THE GPIO PIN HIGH)
        PORTD |= (1 << LAMP_PIN);

        // LOOP TO HALT THE SYSTEM PERMANENTLY
        while (1) {}
    }
    else
    {
        // TURN OFF THE LAMP (SET THE GPIO PIN HIGH)
        PORTD |= ~(1 << LAMP_PIN);
    }
    // DELAY OR PERFORM OTHER TASKS AS NEEDED
    _delay_ms(1000);
}

int main(void)
{
    // CONFIGURE PD4 AS AN OUTPUT PIN TO CONTROL THE LAMP
    DDRD |= (1 << LAMP_PIN);
    // CONFIGURE PORT B AS AN OUTPUT
    DDRB = 0xFF;
    // CONFIGURE TIMER0
    TCCR0 |= (1 << TCCR0_CS02); // SET THE PRESCALER TO 256 (FOR TIMER0)
    TIMSK |= (1 << TIMSK_TOIE0); // ENABLE THE TIMER0 OVERFLOW INTERRUPT

    sei(); // ENABLE GLOBAL INTERRUPTS

    while (1)
    {
        // YOUR MAIN CODE HERE
    }

    return 0;
}

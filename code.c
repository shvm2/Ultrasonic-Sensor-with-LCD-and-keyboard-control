#include <lpc17xx.h>

unsigned int timeval = 0;
unsigned long result = 0;

void timer_init1() {
    LPC_TIM0->TCR = 0x02;
    LPC_TIM0->PR = 0x02;
    LPC_TIM0->MR0 = 49; // 10 microsec pulse
    LPC_TIM0->CTCR = 0x00;
    LPC_TIM0->EMR = 0x20;
    LPC_TIM0->MCR = 0x04;
    LPC_TIM0->TCR = 0x01;
}

void timer_init2() {
    LPC_TIM1->TCR = 0x02;
    LPC_TIM1->PR = 0x02;
    LPC_TIM1->MR0 = 0;
    LPC_TIM1->CTCR = 0x00;
    LPC_TIM1->EMR = 0x10;
    LPC_TIM1->MCR = 0x00;
    LPC_TIM1->TCR = 0x01;
}

int main() {
    SystemInit();
    SystemCoreClockUpdate();

    // Configure pins for trigger and echo
    LPC_PINCON->PINSEL0 &= ~(3 << 30); // P0.15 as GPIO for trigger
    LPC_PINCON->PINSEL1 &= ~(3 << 4);  // P0.16 as GPIO for echo
    LPC_GPIO0->FIODIR |= (1 << 15);    // P0.15 as output (trigger)
    LPC_GPIO0->FIODIR &= ~(1 << 16);   // P0.16 as input (echo)

    while (1) {
        // Send trigger pulse
        LPC_GPIO0->FIOSET = (1 << 15); // Set P0.15 high (trigger)
        timer_init1(); // Start timer for trigger pulse

        // Wait for echo pulse
        while (!(LPC_TIM0->EMR & (1 << 0))); // Wait until echo pulse is received

        LPC_TIM0->TCR = 0x02; // Stop timer

        LPC_GPIO0->FIOCLR = (1 << 15); // Clear trigger

        // Wait for echo response
        while (!(LPC_GPIO0->FIOPIN & (1 << 16))); // Wait until echo is high

        timer_init2(); // Start second timer for echo duration

        // Measure echo duration
        while (LPC_GPIO0->FIOPIN & (1 << 16)); // Wait until echo is low (end of pulse)

        LPC_TIM1->TCR = 0x00; // Stop timer

        timeval = LPC_TIM1->TC; // Get echo duration
        result = timeval / 58.82; // Convert to distance in cm (speed of sound is ~ 343 m/s)

        // Here you can use 'result' for further processing or display
    }

    return 0;
}

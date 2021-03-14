#include <Arduino.h>
#include <NewAttinyOneWire.h>

void NewAttinyOneWire::initOneWireUART()
{
    uint8_t oldSREG = SREG;
    cli();

    // RX Already set as INPUT_PULLUP, just set RX as OUTPUT again?
    if (PORTMUX.CTRLB & PORTMUX_USART0_bm == PORTMUX_USART0_DEFAULT_gc)
        pinMode(PIN_HWSERIAL0_RX, OUTPUT);
    else
        pinMode(PIN_HWSERIAL0_RX_PINSWAP_1, OUTPUT);

    // Set loop back mode on RXD and TXD
    USART0.CTRLA |= USART_LBME_bm;
    // Enable open drain
    USART0.CTRLB |= USART_ODME_bm;
    // Restore SREG content
    SREG = oldSREG;
}
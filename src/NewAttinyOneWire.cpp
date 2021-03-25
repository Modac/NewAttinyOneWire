#include <Arduino.h>
#include <NewAttinyOneWire.h>

void NewAttinyOneWire::initOneWireUART()
{
    uint8_t oldSREG = SREG;
    cli();

    // Reset pin modes to default state (INPUT)
    // TODO: Test for swapped pins and set right ones
    pinMode(PIN_HWSERIAL0_RX, INPUT);
    pinMode(PIN_HWSERIAL0_TX, INPUT);

    // Disable RX and TX for config change
    // TODO: Maybe put before pin mode
    USART0.CTRLB &= ~(USART_RXEN_bm | USART_TXEN_bm);

    // Enable internal pullup
    // TODO: change to pinMode call and consider swapp pins, probably move to other pin mode calls
    PORTB.PIN2CTRL = PORT_PULLUPEN_bm;

    // RX Already set as INPUT_PULLUP, just set RX as OUTPUT again?
    /*
    if (PORTMUX.CTRLB & PORTMUX_USART0_bm == PORTMUX_USART0_DEFAULT_gc)
        pinMode(PIN_HWSERIAL0_RX, OUTPUT);
    else
        pinMode(PIN_HWSERIAL0_RX_PINSWAP_1, OUTPUT);
*/
    
    // Set loop back mode on RXD and TXD
    USART0.CTRLA |= USART_LBME_bm;
    // Enable open drain and RX an TX again
    USART0.CTRLB |= USART_ODME_bm | USART_RXEN_bm | USART_TXEN_bm;

    // Restore SREG content
    SREG = oldSREG;
}

void NewAttinyOneWire::disableReceiver(void)
{
    USART0.CTRLB &= ~USART_RXEN_bm;
}

void NewAttinyOneWire::enableReceiver(void)
{
    Serial.flush();
    USART0.CTRLB |= USART_RXEN_bm;
}
#ifndef NewAttinyOneWire_h
#define NewAttinyOneWire_h

#if (__AVR_ARCH__ < 100)
  #error "This library is designed for 'modern AVR' parts only (post-2016, when they revised peripherals and instruction set timing)"
#endif

class NewAttinyOneWire {
    public:
        static void initOneWireUART();
        static void disableReceiver();
        static void enableReceiver();
};

#endif
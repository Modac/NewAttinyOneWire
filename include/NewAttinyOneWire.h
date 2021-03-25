#ifndef NewAttinyOneWire_h
#define NewAttinyOneWire_h

class NewAttinyOneWire {
    public:
        static void initOneWireUART();
        static void disableReceiver();
        static void enableReceiver();
};

#endif
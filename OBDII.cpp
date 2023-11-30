#include "globals.h"
#include "OBDII.h"

Timer CANTimer;

OBDII::OBDII(int canFrequency) {
    can.frequency(canFrequency);
}

unsigned char OBDII::request(unsigned char pid, bool serialEnabledFlag) {
    CANMessage canMessageTX;

    canMessageTX.id = PID_REQUEST;
    canMessageTX.data[0] = 0x02;
    canMessageTX.data[1] = 0x01;
    canMessageTX.data[2] = pid;
    canMessageTX.data[3] = 0;
    canMessageTX.data[4] = 0;
    canMessageTX.data[5] = 0;
    canMessageTX.data[6] = 0;
    canMessageTX.data[7] = 0;
    canMessageTX.len = 8;

    if (can.write(canMessageTX)) {
        if (serialEnabledFlag) {
            pc.printf("\n\rCAN TX Message - Transmitted\n\r");
        }

        return 1;
    } 
    else {
        return 0;
    }
}

float OBDII::read(unsigned char pid, bool serialEnabledFlag) {
    CANMessage canMessageRX;
    float engineData = -1;
    
    CANTimer.reset();
    CANTimer.start();

    while(CANTimer.read_us() < CAN_TIMEOUT) {
        if (can.read(canMessageRX)) {
            if (serialEnabledFlag) {
                pc.printf("\n\rCAN RX Message - Received\n\r");
                pc.printf("Message ID: %x\n\r", canMessageRX.id);
                pc.printf("Message Length: %x\n\r", canMessageRX.len);
                for (int i = 0; i < (int) canMessageRX.len; i++) {
                    pc.printf("Message Data [%d]: %x\n\r", i, canMessageRX.data[i]);
                }
            }

            if ((canMessageRX.id == PID_REPLY) && (canMessageRX.data[2] == pid)) {
                switch (canMessageRX.data[2]) {
                    case VEHICLE_SPEED:
                        engineData = canMessageRX.data[3]; // VEHICLE_SPEED [km/h] = A
                        break;

                    case ENGINE_SPEED:
                        engineData = (float) ((canMessageRX.data[3] * 256) + canMessageRX.data[4]) / 4; // ENGINE_RPM [rpm] = ((A * 256) + B) / 4
                        break;

                    case THROTTLE:
                        engineData = (float) (canMessageRX.data[3] * 100) / 255; // THROTTLE [%] = (A * 100) / 255
                        break;

                    case ENGINE_COOLANT_TEMP:       
                        engineData = canMessageRX.data[3] - 40; // ENGINE_COOLANT_TEMP [°C] = A - 40 
                        break;
                }
            }
            else {
                engineData = -1;
                can.reset();
            }
        }
    }

    return engineData;
}
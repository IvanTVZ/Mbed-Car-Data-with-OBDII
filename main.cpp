#include "mbed.h"
#include "globals.h"
#include "LCDMenu.h"
#include "OBDII.h"

// Initialize
OBDII obd (CAN_SPEED_500k);
LCDMenu lcdMenu;
Ticker getDataTicker;

// Data variables
float engineData = 0;
float vehicleSpeed = 0;
float engineSpeed = 0;
float engineTemperature = 0;

// Rotary encoder variables
int rotaryEncoderValue;
int rotaryEncoderCurrentValue;
int rotaryEncoderLastValue;

// Menu variables
bool mainMenuFlag = false;
bool dataMenuFlag = false;
bool settingsMenuFlag = false;

// Settings menu variables
bool canEnabledFlag = true;
bool canTestLedEnabledFlag = true;
bool serialEnabledFlag = true;

// Interrupt variables
bool getDataFlag = false;
bool rotaryEncoderRotatedFlag = false;
bool rotaryEncoderButtonFlag = false;

// LCD menu functions
void createMainMenu() {
    mainMenuFlag = true;
    dataMenuFlag = false;
    settingsMenuFlag = false;

    lcdMenu.createMainMenu(rotaryEncoderValue);
}

void createDataMenu() {
    mainMenuFlag = false;
    dataMenuFlag = true;
    settingsMenuFlag = false;

    lcdMenu.createDataMenu(vehicleSpeed, engineSpeed, engineTemperature);
}

void createSettingsMenu() {
    mainMenuFlag = false;
    dataMenuFlag = false;
    settingsMenuFlag = true;

    lcdMenu.createSettingsMenu(canEnabledFlag, canTestLedEnabledFlag, serialEnabledFlag, rotaryEncoderValue);
}

void createAboutMenu() {
    mainMenuFlag = false;
    dataMenuFlag = false;
    settingsMenuFlag = false;

    lcdMenu.createAboutMenu();
}

// Ticker interrupt functions
void getData() {
    getDataFlag = true;
}

void getDataCallback() {
    getDataFlag = false;

    if (canEnabledFlag) {
        if (canTestLedEnabledFlag) {
            led1 = !led1;
        }

        if (obd.request(ENGINE_SPEED, serialEnabledFlag) == 1) {
            engineData = obd.read(ENGINE_SPEED, serialEnabledFlag);
            if (engineData != -1) {
                engineSpeed = engineData;
            }
        }

        if (obd.request(VEHICLE_SPEED, serialEnabledFlag) == 1) {
            engineData = obd.read(VEHICLE_SPEED, serialEnabledFlag);
            if (engineData != -1) {
                vehicleSpeed = engineData;
            }
        }

        if (obd.request(ENGINE_COOLANT_TEMP, serialEnabledFlag) == 1) {
            engineData = obd.read(ENGINE_COOLANT_TEMP, serialEnabledFlag);
            if (engineData != -1) {
                engineTemperature = engineData;
            }
        }

        createDataMenu();
    }
    
    else {
        if (serialEnabledFlag) {
            pc.printf("\n\rCAN Disabled!\n\r");
        }
        if (canTestLedEnabledFlag) {
            led2 = !led2;
            ThisThread::sleep_for(250);
            led2 = !led2;
            ThisThread::sleep_for(250);
        }
    }
}

// Hardware interrupt functions
void rotaryEncoderRotated() {
    rotaryEncoderRotatedFlag = true;
}
void rotaryEncoderRotatedCallback() {
    rotaryEncoderRotatedFlag = false;

    if (mainMenuFlag) {
        rotaryEncoderCurrentValue = rotaryEncoder.Get();

        if (rotaryEncoderCurrentValue != rotaryEncoderLastValue) {
            if (rotaryEncoderCurrentValue > rotaryEncoderLastValue) {
                if (rotaryEncoderValue > -1 && rotaryEncoderValue < 2) {
                    rotaryEncoderValue++;
                }
            }
            
            else {
                if (rotaryEncoderValue > 0 && rotaryEncoderValue < 3) {
                    rotaryEncoderValue--;
                }
            }

            rotaryEncoderLastValue = rotaryEncoderCurrentValue;
        }
        
        createMainMenu();
    }
    else if (settingsMenuFlag) {
        rotaryEncoderCurrentValue = rotaryEncoder.Get();

        if (rotaryEncoderCurrentValue != rotaryEncoderLastValue) {
            if (rotaryEncoderCurrentValue > rotaryEncoderLastValue) {
                if (rotaryEncoderValue > -1 && rotaryEncoderValue < 3) {
                    rotaryEncoderValue++;
                }
            }
            
            else {
                if (rotaryEncoderValue > 0 && rotaryEncoderValue < 4) {
                    rotaryEncoderValue--;
                }
            }

            rotaryEncoderLastValue = rotaryEncoderCurrentValue;
        }
        
        createSettingsMenu();
    }
}

void rotaryEncoderButtonPressed() {
    rotaryEncoderButtonFlag = true;
}
void rotaryEncoderButtonPressedCallback() {
    rotaryEncoderButtonFlag = false;

    if (mainMenuFlag) {
        if (rotaryEncoderValue == 0) {
            createDataMenu();
            getDataTicker.attach(&getData, 0.25);
        }
        else if (rotaryEncoderValue == 1) {
            rotaryEncoderValue = 0;
            createSettingsMenu();
        }
        else {
            createAboutMenu();
        }
    }

    else if (settingsMenuFlag) {
        if (rotaryEncoderValue == 0) {
            canEnabledFlag = !canEnabledFlag;
            createSettingsMenu();
        }
        else if (rotaryEncoderValue == 1) {
            canTestLedEnabledFlag = !canTestLedEnabledFlag;
            createSettingsMenu();
        }
        else if (rotaryEncoderValue == 2) {
            serialEnabledFlag = !serialEnabledFlag;
            createSettingsMenu();
        }
        else {
            rotaryEncoderValue = 1;
            createMainMenu();
        }
    }

    else {
        createMainMenu();
        getDataTicker.detach();
    }
}


// Main 
int main() {
    led1 = 0;
    led2 = 0;

    // LCD initialization
    lcdMenu.initializeLCD();
    createMainMenu();

    // Attach interrupt
    rotaryEncoder.attachSW(&rotaryEncoderButtonPressed);
    rotaryEncoder.attachROT(&rotaryEncoderRotated);

    rotaryEncoderRotatedFlag = true;

    // While
    while(true) {
        if (rotaryEncoderRotatedFlag) {
            rotaryEncoderRotatedCallback();
        }

        if (rotaryEncoderButtonFlag) {
            rotaryEncoderButtonPressedCallback();
        }

        if (getDataFlag) {
            getDataCallback();
        }
    }
}
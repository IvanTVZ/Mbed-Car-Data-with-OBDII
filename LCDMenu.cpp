#include "globals.h"
#include "LiquidCrystal_I2C.h"
#include "LCDMenu.h"

void LCDMenu::initializeLCD() {
    lcd.backlight();
    lcd.init();
}

void  LCDMenu::createMainMenu(int rotaryEncoderValue) {
    lcd.clear();
    lcd.print(" Menu: Data");
    lcd.setCursor(0, 1);
    lcd.print(" Menu: Settings");
    lcd.setCursor(0, 2);
    lcd.print(" Menu: About");

    lcd.setCursor(0, rotaryEncoderValue);
    lcd.print(">");
    lcd.setCursor(0, rotaryEncoderValue);
}

void  LCDMenu::createDataMenu(float vehicleSpeed, float engineSpeed, float engineTemperature) {
    lcd.clear();
    lcd.print("Speed [km/h]: " + to_string((int) vehicleSpeed));

    lcd.setCursor(0, 1);
    lcd.print("Engine [rpm]: " + to_string((int) engineSpeed));

    lcd.setCursor(0, 2);
    lcd.print("Temperature [");
    lcd.print(char(223));
    lcd.print("C]: " + to_string((int) engineTemperature));

    lcd.setCursor(0, 3);
    lcd.print(" Press to return");

    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(0, 3);
}

void LCDMenu::createSettingsMenu(bool canEnabledFlag, bool canTestLedEnabledFlag, bool serialEnabledFlag, int rotaryEncoderValue) {
    lcd.clear();
    lcd.print(" CAN Enabled: ");
    if (canEnabledFlag) {
        lcd.print("T");
    }
    else {
        lcd.print("F");
    }

    lcd.setCursor(0, 1);
    lcd.print(" CAN LED Enabled: ");
    if (canTestLedEnabledFlag) {
        lcd.print("T");
    }
    else {
        lcd.print("F");
    }

    lcd.setCursor(0, 2);
    lcd.print(" Serial Enabled: ");
    if (serialEnabledFlag) {
        lcd.print("T");
    }
    else {
        lcd.print("F");
    }

    lcd.setCursor(0, 3);
    lcd.print(" Press to return");

    lcd.setCursor(0, rotaryEncoderValue);
    lcd.print(">");
    lcd.setCursor(0, rotaryEncoderValue);
}

void LCDMenu::createAboutMenu() {
    lcd.clear();
    lcd.print("Ivan Crnjak");
    lcd.setCursor(0, 1);
    lcd.print("Diplomski studij");
    lcd.setCursor(0, 2);
    lcd.print("Konstrukcijski rad");
    lcd.setCursor(0, 3);
    lcd.print(" Press to return");
    
    lcd.setCursor(0, 3);
    lcd.print(">");
    lcd.setCursor(0, 3);    
}

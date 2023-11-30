#ifndef LCDMENU_H
#define LCDMENU_H

class LCDMenu {
    public:
        void initializeLCD();
        void createMainMenu(int rotaryEncoderValue);
        void createDataMenu(float vehicleSpeed, float engineSpeed, float engineTemperature);
        void createSettingsMenu(bool canEnabledFlag, bool canTestLedEnabledFlag, bool serialEnabledFlag, int rotaryEncoderValue);
        void createAboutMenu(); 
};

#endif
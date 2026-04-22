//Settings class definition 

#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include "Arduino.h"
#include <EEPROM.h>

/* This class is used for maintaining and storing settings of the program in the EEPROM internal memory. It defines a settings struct and methods to automatically save and load the information. 
 * To check if the data stored in the EEPROM are valid, a simple checksum is estimated and compared with the one stored in the memory. 
*/

#define DEFAULT_POWER       0
#define LOADS_NUMBER        4
#define DEFAULT_TIMEROFF    10
#define DEFAULT_TIMERON     10
#define DEFAULT_BUZZER      true 

#define DEFAULT_ALPHA       966 
#define DEFAULT_BETA        9.6 
#define DEFAULT_GAMMA       0

#define MAX_SETTINGS_BOUND  65536

using namespace std;

//SettingsValues is a struct used for containing the data to save/edit/load 
typedef struct SettingsValues{
    uint32_t checksum;                      //checksum used for verify the data 
    unsigned int powers[LOADS_NUMBER];      //power values for all relays 
    bool masks[LOADS_NUMBER];               //boolean masks for all relays 

    unsigned int defaultTimerOff;           //timer off value 
    unsigned int defaultTimerOn;            //timer on value 

    float alpha;                            //power estimation coefficients. 
    float beta; 
    float gamma;
} SettingsValues;

class Settings {
    private: 
    SettingsValues values;
    public:
    Settings();
    
    //loadDefault() loads default value sin the settings struct 
    void loadDefault();

    //load saved() loads the struct data from the given memory address and check if they are valid:
    //  address -> EEPROM addess of the saved data 
    //returns true if the loaded data is valid or false otherwise (default data is automatically loaded)
    //
    bool loadSaved(unsigned int address);
    
    //store() estimates the checksum and saved the fata from the settings struct to the given memory address 
    //  address -> EEPROM address where store the data 
    void store(unsigned int address);

    //Setter pf the various settings
    void setPower(unsigned int load, unsigned int value);
    void setTimerOn(unsigned int value);
    void setTimerOff(unsigned int value);
    void setMask(unsigned int load, bool value);
    void setAlpha(float alpha);
    void setBeta(float beta);
    void setGamma(float gamma);

    //getters of the various settings 
    float getAlpha();
    float getBeta();
    float getGamma();
    unsigned int getPower(unsigned int load);
    unsigned int getTimerOn();
    unsigned int getTimerOff();
    bool getMask(unsigned int load);

};


#endif 

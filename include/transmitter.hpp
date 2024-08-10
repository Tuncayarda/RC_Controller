#ifndef TRANSMITTER_HPP
# define TRANSMITTER_HPP

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Airhmi.h>
#include <string.h>
#include <Scheduler.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <math.h>

#define BATT_CRIT_LVL 9.5 

typedef struct  Channels
{
uint16_t	    channel_0;
uint16_t	    channel_1;
uint16_t	    channel_2;
uint16_t	    channel_3;
uint16_t	    channel_4;
uint16_t	    channel_5;
uint16_t	    channel_6;
uint16_t	    channel_7;
uint16_t	    channel_8;
uint16_t	    channel_9;
uint16_t	    channel_10;
uint16_t	    channel_11;
uint16_t	    channel_12;
uint16_t	    channel_13;
uint16_t	    channel_14;
uint16_t	    channel_15;
}			    Channels;

typedef struct  PowerMonitor
{
float           shuntvoltage;
float           busvoltage;
float           current_mA;
float           loadvoltage;
float           power_mW;
}               PowerMonitor;

enum Pages 
{
    MENU_PAGE,
    TRIM_PAGE,
    CHANNEL_MONITOR_PAGE,
    HOME_PAGE,
    REVERSE_PAGE
};

void defChannels(Channels* channels);
void serialPrintChannels(Channels channels);
void defPins();
void startPowerMonitor();
void getPowerData(PowerMonitor* powerMonitor);
void serialPrintPowerData(PowerMonitor powerMonitor);
Pages defPage(int num);
void updateTrimPage(Channels* channels);
void updateChannelMonitorPage(Channels channels);
void updateMenuPage();
void updateHomePage(Channels channels);
void updateReversePage();
void configureChannelReversal(Channels *channels);
void startRadio();
void sendSignal(Channels channels);
char* intToStr(int num);
void screenRefreshLoop();
void initPageLoop();

#endif
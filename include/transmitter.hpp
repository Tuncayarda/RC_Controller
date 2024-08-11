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

typedef struct Trims
{
int             ch0_trim = 0;
int             ch1_trim = 0;
int             ch2_trim = 0;
int             ch3_trim = 0;
int             ch4_trim = 0;
int             ch5_trim = 0;
int             ch6_trim = 0;
int             ch7_trim = 0;
int             ch8_trim = 0;
int             ch9_trim = 0;
int             ch10_trim = 0;
int             ch11_trim = 0;
int             ch12_trim = 0;
int             ch13_trim = 0;
int             ch14_trim = 0;
int             ch15_trim = 0;
}               Trims;

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

void initPages();
void initTrimPage();

void defChannels();
void serialPrintChannels();
void defPins();
void startPowerMonitor();
void getPowerData();
void serialPrintPowerData();
void updateTrimPage();
void updateChannelMonitorPage();
void updateMenuPage();
void updateHomePage();
void updateReversePage();
void configureChannelReversal();
void configureChannelTrim();
void startRadio();
void sendSignal();

void screenRefreshLoop();
void initPageLoop();

#endif
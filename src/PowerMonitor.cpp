#include "transmitter.hpp"

Adafruit_INA219 ina219;

void startPowerMonitor()
{
  ina219.begin();
  ina219.setCalibration_16V_400mA();
}

void getPowerData(PowerMonitor *powerMonitor)
{
  powerMonitor->shuntvoltage = ina219.getShuntVoltage_mV();
  powerMonitor->busvoltage = ina219.getBusVoltage_V();
  powerMonitor->current_mA = ina219.getCurrent_mA();
  powerMonitor->power_mW = ina219.getPower_mW();
  powerMonitor->loadvoltage = powerMonitor->busvoltage + (powerMonitor->shuntvoltage / 1000);
}

void serialPrintPowerData(PowerMonitor powerMonitor)
{
  Serial.begin(9600);
  Serial.print("Bus Voltage:   ");
  Serial.print(powerMonitor.busvoltage);
  Serial.println(" V");
  Serial.print("Shunt Voltage: ");
  Serial.print(powerMonitor.shuntvoltage);
  Serial.println(" mV");
  Serial.print("Load Voltage:  ");
  Serial.print(powerMonitor.loadvoltage);
  Serial.println(" V");
  Serial.print("Current:       ");
  Serial.print(powerMonitor.current_mA);
  Serial.println(" mA");
  Serial.print("Power:         ");
  Serial.print(powerMonitor.power_mW);
  Serial.println(" mW");
  Serial.println("");
  Serial.end();
  delay(2000);
}
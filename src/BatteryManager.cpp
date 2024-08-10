#include "transmitter.hpp"

extern PowerMonitor powerMonitor;

uint8_t checkBatteryStatus()
{
	if (powerMonitor.loadvoltage <= BATT_CRIT_LVL)
		return (1);
	return (0);
}

#include "transmitter.hpp"

AirVariable pageNum = AirVariable("PageNum");

Channels channels;
Trims trims;
PowerMonitor powerMonitor;
uint8_t pgnbr;
char revData[17] = "0000000000000000";
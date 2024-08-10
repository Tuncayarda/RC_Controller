#include "transmitter.hpp"

AirVariable revSettings = AirVariable("revSettings");

extern char revData[17];

void getRevData()
{
    revSettings.VarGet(revData, 16);
}

void updateReversePage()
{
    getRevData();
}
#include "transmitter.hpp"

extern Channels channels;
extern Trims trims;

extern char revData[17];

void defPins()
{
	pinMode(33, INPUT_PULLUP);
	pinMode(35, INPUT_PULLUP);
	pinMode(31, INPUT_PULLUP);
	pinMode(25, INPUT_PULLUP);
	pinMode(27, INPUT_PULLUP);
	pinMode(29, INPUT_PULLUP);
	pinMode(24, INPUT_PULLUP);
	pinMode(23, INPUT_PULLUP);
	pinMode(30, INPUT_PULLUP);
	pinMode(26, INPUT_PULLUP);
	pinMode(34, INPUT_PULLUP);
	pinMode(32, INPUT_PULLUP);
	pinMode(7, INPUT_PULLUP);
}

void defChannels()
{
	uint16_t *buff = (uint16_t *)&channels;
	for (uint8_t i = 54; i <= 62; i++)
	{
		*buff++ = map(analogRead(i), 0, 952, 1000, 2000);
	}
	channels.channel_9 = digitalRead(7) ? 1000 : 2000;
	channels.channel_10 = digitalRead(33) == 0 ? 2000 : ((digitalRead(35) == 0) ? 1000 : 1500);
	channels.channel_11 = digitalRead(25) == 0 ? 2000 : ((digitalRead(31) == 0) ? 1000 : 1500);
	channels.channel_12 = digitalRead(29) == 0 ? 2000 : ((digitalRead(27) == 0) ? 1000 : 1500);
	channels.channel_13 = digitalRead(24) == 0 ? 2000 : ((digitalRead(23) == 0) ? 1000 : 1500);
	channels.channel_14 = digitalRead(26) == 0 ? 2000 : ((digitalRead(30) == 0) ? 1000 : 1500);
	channels.channel_15 = digitalRead(32) == 0 ? 2000 : ((digitalRead(34) == 0) ? 1000 : 1500);
}

void configureChannelTrim()
{
	uint16_t *ch_buff = (uint16_t *)&channels;
	uint16_t *trim_buff = (uint16_t *)&trims;
	for(uint8_t i = 0; i < 16; i++)
		ch_buff[i] += trim_buff[i];
}

void configureChannelReversal()
{
	uint16_t *buff = (uint16_t *)&channels;
	for(uint8_t i = 0; i < 16; i++)
	{
		if(revData[i] == '1')
			buff[i] = 3000 - buff[i];
	}
}

void serialPrintChannels()
{
	uint16_t *buff = (uint16_t *)&channels;
	Serial.begin(9600);
	for (uint8_t i = 0; i < 16; i++)
	{
		Serial.print(" |");
		Serial.print(i);
		Serial.print(": ");
		Serial.print(*buff++);
	}
	Serial.println();
	Serial.end();
}

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwmDriver = Adafruit_PWMServoDriver();

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
}			        Channels;

RF24 radio(9, 10); // CE, CSN

Channels channels;

const byte address[6] = "00001";

void serialPrintChannels(Channels channels)
{
	uint16_t* buff = (uint16_t*)&channels;
	Serial.begin(9600);
	for(uint8_t i = 0; i < 16; i++)
	{
		Serial.print(" |");
		Serial.print(i);
		Serial.print(": ");
		Serial.print(*buff++);
	}
	Serial.println();
	Serial.end();
}

void setup() 
{
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening();

  radio.setPALevel(RF24_PA_MAX);

  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);

  pwmDriver.begin();
  pwmDriver.setPWMFreq(50);
}

void loop() 
{
  if (radio.available()) 
  {
    radio.read(&channels, sizeof(channels));
    uint16_t *ch_buff = (uint16_t *)&channels;
    for(uint8_t i = 0; i < 16; i++)
    {
      pwmDriver.writeMicroseconds(i, ch_buff[i]);
    }
  }
}

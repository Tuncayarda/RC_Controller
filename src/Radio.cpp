#include "transmitter.hpp"

RF24 radio(4, 5);

const byte address[6] = "00001";

void startRadio()
{
	radio.begin();
	radio.openWritingPipe(address);
	radio.stopListening();
	radio.setPALevel(RF24_PA_MAX);
	radio.setAutoAck(false);
	radio.setDataRate(RF24_250KBPS);
}

void sendSignal(Channels channels)
{
	radio.write(&channels, sizeof(channels));
}
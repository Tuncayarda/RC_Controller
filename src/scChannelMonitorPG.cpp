#include "transmitter.hpp"

extern Channels channels;

AirVariable ch1 = AirVariable("ch1");
AirVariable ch2 = AirVariable("ch2");
AirVariable ch3 = AirVariable("ch3");
AirVariable ch4 = AirVariable("ch4");
AirVariable ch5 = AirVariable("ch5");
AirVariable ch6 = AirVariable("ch6");
AirVariable ch7 = AirVariable("ch7");
AirVariable ch8 = AirVariable("ch8");
AirVariable ch9 = AirVariable("ch9");
AirVariable ch10 = AirVariable("ch10");
AirVariable ch11 = AirVariable("ch11");
AirVariable ch12 = AirVariable("ch12");
AirVariable ch13 = AirVariable("ch13");
AirVariable ch14 = AirVariable("ch14");
AirVariable ch15 = AirVariable("ch15");
AirVariable ch16 = AirVariable("ch16");

void updateChannelMonitorPage()
{
	ch1.VarSeti(channels.channel_0);
	ch2.VarSeti(channels.channel_1);
	ch3.VarSeti(channels.channel_2);
	ch4.VarSeti(channels.channel_3);
	ch5.VarSeti(channels.channel_4);
	ch6.VarSeti(channels.channel_5);
	ch7.VarSeti(channels.channel_6);
	ch8.VarSeti(channels.channel_7);
	ch9.VarSeti(channels.channel_8);
	ch10.VarSeti(channels.channel_9);
	ch11.VarSeti(channels.channel_10);
	ch12.VarSeti(channels.channel_11);
	ch13.VarSeti(channels.channel_12);
	ch14.VarSeti(channels.channel_13);
	ch15.VarSeti(channels.channel_14);
	ch16.VarSeti(channels.channel_15);
}

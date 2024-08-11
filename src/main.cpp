#include "transmitter.hpp"

extern Channels channels;
extern PowerMonitor powerMonitor;
extern uint8_t pgnbr;
extern AirVariable pageNum;
extern char revData[17];

void setup()
{
	Serial1.begin(115200);
	defPins();
	airInit();
	startPowerMonitor();
	startRadio();
	Scheduler.startLoop(screenRefreshLoop);
	Scheduler.startLoop(initPageLoop);
}

void loop()
{
	getPowerData();
	defChannels();
	configureChannelReversal();
	configureChannelTrim();
	sendSignal();
	delay(50);
}

void screenRefreshLoop()
{
	switch (pgnbr)
	{
	case MENU_PAGE:
		updateMenuPage();
		break;
	case TRIM_PAGE:
		updateTrimPage();
		break;
	case CHANNEL_MONITOR_PAGE:
		updateChannelMonitorPage();
		break;
	case HOME_PAGE:
		updateHomePage();
		break;
	case REVERSE_PAGE:
		updateReversePage();
		break;
	default:
		break;
	}
	delay(100);
	yield();
}

void initPageLoop()
{
	pgnbr = pageNum.VarGeti();
	delay(2000);
	yield();
}
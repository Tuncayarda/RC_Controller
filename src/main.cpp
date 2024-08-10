#include "transmitter.hpp"

extern Channels channels;
extern PowerMonitor powerMonitor;
extern uint8_t pgnbr;
extern AirVariable pageNum;
extern char revData[17];

void setup()
{
	defPins();
	Serial1.begin(115200);
	airInit();
	startPowerMonitor();
	startRadio();
	Scheduler.startLoop(screenRefreshLoop);
	Scheduler.startLoop(initPageLoop);
}

void loop()
{
	getPowerData(&powerMonitor);
	defChannels(&channels);
	configureChannelReversal(&channels);
	sendSignal(channels);
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
		updateTrimPage(&channels);
		break;
	case CHANNEL_MONITOR_PAGE:
		updateChannelMonitorPage(channels);
		break;
	case HOME_PAGE:
		updateHomePage(channels);
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
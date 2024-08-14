#include "transmitter.hpp"

AirPicture img_leftJY = AirPicture("img_leftJY");
AirPicture img_rightJY = AirPicture("img_rightJY");
AirVariable batLevel = AirVariable("batLevel");
AirLabel batLabel = AirLabel("batLabel");

extern PowerMonitor powerMonitor;
extern Channels channels;

void updateLJ(uint16_t throttle, uint16_t yaw)
{
	short x = map(yaw, 1000, 2000, -60, 60);
	short y = map(throttle, 1000, 2000, 60, -60);
	double dist = sqrt(x * x + y * y);

	if (dist > 40)
	{
		double angle = atan2(y, x);

		img_leftJY.Set_left(94 + 40 * cos(angle));
		img_leftJY.Set_top(138 + 40 * sin(angle));
	}
	else
	{
		img_leftJY.Set_left(94 + x);
		img_leftJY.Set_top(138 + y);
	}
}

void updateRJ(uint16_t roll, uint16_t pitch)
{
	short x = map(roll, 1000, 2000, -60, 60);
	short y = map(pitch, 1000, 2000, 60, -60);
	double dist = sqrt(x * x + y * y);

	if (dist > 40)
	{
		double angle = atan2(y, x);

		img_rightJY.Set_left(354 + 40 * cos(angle));
		img_rightJY.Set_top(138 + 40 * sin(angle));
	}
	else
	{
		img_rightJY.Set_left(354 + x);
		img_rightJY.Set_top(138 + y);
	}
}

void updateHomePage()
{
	char buff[6];
	updateLJ(channels.channel_4, channels.channel_5);
	updateRJ(channels.channel_8, channels.channel_7);
	sprintf(buff, "%.2f", powerMonitor.loadvoltage);
	batLabel.setText(buff);
}

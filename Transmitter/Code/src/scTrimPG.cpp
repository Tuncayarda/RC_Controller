#include "transmitter.hpp"

AirLabel valLabel = AirLabel("ELabel1");
AirLabel chLabel = AirLabel("ELabel2");
AirLabel trimLabel = AirLabel("trim_label");
AirButton plusButton = AirButton("plusButton");
AirButton minusButton = AirButton("minusButton");
AirSlider slider = AirSlider("Slider1");

extern Channels channels;
extern Trims trims;
char chNum[4];

AirTouch *air_listen_list[] = {
  &plusButton,
  &minusButton,
  NULL
};

int *trim_buff = (int *)&trims;

void plusButtonPopCallBack(void *ptr)
{
    trim_buff[atoi(chNum) - 1] += 10;
}

void minusButtonPopCallBack(void *ptr)
{
    trim_buff[atoi(chNum) - 1] -= 10;
}

void initTrimPage()
{
    plusButton.attachPop(plusButtonPopCallBack, &plusButton);
    minusButton.attachPop(minusButtonPopCallBack, &minusButton);
}

void updateTrimPage()
{
    airLoop(air_listen_list);
    uint16_t *ch_buff = (uint16_t *)&channels;
    char buffer[10];
    
    chLabel.getText(chNum, 2);
    sprintf(buffer, "%d", ch_buff[atoi(chNum) - 1]);
    valLabel.setText(buffer);
    slider.Set_Value(map(atoi(buffer), 1000, 2000, 100, 0));
    sprintf(buffer, "%d", trim_buff[atoi(chNum) - 1]);
    trimLabel.setText(buffer);
}
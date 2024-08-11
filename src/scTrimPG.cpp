#include "transmitter.hpp"

AirLabel valLabel = AirLabel("ELabel1");
AirLabel chLabel = AirLabel("ELabel2");
AirLabel trimLabel = AirLabel("trim_label");

AirSlider slider = AirSlider("Slider1");

extern Channels channels;
extern Trims trims;

void getTrimValues()
{

}

void updateTrimPage()
{
    uint16_t *ch_buff = (uint16_t *)&channels;
    char buffer[10];

    chLabel.getText(buffer, 2);
    sprintf(buffer, "%d", ch_buff[atoi(buffer) - 1]);
    valLabel.setText(buffer);
    slider.Set_Value(map(atoi(buffer), 1000, 2000, 100, 0));
}


#ifndef MAIN_WS2812_H_
#define MAIN_WS2812_H_
#include <stdint.h>
#include <driver/rmt.h>

/**
 * A data type representing the color of a pixel.
 */
typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} pixel_t;


/**
 * Driver for WS2812/NeoPixel data.
 *
 * NeoPixels or WS2812s are LED devices that can illuminate in arbitrary colors with
 * 8 bits of data for each of the red, green and blue channels.  These devices can be
 * daisy chained together to produce a string of LEDs.  If we call each LED instance
 * a pixel, then when we want to set the value of a string of pixels, we need to supply
 * the data for all the pixels.  This class encapsulates setting the color value for
 * an individual pixel within the string and, once you have set up all the desired colors,
 * you can then set all the pixels in a show() operation.  The class hides from you
 * the underlying details needed to drive the devices.
 */
class WS2812 {
public:
	WS2812(int gpioNum, uint16_t pixelCount, int channel=RMT_CHANNEL_0);
	void show();
	void setColorOrder(char *order);
	void setPixel(uint16_t index, uint8_t red, uint8_t green, uint8_t blue);
	void setPixel(uint16_t index, pixel_t pixel);
	void setPixel(uint16_t index, uint32_t pixel);
	void clear();
	virtual ~WS2812();
private:
	char *colorOrder;
	uint16_t pixelCount;
	rmt_channel_t channel;
	rmt_item32_t *items;
	pixel_t *pixels;
};

#endif /* MAIN_WS2812_H_ */

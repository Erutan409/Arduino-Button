#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

enum BUTTON_MODE {
	BUTTON_SIMPLE = 0x01,
	BUTTON_TOGGLE = 0x02
};

class Button {

	public:
		Button(uint8_t pin, BUTTON_MODE mode);
		Button &monitor(void);
		operator bool();

	private:
		uint8_t _pin;
		BUTTON_MODE _mode = BUTTON_SIMPLE;
		bool _state = false;
		bool _toggled = false;
		bool _changed = false;

};

#endif // !BUTTON_H
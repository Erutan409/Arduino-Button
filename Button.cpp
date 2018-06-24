#include <Button.h>

Button::Button(uint8_t pin, BUTTON_MODE mode) {
	this->_pin = pin;
	pinMode(this->_pin, INPUT_PULLUP);
	this->_mode = mode;
}

Button &Button::monitor(void) {
	bool &toggled = this->_toggled;
	bool &state = this->_state;
	bool &changed = this->_changed;
	BUTTON_MODE &mode = this->_mode;

	bool buttonPressed = !(bool)digitalRead(this->_pin);

	if (mode == BUTTON_SIMPLE) {
		state = buttonPressed;

		if (state) {
			changed = true;
		}
	} else if (mode == BUTTON_TOGGLE) {
		if (buttonPressed) {
			if (!toggled) {
				state = true;
				toggled = true;
				changed = true;
			}
		} else {
			toggled = false;
		}
	}

	return *this;
}

Button::operator bool() {
	bool &changed = this->_changed;

	if (changed) {
		changed = false;
		return true;
	}

	return false;
}
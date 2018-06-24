# Arduino-Button

Simple method for using push button, utilizing internal pull-up resistor.

Example:

```c++
#include <Arduino.h>
#include <Relay.h>
#include <Button.h>

#define buttonPin 3
#define waterPumpPin 4

Relay waterPump(4);

/*
Only evaluate to true once when casting instance
to boolean. This will decrease the amount of custom
code needed to not trigger a condition multiple
times when a button is still pressed. 
*/
Button button(buttonPin, BUTTON_TOGGLE);

/*
Evaluate to true whenever the button is pressed.
*/
// Button button(buttonPin, BUTTON_SIMPLE);

void loop(void) {
    // toggle the relay only once when the button is pushed and/or held down
    if ((bool)button.monitor()) {
        waterPump.toggle();
    }
}
```
/*
  Particle Cloud Function

  Demonstrate use of Particle cloud functions to control a "traffic light"
  comprised of 3 LEDS: red, green, and blue.
*/


const pin_t RED_LED = D2;
const pin_t GREEN_LED = D8;
const pin_t BLUE_LED = D5;

struct led_state {
    bool red;
    bool green;
    bool blue;
};

struct led_state current_led_state = { false, false, false };

SYSTEM_THREAD(ENABLED);

int toggleLed(String color)
{
    if (color == "red")
    {
        digitalWrite(RED_LED, current_led_state.red ? LOW : HIGH);
        current_led_state.red = current_led_state.red ? false : true;
        return 1;
    }
    
    if (color == "green")
    {
        digitalWrite(GREEN_LED, current_led_state.green ? LOW : HIGH);
        current_led_state.green = current_led_state.green ? false : true;
        return 1;
    }
    
    if (color == "blue")
    {
        digitalWrite(BLUE_LED, current_led_state.blue ? LOW : HIGH);
        current_led_state.blue = current_led_state.blue ? false : true;
        return 1;
    }

    return -1;
}

void setup()
{
    // Initialise LEDs
    pinMode(RED_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    
    Particle.function("toggle_led", toggleLed);
}

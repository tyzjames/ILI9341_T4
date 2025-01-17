/********************************************************************
*
* ILI9341_T4 library example: calibrating the XPT2046 touchscreen
*
********************************************************************/

#include <Arduino.h>
#include <ILI9341_T4.h>


// DEFAULT WIRING USING SPI 0 ON TEENSY 4/4.1
// Recall that DC must be on a valid cs pin !!! 
#define PIN_SCK     13      // mandatory 
#define PIN_MISO    12      // mandatory
#define PIN_MOSI    11      // mandatory
#define PIN_DC      10      // mandatory
#define PIN_CS      9       // mandatory (but can be any digital pin)
#define PIN_RESET   6       // could be omitted (set to 255) yet it is better to use (any) digital pin whenever possible.
#define PIN_BACKLIGHT 255   // optional. Set this only if the screen LED pin is connected directly to the Teensy 


// ALTERNATE WIRING USING SPI 1 ON TEENSY 4/4.1
// Recall that DC must be on a valid cs pin !!! 

//#define PIN_SCK     27      // mandatory 
//#define PIN_MISO    1       // mandatory
//#define PIN_MOSI    26      // mandatory
//#define PIN_DC      0       // mandatory
//#define PIN_CS      30      // mandatory (but can be any digital pin)
//#define PIN_RESET   29      // could be omitted (set to 255) yet it is better to use (any) digital pin whenever possible.
//#define PIN_BACKLIGHT 255   // optional. Set this only if the screen LED pin is connected directly to the Teensy 


// XPT2046 TOUSCHSCREEN CONNECTED ON THE SAME SPI PORT AS ILI9341:
// 
// - connect T_DIN to the same pin as PIN_MOSI
// - connect T_DO to the same pin as PIN_MISO
#define PIN_TOUCH_IRQ 3   // (optional) can be any digital pin
#define PIN_TOUCH_CS  4   // any digital pin


// 20MHz SPI. Can do much better with short wires
#define SPI_SPEED       20000000


// the screen driver object
ILI9341_T4::ILI9341Driver tft(PIN_CS, PIN_DC, PIN_SCK, PIN_MOSI, PIN_MISO, PIN_RESET, PIN_TOUCH_CS, PIN_TOUCH_IRQ);


void setup() 
    {
    Serial.begin(9600);
    tft.output(&Serial);
    while (!tft.begin(SPI_SPEED))
        {
        Serial.println("Initialization error...");
        delay(1000);
        }
    }


// array to store touchscreen calibration 
int touch_calib[4];

void loop() 
    {

    // run the touchscreen calibration routine
    tft.calibrateTouch(touch_calib);

    // ok, now 'touch_calib' contain the calibration data which 
    // can be loaded next time with: 
    // tft.setTouchCalibration(touch_calib);

    }


/** end of file */


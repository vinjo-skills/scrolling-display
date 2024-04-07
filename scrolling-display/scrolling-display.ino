#include <MD_Parola.h>

#include <MD_MAX72xx.h>

#include <SPI.h>

// Uncomment according to your hardware type

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW  // for module with blue PCB

//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

// Defining size, and output pins

#define MAX_DEVICES 4  // there are 4 modules in our display.

#define CS_PIN 3  // The pin on which chip select is connected.

char message[200] = "";  // char array for storing typed message.

// Create a new instance of the MD_Parola class with hardware SPI connection

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);



void setup() {

  // Intialize the object

  Serial.begin(9600);

  myDisplay.begin();

  myDisplay.setIntensity(8);  // Set the display brightness. Max is 15 and Min is 0

  myDisplay.displayClear();
}

void loop() {

  if (Serial.available() > 0)
  {

    String mes = Serial.readString();
    disp_name(mes);
    Serial.println(message);
    // disp_name(message);
    myDisplay.displayScroll(message, PA_CENTER, PA_SCROLL_LEFT, 100);  // scroll the message left to right with time interval of 100ms.
  }

  if (myDisplay.displayAnimate())  // run scrolling continuously
  {
    myDisplay.displayReset();
  }
}  // code ends here



void disp_name(String word)  //convert String to character array.
{
  for (int i = 0; i < (word.length() - 1); i++)
  {
    message[i] = word[i];
  }
}

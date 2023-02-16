//--------------------------------------------------------------------
//---------------------------USER INTERFACE---------------------------
//--------------------------------------------------------------------
// NOTE: THE PROGRAM MUST BE UPLOADED TO THE ARDUINO BEFORE USE.
// THIS CAN BE DONE BY CLICKING "UPLOAD" IN THE ARDUINO IDE INTERFACE
//--------------------------------------------------------------------
// NOTE: THE CORRECT PORT MUST BE CHOSEN IN THE ARDUINO IDE VIA
// "Tools" -> "Port" -> select the available port in the droupdown menu.
//--------------------------------------------------------------------
// Please choose the length of the tail of dimmer LEDs following the main bright LED
// Possible values are 0, 1, 2 or 3. (don't forget the semicolon at the end!!)
//-----------------------------
byte TAIL_LENGTH = 3;
//-----------------------------
//-----------------------------
// Please define the oscillation frequency in Hz below.
// Please note that 1 Hz is defined as 1 full oscillation per second,
// i.e. once from left to right and from right to left again.
// Please use the following format: FREQUENCY = 1.23;
// (don't forget the semicolon at the end!!)
//-----------------------------
// Maximum possible frequency for TAIL_LENGTH = 0 (see below): 0.9 Hz
// Maximum possible frequency for TAIL_LENGTH = 1 (see below): 0.6 Hz
// Maximum possible frequency for TAIL_LENGTH = 2 (see below): 0.4 Hz
// Maximum possible frequency for TAIL_LENGTH = 3 (see below): 0.3 Hz
//-----------------------------
float FREQUENCY = 0.2;
//-----------------------------
//-----------------------------
// Please define the color of the LEDs below by changing the strength of
// the RED, GREEN and BLUE values, which will mix to give one color.
// Each value ranges from 0 to 255.
// Please use the following format: RED = 123;
// (don't forget the semicolon at the end!!)
// For color mixing examples visit https://www.rapidtables.com/web/color/RGB_Color.html
//-----------------------------
byte RED = 10;
byte GREEN = 10;
byte BLUE  = 10;
//-----------------------------
//-----------------------------
// Please define for how long the program is to run (in seconds)
// Please use the following format: float program_duration = 14.7;
// (don't forget the semicolon at the end!!)
//-----------------------------
float program_duration = 20;
//-----------------------------
//-----------------------------
// Please choose which of the LEDs in a given strip are ON 
// and which are OFF.
// LED_1 is the left-most LED, while LED_36 is the right-most.
// LED number X is ON, if its variable "int LED_X_on_or_off" is equal
// to 1. It is turned OFF, if the variable is equal to 0.
// Please use the following format: int LED_1_on_or_off = 1;
// (don't forget the semicolon at the end!!)
//-----------------------------
byte LED_1_on_or_off = 1;
byte LED_2_on_or_off = 1;
byte LED_3_on_or_off = 1;
byte LED_4_on_or_off = 1;
byte LED_5_on_or_off = 1;
byte LED_6_on_or_off = 1;
byte LED_7_on_or_off = 1;
byte LED_8_on_or_off = 1;
byte LED_9_on_or_off = 1;
byte LED_10_on_or_off = 1;
byte LED_11_on_or_off = 1;
byte LED_12_on_or_off = 1;
byte LED_13_on_or_off = 1;
byte LED_14_on_or_off = 1;
byte LED_15_on_or_off = 1;
byte LED_16_on_or_off = 1;
byte LED_17_on_or_off = 1;
byte LED_18_on_or_off = 1;
byte LED_19_on_or_off = 1;
byte LED_20_on_or_off = 1;
byte LED_21_on_or_off = 1;
byte LED_22_on_or_off = 1;
byte LED_23_on_or_off = 1;
byte LED_24_on_or_off = 1;
byte LED_25_on_or_off = 1;
byte LED_26_on_or_off = 1;
byte LED_27_on_or_off = 1;
byte LED_28_on_or_off = 1;
byte LED_29_on_or_off = 1;
byte LED_30_on_or_off = 1;
byte LED_31_on_or_off = 1;
byte LED_32_on_or_off = 1;
byte LED_33_on_or_off = 1;
byte LED_34_on_or_off = 1;
byte LED_35_on_or_off = 1;
//--------------------------------------------------------------------
//----------------------END OF USER INTERFACE-------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// Pack all the needed RGB values in an array to make for easier use.
// Also, in the Setup it will be ensured that they aren't rounded down
// to zero.
float RGB_values[] = {
  RED,GREEN,BLUE,
  RED*0.2,GREEN*0.2,BLUE*0.2,
  RED*0.05,GREEN*0.05,BLUE*0.05,
  RED*0.01,GREEN*0.01,BLUE*0.01};


// Pack the LED ON/OFF objects into an array 
// for easier calling by for loops etc.
byte LEDS_ON_OR_OFF[] = {0,
  LED_1_on_or_off,LED_2_on_or_off,LED_3_on_or_off,LED_4_on_or_off,
  LED_5_on_or_off,LED_6_on_or_off,LED_7_on_or_off,LED_8_on_or_off,
  LED_9_on_or_off,LED_10_on_or_off,LED_11_on_or_off,LED_12_on_or_off,
  LED_13_on_or_off,LED_14_on_or_off,LED_15_on_or_off,LED_16_on_or_off,
  LED_17_on_or_off,LED_18_on_or_off,LED_19_on_or_off,LED_20_on_or_off,
  LED_21_on_or_off,LED_22_on_or_off,LED_23_on_or_off,LED_24_on_or_off,
  LED_25_on_or_off,LED_26_on_or_off,LED_27_on_or_off,LED_28_on_or_off,
  LED_29_on_or_off,LED_30_on_or_off,LED_31_on_or_off,LED_32_on_or_off,
  LED_33_on_or_off,LED_34_on_or_off,LED_35_on_or_off};

#include <Adafruit_NeoPixel.h>

// To which pin on the Arduino are the LED strips connected to?
// I started with pin 4 instead of 0 or 1 because we need pins 2 and 3 for
// external inputs/triggers/interupts
byte LED_STRIP_1_CONNECTED_TO_PIN = 4;
byte LED_STRIP_2_CONNECTED_TO_PIN = 6; 
byte LED_STRIP_3_CONNECTED_TO_PIN = 7; 
byte LED_STRIP_4_CONNECTED_TO_PIN = 8; 
byte LED_STRIP_5_CONNECTED_TO_PIN = 9; 
byte LED_STRIP_6_CONNECTED_TO_PIN = 10; 
byte LED_STRIP_7_CONNECTED_TO_PIN = 11;
byte LED_STRIP_8_CONNECTED_TO_PIN = 12;
byte LED_STRIP_9_CONNECTED_TO_PIN = 13;
// Pack the objects into an array for easier calling by for loops etc.
byte LED_STRIP_PINS[] = {
  LED_STRIP_1_CONNECTED_TO_PIN, LED_STRIP_2_CONNECTED_TO_PIN,
  LED_STRIP_3_CONNECTED_TO_PIN,LED_STRIP_4_CONNECTED_TO_PIN,
  LED_STRIP_5_CONNECTED_TO_PIN,LED_STRIP_6_CONNECTED_TO_PIN,
  LED_STRIP_7_CONNECTED_TO_PIN,LED_STRIP_8_CONNECTED_TO_PIN,
  LED_STRIP_9_CONNECTED_TO_PIN};

// How many LEDs are there in one strip?
// It is assumed that all LED strips have the same number of LEDs
byte LED_COUNT = 36;  

// Define the delay time after each lighting step in ms for each light tail option
// The values of these variables are defined in the setup loop
float DELAYVAL_TAIL_0;
float DELAYVAL_TAIL_1;
float DELAYVAL_TAIL_2;
float DELAYVAL_TAIL_3;

// Declare the NeoPixel strip objects
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
Adafruit_NeoPixel strip_1(LED_COUNT, LED_STRIP_PINS[0]); // First LED strip
Adafruit_NeoPixel strip_2(LED_COUNT, LED_STRIP_PINS[1]); // Second LED strip
Adafruit_NeoPixel strip_3(LED_COUNT, LED_STRIP_PINS[2]); // Third LED strip
Adafruit_NeoPixel strip_4(LED_COUNT, LED_STRIP_PINS[3]); // Fourth LED strip
Adafruit_NeoPixel strip_5(LED_COUNT, LED_STRIP_PINS[4]); // Fifth LED strip
Adafruit_NeoPixel strip_6(LED_COUNT, LED_STRIP_PINS[5]); // Sixth LED strip
Adafruit_NeoPixel strip_7(LED_COUNT, LED_STRIP_PINS[6]); // Seventh LED strip
Adafruit_NeoPixel strip_8(LED_COUNT, LED_STRIP_PINS[7]); // Eighth LED strip
Adafruit_NeoPixel strip_9(LED_COUNT, LED_STRIP_PINS[8]); // Ninth LED strip
// Pack the objects into an array for easier calling by for loops etc.
Adafruit_NeoPixel STRIPS[] = {
  strip_1,strip_2,strip_3,
  strip_4,strip_5,strip_6,
  strip_7,strip_8,strip_9};
//---------------------------------------------------------------------
// Define button variables to start light trail via button
byte buttonPin1 = 5; // Button no. 1 is connected to pin 2 on the Arduino
byte buttonStatus1 = 0; 
//---------------------------------------------------------------------

void setup() {
  // Calculate the DELAYVAL values
  if(FREQUENCY >= 0.9){DELAYVAL_TAIL_0 = 0;}
  else{DELAYVAL_TAIL_0 = 1000/(20*FREQUENCY) - 55;}
  if(FREQUENCY >= 0.6){DELAYVAL_TAIL_1 = 0;}
  else{DELAYVAL_TAIL_1 = 1000/(22*FREQUENCY) - 77;}
  if(FREQUENCY >= 0.4){DELAYVAL_TAIL_2 = 0;}
  else{DELAYVAL_TAIL_2 = 1000/(24*FREQUENCY) - 100;}
  if(FREQUENCY >= 0.3){DELAYVAL_TAIL_3 = 0;}
  else{DELAYVAL_TAIL_3 = 1000/(26*FREQUENCY) - 120;}

  
  // Get the strips ready and delete any old color settings
  for(int i = 0; i < (sizeof(STRIPS) / sizeof(STRIPS[0])); i++){
  STRIPS[i].begin();
  STRIPS[i].show();
  STRIPS[i].clear();
  STRIPS[i].show();
  STRIPS[i].clear();
  STRIPS[i].show();
  }
  // Ensure that the RGB values aren't rounded down to zero if 
  // they are below one but initially above zero, 
  // as that makes the light trail shorter and makes problems.
  for (int i = 0; i < (sizeof(RGB_values) / sizeof(RGB_values[0])); i++) {
    if(RGB_values[i] < 1 && RGB_values[i] != 0){
      RGB_values[i] = 1;
    }
  }
  // Define button no. 1 to an input giver
  pinMode(buttonPin1, INPUT);
}

void loop() {
  // Implement that when button is pressed, the loop starts.
  buttonStatus1 = digitalRead(buttonPin1);
  if (buttonStatus1 == HIGH){ 
    //---------------------------------------------------------------------
    // Define beginning time
    long beginning_time = millis();
    //Serial.print("Beginning Time: ");
    //Serial.println(beginning_time);
    //---------------------------------------------------------------------
    while(millis() - beginning_time < program_duration * 1000){
      // "TO" DIRECTION
      //-------------------------------------------------------------------
      // TAIL_LENGTH == 3
      if(TAIL_LENGTH == 3){
        // Choose which LED strip to be brightest, iterate through all strips
        for(int i = 0; i <= (sizeof(STRIPS) / sizeof(STRIPS[0])) + 3; i++) {
          // Iterate through all LEDs on the brightest LED strip
          for(int j = 0; j < LED_COUNT; j++){
            // If an LED should be ON, turn it on and also turn the same LEDs
            // in lower strips on, but less bright, so they form the trail
            if(LEDS_ON_OR_OFF[j] == 1){
              if(i<9){
                STRIPS[i].setPixelColor(j, STRIPS[i].Color(
                  RGB_values[0], RGB_values[1], RGB_values[2]));
                STRIPS[i].show();
              } 
              if(i>0 && i<10){
                STRIPS[i-1].setPixelColor(j, STRIPS[i-1].Color(
                  RGB_values[3], RGB_values[4], RGB_values[5]));
                STRIPS[i-1].show();
              }
              if(i>1 && i<11){
                STRIPS[i-2].setPixelColor(j, STRIPS[i-2].Color(
                  RGB_values[6], RGB_values[7], RGB_values[8]));
                STRIPS[i-2].show();
              }
              if(i>2 && i<12){
                STRIPS[i-3].setPixelColor(j, STRIPS[i-3].Color(
                  RGB_values[9], RGB_values[10], RGB_values[11]));
                STRIPS[i-3].show();
              }
            }
          }
          delay(DELAYVAL_TAIL_3);
          for(int l = 0; l < (sizeof(STRIPS) / sizeof(STRIPS[0])); l++){
            STRIPS[l].clear();
            STRIPS[l].show();
          }
          //-------------------------------------------------------------------
        }
      }
      //-------------------------------------------------------------------
      // TAIL_LENGTH == 2
      if(TAIL_LENGTH == 2){
        // Choose which LED strip to be brightest, iterate through all strips
        for(int i = 0; i <= (sizeof(STRIPS) / sizeof(STRIPS[0])) + 2; i++) {
          // Iterate through all LEDs on the brightest LED strip
          for(int j = 0; j < LED_COUNT; j++){
            // If an LED should be ON, turn it on and also turn the same LEDs
            // in lower strips on, but less bright, so they form the trail
            if(LEDS_ON_OR_OFF[j] == 1){
              if(i<9){
                STRIPS[i].setPixelColor(j, STRIPS[i].Color(
                  RGB_values[0], RGB_values[1], RGB_values[2]));
                STRIPS[i].show();
              } 
              if(i>0 && i<10){
                STRIPS[i-1].setPixelColor(j, STRIPS[i-1].Color(
                  RGB_values[3], RGB_values[4], RGB_values[5]));
                STRIPS[i-1].show();
              }
              if(i>1 && i<11){
                STRIPS[i-2].setPixelColor(j, STRIPS[i-2].Color(
                  RGB_values[6], RGB_values[7], RGB_values[8]));
                STRIPS[i-2].show();
              }              
            }
          }
          delay(DELAYVAL_TAIL_2);
          for(int l = 0; l < (sizeof(STRIPS) / sizeof(STRIPS[0])); l++){
            STRIPS[l].clear();
            STRIPS[l].show();
          }
          //-------------------------------------------------------------------
        }
      }
      //-------------------------------------------------------------------
      // TAIL_LENGTH == 1
      if(TAIL_LENGTH == 1){
        // Choose which LED strip to be brightest, iterate through all strips
        for(int i = 0; i <= (sizeof(STRIPS) / sizeof(STRIPS[0])) + 1; i++) {
          // Iterate through all LEDs on the brightest LED strip
          for(int j = 0; j < LED_COUNT; j++){
            // If an LED should be ON, turn it on and also turn the same LEDs
            // in lower strips on, but less bright, so they form the trail
            if(LEDS_ON_OR_OFF[j] == 1){
              if(i<9){
                STRIPS[i].setPixelColor(j, STRIPS[i].Color(
                  RGB_values[0], RGB_values[1], RGB_values[2]));
                STRIPS[i].show();
              } 
              if(i>0 && i<10){
                STRIPS[i-1].setPixelColor(j, STRIPS[i-1].Color(
                  RGB_values[3], RGB_values[4], RGB_values[5]));
                STRIPS[i-1].show();
              }                           
            }
          }
          delay(DELAYVAL_TAIL_1);
          for(int l = 0; l < (sizeof(STRIPS) / sizeof(STRIPS[0])); l++){
            STRIPS[l].clear();
            STRIPS[l].show();
          }
          //-------------------------------------------------------------------
        }
      }
      //-------------------------------------------------------------------
      // TAIL_LENGTH == 0
      if(TAIL_LENGTH == 0){
        // Choose which LED strip to be brightest, iterate through all strips
        for(int i = 0; i <= (sizeof(STRIPS) / sizeof(STRIPS[0])); i++) {
          // Iterate through all LEDs on the brightest LED strip
          for(int j = 0; j < LED_COUNT; j++){
            // If an LED should be ON, turn it on and also turn the same LEDs
            // in lower strips on, but less bright, so they form the trail
            if(LEDS_ON_OR_OFF[j] == 1){
              if(i<9){
                STRIPS[i].setPixelColor(j, STRIPS[i].Color(
                  RGB_values[0], RGB_values[1], RGB_values[2]));
                STRIPS[i].show();
              }                                       
            }
          }
          delay(DELAYVAL_TAIL_0);
          for(int l = 0; l < (sizeof(STRIPS) / sizeof(STRIPS[0])); l++){
            STRIPS[l].clear();
            STRIPS[l].show();
          }
          //-------------------------------------------------------------------
        }
      }
      //-----------------------------------------------------------------------
      // "FRO" DIRECTION
      //-------------------------------------------------------------------
      // TAIL_LENGTH == 3
      if(TAIL_LENGTH == 3){
        // Choose which LED strip to be brightest, iterate through all strips
        for(int i = (sizeof(STRIPS) / sizeof(STRIPS[0]))-1; i>=-4; i--) {
          // Iterate through all LEDs on the brightest LED strip
          for(int j = 0; j < LED_COUNT; j++){
            // If an LED should be ON, turn it on and also turn the same LEDs
            // in lower strips on, but less bright, so they form the trail
            if(LEDS_ON_OR_OFF[j] == 1){
              if(i>-1){
                STRIPS[i].setPixelColor(j, STRIPS[i].Color(
                  RGB_values[0], RGB_values[1], RGB_values[2]));
                STRIPS[i].show();
              }
              if(i<8 && i>-2){
                STRIPS[i+1].setPixelColor(j, STRIPS[i+1].Color(
                  RGB_values[3], RGB_values[4], RGB_values[5]));
                STRIPS[i+1].show();
              }
              if(i<7 && i>-3){
                STRIPS[i+2].setPixelColor(j, STRIPS[i+2].Color(
                  RGB_values[6], RGB_values[7], RGB_values[8]));
                STRIPS[i+2].show();
              }
              if(i<6 && i>-4){
                STRIPS[i+3].setPixelColor(j, STRIPS[i+3].Color(
                  RGB_values[9], RGB_values[10], RGB_values[11]));
                STRIPS[i+3].show();
              } 
            }
          }
          delay(DELAYVAL_TAIL_3);
          for(int l = 0; l < (sizeof(STRIPS) / sizeof(STRIPS[0])); l++){
            STRIPS[l].clear();
            STRIPS[l].show();
          }
          //-------------------------------------------------------------------
        }
      }
      //-------------------------------------------------------------------
      // TAIL_LENGTH == 2
      if(TAIL_LENGTH == 2){
        // Choose which LED strip to be brightest, iterate through all strips
        for(int i = (sizeof(STRIPS) / sizeof(STRIPS[0]))-1; i>=-3; i--) {
          // Iterate through all LEDs on the brightest LED strip
          for(int j = 0; j < LED_COUNT; j++){
            // If an LED should be ON, turn it on and also turn the same LEDs
            // in lower strips on, but less bright, so they form the trail
            if(LEDS_ON_OR_OFF[j] == 1){
              if(i>-1){
                STRIPS[i].setPixelColor(j, STRIPS[i].Color(
                  RGB_values[0], RGB_values[1], RGB_values[2]));
                STRIPS[i].show();
              }
              if(i<8 && i>-2){
                STRIPS[i+1].setPixelColor(j, STRIPS[i+1].Color(
                  RGB_values[3], RGB_values[4], RGB_values[5]));
                STRIPS[i+1].show();
              }
              if(i<7 && i>-3){
                STRIPS[i+2].setPixelColor(j, STRIPS[i+2].Color(
                  RGB_values[6], RGB_values[7], RGB_values[8]));
                STRIPS[i+2].show();
              }              
            }
          }
          delay(DELAYVAL_TAIL_2);
          for(int l = 0; l < (sizeof(STRIPS) / sizeof(STRIPS[0])); l++){
            STRIPS[l].clear();
            STRIPS[l].show();
          }
          //-------------------------------------------------------------------
        }
      }
      //-------------------------------------------------------------------
      // TAIL_LENGTH == 1
      if(TAIL_LENGTH == 1){
        // Choose which LED strip to be brightest, iterate through all strips
        for(int i = (sizeof(STRIPS) / sizeof(STRIPS[0]))-1; i>=-2; i--) {
          // Iterate through all LEDs on the brightest LED strip
          for(int j = 0; j < LED_COUNT; j++){
            // If an LED should be ON, turn it on and also turn the same LEDs
            // in lower strips on, but less bright, so they form the trail
            if(LEDS_ON_OR_OFF[j] == 1){
              if(i>-1){
                STRIPS[i].setPixelColor(j, STRIPS[i].Color(
                  RGB_values[0], RGB_values[1], RGB_values[2]));
                STRIPS[i].show();
              }
              if(i<8 && i>-2){
                STRIPS[i+1].setPixelColor(j, STRIPS[i+1].Color(
                  RGB_values[3], RGB_values[4], RGB_values[5]));
                STRIPS[i+1].show();
              }                           
            }
          }
          delay(DELAYVAL_TAIL_1);
          for(int l = 0; l < (sizeof(STRIPS) / sizeof(STRIPS[0])); l++){
            STRIPS[l].clear();
            STRIPS[l].show();
          }
          //-------------------------------------------------------------------
        }
      }
      //-------------------------------------------------------------------
      // TAIL_LENGTH == 0
      if(TAIL_LENGTH == 0){
        // Choose which LED strip to be brightest, iterate through all strips
        for(int i = (sizeof(STRIPS) / sizeof(STRIPS[0]))-1; i>=-1; i--) {
          // Iterate through all LEDs on the brightest LED strip
          for(int j = 0; j < LED_COUNT; j++){
            // If an LED should be ON, turn it on and also turn the same LEDs
            // in lower strips on, but less bright, so they form the trail
            if(LEDS_ON_OR_OFF[j] == 1){
              if(i>-1){
                STRIPS[i].setPixelColor(j, STRIPS[i].Color(
                  RGB_values[0], RGB_values[1], RGB_values[2]));
                STRIPS[i].show();
              }                                        
            }
          }
          delay(DELAYVAL_TAIL_0);
          for(int l = 0; l < (sizeof(STRIPS) / sizeof(STRIPS[0])); l++){
            STRIPS[l].clear();
            STRIPS[l].show();
          }
          //-------------------------------------------------------------------
        }
      }
    }
  }
}

//--------------------------------------------------------------------
//---------------------------USER INTERFACE---------------------------
//--------------------------------------------------------------------
// NOTE: THE PROGRAM MUST BE UPLOADED TO THE ARDUINO BEFORE USE.
// THIS CAN BE DONE BY CLICKING "UPLOAD" IN THE ARDUINO IDE INTERFACE
//--------------------------------------------------------------------
// NOTE: THE CORRECT PORT MUST BE CHOSEN IN THE ARDUINO IDE VIA
// "Tools" -> "Port" -> select the available port in the droupdown menu.
//--------------------------------------------------------------------
// Please define how many of the 36 LEDs are to be covered by the light oscillations
// A quadrant is equal to an oscillation length of 9.
// Please use the following format: OSCILLATION_LENGTH = 9;
// (don't forget the semicolon at the end!!)
//-----------------------------
byte OSCILLATION_LENGTH = 9;
//-----------------------------
//-----------------------------
// Please define the oscillation frequency in Hz below.
// Please note that 1 Hz is defined as 1 full oscillation per second,
// i.e. once from left to right and from right to left again.
// Please use the following format: FREQUENCY = 1.23;
// (don't forget the semicolon at the end!!)
// Maximum frequency for e.g. OSCILLATION_LENGTH = 9: 3 Hz
// Maximum frequency for e.g. OSCILLATION_LENGTH = 20: 1.3 Hz
//-----------------------------
float FREQUENCY = 1;
//-----------------------------
//-----------------------------
// Please define the color of the LEDs below by changing the strength of
// the RED, GREEN and BLUE values, which will mix to give one color.
// Each value ranges from 0 to 255.
// Please use the following format: RED = 123;
// (don't forget the semicolon at the end!!)
// For color mixing examples visit https://www.rapidtables.com/web/color/RGB_Color.html
//-----------------------------
byte RED = 1;
byte GREEN = 1;
byte BLUE  = 1;
//-----------------------------
//-----------------------------
// Please define for how long the program is to run (in seconds)
// Please use the following format: float program_duration = 14.7;
// (don't forget the semicolon at the end!!)
//-----------------------------
float program_duration = 30;
//-----------------------------
//-----------------------------
// Please choose which of the LED strips are ON and which are OFF.
// Strip 9 is the highest strip in the cylinder, strip 1 the lowest.
// Strip number X is ON, if its variable "int strip_X_on_or_off" is equal
// to 1. It is turned OFF, if the variable is equal to 0.
// Please use the following format: int strip_1_on_or_off = 1;
// (don't forget the semicolon at the end!!)
//-----------------------------
byte strip_9_on_or_off = 0;
byte strip_8_on_or_off = 0;
byte strip_7_on_or_off = 0;
byte strip_6_on_or_off = 0;
byte strip_5_on_or_off = 0;
byte strip_4_on_or_off = 0;
byte strip_3_on_or_off = 0;
byte strip_2_on_or_off = 1;
byte strip_1_on_or_off = 0;
//--------------------------------------------------------------------
//----------------------END OF USER INTERFACE-------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//--------------------------------------------------------------------
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

// Pack the strip ON/OFF objects into an array 
// for easier calling by for loops etc.
byte STRIPS_ON_OR_OFF[] = {
  strip_1_on_or_off,strip_2_on_or_off,strip_3_on_or_off,
  strip_4_on_or_off,strip_5_on_or_off,strip_6_on_or_off,
  strip_7_on_or_off,strip_8_on_or_off,strip_9_on_or_off};

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
byte LED_COUNT = 36; // 35 active ones plus the inactive one in front  

// Define the delay time after each lighting step in ms.
// Its value is calculated in the setup section
float DELAYVAL;



// Declare our NeoPixel strip object:
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
//--------------------------ROTARY ENCODER-----------------------------
//---------------------------------------------------------------------
// Define to which pins the encoder is connected
static byte pinA = 2; // Our first hardware interrupt pin is digital pin 2
static byte pinB = 3; // Our second hardware interrupt pin is digital pin 3
// Define some counter variables
volatile byte aFlag = 0; // let's us know when we're expecting a rising edge on pinA to signal that the encoder has arrived at a detent
volatile byte bFlag = 0; // let's us know when we're expecting a rising edge on pinB to signal that the encoder has arrived at a detent (opposite direction to when aFlag is set)
volatile int encoderPos = 0; //this variable stores our current value of encoder position. Change to int or uin16_t instead of byte if you want to record a larger range than 0-255
volatile int oldEncPos = 0; //stores the last encoder position value so we can compare to the current reading and see if it has changed (so we know when to print to the serial monitor)
volatile byte reading = 0; //somewhere to store the direct values we read from our interrupt pins before checking to see if we have moved a whole detent
//---------------------------------------------------------------------
//----------------------DEFINE COUNTER VARIABLES----------------------
//---------------------------------------------------------------------
volatile int i = 1;
// i is used for determining which LEDs are on at a given time. It can be increased or decreased using the rotary encoder, thereby shifting the light to the left or the right
//volatile int ilower = 1; // ilower sets the lower limit for i
//volatile int iupper = LED_COUNT/4; // iupper sets the upper limit for i
//---------------------------------------------------------------------
//-----------------------------SETUP CODE------------------------------
//---------------------------------------------------------------------
void setup() {
  if(FREQUENCY >= 1000/(20.6 * (2 * OSCILLATION_LENGTH - 2))){DELAYVAL = 0;}
  else{DELAYVAL = 1000/((2 * OSCILLATION_LENGTH - 2)*FREQUENCY) - 20.6;}
  
  // Get the strips ready and delete any old color settings
  for(int m = 0; m < (sizeof(STRIPS) / sizeof(STRIPS[0])); m++){
  STRIPS[m].begin();
  STRIPS[m].show();
  STRIPS[m].clear();
  STRIPS[m].show();
  STRIPS[m].clear();
  STRIPS[m].show();
  }
  //---------------------------------------------------------------------
  // Ensure that the RGB values aren't rounded down to zero if 
  // they are below one but initially above zero, 
  // as that makes the light trail shorter and makes problems.
  for (int m = 0; m < (sizeof(RGB_values) / sizeof(RGB_values[0])); m++) {
    if(RGB_values[m] < 1 && RGB_values[i] != 0){
      RGB_values[m] = 1;
    }
  }
  //---------------------------------------------------------------------
  // Define button no. 1 to an input giver
  pinMode(buttonPin1, INPUT);
  //---------------------------------------------------------------------
  // Define the two signals from the rotary encoder as inputs
  pinMode(pinA, INPUT_PULLUP); // set pinA as an input, pulled HIGH to the logic voltage (5V or 3.3V for most cases)
  pinMode(pinB, INPUT_PULLUP); // set pinB as an input, pulled HIGH to the logic voltage (5V or 3.3V for most cases)
  attachInterrupt(0,PinA,RISING); // set an interrupt on PinA, looking for a rising edge signal and executing the "PinA" Interrupt Service Routine (below)
  attachInterrupt(1,PinB,RISING); // set an interrupt on PinB, looking for a rising edge signal and executing the "PinB" Interrupt Service Routine (below)
  // Begin communications with the serial monitor
  Serial.begin(9600); // start the serial monitor link
}
//---------------------------------------------------------------------
//------------------ROTARY ENCODER INTERRUPT PROGRAMS------------------
//---------------------------------------------------------------------
void PinA(){
  cli(); //stop interrupts happening before we read pin values
  reading = PIND & 0xC; // read all eight pin values then strip away all but pinA and pinB's values
  if(reading == B00001100 && aFlag) { //check that we have both pins at detent (HIGH) and that we are expecting detent on this pin's rising edge
    encoderPos --; //decrement the encoder's position count
    bFlag = 0; //reset flags for the next turn
    aFlag = 0; //reset flags for the next turn
    Serial.print("Position: ");
    Serial.println(encoderPos);
    i --; // decrease the LED position counter variable by one so as to shift the light trail
    if(i == 0){
      i = 35;
    }
  }
  else if (reading == B00000100) bFlag = 1; //signal that we're expecting pinB to signal the transition to detent from free rotation
  sei(); //restart interrupts
}
//---------------------------------------------------------------------
void PinB(){
  cli(); //stop interrupts happening before we read pin values
  reading = PIND & 0xC; //read all eight pin values then strip away all but pinA and pinB's values
  if (reading == B00001100 && bFlag) { //check that we have both pins at detent (HIGH) and that we are expecting detent on this pin's rising edge
    encoderPos ++; //increment the encoder's position count
    bFlag = 0; //reset flags for the next turn
    aFlag = 0; //reset flags for the next turn
    Serial.print("Position: ");
    Serial.println(encoderPos);
    i ++; // increase the LED position counter variable by one so as to shift the light trail
    if(i == 36){
      i = 1;
    }
  }
  else if (reading == B00001000) aFlag = 1; //signal that we're expecting pinA to signal the transition to detent from free rotation
  sei(); //restart interrupts
}
//---------------------------------------------------------------------
//-----------------------------LOOP CODE-------------------------------
//---------------------------------------------------------------------
void loop() {
//---------------------------------------------------------------------
//-----------------------------LED STRIPS------------------------------
//---------------------------------------------------------------------
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
      //-------------------------------------------------------------------
      //-------------------------------------------------------------------
      // "TO" DIRECTION
      // Choose which LED to be brightest, iterate through all LEDs
      for(int counter = 1; counter < OSCILLATION_LENGTH; counter++) { 
        // Iterate through all strips
        for(int j = 0; j <= sizeof(STRIPS) / sizeof(STRIPS[0]); j++){
          // If a strip should be ON, turn LED i on on that strip and also turn
          // the LEDs left of it on, but less bright, so they form the trail
          if(STRIPS_ON_OR_OFF[j] == 1){            
            STRIPS[j].setPixelColor(i, STRIPS[j].Color(
              RGB_values[0], RGB_values[1], RGB_values[2]));
            STRIPS[j].show();            
          }          
        }
        //-------------------------------------------------------------------
        delay(DELAYVAL);
        //-------------------------------------------------------------------
        for(int l = 0; l < (sizeof(STRIPS) / sizeof(STRIPS[0])); l++){
          STRIPS[l].clear();
          STRIPS[l].show();
        }
        //-------------------------------------------------------------------
        i++;
        if(i == 36){
          i = 1;
        }
        //-------------------------------------------------------------------
      }     
    //-------------------------------------------------------------------  
    //-------------------------------------------------------------------
      // "FRO" DIRECTION
      // Choose which LED to be brightest, iterate through all LEDs
      for(int counter = 1; counter < OSCILLATION_LENGTH; counter++) {
        // Iterate through all strips
        for(int j = 0; j <= sizeof(STRIPS) / sizeof(STRIPS[0]); j++){
          // If a strip should be ON, turn LED i on on that strip and also turn
          // the LEDs right of it on, but less bright, so they form the trail
          if(STRIPS_ON_OR_OFF[j] == 1){
            STRIPS[j].setPixelColor(i, STRIPS[j].Color(
              RGB_values[0], RGB_values[1], RGB_values[2]));
            STRIPS[j].show();
          }
        }
        //-------------------------------------------------------------------
        delay(DELAYVAL);
        //-------------------------------------------------------------------
        for(int l = 0; l < (sizeof(STRIPS) / sizeof(STRIPS[0])); l++){
          STRIPS[l].clear();
          STRIPS[l].show();
        }
        //-------------------------------------------------------------------
        i--;
        if(i == 0){
          i = 35;
        }
      }
    }
  }
}

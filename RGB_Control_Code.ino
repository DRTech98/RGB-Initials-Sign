#include <IRremote.hpp> //Includes the IR remote library
int RECV_PIN = 2; //Declares the TSOP4838 IR Reciever as pin 2
IRrecv irrecv(RECV_PIN); //Call the declared pin
decode_results results; //Set the variable as results to be decoded
#include <Adafruit_NeoPixel.h> //Include the Neopixel librar
#include "WS2812_Definitions.h" //Include the WS2812 library, though we are using a clone it behaves the same with just a different pinout

int delaytime = 5;  //Set delaytime to 5ms
String myResults;   //Declaring string variable
int LEDPIN = 6;     //Set RGB pin as pin 6 on the Arduino Uno
int NUMPIXELS = 24; //Declare the number of pixels you are using
float defact = 1;
int Counter = 0;    //Set counter to 0, will be used to keep track of button presses for the POWER button
int colorARRY[3];   //Declare a static array of 3, this will be used to store the 3 primary colors (RED,BLUE, GREEN)
int RX = 125;       //Preset the Red color at 125
int GY = 125;       //Preset the Green color at 125
int BZ = 125;       //Preset the BLUE color at 125
bool ON;            //Boolean statement, after POWER is pressed and when true the user can change the colors,
                    //When false the user cannot change colors unitl the power button is pressed again



Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800); //Set the number of pixels, led pin, primary colors and frequency

void setup() {
  
Serial.begin(9600); //Serial monitor output
IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
strip.begin(); //Begin the neopixel strip

}


void loop() {



if (IrReceiver.decode()) {
  IrReceiver.resume(); // Enable receiving of the next value  

if (IrReceiver.decodedIRData.decodedRawData == 0xBA45FF00){ //IF this value is decoded...
myResults = "Power"; //Set string to power
Serial.println(myResults); //Serial print string
Counter = Counter + 1; //Advance the counter by one

  for (int i =0;i<24;i++) //Increment i by one until it reaches 24 as that was declared as the number of pixels
    {
      colorARRY[i] = RX, GY,BZ; //Set the static array equal to the variables we delcared earlier in the scope
      strip.setPixelColor(i, strip.Color(RX,GY,BZ)); //Set the strip to the i increement to assign each led to the respective variables
      strip.show(); //Begin the neopixel strip
      delay(delaytime); //Set delay to delaytime
      ON = true; //Set boolean of ON to true so the user can change the colors
    }

}

if (Counter %2 == 0){ //If counter is NOT divisible by 2...
myResults = "Power Off"; //Set string to power off
Serial.println(myResults); //Serial print string
   for (int i =0;i<24;i++) //Increment i by one until it reaches 24 as that was declared as the number of pixels
    {
      strip.setPixelColor(i, strip.Color(0,0,0)); //Set the strip to 0 for all primary colors
      strip.show(); //Begin the neopixel strip
      delay(delaytime); //Set delay to delaytime
      ON = false; //Set boolean of ON to false so the user cannot change the colors
    }

 }
 
if (IrReceiver.decodedIRData.decodedRawData == 0xC916FF00&&ON==true){ //IF this value is decoded and boolean set to ture 
myResults = "RED"; //Set string to RED
Serial.println(myResults); //Serial print string


  for (int i =0;i<24;i++) //Increment i by one until it reaches 24 as that was declared as the number of pixels
    {
      RX = 255; //Set RX to 255
      GY = 0;   //Set GY to 0
      BZ = 0;   //Set BZ to 0

      colorARRY[i] = RX, GY,BZ; //Set the static array equal to the variables we delcared earlier in the scope
      strip.setPixelColor(i, strip.Color(RX,GY,BZ)); //Set the strip to the i increement to assign each led to the respective variables
      strip.show(); //Begin the neopixel strip
      delay(delaytime); //Set delay to delaytime
    }

}



 if (IrReceiver.decodedIRData.decodedRawData == 0xC30CFF00&&ON==true){ 
myResults = "Green"; 
Serial.println(myResults); 


  for (int i =0;i<24;i++) 
    {
      RX = 0;
      GY = 255;
      BZ = 0;

      colorARRY[i] = RX,GY,BZ;
      strip.setPixelColor(i, strip.Color(RX,GY,BZ));
      strip.show();
      delay(delaytime);
    }

}


 if (IrReceiver.decodedIRData.decodedRawData == 0xCA15FF00&&ON==true){
myResults = "Minus";
Serial.println(myResults);


  for (int i =0;i<24;i++)
    {
   
      
      colorARRY[i] = RX, GY,BZ;
      strip.setPixelColor(i, strip.Color(RX,GY,BZ));
      

      
      }
      int x = strip.getBrightness();
       if (x>15){ //If the variable x is greater than 15 (15 to 255 bits as its an 8 bit protocol)
        strip.setBrightness(x-15); //Used the setBrightness function to decrease the brightness of the LEDs from its set brighness up to 15
        strip.show();
        delay(delaytime);
        
      
    }

}

if (IrReceiver.decodedIRData.decodedRawData == 0xB946FF00&&ON==true){
myResults = "Plus";
Serial.println(myResults); 


  for (int i =0;i<24;i++)
    {
      colorARRY[i] = RX, GY,BZ;
      strip.setPixelColor(i, strip.Color(RX,GY,BZ));
    

     
      }
      int y = strip.getBrightness();
      if (y<255){ //If the variable y is less than 255 (15 to 255 bits as its an 8 bit protocol)
        strip.setBrightness(y+15); //Used the setBrightness function to increase the brightness of the LEDs from its set brightness up to 255
        strip.show();
        delay(delaytime);
    }

}

if (IrReceiver.decodedIRData.decodedRawData == 0xE718FF00&&ON==true){
myResults = "Blue";
Serial.println(myResults);


  for (int i =0;i<24;i++)
    {
      RX = 0;
      GY = 0;
      BZ = 255;

      colorARRY[i] = RX, GY,BZ;
      strip.setPixelColor(i, strip.Color(RX,GY,BZ));
      strip.show();
      delay(delaytime); 
    }

}

if (IrReceiver.decodedIRData.decodedRawData == 0xA15EFF00&&ON==true){
myResults = "Yellow";
Serial.println(myResults);


  for (int i =0;i<24;i++)
    {
      RX = 255;
      GY = 255;
      BZ = 0;

      colorARRY[i] = RX, GY,BZ;
      strip.setPixelColor(i, strip.Color(RX,GY,BZ));
      strip.show();
      delay(delaytime); 
    }

}

if (IrReceiver.decodedIRData.decodedRawData == 0xC708FF00&&ON==true){
myResults = "Cyan";
Serial.println(myResults);


  for (int i =0;i<24;i++)
    {
      RX = 72;
      GY = 189;
      BZ = 187;

      colorARRY[i] = RX, GY,BZ;
      strip.setPixelColor(i, strip.Color(RX,GY,BZ));
      strip.show();
      delay(delaytime); 
    }

}

if (IrReceiver.decodedIRData.decodedRawData == 0xE31CFF00&&ON==true){
myResults = "Magenta";
Serial.println(myResults);


  for (int i =0;i<24;i++)
    {
      RX = 255;
      GY = 0;
      BZ = 255;

      colorARRY[i] = RX, GY,BZ;
      strip.setPixelColor(i, strip.Color(RX,GY,BZ));
      strip.show();
      delay(delaytime); 
    }

}

if (IrReceiver.decodedIRData.decodedRawData == 0xA55AFF00&&ON==true){
myResults = "Orange";
Serial.println(myResults);


  for (int i =0;i<24;i++)
    {
      RX = 255;
      GY = 140;
      BZ = 0;

      colorARRY[i] = RX, GY,BZ;
      strip.setPixelColor(i, strip.Color(RX,GY,BZ));
      strip.show();
      delay(delaytime); 
    }

}

if (IrReceiver.decodedIRData.decodedRawData == 0x8D42FF00&&ON==true){
myResults = "Pink";
Serial.println(myResults);


  for (int i =0;i<24;i++)
    {
      RX = 255;
      GY = 105;
      BZ = 180;

      colorARRY[i] = RX, GY,BZ;
      strip.setPixelColor(i, strip.Color(RX,GY,BZ));
      strip.show();
      delay(delaytime); 
    }

}

if (IrReceiver.decodedIRData.decodedRawData == 0xAD52FF00&&ON==true){
myResults = "White";
Serial.println(myResults);


  for (int i =0;i<24;i++)
    {
      RX = 125;
      GY = 125;
      BZ = 125;

      colorARRY[i] = RX, GY,BZ;
      strip.setPixelColor(i, strip.Color(RX,GY,BZ));
      strip.show();
      delay(delaytime); 
    }

}


IrReceiver.resume(); //Resume the IrReceiver so it doesn't get stuck on the previous code it recieved, updating it each time a button is pressed

}

}

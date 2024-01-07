#include <IRremote.hpp> //Includes the IR remote library
int RECV_PIN = 2; //Declares the TSOP4838 IR Reciever as pin 2
IRrecv irrecv(RECV_PIN); //Call the declared pin
decode_results results; //Set the variable as results to be decoded
String myResults; //Declaring string variable

void setup()
{
Serial.begin(9600); //Serial monitor output
IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop() {
if (IrReceiver.decode()) {
Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
/* USE NEW 3.x FUNCTIONS */
IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
IrReceiver.printIRSendUsage(&Serial); // Print the statement required to send this data
IrReceiver.resume(); // Enable receiving of the next value

if (IrReceiver.decodedIRData.decodedRawData == 0xCA15FF00){ //IF this value is decoded...
delay(100); //Set delay to 100ms
myResults = "Minus"; //Set string to minus
Serial.println(myResults); //Serial print my results (Used to see if the remote is actually communicating with the IR reciever)
}
IrReceiver.resume(); //Resume the IR receiver so that it doesn't get stuck on a particular code
}




//Codes used for each funciton:
//BA45FF00 - Power - ON/OFF Button
//C916FF00 - 0 - RED
//C30CFF00 - 1 - GREEN
//E718FF00 - 2 - BLUE
//A15EFF00 - 3 - YELLOW
//C708FF00 - 4 - CYAN 
//E31CFF00 - 5 - MAGENTA
//A55AFF00 - 6 - ORANGE 
//8D42FF00 - 7 - PINK
//AD52FF00 - 8 - WHITE
//B54AFF00 - 9 - Theater Chase
//E619FF00 - EQ - Rainbow
//CA15FF00 - - BUTTON FOR BRIGHTNESS CONTROL
//B946FF00 - + BUTTON FOR BRIGHTNESS CONTROL





 



}

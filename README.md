# RGB-Initials-Sign
A redo of a project I attempted at the end of 2022 involving an IR remote, WS2812b RGB LED clones (IN-PI554FCH), where depending on what button is pressed on the remote determines the color that would be shown on the RGB LED. Brightness control was also another feature where if the user would press the VOL + button the brightness would be increased and the VOL- button would decrease the brightness. 

At first, I used the RGB breakout board (which can be found here: https://github.com/DRTech98/RGB-LED-Breakout-Board) I designed to prototype the idea using an Arduino Uno, however, I did not complete the prototype stage. I did not fully complete the code or hardware integration to match the pins that were used from the Arduino Uno to the Atmega32u4 I was using. The IR receiver I chose from Digikey was the TSSP58038, which is used for light barriers, not for remote controls. Here is a list of several other issues that the board had originally:

1. Used the AP62201WU-7 to step down the voltage from 5V to 3V3 which was not necessary as the high current part of the circuit is powered by the 5V USB.
2. The LED connected to the TSSP58038 is pulled high, causing the LED to be on at all times.
3. No power-good LED is present to check if the 5V is properly giving power.
4. MCU is missing two 100nF capacitors and a push button to properly bootload.
5. The pin header footprint is too small to work with the USBasp programmer.
6. TVS diodes for the ICSP header are unnecessary.
7. The Pi filter for filtering and creating cutoff frequency via USB connector is not needed, as this project has low speed and frequency complicates the design, and increases the cost of BOM.
8. Missing USB to UART communication for USB-C connector, PCB could be bootloaded and programmed via USBasp but not the USB-C connector.

This new version corrects all of these mistakes and cleans up the overall design, with proper testing and implementation of code to finish the original idea that was started in 2022. 

Several parts are pre-assembled from PCBWay, all components on the board are surface mount with 0.5mm traces for power, 0.3mm for signal and a (Put # of layers here) board, files included have the BOM, schematic, PCB, gerber files, and CPL files for the manufacturer. 

The RGB sign is a great example of a beginner project involving the communication of hardware and firmware, and covered power regulation, UART communication protocol, PWM, ICSP, along with the fundamentals of programming.

Much of the code I wrote to control the LEDS includes for loops, booleans, a static array to store the color pixels, if statements, and functions to set the brightness and store the color data depending on what code is received from the remote. 

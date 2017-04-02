# VIP Badge - New Orleans Maker Faire 2017
Badge code and instructions for the 2017 NOLA Mini Maker Faire VIP Badge Kit

You can purchase your VIP tickets for the 2017 New Orleans Mini Maker Faire at: 
https://www.eventbrite.com/e/2017-new-orleans-mini-maker-faire-tickets-29504311189

This kit is included with the purchase of the VIP ticket. One kit per VIP ticket.

Be creative! The components chosen for this design were picked with the intention
that you would want to customize your badge to make it your own. Paint it, stain it, 
change the program, add more components, etc. 

If you need help building/customizing your badge, we will have a meetup on April 13th at
the Delgado FabLab at 5pm. 

## Components

The following components are included in the 2017 VIP Badge Kit:

- Arduino Pro Micro with ATmega32U4 5V/16MHz 
- White 128X64 0.96 inch OLED with SPI
- 3 x AAA Battery Pack
- Blue 5mm LED (quantity 3)
- 560 Ohm Resistor, 1/4 W, 5%
- Neck lanyard

## What you'll need

Gather these tools before starting on your build and it will go much smoother!

- Soldering iron and solder
- CA glue (Superglue)
- Hot glue and gun
- 26 gauge hookup wire
- 7/32 drill bit
- Flush cut wire cutters or small snips
- Micro USB cable
- Computer with the Arduino IDE loaded

## Completed Example Badge

Front Side | Back Side
---------- | ---------
![Badge Front](https://raw.githubusercontent.com/zagnut007/MakerFaire2017/master/images/front.jpg) | ![Badge Back](https://raw.githubusercontent.com/zagnut007/MakerFaire2017/master/images/back.jpg)

## Building your badge

Please read and review these instructions before starting your build.

### Step 1: Glue the two chassis layers together
  - Use the CA glue to glue the layers together
  - The bottom-right corner of the top layer should be offet from the edge of the base layer by 3mm from the right and 3mm from the bottom
  - The upper-left corner of the top layer should have a 1mm offset from the left and top of the base layer
  - You can choose which internal/cut pieces to glue on or leave out

### Step 2: Drill out the LED holes
  - If you intend to install the included LEDs, you will want to drill out three holes in the spaces provided just above the "VIP"
  - Be sure to use a backer board when drilling to reduce blowout
  - Use the 7/32 or 5mm drill bit to make the holes

### Step 3: Install the LEDs
  - Use hot glue to secure the LEDs
  - It is recommended you orient the LEDs in the same direction as you will be soldering the negative leads together with the resistor
  - The short lead is the negative lead
    - Solder the three short leads to either end of the 560 ohm resistor
    - Connect the other end of the resistor to a piece of hookup wire. This will be soldered to the Arduino after you have mounted the Arduino to the badge

### Step 4: Mount Arduino and OLED
  - To mount the Arduino:
  	- Add a good bead of hot glue to the bottom of the Arduino (USB port is top side) and place in the lower-left area of the badge.
  	- Be sure the access holes and the pin holes in the Arudino line up so you have access to all pin holes
  - To mount the OLED:
  	- Add a good blob of hot glue to each corner of the bottom of the OLED and place in the upper-right corner of the badge
  	- Hold the OLED level until the glue cools
  	- Be sure no hot glue covers the 6 pin holes at the top of the OLED
  	- The pin holes of the OLED should face up (towards the lanyard when wearing the badge)

### Step 5: Wiring things up
  - Leave ROOM for the battery pack
  	- When looking at the back of the badge, the battery pack will mount to the flat area above the Arduino access holes and to the side of the OLED access hole.
  	- Be sure to route your wires around this area
  	- We will be using the RAW and GND located on the upper portion of the Arduino for the battery pack when that piece is installed later
  - Wire the LEDs first
    - Route the wires down, then make a 90 degree turn to the Arduino
  	- Cut the leads short and don't leave too much exposed wire to keep from shorting anything out
  	- The positive leads of the LEDs go to pins 2, 3, and 4 on the Arduino
  	- The combined negative lead of the LEDs that is connected to the resistor goes to one of the GND (ground) pins on the lower portion of the Arduino
  	- You can use hot glue to insulate the positive leads from touching the negative leads
  - Wire the OLED
    - Route the wires down, over the LEDs, then make a 90 degree turn to the Arduino
  	- The VCC on the OLED should connect to the VCC on Arduino
  	- The GND on the OLED should connect to 2nd GND pin on the lower portion of the Arduino
  	- The other 4 OLED pins should connect as described in the sketch file
  		- OLED D/C => Pin 8
  		- OLED SDA => Pin 9
  		- OLED CLK => Pin 10
  		- OLED RST => Pin 14
  - Secure the loose hookup wires with a few dabs of hot glue if desired

### Step 6: Test and load sketch
  - Once you plug in the USB cable and load the sketch, the Arduino will be powered up. You will not need the battery pack yet.
  - The sketch provided requires two libraries that provide functionality to connect to the OLED. The URLs for these libraries is at the top of the sketch/source code.
  - If using the default sketch, be sure to change the name constant on line 39 to your name
  - If everything was connected properly, you should see the LEDs and OLED turn on and be working

### Step 7: Mount the battery pack
  - Hot glue the batter pack with the leads facing down and the On/Off switch facing out
  - Solder the red lead to the RAW pin on the Arduino
  - Solder the black lead to the GND pin next to the RAW pin on the Arduino
  - Install three AAA batteries and turn it on!

### Step 8: Install the lanyard and show off your build!

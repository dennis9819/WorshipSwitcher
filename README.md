# WorshipSwitcher
Worship switcher is a simple device for switching chord-sheet pages on the fly.

## Hardware
WorshipSwitcher is designed arround the Arduino Pro Micro and the Digispark. All you need to build your own is:
* Arduino Pro Micro (Make sure it is a Pro Micro and not a Pro Mini) or Digispark
* Two push buttons

### Wiring for the Arduino Pro Micro
The Push-Buttons connect to Pin 8 and 9. Pins 8 and 9 are configured as active-low with internal pushup resistors. Therefore the switches need to be connected against ground.

### Wiring for the Digispark
The Push-Buttons connect to P0 and P2. Pins P0 and P2 are configured as active-low with internal pushup resistors. Therefore the switches need to be connected against ground.
Pin P1 is connected to the internal LED. It blinks when the USb Keybioard is initialized and it is ready to be used.

## Software
The firmware is designed for Acrobat Reader for iOS in Single Page mode. It also works with OnSong. 

The mapped keycodes are PAGE_UP and PAGE_DOWN.
In onsong, this mimics the behaviour of the AirTurn Pedals and can be mapped to various functions. 

## Usage
### Button 1 - Back / Top
Button 1 has a primary and secondary function, depending on the time the button is pressed:
* less than 1 1/2 seconds: previous page
* more than 1 1/2 seconds: go to first page

### Button 2 - Next
Button 2 switches to the next page
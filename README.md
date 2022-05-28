# WorshipSwitcher
Worship switcher is a simple device for switching chord-sheet pages on the fly.

## Hardware
WorshipSwitcher is designed arround the Arduino Pro Micro. All you need to build your own is:
* Arduino Pro Micro (Make sure it is a Pro Micro and not a Pro Mini)
* Two push buttons

The Push-Buttons connect to Pin 8 and 9. Pins 8 and 9 are configured as active-low with internal oush.up resistors. Therefore the switches need to be connected against ground.

## Software
The firmware is designed for Acrobat Reader for iOS in Single Page mode.

## Usage
### Button 1 - Back / Top
Button 1 has a primary and secondary function, depending on the time the button is pressed:
* less than 1 1/2 seconds: previous page
* more than 1 1/2 seconds: go to first page

### Button 2 - Next
Button 2 switches to the next page
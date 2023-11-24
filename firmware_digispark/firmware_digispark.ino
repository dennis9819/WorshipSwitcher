#include "DigiKeyboard.h"

#define SW_1_PIN 0
#define SW_2_PIN 2
#define debounceTimeConst 200   //debounce time in ms

unsigned long sw1_debounce = 0; //debounce var (last time button was pressed)
unsigned long sw2_debounce = 0; //debounce var (last time button was pressed)
void setup() {
  // don't need to set anything up to use DigiKeyboard
  pinMode(SW_1_PIN, INPUT_PULLUP);
  pinMode(SW_2_PIN, INPUT_PULLUP);
  DigiKeyboard.sendKeyStroke(0);  
  DigiKeyboard.delay(100);
}

int ledState = LOW;  // ledState used to set the LED
unsigned long previousMillis = 0;  // will store last time LED was updated


void loop() {
  unsigned long now = millis();           //timestamp of start of loop
  // debounce button 1
  if(digitalRead(SW_1_PIN) == false){
    if(sw1_debounce + debounceTimeConst < now){
      unsigned long pressed = millis();   //store time when button is pressed
      delay(150);                         //initial delay to compensate bounce
      while( digitalRead(SW_1_PIN) == false ){
        // wait for button release
      }
      if (pressed + 1000 > millis() ) {
        // pressed shorter than 1s
        pdf_up();
      }else{
        // pressed longer than 1s
        pdf_top();
      }
    }
    sw1_debounce = now;    
  }

  // debounce button 2
  if(digitalRead(SW_2_PIN) == false){
    if(sw2_debounce + debounceTimeConst < now){ pdf_down(); }
    sw2_debounce = now;
  }
  //Serial.println(sw1_debounce);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 500) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(1, ledState);
  }
}

#define KEY_RIGHT_ARROW       0x4F     // Keyboard RightArrow  -> Alternative arrow keys names
#define KEY_LEFT_ARROW        0x50     // Keyboard LeftArrow
#define KEY_DOWN_ARROW        0x51     // Keyboard DownArrow
#define KEY_UP_ARROW          0x52     // Keyboard UpArrow
#define KEY_PAGE_UP           0x4B     // Keyboard PageUp
#define KEY_DELETE            0x4C     // Keyboard Delete Forward
#define KEY_END               0x4D     // Keyboard End
#define KEY_PAGE_DOWN         0x4E     // Keyboard PageDown
#define KEY_HOME              0x4A     // Keyboard Home
//Keyborad Event definitions

void pdf_up() {
    DigiKeyboard.sendKeyStroke(KEY_PAGE_UP);  
    //Keyboard.press(KEY_LEFT_ARROW);  
    DigiKeyboard.delay(100);
}

void pdf_down() {
    DigiKeyboard.sendKeyStroke(KEY_PAGE_DOWN);  
    //Keyboard.press(KEY_RIGHT_ARROW);  
    DigiKeyboard.delay(100);
}

void pdf_top() {
    DigiKeyboard.sendKeyStroke(KEY_HOME);  
    //Keyboard.press(KEY_RIGHT_ARROW);  
    DigiKeyboard.delay(100);
}

/**
 * Dennis Gunia (c) 2022
 *
 * USB Keyboard for Worship song-switching
 * 
 *
 * Designed for Arduino Pro Micro
 * 
 * Use pin 8 and 9 as inputs. Connect Switches to Ground.
 * 
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */


#include <Keyboard.h>

#define SW_1_PIN 8
#define SW_2_PIN 9

#define debounceTimeConst 200   //debounce time in ms

unsigned long sw1_debounce = 0; //debounce var (last time button was pressed)
unsigned long sw2_debounce = 0; //debounce var (last time button was pressed)

void setup() {
  // Set input pins with pullup
  pinMode(SW_1_PIN, INPUT_PULLUP);
  pinMode(SW_2_PIN, INPUT_PULLUP);

  //Initialize USB Keyboard
  Keyboard.begin();
}

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
}

//Keyborad Event definitions

void pdf_up() {
    Keyboard.press(KEY_PAGE_UP);  
    //Keyboard.press(KEY_LEFT_ARROW);  
    delay(100);
    Keyboard.releaseAll();
}

void pdf_down() {
    Keyboard.press(KEY_PAGE_DOWN);  
    //Keyboard.press(KEY_RIGHT_ARROW);  
    delay(100);
    Keyboard.releaseAll();
}

void pdf_top() {
    Keyboard.press(KEY_RIGHT_GUI);  
    Keyboard.press(KEY_UP_ARROW);  
    delay(100);
    Keyboard.releaseAll();
}

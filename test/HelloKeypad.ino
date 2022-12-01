

#include <Keypad.h>         //include keypad library - first you must install library (library link in the video description)



const byte rows = 4;  //number of the keypad's rows and columns
const byte cols = 4;

char keyMap[rows][cols] = {  //define the cymbols on the buttons of the keypad

  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[rows] = { 11, 10, 9, 8 };  //pins of the keypad²²²
byte colPins[cols] = { 7, 6, 5, 4 };
int k = 0;
char arr[10];
char data;

Keypad keypad = Keypad(makeKeymap(keyMap), rowPins, colPins, rows, cols);


void setup() {

  Serial.begin(9600);

}

void loop() {

  char whichKey = keypad.getKey();  //define which key is pressed with getKey
  

  if (whichKey == '*' || whichKey == '#' || whichKey == 'A' ||  //define invalid keys
      whichKey == 'B' || whichKey == 'C' || whichKey == 'D') {

    delay(1000);
    k = 0;
  } else if (whichKey == '0' || whichKey == '1' || whichKey == '2' || whichKey == '3' || whichKey == '4' || whichKey == '5' || whichKey == '6' || whichKey == '7' || whichKey == '8' || whichKey == '9') {
     delay(200);
    arr[k] = whichKey;
    k++;
  }

  if (k == 6) {
    Serial.write(arr);
    k = 0;
    for (int j = 0; j < 6; j++) {
      arr[j] = "";
    
    }
  }
}

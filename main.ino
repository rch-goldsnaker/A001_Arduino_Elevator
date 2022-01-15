
int buttonState1 = 0; //Bottom 1
int buttonState2 = 0; //Bottom 2
int buttonState3 = 0; //Bottom 3
int buttonState4 = 0; //Bottom 4
int buttonState5 = 0; //Limit Switch 1
int buttonState6 = 0; //Limit Switch 2
int buttonState7 = 0; //Limit Switch 3
int buttonState8 = 0; //Limit Switch 4

int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;
int i;
int statusLS[]={0,0,0,0};
int Floor1[]={1,0,0,0};
int Floor2[]={0,1,0,0};
int Floor3[]={0,0,1,0};
int Floor4[]={0,0,0,1};
int Case;
int statusB[]={0,0,0,0};
int statusBR[]={0,0,0,0};



//Outputs

const int ledPIN1 = 11; //MOTOR UP
const int ledPIN2 = 12; //MOTOR DOWN

void setup()
{
  pinMode(ledPIN1 , OUTPUT);  
  pinMode(ledPIN2 , OUTPUT); 
}

boolean array_cmp(int *a, int *b, int len_a, int len_b){
      int n;

      // if their lengths are different, return false
      if (len_a != len_b) return false;

      // test each element to be the same. if not, return false
      for (n=0;n<len_a;n++) if (a[n]!=b[n]) return false;

      //ok, if we have not returned yet, they are equal :)
      return true;
}

void loop()
{
  // read the state of the pushbutton value
  buttonState1 = digitalRead(2);  
  buttonState2 = digitalRead(3);
  buttonState3 = digitalRead(4);
  buttonState4 = digitalRead(5);
  buttonState5 = digitalRead(6);  
  buttonState6 = digitalRead(7);  
  buttonState7 = digitalRead(8);  
  buttonState8 = digitalRead(9);

  Serial.begin(9600);
  
// Set the Status of LS

if (buttonState5 == HIGH){statusLS[0]= 1;};
if (buttonState6 == HIGH){statusLS[1]= 1;};
if (buttonState7 == HIGH){statusLS[2]= 1;};
if (buttonState8 == HIGH){statusLS[3]= 1;};

if (buttonState1 == HIGH){statusB[0]= 1;};
if (buttonState2 == HIGH){statusB[1]= 1;};
if (buttonState3 == HIGH){statusB[2]= 1;};
if (buttonState4 == HIGH){statusB[3]= 1;};

if (array_cmp(statusBR, statusB, 4, 4) == true){Serial.println("OK");};
  

if (array_cmp(Floor1, statusLS, 4, 4) == true){Case = 1;};
if (array_cmp(Floor2, statusLS, 4, 4) == true){Case = 2;};
if (array_cmp(Floor3, statusLS, 4, 4) == true){Case = 3;};
if (array_cmp(Floor4, statusLS, 4, 4) == true){Case = 4;};

 switch (Case) {
    case 1:
        Serial.println("1");
      break;
    case 2:
        Serial.println("2");
      break;
    case 3:
        Serial.println("3");
      break;
    case 4:
        Serial.println("4");
      break;
    default:
        Serial.println("Error");
      break;
  }

// 1 to 2 
  
  
  if (buttonState2 != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH and buttonState5 == HIGH and buttonState6 == LOW and buttonState7 == LOW and buttonState8 == LOW) {
      // if the current state is HIGH, then the button
      // went from off to on
      buttonPushCounter += 1;
      Serial.println("on");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW, then the button
      // went from on to off
      Serial.println("off");
    }
    // delay a little bit to avoid debouncing
    delay(10); // Wait for 5 millisecond(s)
  }
  // save the current state as the last state, for
  // the next time through the loop
  
  lastButtonState = buttonState2;
  
  if (buttonPushCounter == 1 and buttonState6 ==LOW ) {
    digitalWrite(ledPIN1, HIGH);
  } else {
    digitalWrite(ledPIN1, LOW);
  }
  
  	
}
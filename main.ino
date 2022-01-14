
int buttonState1 = 0; //Senal de motor subir
int buttonState2 = 0; //Senal de motor bajar
int buttonState3 = 0; //Fin de carrera 1
int buttonState4 = 0; //Fin de carrera 2

int buttonState = 0;

int lastButtonState = 0;

int buttonPushCounter = 0;

//Outputs

const int ledPIN1 = 9;
const int ledPIN2 = 10;

//Imputs

const int bottom1 = 2; // botom 1 piso
const int bottom2 = 3; // boton 2 piso
const int limitSwitch1 = 4; // Fin de carrera 1 piso.
const int limitSwitch2 = 5; // Fin de carrera 1 piso.

void setup()
{
  pinMode(bottom1, INPUT);  
  pinMode(bottom2, INPUT);
  pinMode(ledPIN1 , OUTPUT);  //definir pin como salida  
  pinMode(ledPIN2 , OUTPUT);  //definir pin como salida
}

void loop()
{
  // read the state of the pushbutton value
  buttonState1 = digitalRead(2);  
  buttonState2 = digitalRead(3);
  buttonState3 = digitalRead(4);
  buttonState4 = digitalRead(5);
  
  Serial.begin(9800);

// 1 al 2 piso
  
  if (buttonState2 != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
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
  
  if (buttonPushCounter == 1) {
    digitalWrite(ledPIN1, HIGH);
  } else {
    digitalWrite(ledPIN1, LOW);
  }
  	
}
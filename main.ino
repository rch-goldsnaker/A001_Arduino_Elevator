
// Inputs

int BS1 = 0; //Bottom 1
int BS2 = 0; //Bottom 2
int BS3 = 0; //Bottom 3
int BS4 = 0; //Bottom 4
int LS1 = 0; //Limit Switch 1
int LS2 = 0; //Limit Switch 2
int LS3 = 0; //Limit Switch 3
int LS4 = 0; //Limit Switch 4

//Outputs

const int MotorUp = 11; //MOTOR UP
const int MotorDown = 12; //MOTOR DOWN

//Extra variables

int statusLS[]={0,0,0,0};
int Floor1[]={1,0,0,0};
int Floor2[]={0,1,0,0};
int Floor3[]={0,0,1,0};
int Floor4[]={0,0,0,1};
int Case;
int SubCase;

void setup()
{
  pinMode(MotorUp , OUTPUT);  
  pinMode(MotorDown , OUTPUT);  
  pinMode(2, INPUT);  
  pinMode(3, INPUT);  
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);  
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
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

// This function set the status of Limit Switch
 int status(){
  if (LS1 == HIGH){statusLS[0]= 1;}else{statusLS[0]= 0;};
  if (LS2 == HIGH){statusLS[1]= 1;}else{statusLS[1]= 0;};
  if (LS3 == HIGH){statusLS[2]= 1;}else{statusLS[2]= 0;};
  if (LS4 == HIGH){statusLS[3]= 1;}else{statusLS[3]= 0;};
  if (array_cmp(Floor1, statusLS, 4, 4) == true){Case = 1;};
  if (array_cmp(Floor2, statusLS, 4, 4) == true){Case = 2;};
  if (array_cmp(Floor3, statusLS, 4, 4) == true){Case = 3;};
  if (array_cmp(Floor4, statusLS, 4, 4) == true){Case = 4;};
}

void loop()
{
  //Read the state of the pushbuttons and limit switch
  BS1 = digitalRead(2); //Push-button to 1 floor
  BS2 = digitalRead(3); //Push-button to 2 floor
  BS3 = digitalRead(4); //Push-button to 3 floor
  BS4 = digitalRead(5); //Push-button to 4 floor
  LS1 = digitalRead(6); //Limit switch in 1 floor
  LS2 = digitalRead(7); //Limit switch in 2 floor
  LS3 = digitalRead(8); //Limit switch in 3 floor
  LS4 = digitalRead(9); //Limit switch in 4 floor
	
  //Read the status of the elevator position using the function status in order to get Case value.
  status();
  
  //Print the elevator position
  Serial.println("......................................");
  Serial.println("Ready to Start");
  delay (500);  
  Serial.println((String)"You are in floor "+ Case);
  delay (500);
  Serial.println((String)"Last elevator flow "+ SubCase);
  delay (500);
 
 switch (Case) {
  case 1:
    if (BS2 == HIGH ){SubCase = 12;};
    if (BS3 == HIGH ){SubCase = 13;};   
    if (BS4 == HIGH ){SubCase = 14;};
    switch (SubCase) {
      case 12:
        while(LS1 == 1 and digitalRead(7) == 0){
          Serial.println("ELEVATOR UP");
          digitalWrite(MotorUp, HIGH);
        };
        digitalWrite(MotorUp, LOW);
        break;
      case 13:
        while(LS1 == 1 and digitalRead(8) == 0){
          Serial.println("ELEVATOR UP");
          digitalWrite(MotorUp, HIGH);
        };
        digitalWrite(MotorUp, LOW);
        break; 
      case 14:
        while(LS1 == 1 and digitalRead(9) == 0){
          Serial.println("ELEVATOR UP");
          digitalWrite(MotorUp, HIGH);
        };
        digitalWrite(MotorUp, LOW);
        break;
    }	
    break;
  case 2:
    if (BS1 == HIGH ){SubCase = 21;}
    if (BS3 == HIGH ){SubCase = 23;}   
    if (BS4 == HIGH ){SubCase = 24;}
    switch (SubCase) {
      case 21:
        while(LS2 == 1 and digitalRead(6) == 0){
          Serial.println("ELEVATOR DOWN");
          digitalWrite(MotorDown, HIGH);
        };
        digitalWrite(MotorDown, LOW);
        break;
      case 23:
        while(LS2 == 1 and digitalRead(8) == 0){
          Serial.println("ELEVATOR UP");
          digitalWrite(MotorUp, HIGH);
        };
        digitalWrite(MotorUp, LOW);
        break;
      case 24:
        while(LS2 == 1 and digitalRead(9) == 0){
          Serial.println("ELEVATOR UP");
          digitalWrite(MotorUp, HIGH);
        };
        digitalWrite(MotorUp, LOW);
        break;
    };  	
    break;
  case 3:
    if (BS1 == HIGH ){SubCase = 31;}
    if (BS2 == HIGH ){SubCase = 32;}   
    if (BS4 == HIGH ){SubCase = 34;}
    switch (SubCase) {
      case 31:
        while(LS3 == 1 and digitalRead(6) == 0){
          Serial.println("ELEVATOR DOWN");
          digitalWrite(MotorDown, HIGH);
        };
        digitalWrite(MotorDown, LOW);
        break;
      case 32:
        while(LS3 == 1 and digitalRead(7) == 0){
          Serial.println("ELEVATOR DOWN");
          digitalWrite(MotorDown, HIGH);
        };
        digitalWrite(MotorDown, LOW);
        break;
      case 34:
        while(LS3 == 1 and digitalRead(9) == 0){
          Serial.println("ELEVATOR UP");
          digitalWrite(MotorUp, HIGH);
        };
        digitalWrite(MotorUp, LOW);
        break;
    };  	
    break;
  case 4:
    if (BS1 == HIGH ){SubCase = 41;}
    if (BS2 == HIGH ){SubCase = 42;}   
    if (BS3 == HIGH ){SubCase = 43;}
    switch (SubCase) {
      case 41:
        while(LS4 == 1 and digitalRead(6) == 0){
          Serial.println("ELEVATOR DOWN");
          digitalWrite(MotorDown, HIGH);
        };
        digitalWrite(MotorDown, LOW);
        break;
      case 42:
        while(LS4 == 1 and digitalRead(7) == 0){
          Serial.println("ELEVATOR DOWN");
          digitalWrite(MotorDown, HIGH);
        };
        digitalWrite(MotorDown, LOW);
        break;
      case 43:
        while(LS4 == 1 and digitalRead(8) == 0){
          Serial.println("ELEVATOR DOWN");
          digitalWrite(MotorDown, HIGH);
        };
        digitalWrite(MotorDown, LOW);
        break;
    };  	
    break;
  default:
      Serial.println("Transition");delay (500);
    break;
  };
}
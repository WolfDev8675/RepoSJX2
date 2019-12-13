/*Code definition for operation of tank waterlevel management using two pumps
**** Arduino nano
**** future upgrade -IOT
****
  Pinout used
  pins D4,D5,D6,D7 input levels
  pins D2,D3 output actuator to relays
  D4,D5 low,High for Main tank
  D6,D7 low,High for Filter tank
*/
int mT_low = 4;
int mT_High = 5;
int fT_low = 6;
int fT_High = 7;
int pAct_mT = 2;
int pAct_fT = 3;
void setup()
{
  // put your setup code here, to run once:
  /*
      Setup of pin modes for proper operations.
      Code might be updated later for wifi monitoring and control using IoT parameters
  */
  Serial.begin(9600);   // Serial setup
  pinMode(mT_low, INPUT);    // pin modes declaration
  pinMode(mT_High, INPUT);
  pinMode(fT_low, INPUT);
  pinMode(fT_High, INPUT);
  pinMode(pAct_mT, OUTPUT);
  pinMode(pAct_fT, OUTPUT);

} // end of setup section

void loop()
{

  // put your main code here, to run repeatedly:
  /*
     input of button mode and immediate response impact
     structured in separate if-else checks
      ## intricacies to be added later with Android packaging and control for IoT & Wifi.
  */
  if (!digitalRead(mT_low))
    digitalWrite(pAct_fT, HIGH);
  if (!digitalRead(fT_low))
    digitalWrite(pAct_mT, HIGH);
  if (digitalRead(mT_High))
  {
    delay(1000);
    digitalWrite(pAct_fT, LOW);
  }
  if (digitalRead(fT_High))
  {
    delay(1000);
    digitalWrite(pAct_mT, LOW);
  }

}  //end of loop section

/*
   code courtesy
   @ Bishal Biswas
   Github: https://github.com/WolfDev8675/RepoSJX2
*/

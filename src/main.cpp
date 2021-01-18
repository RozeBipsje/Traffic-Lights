#include <Arduino.h>

// pinverdeling
int RED1 = 2;
int RED2 = 3;
int YELLOW1 = 4;
int YELLOW2 = 5;
int GREEN1 = 6;
int GREEN2 = 7;
int button = 9;

//timers
int DELAY_GREEN = 5000;
int DELAY_YELLOW = 2000;
int DELAY_YELLOW2 = 500;
int DELAY_RED = 5000;

// button states
boolean oldSwitchState = LOW;
boolean newSwitchState = LOW;
byte state = 0;


void setup()

{
  Serial.begin(9600);
  pinMode(GREEN1, OUTPUT); 
  pinMode(YELLOW1, OUTPUT);
  pinMode(RED1, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(YELLOW2, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(button, INPUT);
}

void green_light()
{
  digitalWrite(GREEN1, HIGH);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(YELLOW2, LOW);
  digitalWrite(RED2, HIGH);
}

void yellow_light()
{
  digitalWrite(GREEN1, LOW);
  digitalWrite(YELLOW1, HIGH);
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(YELLOW2, LOW);
  digitalWrite(RED2, HIGH);
}

void red_light()
{
  digitalWrite(GREEN1, LOW);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(RED1, HIGH);
  digitalWrite(GREEN2, HIGH);
  digitalWrite(YELLOW2, LOW);
  digitalWrite(RED2, LOW);
}

void yellow_light2()
{
  digitalWrite(GREEN1, LOW);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(RED1, HIGH);
  digitalWrite(GREEN2, LOW);
  digitalWrite(YELLOW2, HIGH);
  digitalWrite(RED2, LOW);
}

void yellow_blink()
{
  digitalWrite(YELLOW1, HIGH);
  digitalWrite(YELLOW2, HIGH);
  digitalWrite(RED1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(GREEN1, LOW);
  digitalWrite(GREEN2, LOW);

}

void lights_off()
{
  digitalWrite(GREEN1, LOW);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(YELLOW2, LOW);
  digitalWrite(RED2, LOW);
}

void loop(){
{
  newSwitchState = digitalRead(button);
  if ( newSwitchState != oldSwitchState )
  {
    // has the button switch been closed?
    if ( newSwitchState == HIGH )
    {
      // increase the value of state
      state++;
      if (state > 3) {
        state = 0;
      }
      // turn all LEDs off. Doing it this way means we do not need to care about the individual LEDs
      // simply turn them all off and then turn on the correct one.
  digitalWrite(GREEN1, LOW);
  digitalWrite(YELLOW1, LOW);
  digitalWrite(RED1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(YELLOW2, LOW);
  digitalWrite(RED2, LOW);
     
      // Because the value of state does not change while we are testing it we don't need to use else if
      while (state == 1) {
        
  green_light();
  delay(DELAY_GREEN);
  yellow_light();
  delay(DELAY_YELLOW);
  red_light();
  delay(DELAY_RED);
    yellow_light2();
  delay(DELAY_YELLOW);
  
}
while (state == 2) {
  yellow_blink();
  delay(DELAY_YELLOW2);
  yellow_blink();
  delay(DELAY_YELLOW2);
  
}
while (state == 3) {
        lights_off();
      }
    }
    oldSwitchState = newSwitchState;
  }
}}
#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(250);
	digitalWrite(_pin,LOW);
	delay(250);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(1000);
	digitalWrite(_pin,LOW);
	delay(250);
}
    
String characters=""; 
String morse="";
void setup() 
{
 Serial.begin(9600);
}
char arry[][4]={
  {'.','-','*','*'},
  {'-','.','.','.'},
  {'-','.','-','.'},
  {'-','.','.','*'},
  {'.','*','*','*'},
  {'.','.','-','.'},
  {'-','-','.','*'},
  {'.','.','.','.'},
  {'.','.','*','*'},
  {'.','-','-','-'},
  {'-','.','-','*'},
  {'.','-','.','.'},
  {'-','-','*','*'},
  {'-','.','*','*'},
  {'-','-','-','*'},
  {'.','-','-','.'},
  {'-','-','.','-'},
  {'.','-','.','*'},
  {'.','.','.','*'},
  {'-','*','*','*'},
  {'.','.','-','*'},
  {'.','.','.','-'},
  {'.','-','-','*'},
  {'-','.','.','-'},
  {'-','.','-','-'},
  {'-','-','.','.'},
};
void loop()
{ 
  int n=0;
  while (Serial.available()>0)  
    {
        characters+=char(Serial.read());
        delay(2);
        n++;
    }
   for (int i=0;i<n;i++)
    {
     for (int j=0;j<4;j++)
      {
        if (characters[i]>=97&&characters[i]<=122)
          {
            morse += char(arry[int(characters[i]-97)][j]);
          }
          morse += ' ';
      }
      Serial.println(morse);
    }
    delay(2);
}

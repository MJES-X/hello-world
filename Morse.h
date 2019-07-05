#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
  private:
    int _pin;
};
#endif /*_MORSE_H*/
    
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

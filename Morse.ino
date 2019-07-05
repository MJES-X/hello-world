class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
    int _dottime;
};

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_dottime=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime*3);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*4);
}

void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*6);
}

Morse morse(13);
char MORSE[][4] = {
  {'.', '-', '*', '*'}, 
  {'-', '.', '.', '.'}, 
  {'-', '.', '-', '.'}, 
  {'-', '.', '.', '*'}, 
  {'.', '*', '*', '*'}, 
  {'.', '.', '-', '.'}, 
  {'-', '-', '.', '*'}, 
  {'.', '.', '.', '.'}, 
  {'.', '.', '*', '*'}, 
  {'.', '-', '-', '-'}, 
  {'-', '.', '-', '*'}, 
  {'.', '-', '.', '.'}, 
  {'-', '-', '*', '*'}, 
  {'-', '.', '*', '*'}, 
  {'-', '-', '-', '*'}, 
  {'.', '-', '-', '.'}, 
  {'-', '-', '.', '-'}, 
  {'.', '-', '.', '*'}, 
  {'.', '.', '.', '*'}, 
  {'-', '*', '*', '*'}, 
  {'.', '.', '-', '*'}, 
  {'.', '.', '.', '-'}, 
  {'.', '-', '-', '*'}, 
  {'-', '.', '.', '-'}, 
  {'-', '.', '-', '-'}, 
  {'-', '-', '.', '.'}, 
  {'-', '-', '-', '*'},
  {'*', '-', '*', '-'} 
};

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String characters = "";
  String chars = "";
  int k = 0;
  int n = 0;
  while(Serial.available()>0)
  {
    k = 1;
    characters += char(Serial.read());
    delay(1); 
    n++;
  }

  if(k)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<4;j++)
      {
        if((characters[i]>=97&&characters[i]<=122))
        {
          chars += char(MORSE[int(characters[i]-97)][j]);
        }
        if(characters[i]==13)
        {
          chars += char(MORSE[27][j]);
        }
        if(characters[i]==32)
        {
         chars += char(MORSE[28][j]);
        }
      }
      chars += ' ';
    }
    Serial.println(chars);
    for(int i = 0;chars[i]!='\0' ; i++)
    {
      if(chars[i] == '.')morse.dot();
      else if(chars[i] == '-')morse.dash();
      else if(chars[i] == ' ')morse.w_space();
      if (chars[i] != ' ' && characters[i] != '*')morse.c_space();
    }
    delay(2);
  }
}

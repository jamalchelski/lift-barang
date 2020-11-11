
//Tombol naik & Turun
const int Tnaik = 10;
const int Tturun = 9;

//LimitSwitch atas & bawah
const int LSTop = 12;
const int LSBot = 11;

//relay untuk motor naik & turun
const int MUp = 2;
const int MDown = 3;

void setup()
{
  pinMode(Tnaik, INPUT);
  pinMode(Tturun, INPUT);
  pinMode(LSTop, INPUT);
  pinMode(LSBot, INPUT);

  pinMode(MUp, OUTPUT);
  pinMode(MDown, OUTPUT);
  digitalWrite(MUp, HIGH);
  digitalWrite(MDown, HIGH);

  int TN = digitalRead(Tnaik);
  int LA = digitalRead(LSTop);
  int TT = digitalRead(Tturun);
  int LB = digitalRead(LSBot);
  if (LA == HIGH && LB == HIGH)
  {
    digitalWrite(MDown, LOW);
  }
  Serial.begin(9600);
}

void loop()
{
  int TN = digitalRead(Tnaik);
  int LA = digitalRead(LSTop);
  int TT = digitalRead(Tturun);
  int LB = digitalRead(LSBot);
  if (LB == LOW && TN == LOW)
  {
    digitalWrite(MUp, LOW);
  }
  if (LB == HIGH && LA == LOW)
  {
    digitalWrite(MUp, HIGH);
  }
  if (LA == LOW && TT == LOW)
  {
    digitalWrite(MDown, LOW);
  }
  if (LA == HIGH && LB == LOW)
  {
    digitalWrite(MDown, HIGH);
  }

  delay(100);
}

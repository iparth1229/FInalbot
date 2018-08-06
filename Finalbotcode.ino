
int lfs = 2; //leftfarsensor
int lns = 3; //leftnearsensor
int cs = 4;  //centersensor
int rns = 5;  //rightnearsensor
int rfs = 6; //rightfarsensor

int lnr;
int lfr;
int cr;
int rfr;
int rnr;

int leftmotor1 = 10;
int leftmotor2 = 11;
int rightmotor1 = 12;
int rightmotor2 = 13;

void Left();
void Right();
void straight();
void turnAround();
void finish();


void setup() {

  pinMode(lns, INPUT);
  pinMode(lfs, INPUT);
  pinMode(cs, INPUT);
  pinMode(rns, INPUT);
  pinMode(rfs, INPUT);

  pinMode(leftmotor1, OUTPUT);
  pinMode(leftmotor2, OUTPUT);
  pinMode(rightmotor1, OUTPUT);
  pinMode(rightmotor2, OUTPUT);

  Serial.begin(115200);

}

void loop() {

  readSensors();
  if ( lfr == HIGH && rfr == HIGH && cr == LOW )
  {
    straight();
  }
  else
  {
    leftHandWall();
  }
}

void readSensors()
{
  lnr = digitalRead(lns);
  lfr = digitalRead(lfs);
  cr = digitalRead(cs);
  rfr = digitalRead(rfs);
  rnr = digitalRead(rns);
}

void leftHandWall()
{
  if (lfr == LOW && rfr == LOW)
    digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  delay(300);

  readSensors();
  if (lfr == HIGH && rfr == HIGH)
  {
    Left();
  }
  else
  {
    finish();
  }


  if (lfr == LOW)
  {
    digitalWrite(leftmotor1, HIGH);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
    delay(300);
    readSensors();
    if (lfr == HIGH && rfr == HIGH)
    {
      Left();
    }
    else
    {
      finish();
    }
  }

  if (rfr == LOW)
  {
    digitalWrite(leftmotor1, HIGH);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
    delay(300);
    readSensors();

    if (lfr == LOW)
    {
      readSensors();

      if (rfr == LOW && lfr == LOW)
      {
        finish();
      }
      else if (rfr == HIGH && lfr == HIGH && cr == HIGH)
      {
        Right();
      }
      else
      {
        straight();
        return;
      }
    }

    if(lfr==HIGH && cr==HIGH && rfr==HIGH)
    {
      Right();
      return; 
    }
  }
  readSensors();
  if (lfr == HIGH && lnr == HIGH && cr == HIGH && rfr == HIGH && rnr == HIGH)
  {
    turnAround();
  }
}
  
  void finish() {

    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
  }

  void Left() {
  while (digitalRead(lns) == LOW)
  {
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
    delay(4);
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(2);
  }

  while (digitalRead(lns) == HIGH)
  {
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
    delay(4);
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(1);
  }

  while (digitalRead(lfs) == LOW && digitalRead(lns) == LOW)
  {
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
    delay(4);
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(1);
  }
}

void Right()
{
  while (digitalRead(rns) == LOW)
  {
    digitalWrite(leftmotor1, HIGH);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(2);
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(1);
  }
  while (digitalRead(rns) == HIGH)
  {
    digitalWrite(leftmotor1, HIGH);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(2);
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(1);
  }

  while (digitalRead(lns == HIGH))
  {
    digitalWrite(leftmotor1, HIGH);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(2);
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(1);
  }
}

void straight()
{
  if (digitalRead(lns) == HIGH)
  {
    digitalWrite(leftmotor1, HIGH);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
    delay(2);
    digitalWrite(leftmotor1, HIGH);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(1);
    return;
  }

  if (digitalRead(rns) == HIGH)
  {
    digitalWrite(leftmotor1, HIGH);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
    delay(2);
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
    delay(1);
    return;
  }

  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  delay(2);
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, LOW);
  digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, LOW);
  delay(1);

}

void turnAround()
{
  digitalWrite(leftmotor1, HIGH);
  digitalWrite(leftmotor2, LOW);
  digitalWrite(rightmotor1, HIGH);
  digitalWrite(rightmotor2, LOW);
  delay(100);
  while (digitalRead(lns) == HIGH || digitalRead(cs) == HIGH)
  {
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, HIGH);
    digitalWrite(rightmotor1, HIGH);
    digitalWrite(rightmotor2, LOW);
    delay(2);
    digitalWrite(leftmotor1, LOW);
    digitalWrite(leftmotor2, LOW);
    digitalWrite(rightmotor1, LOW);
    digitalWrite(rightmotor2, LOW);
    delay(1);
  }
}


int S1 = 2;// left far sensor
int S2 = 3;// left near sensor
int S3 = 4;//
int S4 = 7;
int S5 = 8;
int LM1 = 9;      // left motor
int LM2 = 10;      // left motor
int RM1 = 11;      // right motor
int RM2 = 12;      // right motor
int A;
int B;
int C;
int D;
int E;
int en1=5;
int en2=6;
const int w = 0;     // low
const int b = 1 ;    // high
void setup()
{
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
}

void loop()
{
 A = digitalRead(S1);
 B = digitalRead(S2);
 C = digitalRead(S3);
 D = digitalRead(S4);
 E = digitalRead(S5);

   if(A == b && B== b && C== w && D== b && E == b)
 {
  straight();
 }
   if (A==b && B==w && C==w && D==b && E==b || A==b && B==w && C==b && D==b && E==b )
  {
    leftcurve();
  }
  if(A==b && B==b && C==w && D==w && E==b ||  A==b && B==b && C==b && D==w && E==b  )
  {
    rightcurve();
  }
  if(A == b && B== b && C== w && D==w && E == w)//rightT
  {
  stop1();  
  delay(300);
  straight();
  delay(100);
  
  if(A == b && B== b && C== w && D== b && E == b)
  {
  straight();
  }
  else 
  {
  right();
  }
  }  
  }
                        

void straight()
{
  analogWrite(en1,120);
  analogWrite(en2,125);
  
 digitalWrite(LM1,HIGH);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,HIGH);
 digitalWrite(RM2,LOW);;
}
void leftcurve()
{
 analogWrite(en1,120);
   analogWrite(en2,125);

    digitalWrite(LM1,LOW);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,HIGH);
 digitalWrite(RM2,LOW);
}
void rightcurve()
{
  analogWrite(en1,120);
   analogWrite(en2,125);

    digitalWrite(LM1,HIGH);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,LOW);
 digitalWrite(RM2,LOW);
}
void right()
{
   do
  {
    analogWrite(en1,120);
   analogWrite(en2,125);
    
  digitalWrite(LM1,HIGH);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,LOW);
 digitalWrite(RM2,HIGH);
}while (A != b && B != b && C != w && D != b && E != b);
}

void stop1()
{
    analogWrite(en1,0);
   analogWrite(en2,0);
    
  digitalWrite(LM1,LOW);
 digitalWrite(LM2,LOW);
 digitalWrite(RM1,LOW);
 digitalWrite(RM2,LOW);
}

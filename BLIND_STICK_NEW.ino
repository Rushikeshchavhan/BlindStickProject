int trigger3=5;//3rd
int echo3=4;

int trigger4=3;//4th
int echo4=2;

int trigger2=7;//2nd
int echo2=6;

int trigger1=9;//1st
int echo1=8;


int Rec1=10;
int Rec2=11;
int Rec3=12;
int Rec4=13;
int Rec5=A5;

int Rec6=A0;
int Rec7=A6;
int Moisture=A1;
int LDR=A2;

int LED=A3;

int Time1,Time2,Time3,Time4;
int distance1,distance2,distance3,distance4;


void setup() {
  pinMode(trigger1,OUTPUT);
  pinMode(echo1,INPUT);

  pinMode(trigger2,OUTPUT);
  pinMode(echo2,INPUT);

  pinMode(trigger3,OUTPUT);
  pinMode(echo3,INPUT);

  pinMode(trigger4,OUTPUT);
  pinMode(echo4,INPUT);

 pinMode(Rec6,OUTPUT);
 digitalWrite(Rec6,HIGH);

 pinMode(Rec7,OUTPUT);
 digitalWrite(Rec7,HIGH);
pinMode(Rec1,OUTPUT);
pinMode(Rec2,OUTPUT);
pinMode(Rec3,OUTPUT);
pinMode(Rec4,OUTPUT);
pinMode(Rec5,OUTPUT);
digitalWrite(Rec1,HIGH);
digitalWrite(Rec2,HIGH);
digitalWrite(Rec3,HIGH);
digitalWrite(Rec4,HIGH);
digitalWrite(Rec5,HIGH);

pinMode(Moisture,INPUT);
pinMode(LDR,INPUT);
pinMode(LED,OUTPUT);
digitalWrite(LED,LOW);
  Serial.begin(9600);

 
}

void loop() {

  int M=digitalRead(Moisture);
  Serial.print("Moisture =");
  Serial.println(M);
  
  int L=analogRead(LDR);
  Serial.print("LDR =");
  Serial.println(L);
  

  
 digitalWrite(trigger1,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger1,HIGH);
 delayMicroseconds(2);
 digitalWrite(trigger1,LOW);
Time1=pulseIn(echo1,HIGH);
distance1=Time1/29/2;


 digitalWrite(trigger2,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger2,HIGH);
 delayMicroseconds(2);
 digitalWrite(trigger2,LOW);
Time2=pulseIn(echo2,HIGH);
distance2=Time2/29/2;



  digitalWrite(trigger3,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger3,HIGH);
 delayMicroseconds(2);
 digitalWrite(trigger3,LOW);


Time3=pulseIn(echo3,HIGH);
distance3=Time3/29/2;

digitalWrite(trigger4,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger4,HIGH);
 delayMicroseconds(2);
 digitalWrite(trigger4,LOW);


Time4=pulseIn(echo4,HIGH);
distance4=Time4/29/2;

if(distance1>=70&&distance1<=80)
  distance1=300;
if(distance2>=70&&distance2<=80)
  distance2=300;
if(distance3>=70&&distance3<=80)
  distance3=300;
if(distance4>=70&&distance4<=80)
  distance4=300;

  
Serial.print("Front Obstacle In Centimeter IS : ");
Serial.print(distance1);
Serial.println("Centimeter");



Serial.print("Divider Obstacle In Centimeter IS : ");
Serial.print(distance2);
Serial.println("Centimeter");


Serial.print(" Down In Centimeter IS : ");
Serial.print(distance3);
Serial.println("Centimeter");

Serial.print("Staircase Front In Centimeter IS : ");
Serial.print(distance4);
Serial.println("Centimeter");



if((distance4<=20))//GO UP
{
    Serial.println("Go UP");
    digitalWrite(Rec1,LOW);
    delay(50);
    digitalWrite(Rec1,HIGH);
    delay(2000);
}
else if(distance3>22)//GO DOWN
{
    Serial.println("Go Down");
    digitalWrite(Rec2,LOW);
    delay(50);
    digitalWrite(Rec2,HIGH);
    delay(2000);
}  
else if(((distance2<=100)&&(distance4<=100)&&(distance1>110)&&(distance3>10)))//lower oject 100
{
    Serial.println("Lower Object Detected");
    digitalWrite(Rec3,LOW);
    delay(50);
    digitalWrite(Rec3,HIGH);
    delay(2000);
}

else if((distance1<=100)&&(distance2<=90)&&(distance4<=100)&&(distance3>10))//Main object 150
{
    Serial.println("Main Object Detected");
    // digitalWrite(Vib,HIGH);
    digitalWrite(Rec4,LOW);
    delay(50);
    digitalWrite(Rec4,HIGH);
    
    delay(2000);

    /*Go Stright Logic*/
 Loop:   
      digitalWrite(trigger1,LOW);
      delayMicroseconds(2);
      digitalWrite(trigger1,HIGH);
      delayMicroseconds(2);
      digitalWrite(trigger1,LOW);
      Time1=pulseIn(echo1,HIGH);
      distance1=Time1/29/2;
      Serial.println(distance1);
      if(distance1>=70&&distance1<=80)
        distance1=300;
      if(distance1>=100)
      {
        Serial.println("Go Stright");
        digitalWrite(Rec6,LOW);
        delay(50);
        digitalWrite(Rec6,HIGH);
        delay(5000);
      }
      else
        goto Loop;
        
        
}



if(M==0)
{
    Serial.println("Water Detected");
    digitalWrite(Rec5,LOW);
    delay(50);
    digitalWrite(Rec5,HIGH);
    delay(2000);
}


if(L<=30)
{
    
    digitalWrite(LED,HIGH);
    Serial.println("LIGHT DETECTED");
        digitalWrite(Rec7,LOW);
        delay(50);
        digitalWrite(Rec7,HIGH);
        delay(2000);
    
}
else
{
  digitalWrite(LED,LOW);
}

//delay(3000);
}

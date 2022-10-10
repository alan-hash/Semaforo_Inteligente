// C++ code
int Projo=5;
int Pverde=4;
int Pamarillo=6;

long cmS1=0;
long cmS2=0;

int trig1=2;
int echo1=3;

int trig2=9;
int echo2=8;


int Crojo=12;
int Camarillo=11;
int Cverde=10;


long  readUltrasonicDistance ( int triggerPin , int echoPin )
{
  pinMode ( triggerPin , OUTPUT ) ; 
  digitalWrite ( triggerPin , LOW ) ;
  delay(1000);
  digitalWrite ( triggerPin , HIGH ) ;
  delay(1000);
  digitalWrite ( triggerPin , LOW ) ; 
  pinMode ( echoPin , INPUT ) ;
  return ( pulseIn ( echoPin , HIGH ) * 0.01723 ) ;
 }


void setup()
{
  Serial.begin(9600);

  pinMode(Crojo, OUTPUT);
  pinMode(Camarillo, OUTPUT);
  pinMode(Cverde, OUTPUT);
  
  pinMode(Projo, OUTPUT);
  pinMode(Pverde, OUTPUT);
  pinMode(Pamarillo, OUTPUT);
  
  digitalWrite(Cverde,HIGH);
  digitalWrite(Projo,HIGH);
  
}

void loop()
{
  cmS1= readUltrasonicDistance ( trig1 , echo1) ;
  cmS2 = readUltrasonicDistance ( trig2 , echo2) ;
  
  
  Serial.print ( cmS1 ) ;
  Serial.println ( " cmS1 " ) ;
  
  Serial.print ( cmS2 ) ;
  Serial.println ( " cmS2 " ) ;
  
  
  if (cmS1<=100 && cmS2>=100) {
   
  	digitalWrite(Cverde,LOW);
  	digitalWrite(Camarillo,HIGH);
  	delay(1500);
    
    digitalWrite(Camarillo,LOW);
  	digitalWrite(Crojo,HIGH);
  	delay(1500);
    
 
  	digitalWrite(Projo,LOW);
  	digitalWrite(Pverde,HIGH);
  	delay(1000);
}
  
  if ( cmS1>=100 && cmS2<=100) {
  
  digitalWrite(Cverde,HIGH);
  digitalWrite(Crojo,LOW);
  delay(1000);
    
  digitalWrite(Pamarillo,HIGH);
  digitalWrite(Pverde,LOW);
  delay(1000);
 
  digitalWrite(Projo,HIGH);
  digitalWrite(Pamarillo,LOW);
  delay(1000);
 
  digitalWrite(Cverde,HIGH);
  digitalWrite(Camarillo,LOW);
  delay(1000);
     
  }
  
  if ( cmS1==cmS2) {
    digitalWrite(Cverde,HIGH);
  	digitalWrite(Projo,HIGH);
  }
      
}
  
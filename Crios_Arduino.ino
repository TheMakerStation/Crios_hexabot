
#include <Servo.h>
#include "IRremote.h"
#include <Ultrasonic.h>
#define RECV_PIN A0 

// (ultrasonic.Ranging(CM))
int cm = 0;
int pos = 0;
IRrecv irrecv(RECV_PIN);       
decode_results results;            
Servo leg1T,leg1L,leg2T,leg2L,leg3T,leg3L,leg4T,leg4L,leg5T,leg5L,leg6T,leg6L;  

 
 // for(pos = 0; pos < 10; pos += 1)
 // {  myservo.write(pos);   } 
 Ultrasonic ultrasonic(1,0); // (Trig PIN,Echo PIN)
void setup()   
{ 
  // Serial.begin(9600);
 irrecv.enableIRIn(); 
 initServo();
 }

void loop()   

{
  if (irrecv.decode(&results)) 
{
  translateIR(); 
   irrecv.resume(); 
  } 

} 

void translateIR() 

{

  switch(results.value)


  {

case 0xFF629D:  

    Serial.println(" WALK           "); 
   walk();
   inStandby();
    break;
    
  case 0xFF22DD:  

    Serial.println(" LEFT         ");
   leftTurn(); 
   inStandby();
    break;

  case 0xFF02FD:  

 Serial.println(" INSTANDBY        "); 
 
 inStandby();
  break;

  case 0xFFC23D: 

    Serial.println(" RIGHT    "); 
    rightTurn();
    inStandby();
    break;
    
  case 0xFFA857:  

    Serial.println(" WALK IN REVERSE         "); 
    walkReverse();
    inStandby();
    break;
    
  case 0xFF6897:  
  initServo();
    Serial.println(" 1            "); 
            for(pos = 0; pos < 2; pos += 1)
 {    legup();    }
  delay (800);
  inStandby();
    break;

  case 0xFF9867:  
    Serial.println(" 2          ");
     for(pos = 0; pos < 10; pos += 1)
 {  walk();  } 
  inStandby();
 
    break;

  case 0xFFB04F:  
    Serial.println(" 3       "); 
    upPosB();
 
  
    break;

  case 0xFF30CF:  
    Serial.println(" 4            "); 
    
   for(pos = 0; pos < 10; pos += 1)
 {    leftTurn();    } 
  inStandby();
    
    break;

  case 0xFF18E7:  
    Serial.println(" 5             "); 
    for(pos = 0; pos < 10; pos += 1)
 {  walk();  } 
  
 
  for(pos = 0; pos < 10; pos += 1)
 {    leftTurn();    } 
 
     for(pos = 0; pos < 10; pos += 1)
 {  walk();  } 

  for(pos = 0; pos < 10; pos += 1)
 {    leftTurn();    } 

 break;
 
 
  case 0xFF7A85:  
    Serial.println(" 6             "); 
        for(pos = 0; pos < 10; pos += 1)
 {    rightTurn();    }
  inStandby();
    break;

  case 0xFF10EF:  
    Serial.println(" 7             "); 
tFromt();

 
    break;

  case 0xFF38C7:  
    Serial.println(" 8             "); 
    for(pos = 0; pos < 10; pos += 1)
 {   walkReverse();   }
 inStandby(); 
    break;

  case 0xFF5AA5:  
    Serial.println(" 9             "); 
   tBack();
    break;

  case 0xFF42BD:  
    Serial.println(" *              "); 
   ai();
    break;


  case 0xFF4AB5:  

    Serial.println(" 0             "); 
  inOff();
    break;

  case 0xFF52AD:  
    Serial.println(" #           "); 
     initServo();
      inStandby(); 
    break;

  default: 
    Serial.println(" other button   ");
  }
  delay(500);


} //END translateIR
void initServo()  

{
   leg1T.attach(2); 
  leg1L.attach(3);
  leg2T.attach(4);
  leg2L.attach(5);     
  leg3T.attach(6);
  leg3L.attach(7);
  leg4T.attach(8);
  leg4L.attach(9);
  leg5T.attach(10);
  leg5L.attach(11);
  leg6T.attach(12);
  leg6L.attach(13);
  
  leg1T.write (80);
 leg1L.write(10);
 leg2T.write(30);
 leg2L.write(100);
 leg3T.write(20);
 leg3L.write(20);
 leg4T.write(10);
 leg4L.write(110);
 leg5T.write(20);
 leg5L.write(25);
 leg6T.write(50);
 leg6L.write(10);

}
 
  
void inStandby()
{
 leg1T.write (80);
 leg1L.write(10);
 leg2T.write(30);
 leg2L.write(100);
 leg3T.write(20);
 leg3L.write(20);
 leg4T.write(10);
 leg4L.write(110);
 leg5T.write(20);
 leg5L.write(25);
 leg6T.write(50);
 leg6L.write(10);
 
}  

void walk()
{
 
     //Step 1
 
 leg1T.write (90);
 leg1L.write(10);
 leg2T.write(40);
 leg2L.write(70);
 leg3T.write(10);
 leg3L.write(50);
 leg4T.write(0);
 leg4L.write(110);
 leg5T.write(30);
 leg5L.write(25);
 leg6T.write(60);
 leg6L.write(40);
 delay(200);



 //Step 2
 
 leg1T.write (70);
 leg1L.write(10);
 leg2T.write(20);
 leg2L.write(70);
 leg3T.write(30);
 leg3L.write(50);
 leg4T.write(20);
 leg4L.write(110);
 leg5T.write(10);
 leg5L.write(25);
 leg6T.write(40);
 leg6L.write(40);
 delay(200);
 
 
 
 
  //Step 3
 
 leg1T.write (70);
 leg1L.write(40);
 leg2T.write(20);
 leg2L.write(100);
 leg3T.write(30);
 leg3L.write(20);
 leg4T.write(20);
 leg4L.write(80);
 leg5T.write(10);
 leg5L.write(55);
 leg6T.write(40);
 leg6L.write(10);
 delay(200);
 
   //Step 4
 
 leg1T.write (90);
 leg1L.write(40);
 leg2T.write(40);
 leg2L.write(100);
 leg3T.write(10);
 leg3L.write(20);
 leg4T.write(0);
 leg4L.write(80);
 leg5T.write(30);
 leg5L.write(55);
 leg6T.write(60);
 leg6L.write(10);
 delay(200);
 
}

void walkReverse()
{
    //Step 4
 
 leg1T.write (90);
 leg1L.write(30);
 leg2T.write(40);
 leg2L.write(100);
 leg3T.write(10);
 leg3L.write(20);
 leg4T.write(0);
 leg4L.write(90);
 leg5T.write(30);
 leg5L.write(45);
 leg6T.write(60);
 leg6L.write(10);
 delay(200);   

  //Step 3
 
 leg1T.write (70);
 leg1L.write(30);
 leg2T.write(20);
 leg2L.write(100);
 leg3T.write(30);
 leg3L.write(20);
 leg4T.write(20);
 leg4L.write(90);
 leg5T.write(10);
 leg5L.write(45);
 leg6T.write(40);
 leg6L.write(10);
 delay(200);

 //Step 2
 
 leg1T.write (70);
 leg1L.write(10);
 leg2T.write(20);
 leg2L.write(80);
 leg3T.write(30);
 leg3L.write(40);
 leg4T.write(20);
 leg4L.write(110);
 leg5T.write(10);
 leg5L.write(25);
 leg6T.write(40);
 leg6L.write(30);
 delay(200);
 
   //Step 1
 
 leg1T.write (90);
 leg1L.write(10);
 leg2T.write(40);
 leg2L.write(80);
 leg3T.write(10);
 leg3L.write(40);
 leg4T.write(0);
 leg4L.write(110);
 leg5T.write(30);
 leg5L.write(25);
 leg6T.write(60);
 leg6L.write(30);
 delay(200);
}
 
void inOff()
{
  	
 leg1T.write (80);
 leg1L.write(10);
 leg2T.write(30);
 leg2L.write(100);
 leg3T.write(20);
 leg3L.write(20);
 leg4T.write(10);
 leg4L.write(110);
 leg5T.write(20);
 leg5L.write(25);
 leg6T.write(50);
 leg6L.write(10);
delay(200);
 
 leg1T.detach(); 
 leg1L.detach();
 leg2T.detach();
 leg2L.detach();     
 leg3T.detach();
 leg3L.detach();
 leg4T.detach();
 leg4L.detach();
 leg5T.detach();
 leg5L.detach();
 leg6T.detach();
 leg6L.detach();

  } 
 
 
 void rightTurn()
 {
 
 leg1T.write (90);
 leg1L.write(30);
 leg2T.write(40);
 leg2L.write(100);
 leg3T.write(10);
 leg3L.write(20);
  leg4T.write(0);
 leg4L.write(110);
 leg5T.write(30);
 leg5L.write(25);
 leg6T.write(60);
 leg6L.write(30);
 delay(200);

 
 leg1T.write (70);
 leg1L.write(30);
 leg2T.write(20);
 leg2L.write(100);
 leg3T.write(30);
 leg3L.write(20);
 leg4T.write(20);
 leg4L.write(110);
 leg5T.write(10);
 leg5L.write(25);
 leg6T.write(40);
 leg6L.write(30);
delay(200);
 
 leg1T.write (70);
 leg1L.write(10);
 leg2T.write(20);
 leg2L.write(80);
 leg3T.write(30);
 leg3L.write(40);
 leg4T.write(20);
 leg4L.write(90);
 leg5T.write(10);
 leg5L.write(45);
 leg6T.write(40);
 leg6L.write(10);
 delay(200);
 
 leg1T.write (90);
 leg1L.write(10);
 leg2T.write(40);
 leg2L.write(80);
 leg3T.write(10);
 leg3L.write(40);
 leg4T.write(0);
 leg4L.write(90);
 leg5T.write(30);
 leg5L.write(45);
 leg6T.write(60);
 leg6L.write(10);
 delay(200);
   
 }
 
  void leftTurn()
 
 {
    //Step 1
 
 leg1T.write (90);
 leg1L.write(10);
 leg2T.write(40);
 leg2L.write(80);
 leg3T.write(10);
 leg3L.write(40);
 leg4T.write(0);
 leg4L.write(90);
 leg5T.write(30);
 leg5L.write(45);
 leg6T.write(60);
 leg6L.write(10);

 delay(200);



 //Step 2
 
 leg1T.write (70);
 leg1L.write(10);
 leg2T.write(20);
 leg2L.write(80);
 leg3T.write(30);
 leg3L.write(40);
 leg4T.write(20);
 leg4L.write(90);
 leg5T.write(10);
 leg5L.write(45);
 leg6T.write(40);
 leg6L.write(10);
 
 delay(200);
 
 
 
 
  //Step 3
 
 leg1T.write (70);
 leg1L.write(30);
 leg2T.write(20);
 leg2L.write(100);
 leg3T.write(30);
 leg3L.write(20);
 leg4T.write(20);
 leg4L.write(110);
 leg5T.write(10);
 leg5L.write(25);
 leg6T.write(40);
 leg6L.write(30);

 delay(200);
 
   //Step 4
 
 leg1T.write (90);
 leg1L.write(30);
 leg2T.write(40);
 leg2L.write(100);
 leg3T.write(10);
 leg3L.write(20);
  leg4T.write(0);
 leg4L.write(110);
 leg5T.write(30);
 leg5L.write(25);
 leg6T.write(60);
 leg6L.write(30);
 delay(200);
 
  
 }
 void upPosA()
 {
  
 //up position
 
 leg1T.write (80);
 leg1L.write(130);
 leg2T.write(30);
 leg2L.write(0);
 leg3T.write(20);
 leg3L.write(110);
 leg4T.write(10);
 leg4L.write(20);
 leg5T.write(20);
 leg5L.write(170);
 leg6T.write(50);
 leg6L.write(135);
 }
 
 
 void upPosB()
 {
   
 //UP Position B

 leg1T.write (80);
 leg1L.write(60);
 leg2T.write(30);
 leg2L.write(50);
 leg3T.write(20);
 leg3L.write(60);
 leg4T.write(10);
 leg4L.write(60);
 leg5T.write(20);
 leg5L.write(65);
 leg6T.write(50);
 leg6L.write(60);
  
 }
 
 void tFromt()
 {
   
 //turn fromt
 
 leg1T.write (10);
 leg1L.write(60);
 leg2T.write(90);
 leg2L.write(50);
 leg3T.write(0);
 leg3L.write(60);
 leg4T.write(25);
 leg4L.write(60);
 leg5T.write(0);
 leg5L.write(65);
 leg6T.write(80);
 leg6L.write(60);  
 }
 
 void tBack()
 {
    //turn back
 
 leg1T.write (120);
 leg1L.write(60);
 leg2T.write(5);
 leg2L.write(50);
 leg3T.write(40);
 leg3L.write(60);
 leg4T.write(0);
 leg4L.write(60);
 leg5T.write(70);
 leg5L.write(65);
 leg6T.write(10);
 leg6L.write(60);
 }
 
 void mBack()
 {
  //move back
 leg1T.write (120);
 leg1L.write(60);
 leg2T.write(5);
 leg2L.write(50);
 leg3T.write(40);
 leg3L.write(60);
 leg4T.write(0);
 leg4L.write(60);
 leg5T.write(25);
 leg5L.write(65);
 leg6T.write(35);
 leg6L.write(60);
 
 }
 
 void mFromt()
 {
    //move fromt
 
 leg1T.write (80);
 leg1L.write(60);
 leg2T.write(30);
 leg2L.write(50);
 leg3T.write(0);
 leg3L.write(60);
 leg4T.write(25);
 leg4L.write(60);
 leg5T.write(0);
 leg5L.write(65);
 leg6T.write(80);
 leg6L.write(60);
 }
 
 void legup()
 
 {
  
   
 //UP Position B

 leg1T.write (80);
 leg1L.write(10);
 leg2T.write(30);
 leg2L.write(50);
 leg3T.write(20);
 leg3L.write(60);
 leg4T.write(10);
 leg4L.write(60);
 leg5T.write(20);
 leg5L.write(65);
 leg6T.write(50);
 leg6L.write(60);
  delay (800);
 leg1T.write (80);
 leg1L.write(40);
 leg2T.write(30);
 leg2L.write(50);
 leg3T.write(20);
 leg3L.write(60);
 leg4T.write(10);
 leg4L.write(60);
 leg5T.write(20);
 leg5L.write(65);
 leg6T.write(50);
 leg6L.write(60);
   delay (800);
   
 }
 
 void po()
 {
 leg1T.write (80);
 leg1L.write(10);
 leg2T.write(30);
 leg2L.write(50);
 leg3T.write(20);
 leg3L.write(60);
 leg4T.write(10);
 leg4L.write(60);
 leg5T.write(20);
 leg5L.write(65);
 leg6T.write(50);
 leg6L.write(60);
 }
 
 void ai()
 {
   cm = (ultrasonic.Ranging(CM));
    while (cm > 10) 
      { 
     walk();  
    cm = (ultrasonic.Ranging(CM));
      } 
      
    for(pos = 0; pos < 10; pos += 1)
     { leftTurn();} 
     delay (200);
     ai();
 }
 
/* ( THE END ) */




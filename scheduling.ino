#include <Servo.h>

Servo servo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo servo2;
int pos = 0;    // variable to store the servo position
int trigPin = 14;    // Trigger
int echoPin = 15;    // Echo
int trigPin1 = 19;    // Trigger
int echoPin1 = 18;    // Echo
int buttonPin1=53;
int buttonPin2=52;
int buttonPin3=50;
int speaker1=8;
int speaker2=9;
int speaker3=10;
int led1=41;
int led2=33;
int led3=37;
int bugger=16;
int speaker=17;
long duration, cm;
int button1=0;
int button2=0;
int i,j;
long dist2;
int e=0;
int m=0;
int buttonState1=0;
int buttonState2=0;
int buttonState3=0;



 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  servo1.attach(46);  // attaches the servo on pin 46 to the servo object
  servo2.attach(44);
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  pinMode(buttonPin3,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(bugger,OUTPUT);
  pinMode(speaker1,OUTPUT);
  pinMode(speaker2,OUTPUT);
  pinMode(speaker3,OUTPUT);
  buttonState1=LOW;
  buttonState2=LOW;
  buttonState3=LOW;
   
}



void loop(){
  Serial.print("loop\n");
  buttonState1=digitalRead(buttonPin1);
  buttonState2=digitalRead(buttonPin2);
  buttonState3=digitalRead(buttonPin3);
//open box for medicine insert
  if(buttonState3==HIGH) {
    //insert medicine
    digitalWrite(speaker1,HIGH);
    digitalWrite(speaker2,HIGH);
    digitalWrite(speaker3,HIGH);
    delay(1000);
    digitalWrite(speaker1,LOW);
    digitalWrite(speaker2,LOW);
    digitalWrite(speaker3,LOW);
    Serial.print("333\n");
     digitalWrite(led3,HIGH); 
     delay(1000);
     digitalWrite(led3,LOW);
    
       for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
       // in steps of 1 degree
        servo1.write(pos);              // tell servo to go to position in variable 'pos'
        servo2.write(pos);  
          delay(30);                       // waits 15ms for the servo to reach the position
        }
    delay(10000);
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
         servo1.write(pos);              // tell servo to go to position in variable 'pos'
         servo2.write(pos); 
           delay(30);                       // waits 15ms for the servo to reach the position
        }
     buttonState3=LOW;
    }
  //morning time setup    
 else if(buttonState1==HIGH){
  button1=0;
  //speaker morning time scheduled
  digitalWrite(speaker1,HIGH);
  digitalWrite(speaker1,LOW);
  digitalWrite(speaker3,LOW);
   delay(1000);
    digitalWrite(speaker1,LOW);
    digitalWrite(speaker2,LOW);
    digitalWrite(speaker3,LOW);
    Serial.print("1111\n");
     digitalWrite(led1,HIGH); 
     delay(1000);
     digitalWrite(led1,LOW);
      morning();
      }
  //evening time setup
 else  if(buttonState2==HIGH){
  button2=0;
  //evening time scheduled
  digitalWrite(speaker1,LOW);
  digitalWrite(speaker2,HIGH);
  digitalWrite(speaker3,LOW); 
  delay(1000);
    digitalWrite(speaker1,LOW);
    digitalWrite(speaker2,LOW);
    digitalWrite(speaker3,LOW);
    Serial.print("222\n");
     digitalWrite(led2,HIGH); 
     delay(1000);
     digitalWrite(led2,LOW); 
      evening();    
      
      }
 }

//when u r trying to setup time at morning for mornin medicine
//work for once a day medicine and work for twice a day medicine (morning)
//set morning time for once and twice a day for only morning schedule
void morning(){
   Serial.print("morning tablet set gat open\n");
  servomotor1();    
   Serial.print("morning motor morning get closed\n");  
      
            int dist2=proximity();
             //delay 10 second for looop or we can use speker to ask for insertion of medicine
             if(dist2>=20){
              //insert medicine
              digitalWrite(speaker1,LOW);
              digitalWrite(speaker1,LOW);
              digitalWrite(speaker1,HIGH);
              delay(1000);
              digitalWrite(speaker1,LOW);
              digitalWrite(speaker2,LOW);
              digitalWrite(speaker3,LOW);
              Serial.print("check morning tablet input\n");
                   for(int j=0;j<3&&dist2>=20;j++){
                    //insert medicine
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                           Serial.print("opened\n");
                           Serial.print(j);
                           Serial.print("time till now to complete request for return medicine\n");
                        digitalWrite(speaker,HIGH);//for speaker to speak connected to raspberry pi
                        servomotor1();
                        dist2=proximity();
                      
                        delay(5000);
                        digitalWrite(speaker,LOW);//stop speaker     
                          }
                 }
  
    m=1;// morning  used
  for(int i=0;i<180&&button1<=180;i++){
    
                           
    Serial.print("\n waiting for input/waiting to reach scheduled time  :  ");
    Serial.print(i);
    buttonState1=LOW;
    buttonState2=LOW;
    buttonState3=LOW;
    buttonState1=digitalRead(buttonPin1);
    buttonState2=digitalRead(buttonPin2);
    buttonState3=digitalRead(buttonPin3);
     //return and update morning schedule
      if(buttonState1==HIGH){
        Serial.print("morning updated\n");
         buttonState2==LOW;
         buttonState3==LOW;
         button1=0;
            return;
        }
     //return and put more medicine   
      if(buttonState3==HIGH){
        
        Serial.print("open box both to insert medicine\n");
        
         buttonState1==LOW;
         buttonState2==LOW;
             return;
        }
      button1+=1;
      if(e==1)button2+=1;
      delay(1000);   
      if(buttonState2==HIGH){
        
        Serial.print("selected nigh schedule time\n");
        
 
        servomotor2();           
             dist2=proximity1();
            
            //delay 10 second for looop or we can use speker to ask for insertion of medicine
             if(dist2>=20){
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
        Serial.print("check missing medicine\n");
                   for(int j=0;j<3&&dist2>=20;j++){
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                        digitalWrite(speaker,HIGH);//for speaker to speak connected to raspberry pi
                           servomotor2();
                           Serial.print("opened");
                           Serial.print(j);
                           Serial.print("time till now to complete request for return medicine\n");
                           dist2=proximity1();
                           Serial.print("222+morning\n");
                           button1+=7;
                           button2+=7;
                           delay(5000);
                           digitalWrite(speaker,LOW);//stop speaker     
                     }
               }
            e=1;
          for(int j=0;j<180;j++){
            
        Serial.print("waiting for input / to reach end of scheduled time :\n");
        Serial.print(j);
              buttonState1=LOW;
              buttonState2=LOW;
              buttonState3=LOW;
              buttonState1=digitalRead(buttonPin1);
              buttonState2=digitalRead(buttonPin2);
              buttonState3=digitalRead(buttonPin3);
            //return and update morning schedule
              if(buttonState1==HIGH){
                Serial.print("rescheduled morning\n");
                buttonState2==LOW;
                buttonState3==LOW;
                button1=0;
                    return;
                 }

            //return and update morning schedule
              if(buttonState2==HIGH){
                Serial.print("rescheduled evening\n");
              buttonState1==LOW;
              buttonState3==LOW;
              button2=0;
                  return;
                 } 
             
           //return and put more medicine  
             if(buttonState3==HIGH){
              Serial.print("return put medicine\n");
             buttonState1==LOW;
             buttonState2==LOW;
                 return;
                }
        
                button1+=1;
                button2+=1;
                delay(1000);
   
                if(button1>=180){
                  digitalWrite(speaker1,HIGH);
                           digitalWrite(speaker1,HIGH);
                           digitalWrite(speaker1,LOW);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
            Serial.print("\nreached scheduled time for morning\n");
                   servomotor1();           
                   dist2=proximity();
                  
                  //delay 10 second for looop or we can use speker to ask for insertion of medicine
                   if(dist2>=20){
                                               digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                     Serial.print("morning verify presence of medicine in box\n");
                       for(int j=0;j<3&&dist2>=20;j++){
                                                   digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                          digitalWrite(speaker,HIGH);//for speaker to speak connected to raspberry pi
                             servomotor1();
                             dist2=proximity();
                             Serial.print("morning verify presence of medicine in box\n");
                             button2+=7;
                             delay(5000);
                         digitalWrite(speaker,LOW);//stop speaker     
                          }
                     }
                     //making button1 = 0 and return to evening function as we see now morning work is done so we have to do evening schedule or alarm throw 
                     //evening function 
                      button1=0;
                      buttonState2=HIGH;
                          return ;
                        
                  }
                
                
                }

    }
    
  
  }


      if(button1>=179){
        Serial.print("\nscheduled time reached\n ");
                           digitalWrite(speaker1,HIGH);
                           digitalWrite(speaker1,HIGH);
                           digitalWrite(speaker1,LOW);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
         Serial.print("\n reached schedule time for morning\n");
             servomotor1();           
             dist2=proximity();
           
            
             //delay 10 second for looop or we can use speker to ask for insertion of medicine
             if(dist2>=20){
                                         digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
               Serial.print("morning verify presence of medicine in box\n");
                   for(int j=0;j<3&&dist2>=20;j++){
                                               digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                   Serial.print("morning verify presence of medicine in box\n");
                        digitalWrite(speaker,HIGH);//for speaker to speak connected to raspberry pi
                        servomotor1();
                        dist2=proximity();
                        
                        delay(5000);
                        digitalWrite(speaker,LOW);//stop speaker     
                          }
                 }
               
                    //making button1 = 0 and return to evening function as we see now morning work is done so we have to do evening schedule or alarm throw 
                    //evening function 
                button1=0;
           buttonState1=HIGH;
                 return ;
                        
        }



  
  
}



void evening(){
      Serial.print("EVENING scheduling done");
    servomotor2();           
             dist2=proximity1();
             
            //delay 10 second for looop or we can use speker to ask for insertion of medicine
             if(dist2>=20){
                                         digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
              
           Serial.print("evening verify presence of medicine in box\n");
                 
                   for(int j=0;j<3&&dist2>=20;j++){
                                               digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                        digitalWrite(speaker,HIGH);//for speaker to speak connected to raspberry pi
                           
                           
                           servomotor2();
                           dist2=proximity1();
                           Serial.print("morning verify presence of medicine in box\n");
                        
                           delay(5000);
                           digitalWrite(speaker,LOW);//stop speaker     
                     }
               }
    
  
  e=1;//evening used

  for(int i=0;i<180&&button2<=180;i++){
    Serial.print("\nWaiting for input/ scheduling new time\n");
    buttonState1=LOW;
    buttonState2=LOW;
    buttonState3=LOW;
    buttonState1=digitalRead(buttonPin1);
    buttonState2=digitalRead(buttonPin2);
    buttonState3=digitalRead(buttonPin3);
     //return and update morning schedule
      if(buttonState2==HIGH){
        
          Serial.print("evening reschedule done\n");
         buttonState2==LOW;
         buttonState3==LOW;
         button1=0;
            return;
        }
     //return and put more medicine   
      if(buttonState3==HIGH){
          Serial.print("Put medicine\n");
         buttonState1==LOW;
         buttonState2==LOW;
             return;
        }
      button2+=1;
      if(m==1)button1+=1;
      delay(1000);   
      if(buttonState1==HIGH){
              Serial.print("morning scheduling done\n");
             servomotor1();           
             dist2=proximity();
             
            //delay 10 second for looop or we can use speker to ask for insertion of medicine
              Serial.print("morning verify presence of medicine in box\n");
             if(dist2>=20){
                                         digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
               Serial.print("morning verify presence of medicine in box\n");
                   for(int j=0;j<3&&dist2>=20;j++){
                                               digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                        digitalWrite(speaker,HIGH);//for speaker to speak connected to raspberry pi
                           servomotor1();
                           dist2=proximity();
                           Serial.print("morning verify presence of medicine in box\n");
                           button1+=7;
                           button2+=7;
                           delay(5000);
                           digitalWrite(speaker,LOW);//stop speaker     
                     }
               }

        
            m=1;
          for(int j=0;j<180;j++){
              buttonState1=LOW;
              buttonState2=LOW;
              buttonState3=LOW;
              buttonState1=digitalRead(buttonPin1);
              buttonState2=digitalRead(buttonPin2);
              buttonState3=digitalRead(buttonPin3);
            //return and update morning schedule
              if(buttonState1==HIGH){
                 Serial.print("morning rescheduling done\n");
                buttonState2==LOW;
                buttonState3==LOW;
                button1=0;
                    return;
                 }

           //return and update morning schedule
             if(buttonState2==HIGH){
               Serial.print("evening reschedulig done\n");
               Serial.print("\n");
               buttonState1==LOW;
               buttonState3==LOW;
               button2=0;
                   return;
            } 
             
          //return and put more medicine  
             if(buttonState3==HIGH){
               Serial.print("Put medicine\n");
               buttonState1==LOW;
               buttonState2==LOW;
                 return;
            }
        
                button1+=1;
                button2+=1;
                delay(1000);
   
                if(button2>=180){
                  digitalWrite(speaker1,HIGH);
                           digitalWrite(speaker1,HIGH);
                           digitalWrite(speaker1,LOW);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                 Serial.print("evening scheduled time reached\n");
                   servomotor2();           
                   dist2=proximity1();
                    Serial.print("evening verify presence of medicine in box\n");
                  //delay 10 second for looop or we can use speker to ask for insertion of medicine
                   if(dist2>=20){
                                                       digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                     Serial.print("morning verify presence of medicine in box\n");
                     for(int j=0;j<3&&dist2>=20;j++){
                                                 digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                          digitalWrite(speaker,HIGH);//for speaker to speak connected to raspberry pi
                             servomotor2();
                             dist2=proximity1();
                              Serial.print("morning verify presence of medicine in box\n");
                             button1+=7;
                             delay(5000);
                         digitalWrite(speaker,LOW);//stop speaker     
                          }
                     }
                      button2=0;
                      buttonState1=HIGH;
                      buttonState2=LOW;
                      buttonState3=LOW;
                          return ;
                        
                  }  
                
                }

    }
    
  
  }


     if(button2>=180){
      digitalWrite(speaker1,HIGH);
                           digitalWrite(speaker1,HIGH);
                           digitalWrite(speaker1,LOW);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
         Serial.print("evening scheduled time reached\n");
             servomotor2();           
             dist2=proximity1();
            //delay 10 second for looop or we can use speker to ask for insertion of medicine
             Serial.print("morning verify presence of medicine in box\n");
             if(dist2>=20){
                                         digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
               Serial.print("morning verify presence of medicine in box\n");
                   for(int j=0;j<3&&dist2>=20;j++){
                                               digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker1,HIGH);
                           delay(1000);
                           digitalWrite(speaker1,LOW);
                           digitalWrite(speaker2,LOW);
                           digitalWrite(speaker3,LOW);
                        digitalWrite(speaker,HIGH);//for speaker to speak connected to raspberry pi
                           servomotor2();
                            Serial.print("morning verify presence of medicine in box\n");
                           dist2=proximity1();
                           delay(5000);
                           digitalWrite(speaker,LOW);//stop speaker     
                          }
                       }
                       button2=0;
                       buttonState2=HIGH;
                        return ;
                      
                        
          }  



  
  }
long proximity(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
    Serial.print("\n morning medicine presench check_distance is :  "); 
    Serial.print(cm);
    Serial.print("\n");
    return cm;
  }


long proximity1(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin1, INPUT);
  duration = pulseIn(echoPin1, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  Serial.print("\n evening medicine presench check_distance is :  ");
  Serial.print(cm);
  Serial.print("\n");
    return cm;
  }

  

void servomotor1() {
 
          //bugger
          for(int j=0;j<3;j+=1){
             Serial.print("\n1.BUZZER BUZZER BUZZER\n");
              digitalWrite(bugger,HIGH);
              delay(2000);
              digitalWrite(bugger,LOW);
              delay(2000);
          }
          for(int j=0;j<180;j+=1){
            servo1.write(j);
            delay(15);
            }
          delay(5000); 
          
          button2+=6; 
          for(int j=180;j>=0;j-=1){
            servo1.write(j);
            delay(15);
            } 
            
             
  }

void  servomotor2(){

          //bugger
          for(int j=0;j<3;j+=1){
              Serial.print("\n1.BUZZER BUZZER BUZZER\n");
              digitalWrite(bugger,HIGH);
              delay(2000);
              digitalWrite(bugger,LOW);
              delay(2000);          }
          for(int j=0;j<180;j+=1){
            servo2.write(j);
            delay(15);
            }
          delay(5000);
            
          for(int j=180;j>=0;j-=1){
            servo2.write(j);
            delay(15);
            }
           
          Serial.print("motor2\n");
  
  }

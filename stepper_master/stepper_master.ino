
#include "DFPlayer_Mini_Mp3.h"


#define MAX 1500  // Number of steps for turning loose or tight

#define trigPin 13
#define echoPin 12

#define motorPin1 2
#define motorPin2 3
#define motorPin3 4
#define motorPin4 5

#define controlPin 7
#define delayTime 4
  
#define TIGHT 1
#define LOOSE 0
#define STOP -1

#define DEBUG 1     // Set to 1 to see serial port messages, this MAY conflict with the MP3 playback !

#define SAMPLES 50   // Number of Consecutive samples before concluding distance of the object  

int dir = STOP; 
int state = LOOSE;


// TIGHT = CCW
// LOSE = CW

#define DISTANCE_TOO_CLOSE  0         // Audio File 0001.MP3
#define DISTANCE_PERFECT    1         // Audio File 0002.MP3
#define DISTANCE_FAR        2         // Audio file 0003.MP3
#define DISTANCE_TOO_FAR    3         // Audio File 0004.MP3
#define DISTANCE_START      4         // Audio File 0005.MP3


#define DISTANCE_CLOSE_CM      50      
// ignore 51 to 69
#define DISTANCE_PERFECT_CM_MIN    70
#define DISTANCE_PERFECT_CM_MAX    120
// ignore 121 to 199
#define DISTANCE_FAR_CM        220

int distance = DISTANCE_START;
int distance_old = DISTANCE_START;
int distance_new = DISTANCE_START;

long duration, dist;
    
// MP3
// 1 = Tight
// 2 = Open 
// 3 = Intro
void setup() 
{

  pinMode(controlPin, OUTPUT);
  digitalWrite(controlPin, LOW); 
  // Pins for stepper motor
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  // Pins for distance meter
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
 
  mp3_set_serial (Serial); //set Serial for DFPlayer-mini mp3 module
  mp3_set_volume (50);
  
  //mp3_stop ();

  mp3_play (5); // 3 = 3rd audio file

  // wait before starting 
  
  delay(5000);

}

void turn_loose()
{
   digitalWrite(controlPin, 0);
  int i = 0;

  for (i = 0; i < MAX; i++ )
  {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(delayTime);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(delayTime);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(delayTime);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(delayTime);
  }

 // turn motor coils all  off
 
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
 
  // mp3_stop (); // stop when turn completed

}

void turn_tight()
{
   int i = 0;

   digitalWrite(controlPin,1);

  for (i = 0; i < MAX; i++ )
  {

    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(delayTime);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    delay(delayTime);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(delayTime);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
    delay(delayTime);

  } 

  // turn motor coils all  off
 
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  
  // mp3_stop (); // stop when turn completed

}       
 
int i = 0;
int count = 0;

void loop() 
{
   // Measure the distance using the HC-SR04

   if ( i == 500) // can change this to a lower value for faster reading the sensor
   {
      i = 0;

      if (DEBUG)
      {
   
        if (DEBUG)
        {
           // Serial.print("STATE = ");
           // if (state == LOOSE) Serial.println("LOOSE");
           // if (state == TIGHT ) Serial.println ("TIGHT");
        }        
      }     
      
      digitalWrite(trigPin, LOW);  // Added this line
      delayMicroseconds(2); // Added this line  2
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10); // Added this line 10
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      dist = (duration/2) / 29.1;
      delay(1);

      if (DEBUG)
      {
         Serial.print(dist);
         Serial.println(" cm");
        // Serial.print("count=");
        // Serial.println(count);    
      }
      

     if ((dist > DISTANCE_FAR_CM) && (dist < 500))
     {
      // if (DEBUG) Serial.println("TOO_FAR");   
       if (distance_new == DISTANCE_TOO_FAR) count++; else count = 0;
       distance_new = DISTANCE_TOO_FAR;  
       if (count == SAMPLES) 
       {
          distance= distance_new;        
          if (DEBUG) Serial.println("DISTANCE IS TOO FAR");   
          count = 0; 
       }   

     }  
     else if ((dist >= DISTANCE_PERFECT_CM_MAX) && (dist < DISTANCE_FAR_CM))
     {
      // if (DEBUG) Serial.println("FAR");   
        if (distance_new == DISTANCE_FAR) count++; else count = 0;
        distance_new = DISTANCE_FAR;
        if (count == SAMPLES) 
        {            
            distance = distance_new;
            if (DEBUG) Serial.println("DISTANCE IS FAR");     
            count = 0;
        }  
        
     }
     else if ((dist >= DISTANCE_PERFECT_CM_MIN) && (dist < DISTANCE_PERFECT_CM_MAX))
     {
     //   if (DEBUG) Serial.println("PERFECT");
        if (distance_new == DISTANCE_PERFECT) count++; else count = 0;  
        distance_new = DISTANCE_PERFECT;
        if (count == SAMPLES) 
        {
          distance= distance_new;     
          if (DEBUG) Serial.println("DISTANCE IS PERFECT");
          count = 0;
        }        
     }
     else
     {  
        if (dist < DISTANCE_CLOSE_CM)
        {
         // if (DEBUG) Serial.println("TOO_CLOSE");
          if (distance_new == DISTANCE_TOO_CLOSE) count++; else count = 0;  
          distance_new = DISTANCE_TOO_CLOSE;
          if (count == SAMPLES) 
          {          
             distance= distance_new;            
             if (DEBUG) Serial.println("DISTANCE IS TOO CLOSE");
             count = 0;
          }        
        }
     }

     // Only play a sound when the distance (state) changes      
     if (distance_old != distance)
     {
       if (DEBUG) Serial.println("DISTANCE CHANGED !");
        mp3_play (distance+1);
        distance_old = distance;
        count = 0;
     }

     // check if we should change to TIGHT if current state is LOOSE
     
     if (state == LOOSE)
     {
        if (distance == DISTANCE_TOO_CLOSE)
        {
           if (DEBUG) Serial.println("WAIT !!! CHANGING MOTOR TO TIGHT");
           dir = TIGHT; 
        }
     }

     // check if we should change to LOOSE if current state is TIGHT 
     
      
     if (state == TIGHT)
     {
         if (distance == DISTANCE_FAR)
         {
            if (DEBUG) Serial.println("WAIT !!!! CHANGING MOTOR TO LOOSE");
            dir = LOOSE;
         }
     }

     if ((dir == TIGHT) && (state == LOOSE))
     {
        turn_tight();
        state = TIGHT;
       // count = 0;
      }
  
      if ((dir == LOOSE) && (state == TIGHT ))
      {
         turn_loose();
         state = LOOSE;
      //  count = 0;
      }      
  }
 
  i++;

}

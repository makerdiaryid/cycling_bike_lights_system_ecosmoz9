#include <Adafruit_NeoPixel.h>

#define PINback        6
#define PINfront         5

#define NUMPIXELSback      7
#define NUMPIXELSfront     16

int frontlightmode=0;


Adafruit_NeoPixel TAILlight = Adafruit_NeoPixel(NUMPIXELSback, PINback, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel FRONTlight = Adafruit_NeoPixel(NUMPIXELSfront, PINfront, NEO_RGB + NEO_KHZ800);

int delayval = 170; // delay for half a second


void setup() {
    TAILlight.begin(); // This initializes the NeoPixel library.
    FRONTlight.begin();
    
Serial.begin(9600);
pinMode(9, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);
pinMode(11, INPUT_PULLUP);
pinMode(12, INPUT_PULLUP);

     standbytailred();
     frontwhitelevel1();
    
}

void loop() {
   if(digitalRead(9)!=HIGH){
        Serial.println("pin 9 press");
        //hazard lamp
        hazardlamp();
        standbytailred();
    
  }else if(digitalRead(10)!=HIGH){
        Serial.println("pin 10 press");
        //change mode
        frontlightmode++;
        if(frontlightmode==0){
          frontwhitelevel1();
        }else if(frontlightmode==1){
          frontwhitelevel2();
        }else if(frontlightmode==2){
          frontwhitelevel3();
        }else if(frontlightmode==3){
          frontwarmlevel1();
        }else if(frontlightmode==4){
          frontwarmlevel2();
        }else if(frontlightmode==5){
          frontwarmlevel3();
        }else if(frontlightmode==6){
          frontwhitelevel1();
          frontlightmode=0;
        }
        while(digitalRead(10)!=HIGH){
          delay(100);
        }
  }else if(digitalRead(11)!=HIGH){
        Serial.println("pin 11 press");
        //right
        right();
       
        standbytailred();
  }else if(digitalRead(12)!=HIGH){
        Serial.println("pin 12 press");
        //left
        left();
        
        standbytailred();
  }

}

void standbytailred(){ 
  for(int i=0 ; i<NUMPIXELSback ; i++ ){
    TAILlight.setPixelColor(i, TAILlight.Color(0,200,0));
  }
  TAILlight.show();
}

void stanbyfront(){
        if(frontlightmode==0){
           frontwhitelevel1();
        }else if(frontlightmode==1){
          frontwhitelevel2();
        }else if(frontlightmode==2){
          frontwhitelevel3();
        }else if(frontlightmode==3){
          frontwarmlevel1();
        }else if(frontlightmode==4){
          frontwarmlevel2();
        }else if(frontlightmode==5){
          frontwarmlevel3();
        }
}


void frontwhitelevel1(){
  for(int i=0 ; i<NUMPIXELSfront ; i++ ){
    FRONTlight.setPixelColor(i, FRONTlight.Color(100,100,100));
  }
  FRONTlight.show();
}

void frontwhitelevel2(){
   for(int i=0 ; i<NUMPIXELSfront ; i++ ){
    FRONTlight.setPixelColor(i, FRONTlight.Color(170,170,170));
  }
  FRONTlight.show();
}


void frontwhitelevel3(){
   for(int i=0 ; i<NUMPIXELSfront ; i++ ){
    FRONTlight.setPixelColor(i, FRONTlight.Color(255,255,255));
  }
  FRONTlight.show();
}

void frontwarmlevel1(){
  for(int i=0 ; i<NUMPIXELSfront ; i++ ){
    FRONTlight.setPixelColor(i, FRONTlight.Color(100,100,20));
  }
  FRONTlight.show();
}

void frontwarmlevel2(){
    for(int i=0 ; i<NUMPIXELSfront ; i++ ){
    FRONTlight.setPixelColor(i, FRONTlight.Color(170,170,34));
  }
  FRONTlight.show();
}


void frontwarmlevel3(){
   for(int i=0 ; i<NUMPIXELSfront ; i++ ){
    FRONTlight.setPixelColor(i, FRONTlight.Color(255,255,50));
  }
  FRONTlight.show();
}

void left(){
  int countertemp=0;
  while(digitalRead(12)!=HIGH){
    countertemp++;
     if(countertemp%2==0){
        TAILlight.setPixelColor(6, TAILlight.Color(170,170,0));
        TAILlight.setPixelColor(5, TAILlight.Color(170,170,0));
        TAILlight.show();

       FRONTlight.setPixelColor(3, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(4, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(11, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(12, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(2, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(5, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(10, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(13, FRONTlight.Color(170,170,0));
        FRONTlight.show();
    }else{
        standbytailred();
        stanbyfront();
    }
    delay(300);
  }

}

void right(){
    int countertemp=0;
  while(digitalRead(11)!=HIGH){
    countertemp++;
    if(countertemp%2==0){
        TAILlight.setPixelColor(0, TAILlight.Color(170,170,0));
        TAILlight.setPixelColor(1, TAILlight.Color(170,170,0));
        TAILlight.show();
  
        
        FRONTlight.setPixelColor(0, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(7, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(8, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(15, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(1, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(6, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(9, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(14, FRONTlight.Color(170,170,0));
        FRONTlight.show();
    }else{
        standbytailred();
        stanbyfront();
    }
    delay(300);
  }
}

void left2(){
  int countertemp=0;
  while(digitalRead(12)!=HIGH){
    countertemp++;
    if(countertemp%3==0){
      TAILlight.setPixelColor(0, TAILlight.Color(70,70,0));
      TAILlight.setPixelColor(1, TAILlight.Color(70,70,0));
      TAILlight.setPixelColor(2, TAILlight.Color(255,255,0));
      TAILlight.show();
    }else if(countertemp%3==1){
      TAILlight.setPixelColor(0, TAILlight.Color(70,70,0));
      TAILlight.setPixelColor(1, TAILlight.Color(255,255,0));
      TAILlight.setPixelColor(2, TAILlight.Color(70,70,0));
      TAILlight.show();
    }else{
      TAILlight.setPixelColor(0, TAILlight.Color(255,255,0));
      TAILlight.setPixelColor(1, TAILlight.Color(70,70,0));
      TAILlight.setPixelColor(2, TAILlight.Color(70,70,0));
      TAILlight.show();
    }
    delay(300);
  }
}

void right2(){
  int countertemp=0;
  while(digitalRead(11)!=HIGH){
    countertemp++;
     if(countertemp%3==0){
        TAILlight.setPixelColor(6, TAILlight.Color(70,70,0));
        TAILlight.setPixelColor(5, TAILlight.Color(70,70,0));
        TAILlight.setPixelColor(4, TAILlight.Color(255,255,0));
        TAILlight.show();
    }else if(countertemp%3==1){
        TAILlight.setPixelColor(6, TAILlight.Color(70,70,0));
        TAILlight.setPixelColor(5, TAILlight.Color(255,255,0));
        TAILlight.setPixelColor(4, TAILlight.Color(70,70,0));
        TAILlight.show();
    }else{
        TAILlight.setPixelColor(6, TAILlight.Color(255,255,0));
        TAILlight.setPixelColor(5, TAILlight.Color(70,70,0));
        TAILlight.setPixelColor(4, TAILlight.Color(70,70,0));
        TAILlight.show();
    }
    delay(300);
  }
}

void hazardlamp(){
  int countertemp=0;
  while(digitalRead(9)!=HIGH){
    countertemp++;
    if(countertemp%2==0){
        TAILlight.setPixelColor(0, TAILlight.Color(170,170,0));
        TAILlight.setPixelColor(1, TAILlight.Color(170,170,0));
        TAILlight.setPixelColor(6, TAILlight.Color(170,170,0));
        TAILlight.setPixelColor(5, TAILlight.Color(170,170,0));
        TAILlight.show();
  
        FRONTlight.setPixelColor(3, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(4, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(11, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(12, FRONTlight.Color(170,170,0));
         FRONTlight.setPixelColor(0, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(7, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(8, FRONTlight.Color(170,170,0));
        FRONTlight.setPixelColor(15, FRONTlight.Color(170,170,0));
        FRONTlight.show();
    }else{
        standbytailred();
        stanbyfront();
    }
    delay(300);
  }
}






#include "Note.h"
#define REST 0


int tempo = 144;


int buzzer = 11;

int noteDuration[] ={


  2,  4,
   -4, 8,  4,
   2,  4,
   -2, 
   -2,
   -4, 8,  4,
   2,  4,
   -1, 
   4,

   -4, 8,  4, //10
   2,  4,
   2,  4,
   2,  4,
   -4,  8,  4,
  2,  4,
   -1,
  4,
     
   2, 4,//18
   2, 4,
   2,  4,
   2,  4,
  -4,  8,  4,
   2,  4,
   -1, 
  4,4,  

   2, 4,//26
   2, 4,
   2,  4,
   2,  4,
   -4,  8,  4,
   2, 4,
   -1, 


};


int melody[] = {


 
  
  REST, NOTE_D4,
  NOTE_G4,  NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_D5,
  NOTE_C5,  
  NOTE_A4, 
  NOTE_G4,  NOTE_AS4, NOTE_A4,
  NOTE_F4, NOTE_GS4,
  NOTE_D4,  
  NOTE_D4,

  NOTE_G4,  NOTE_AS4, NOTE_A4, //10
  NOTE_G4, NOTE_D5,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5,  NOTE_D5, NOTE_CS5,
  NOTE_CS4,NOTE_B4,
  NOTE_G4, 
  NOTE_AS4,
     
  NOTE_D5, NOTE_AS4,//18
  NOTE_D5, NOTE_AS4,
  NOTE_DS5, NOTE_D5,
  NOTE_CS5, NOTE_A4,
  NOTE_AS4,  NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_D4,
  NOTE_D5,  
  REST,  NOTE_AS4, 

  NOTE_D5, NOTE_AS4,//26
  NOTE_D5, NOTE_AS4,
  NOTE_F5, NOTE_E5,
  NOTE_DS5, NOTE_B4,
  NOTE_DS5,  NOTE_D5, NOTE_CS5,
  NOTE_CS4, NOTE_AS4,
  NOTE_G4,  
  
};


int notes = sizeof(melody) / sizeof(melody[0]);

int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDurationDelay = 0;

// 新增這些變數

bool PlayMusic = false;
bool Hit = false;
int CurrentTime = 0 ;
int LastTime  = 0;
int thisNote = 0

void setup() {
  

  PlayMusic = false;
  pinMode( 4 , INPUT );
  pinMode( 5 , OUTPUT );

  Current = millis();
  LastTime = CurrentTime ; 

}

void loop() {

    Current = millis();
    

  if ( digitalRead( 4 ) == HIGH && ( Hit == false) ){

        PlayMusic = !PlayMusic ;
        Hit = true;
        delay(12);

  }
  
  if ( digitalRead( 4 ) == LOW && ( Hit == true)   ){

        Hit = false;
  }



  if(  thisNote <= notes ){

      thisNote = 0;
      PlayMusic = false;
  
  }

  if(PlayMusic == true ){

      divider = noteDuration[thisNote];
      if (divider > 0) {
      
        noteDurationDelay = (wholenote) / divider;
      } else if (divider < 0) {
      
        noteDurationDelay = (wholenote) / abs(divider);
        noteDurationDelay *= 1.5; 
      }
      

      if( CurrentTime - LastTime  > noteDurationDelay  ){

          noTone(buzzer);
          thisNote =  thisNote + 1;
          LastTime = CurrentTime ; 

      }
      else{
          tone(buzzer, melody[thisNote]);
      }

      
  }
  else{

    LastTime = CurrentTime ; 

  }
  
  

}


/*
  for (int thisNote = 0; thisNote < notes ; thisNote = thisNote + 1) {

   
    divider = noteDuration[thisNote];
    if (divider > 0) {
      
      noteDurationDelay = (wholenote) / divider;
    } else if (divider < 0) {
     
      noteDurationDelay = (wholenote) / abs(divider);
      noteDurationDelay *= 1.5; 
    }

   
    tone(buzzer, melody[thisNote], noteDurationDelay*0.9);

   
    delay(noteDurationDelay);
    
  
    noTone(buzzer);
  }





*/
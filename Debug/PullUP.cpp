#include "Energia.h"

#line 1 "C:/Users/ErnestoVM/Documents/CCS/PullUP/PullUP.ino"

#define PUSH       	P2_2
#define SDTBY_LED  	P2_0
#define PWRON_LED  	P2_1
#define PIN_EN_RASP	P2_3

void state(int b1, int b2, int b3);
void setup();
void loop();

#line 7
int counter = 0;

void state(int b1, int b2, int b3)
{

	digitalWrite(PIN_EN_RASP, b1);
	digitalWrite(PWRON_LED, b2);
	digitalWrite(SDTBY_LED, b3);

}


void setup()
{

	Serial.begin(9600);
	pinMode(PUSH, INPUT_PULLUP);

	pinMode(PIN_EN_RASP, OUTPUT);
	pinMode(PWRON_LED, OUTPUT);
	pinMode(SDTBY_LED, OUTPUT);


state(1,1,0);


}




void loop()
{
  if (digitalRead(PUSH) == HIGH){
	  delay(2000);
	  state(1,1,0);
	  counter++;

	  if(counter >= 4){		
		  state(1,1,1);

		  for(int a = 0;a<=20;a++){	
			 delay(2500);

			 if (digitalRead(PUSH) == HIGH){counter++;}

			 if(counter >= 8){		
				delay(2000);
			 	state(0,0,1);
			 	counter=0;
			 	a=20;
			 	}
		  }
		  state(0,0,1);
		  counter=0;
		  delay(2000);
	  }


  }else if (digitalRead(PUSH) == LOW){
	  	counter=0;

  }
}





#define PUSH       	P2_2
#define SDTBY_LED  	P2_0
#define PWRON_LED  	P2_1
#define PIN_EN_RASP	P2_3

int counter = 0;

void state(int b1, int b2, int b3)
{

	digitalWrite(PIN_EN_RASP, b1);
	digitalWrite(PWRON_LED, b2);
	digitalWrite(SDTBY_LED, b3);

}

// setup initializes serial and the button pin
void setup()
{

	Serial.begin(9600);
	pinMode(PUSH, INPUT_PULLUP);

	pinMode(PIN_EN_RASP, OUTPUT);
	pinMode(PWRON_LED, OUTPUT);
	pinMode(SDTBY_LED, OUTPUT);

//function (1,1,0)=AutoON, (0,0,1)=AutoOFF
state(1,1,0);
//state(0,0,1);

}


// loop checks the button pin each time,
// and will send serial if it is pressed
void loop()
{
  if (digitalRead(PUSH) == HIGH){
	  delay(2000);
	  state(1,1,0);
	  counter++;

	  if(counter >= 4){		//10 seconds to controlled shutdown
		  state(1,1,1);

		  for(int a = 0;a<=20;a++){	//60 seconds for auto OFF
			 delay(2500);

			 if (digitalRead(PUSH) == HIGH){counter++;}

			 if(counter >= 8){		//20 seconds to forced shutdown
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

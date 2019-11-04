/*
ax12.h
	ax12SetRegister
	ax12GetRegister
	ax12SetRegister2
	ax12GetRegister2
    SetPosition(id,pos)
    GetPosition(id)
    TorqueOn(id)
    Relax(id)
    GetLeftIRData(id)
    GetCenterIRData(id)
    GetRightIRData(id)
    GetObstacles(id)
    PlayTone(id, note)
Servos
    d0,d1,d2
Buttons
    d3,d4,d5
Max rotation
    12: 0 1023
    13 - 18: 200 - 800
	
Observation:
	c++11 does not work
    enuns don't work
*/
#include <ax12.h>
#include <Servo.h>

//buttons
const int button_1 = 3;
const int button_2 = 4;
const int button_3 = 5;
const int button_4 = 6;

//arm velocity
int vel = 100;

//servos
Servo servo_1;
Servo servo_2;
Servo servo_3;

bool hand_test;

// move arm to a position
void move(int a1,int a2,int a3,int a4,int a5,int a6, int a7)
{
  
	SetPosition(12,a1);
	SetPosition(13,a2);
	SetPosition(14,a3);
	SetPosition(15,a4);
	SetPosition(16,a5);
	SetPosition(17,a6);
	SetPosition(18,a7);
	
	//slows the arm movement towards the next position
	//	needs to be changed every time a new target position is chosen
	ax12SetRegister2(12, 32, vel-75);
	ax12SetRegister2(13, 32, vel);
	ax12SetRegister2(14, 32, vel);
	ax12SetRegister2(15, 32, vel-50);
	ax12SetRegister2(16, 32, vel-50);
	ax12SetRegister2(17, 32, vel);
	ax12SetRegister2(18, 32, vel);
}

//center the arm servos
void center()
{
	move(512,512,512,512,512,512,512);
	delay(800);
}

void hello()
{
	//set velocity to 100
    vel = 100;
    
	// all servos position for hello movement as indexes of the array
	int m_12[] = {500,500,500,500,500,500,500};
	int m_13[] = {475,475,475,475,475,475,475};
	int m_14[] = {546,546,546,546,546,546,546};
	int m_15[] = {841,723,671,723,671,723,671};
	int m_16[] = {183,303,354,300,354,300,354};
	int m_17[] = {534,667,500,667,500,667,500};
	int m_18[] = {511,511,511,511,511,511,511};
	int deay[] = {800,1000,1000,1000,1000,1000,1000};
	int siz = 7;

	
	for(int i=0 ; i<siz ;i++)
	{
        //iterates the arrays to move the arm to position
		move(m_12[i],m_13[i],m_14[i],m_15[i],m_16[i],m_17[i],m_18[i]);
		delay(deay[i]);
	}		
}

void jaken()
{
	//set velocity to 100
    vel = 200;
  
	// all servos position for hello movement as indexes of the array
	int m_12[] = {512,512,512,512,512,512,512};

	int m_13[] = {600,600,600,600,600,600,600};
	int m_14[] = {420,420,420,420,420,420,420};

	int m_15[] = {650,850,512,850,512,850,650};
	int m_16[] = {375,150,512,150,512,150,375};

	int m_17[] = {512,512,512,512,512,512,512};

	int m_18[] = {512,512,512,512,512,512,512};
	int deay[] = {800,800,800,800,800,800,800};
	int siz = 7;

	for(int i=0 ;i<siz;i++)
	{
		//iterates the arrays to move the arm to position
		move(m_12[i],m_13[i],m_14[i],m_15[i],m_16[i],m_17[i],m_18[i]);
		delay(deay[i]);
	}	
}

int get_input()
{
    // button inputs
    if (digitalRead(button_1) == HIGH)
        return 0;
    else if (digitalRead(button_2) == HIGH)
        return 1;
    else if (digitalRead(button_3) == HIGH)
        return 2;
    else if (digitalRead(button_4) == HIGH)
        return 3;
    else
        return 4;
}

//change the hand position
void hand(int upper, int middle, int lower)
{
    servo_1.write(upper);
    servo_2.write(middle);
    servo_3.write(lower);
}

void setup()
{
	//servos input
    servo_1.attach(0);
    servo_2.attach(1);
    servo_3.attach(2);
	
	//buttons input
    pinMode(button_1, INPUT);
    pinMode(button_2, INPUT);
    pinMode(button_3, INPUT);
    pinMode(button_4, INPUT);

	//set hand to position
    hand(0, 0, 0);
    
    hand_test = false;
}

void loop()
{
	//get input();
    int state = get_input();
    
    if (state == 0)
    {
      hello();
    }
    else if (state == 1)
    {
       center();
    }
    else if (state == 2)
    {
        jaken();
    }
    else if(state == 3)
    {
       if(hand_test == false)
        {
          hand(0, 0, 0);
          hand_test=true;
          delay(500);
        }
        else
        {
          hand(180, 180, 180);
          hand_test=false;
          delay(500);
        }
    }
}

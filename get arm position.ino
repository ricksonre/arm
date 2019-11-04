#include <ax12.h>
#include <BioloidController.h>
 
/*
*	This code reads the position of the servos in the arm an print them
*/

BioloidController bioloid = BioloidController(1000000);

void setup(){
  Serial.begin(9600);
  
  // moves all arms to initial position
  SetPosition(12, 512);
  SetPosition(13, 512);
  SetPosition(14, 512);
  SetPosition(15, 512);
  SetPosition(16, 512);
  SetPosition(17, 512);
  SetPosition(18, 512);
  delay(100);
  
  // Turning torque off of the servos on the arm.
  // 	This is done so you can move the arm manually
  Relax(12);    
  Relax(13);
  Relax(14);
  Relax(15);
  Relax(16);
  Relax(17);
  Relax(18);
  delay(1000);
}
 
void loop()
{
	
	//reads the current position of the arm from the register and prints it
    Serial.println(ax12GetRegister(12, 36, 2));
    Serial.println(ax12GetRegister(13, 36, 2));
    Serial.println(ax12GetRegister(14, 36, 2));
    Serial.println(ax12GetRegister(15, 36, 2));
    Serial.println(ax12GetRegister(16, 36, 2));
    Serial.println(ax12GetRegister(17, 36, 2));
    Serial.println(ax12GetRegister(18, 36, 2));
    Serial.println();
	delay(500);
}

/*
	What Imagine your older code would be like 
*/
/*
	void setup()
	{
	  Serial.begin(9600);
	  
	  // moves all arms to initial position
	  SetPosition(12, 512);
	  SetPosition(13, 512);
	  SetPosition(14, 512);
	  SetPosition(15, 512);
	  SetPosition(16, 512);
	  SetPosition(17, 512);
	  SetPosition(18, 512);
	  delay(100);
	  
	  // Turning torque off of the servos on the arm.
	  // 	This is done so you can move the arm manually
	  Relax(12);    
	  Relax(13);
	  Relax(14);
	  Relax(15);
	  Relax(16);
	  Relax(17);
	  Relax(18);
	  delay(1000);
	}
 
	void loop()
	{
		
		//reads the current position of the arm from the arm and set the position of the other arm as it.
		SetPosition(1,ax12GetRegister(12, 36, 2));
		SetPosition(2,ax12GetRegister(13, 36, 2));
		SetPosition(3,ax12GetRegister(14, 36, 2));
		SetPosition(4,ax12GetRegister(15, 36, 2));
		SetPosition(5,ax12GetRegister(16, 36, 2));
		SetPosition(6,ax12GetRegister(17, 36, 2));
		SetPosition(7,ax12GetRegister(18, 36, 2));
		Serial.println();
		delay(500);
	}

*/


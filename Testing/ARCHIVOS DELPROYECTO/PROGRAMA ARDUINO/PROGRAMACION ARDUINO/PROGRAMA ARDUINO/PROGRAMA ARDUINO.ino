#include <Servo.h>
Servo myservo; 
Servo myservo2;
Servo myservo3;  
#include <Stepper.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 2, 5, 6, 7);
//Stepper Motorpaso1(stepsPerRevolution, 1,8,9,10);
int pos = 130; 
int pos1 = 0; 
int pos2 = 80;
int pao=0;
int var1;

int ang1=0;
int ang2=0;
int ang3=0;

void setup() 
{
   myStepper.setSpeed(20);
myservo.attach(9); 
myservo2.attach(10); 
myservo3.attach(11); 
Serial.begin(9600);
}

void loop() 
{
   if (Serial.available())
   {
  
  var1=Serial.read();
   
   //MOTOR DE PASO  
   if (var1=='a')
    { 
        myStepper.step(1);
        pao=pao+1;
        Serial.write(pao);
     }
       
     if (var1=='b')
     {//myStepper.step(0);
      }

      if (var1=='c')
    { 
      myStepper.step(-1);
      pao=pao-1;
      Serial.write(pao);
     }
    //SERVO 4  
      if (var1=='j')
    { 
      myservo.write(pos);
      pos++;
      Serial.write(pos);
     // myservo.write(90);
    
      
   }
         if (var1=='k')
        
    { 
    
      myservo.write(pos);
      
    
   }
        if (var1=='z')
    { 
    
      myservo.write(pos);
      pos--;
    Serial.write(pos);
   }
     
         if (var1=='g')
    { 
      myservo2.write(pos1);
      pos1++;
      Serial.write(pos1);
     // myservo.write(90);
    
      
   }
         if (var1=='h')
    { 
    
      myservo2.write(pos1);
      
    
   }
        if (var1=='i')
    { 
    
      myservo2.write(pos1);
      pos1--;
       Serial.write(pos1);
    
   }

    
    if (var1=='d')
    { 
      myservo3.write(pos2);
      pos2++;
       Serial.write(pos2);
     // myservo.write(90);
    
      
   }
         if (var1=='e')
    { 
    
      myservo3.write(pos2);
      
    
   }
        if (var1=='f')
    { 
    
      myservo3.write(pos2);
      pos2--;
       Serial.write(pos2);
    
   }
   
   
//AUTOMATICO
if(var1=='w')
{
   myStepper.step(100);
   delay(1000);

   for (int a = 80; a >= 34; a -= 1) 
   { 
    myservo3.write(a);              
    delay(50);                      
  }
   
  for (int a = 0; a <= 50; a += 1) 
   { 
    myservo2.write(a);              
    delay(50);                      
  }
   
   
   myservo.write(30);
   delay(1000);

  for (int a = 50; a >= 0; a -= 1) 
   { 
    myservo2.write(a);              
    delay(50);                      
  }

       for (int a = 34; a <= 80; a += 1) 
   { 
    myservo3.write(a);              
    delay(50);                      
  }
   
  
   //myservo.write(130);
   //myservo.write(130);
  
   myStepper.step(-100);
   delay(1000);
      for (int a = 80; a >= 34; a -= 1) 
   { 
    myservo3.write(a);              
    delay(50);                      
  }
    for (int a = 0; a <= 50; a += 1) 
   { 
    myservo2.write(a);              
    delay(50);                      
  }

    myservo.write(130);
   delay(1000);

     for (int a = 50; a >= 0; a -= 1) 
   { 
    myservo2.write(a);              
    delay(50);                      
  }

          for (int a = 34; a <= 80; a += 1) 
   { 
    myservo3.write(a);              
    delay(50);                      
  }
   
}
}


 
 }


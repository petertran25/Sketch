//Peter Tran December 13 2022
 //define IO pin 
  #define SpeedLeft 5
  #define SpeedRight 6
  #define DirectionLeft 7
  #define DirectionRight 8
  #define PowerAll 3 
void setup() { //setting the motor pins as outputs
 pinMode(SpeedLeft,OUTPUT);
 pinMode(SpeedRight,OUTPUT); 
 pinMode(DirectionLeft,OUTPUT);
 pinMode(DirectionRight,OUTPUT);
 pinMode(PowerAll, OUTPUT);
}
void foward(int speed){  //basic for foward
  digitalWrite(DirectionRight,HIGH);
  analogWrite(SpeedRight,speed);
  digitalWrite(DirectionLeft,HIGH);
  analogWrite(SpeedLeft,speed);
  digitalWrite(PowerAll,HIGH);
 
}
void backward(int speed){ //backwards, meaning right and left speed is low
 digitalWrite(DirectionRight,LOW);
  analogWrite(SpeedRight,speed);
  digitalWrite(DirectionLeft,LOW);
  analogWrite(SpeedLeft,speed);
  digitalWrite(PowerAll,HIGH);

}
void right(int speed){ //Turning right = wheels on the right stop 
  digitalWrite(DirectionRight,HIGH);
  analogWrite(SpeedRight,speed);
  digitalWrite(DirectionLeft,HIGH);
  analogWrite(SpeedLeft,0);
  digitalWrite(PowerAll,HIGH);

}
void left(int speed){ //Turning left = wheels on the left stop 
  digitalWrite(DirectionRight,HIGH); 
  analogWrite(SpeedRight,0);
  digitalWrite(DirectionLeft,HIGH);
  analogWrite(SpeedLeft,speed);
  digitalWrite(PowerAll,HIGH);

}
void speedUpfoward(){
  for(int i=0; i<=255; i++){
    foward (1);
    delay (20);
  }
}
void slowDownforward(){
  for(int i=255; i>=0; i--){
    foward(i);
    delay(20);
  }
}
void loop() { 
foward(100); 
delay(7500);
//go foward with the speed of 100 for 7.5 seconds
left(80);
delay(1000);
//go left at the speed of 80 (the speed didn't really matter that much for left and right) for exactly 1 second for a almost 90 degree turn
foward(85); 
delay(4500);
//go foward so after the turn, it immedietly goes straight for 4.5 seconds 
right(80);
delay(1500);
//turn right so is is pointed towards square 3
foward(100);
delay(5500);
//go foward straight down to sqaure 3 for 5.5 seconds at the speed of 100
right(85);
delay(1000);
//turn so it is facing the hallway door for one second
foward(100);
delay(7500);
//go straight toward the hallway at the speed of 100 for 7.5 seconds
left(80);
delay(1000);
//goes left for 1 second so it is facing sqaure 4 so the next line of code can go straight in
foward(100);
delay(800);
//Sqaure 4 

}

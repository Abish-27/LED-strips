#define red 5
#define blue 6
#define green 3

int mode = 0;
int brightness = 0;

void setup() {
  pinMode(red, OUTPUT);
  //pinMode(green, OUTPUT);
  //pinMode(blue, OUTPUT);
}

void loop() {
  //digitalWrite(red, HIGH);
  //digitalWrite(blue, HIGH);
  //digitalWrite(green, HIGH);
  if (mode == 0){
    defaultMode();
  }
  else if(mode == 1){
    discoMode();
  }
  else if(mode == 2){
    fadeMode();
  }

}


//--- LIGHT MODES ---//

void discoMode(){
  change(100, 100, 100, 0.5);
  //delay(500);
  allOff();
  change(80, 250, 50, 0.5);
  //delay(500);
  allOff();
  change(250, 250, 10, 0.5);
  //delay(500);
  allOff();
  change(30, 250, 250, 0.5);
  //delay(500);
  allOff();

}

void defaultMode(){
  
  Red(1);
  Blue(1);
  Green(1);
  Purple(1);
  Cian(1);
  Yellow(1);

}

void fadeMode(){
  for(int i = 0; i < 250; i++){
    analogWrite(red, brightness);
    brightness += 1;
    delay(10);
  }

  delay(500);

  for(int i = 0; i < 250; i++){
    analogWrite(red, brightness);
    analogWrite(blue, brightness);
    analogWrite(green, brightness);
    brightness -= 1;
    delay(10);
  }
  
  fadeMode();

}
  





//--FUNCTIONS TO CHANGE LIGHT BRIGHTNESS--
void change(int redB, int greenB, int blueB, double seconds){
  seconds = seconds * 1000;
  change(redB, greenB, blueB);
  delay(seconds);
}

void change(int redB, int greenB, int blueB){
  if(redB == 251){
    turnOff(red);
  }
  else{
    analogWrite(red, redB);
  }

  if(greenB == 251){
    turnOff(green);
  }
  else{
    analogWrite(green, greenB);
  }

  if(blueB == 251){
    turnOff(blue);
  }
  else{
    analogWrite(blue, blueB);
  }
  
}
void turnOff(int color){
  digitalWrite(color, HIGH);
}

void allOff(){
  digitalWrite(red, HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(green, HIGH);
  delay(400);

}


//-------------COLOURS-----------//
void Red(int t){
  change(10, 251, 251, t);//red
}

void Blue(int t){
  change(251, 251, 10, t);//blue
}

void Green(int t){
  change(251, 10, 251, t);//green
}

void Purple(int t){
  change(80, 250, 80, t);//purple
}

void Yellow(int t){
  change(80, 80, 250, t);//yellowish-green
}

void Cian(int t){
  change(250, 80, 80, t);//cian
}

  
  
  

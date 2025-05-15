#include <PCM.h>
#include <SoftwareSerial.h>

//SoftwareSerial BT(10,9); // BT(Tx,Rx)
int c = 1;
int i = 0;
int state = 0;
int Incoming_value = 0;
//char Incoming_value = 0;

void setup()
{
  //BT.begin(9600);
  Serial.begin(9600);    // Bit rate for serial communication
  //Serial.begin(38400); // Bit rate for bluetooth communication
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  //pinMode(10,INPUT);
  //pinMode(9,OUTPUT);
}
void loop()
{
  //tone(11, 400);
  //tone(11, 3000);

  //BT.listen();
  //if(BT.available() > 0)
  if(Serial.available() > 0){
    if(c == 1){
      pinMode(1, OUTPUT);
      //BT.write("Welcome!");
      Serial.write("Welcome!");
      c = 0;
    }

    //Incoming_value = BT.read();
    Incoming_value = Serial.read();
    Serial.print(Incoming_value*20);
    //Serial.println(Incoming_value*20);

//    char sample[1076];
//    if(i == 1076){
//      startPlayback(sample, sizeof(sample));
//    }
//    else{
//      sample[i] = Incoming_value;
//    }
//    i = i + 1;

    pinMode(11, OUTPUT);
    tone(11, Incoming_value*20);
    //if(Serial.available() == 0){
      delay(30);
      noTone(11);
      delay(30);
    //}
    
    Serial.print("\n");
    if(Incoming_value == 49){ // 49 ascci
      pinMode(13, OUTPUT);
      digitalWrite(13, HIGH);
      pinMode(8, OUTPUT);
    }
    else if(Incoming_value == 48){ // 48 ascci
      pinMode(13, OUTPUT);
      digitalWrite(13, LOW);
      pinMode(8, INPUT);
    }
  }
 
}

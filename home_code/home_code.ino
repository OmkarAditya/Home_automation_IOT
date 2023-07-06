  #include <SoftwareSerial.h>
#include <dht.h>
dht DHT;

const int mqpin=A1;
const int dhtpin=6;
const int ldrPin = A0;
const int pir = 9;  
const int relay1=3;
const int relay2=8;
const int alarm=5;

char data;
float sensorValue; 
int val = 0;  



int flag1 = 0;             
int flag2 = 0;
   
float arr[4];

void setup() {
  // put your setup code here, to run once:
  pinMode(ldrPin, INPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(alarm,OUTPUT);
  pinMode(pir,INPUT);
  Serial.begin(9600); // sets the serial port to 9600

}

void loop() {

   float ldr = analogRead(ldrPin);
   val = digitalRead(pir);  // read input value
  //BLUETOOTH CODE
  if(Serial.available()>0){
    data=Serial.read();
//    Serial.println(data); 
    if(data=='1'){
      flag1=1;
      digitalWrite(relay1,LOW);
   
     
    }
    else if(data=='2'){
      flag1=0;
      digitalWrite(relay1,HIGH);
      
 
    }
    else if(data=='3'){
      flag2=1;
      digitalWrite(relay2,LOW);  
       
    
    }
    else if(data=='4'){ 
      flag2=0;
      digitalWrite(relay2,HIGH);
      
    }   
    else if(data=='0'){
      exit(0);  
    } 
    else if(data=='5'){
      digitalWrite(relay1,HIGH);
      digitalWrite(relay2,HIGH);      
    }

  }
 


  //LDR SENSOR
  if (ldr <= 840) {
    if(flag1!=1){
      
    
    digitalWrite(relay1, HIGH);
//    Serial.print("Its DAY Time, Turn OFF the LED : ");
     arr[0]=ldr;
//    Serial.println(ldr);
    }
  
  } 
  
 
  else {
    digitalWrite(relay1, LOW);
//    Serial.print("Its NIGHT time, LED is TURNED ON: ");
//    Serial.println(ldr);
  }
  


  //PIR SENSOR
    if(val==1){           // check if the input is HIGH
    digitalWrite(relay2, LOW);  // turn LED ON
//      Serial.println("Motion detected!");
      
    }
  else {
    if(flag2!=1){
    digitalWrite(relay2, HIGH); // turn LED OFF
//      Serial.println("NO MOTION!");

  }
  }
  


  //DHT SENSOR
  int chk = DHT.read11(dhtpin);
//  Serial.print("Temperature = ");
  arr[1]=DHT.temperature;
//  Serial.println(DHT.temperature);
//  Serial.print("Humidity = ");
  arr[2]=DHT.humidity;
//  Serial.println(DHT.humidity);
//  delay(1000);


  //GAS SENSOR
  sensorValue = analogRead(mqpin); // read analog input pin 0
//  Serial.print("Gas Sensor Value: ");
  arr[3]=sensorValue;
//  Serial.println(sensorValue);    
//  Serial.print(" ");
   // 200 limit safety limit
   if(sensorValue>=390){
      digitalWrite(alarm,HIGH);
   
//      Serial.println("NOT SAFE");
   }
   else{
      digitalWrite(alarm,LOW);
    
//      Serial.println("U ARE SAFE");
   }

//  Serial.println("***********************************************************");
    
//   Serial.write((byte*)arr, sizeof(arr));
  for(int g=0;g<4;g++){
    Serial.println(arr[g]);
  }
  delay(1000);

}

# Home_automation_IOT
AN IOT PROJECT(USING ARDUINO,PYTHON,HTML) INTEGRATED WITH THINGSPEAK AND MIT APP INVENTOR WITH A COMBINATION OF SENSORS AND BLUETOOTH
,ALSO A WEBSITE IS CREATED WHICH SHOWS THE GRAPH VALUES FRM THINGSPEAK

COMPONENTS USED:
arduino, breadboard,wires,bulbs, ldr sensor, dht11 sensor, pir sensor , gas sensor(mq6), bluetooth module, relay


SOFTWARE USED: arduino IDE, Python IDE, thingspeak, MIT app inventor

NOTE: TO RUN ARDUINO CODE FIRST INSTALL DHTLib.zip FILE and include the library in arduino ide by sketches->Include library->Add .zipfile

I have shown the working of my model in two linked videos with full description below-


1.USE OF VARIOUS SENSORS AND DATA TRANSMISSION TO THINGSPEAK

https://github.com/OmkarAditya/Home_automation_IOT/assets/108687318/66033769-8346-4be1-89de-bb89c7a24bc7

2.DYNAMIC DATA TRANMISSION TO THINGSPEAK VIA PYTHON

![thingspeak](https://github.com/OmkarAditya/Home_automation_IOT/assets/108687318/887aa5d4-f5cf-40a9-83be-6ebd6ddc0c45)

3. WEBSITE LIVE DATA TRANSMISSION
![website1png](https://github.com/OmkarAditya/Home_automation_IOT/assets/108687318/7288dd11-37f0-45cd-9999-eafc96a522bf)
![website2](https://github.com/OmkarAditya/Home_automation_IOT/assets/108687318/7f314270-a3ec-4aa4-bfbd-d908edba143a)


4.USE OF BLUETOOTH MODULE

https://github.com/OmkarAditya/Home_automation_IOT/assets/108687318/3a9209dc-68ad-4d7d-9309-bc2796622349

5. BLUETOOTH APP FROM MIT APP INVENTOR
 
![bluetooth](https://github.com/OmkarAditya/Home_automation_IOT/assets/108687318/ce79ab9e-a834-4b4b-8205-d6a2c5776d23)

BRIEF EXPLAINATION OF THE WORKING:

1. Through arduino we collect data from various sensors.
2. DHT11 sensor detects temperature ,humidity and data is dynamically sent to thingspeak to detect graphically
3. LDR sensors detect the intensity of light in surrounding..if it is dark then led1 turns on
4. PIR sensor detects human motion and if so turns on the second led
5. Gas sensor detects smoke and if so then the alarm is turned on and so is an red led light connected on the breadboard
6. BLUETOOTH module helps in connecting the MIT app to our IOT system
   a) ON_LED1 button turns on the first room led on being pressed and OFF_LED1 button turns off the first room led
   b) ON_LED2 button turns on the second room led on being pressed and OFF_LED1 button turns off the first room led
   c) VOICE RECOGNIZATION THROUGH GOOGLE SERVICES: if we tell "ON FIRST ROOM" it ons first room and if we tell "ON SECOND ROON" it ons second room on pressing the voice button


# ESP32-Tempidity

This is the backbone of Tempidity project where you set up the sensors and send the data of those sensors to firebase .


## Installation and Requirements

#### Firstly Get an ESP32(WITH WIFI MODULE) ,a microUSB cable, DH-11 sensor, IR sensor , Jump cables and 2 Bread boards .  

- Now attach the two breadboards and fix the ESP32 on breadboard. For reference(This is a google Image) ![](https://cdn.shopify.com/s/files/1/0609/6011/2892/files/doc-breadboard-wiring-dht11-esp32-arduino-example.jpg)

- Then conect the cables according to the Labels on sensor 

- It should look like this. This is my Image.
![](https://github.com/vegeta2op/Tempidity/assets/71753965/99c1b13b-baa3-4257-9d0e-31a188049246)

#### Make a firebase account from google.  
- In firebase make a new project and name it anything you want to.
- Under build, Go to RealTime Database on the menu and make a new Database , Choose the nearest server , and keep it in test mode for the time being . 
- Now copy the URL that's visible and paste it in notepad. 

#### Fetch the API key 
- You can find the Web API KEY in:
```bash
(gear-next-to-project-name) > Project Settings > General
```
- Take a note of that too

- Go to the program and edit the parameters in the lines I've commented.

#### Libraries

- Go to the Library Manager of arduino IDE and add `DHT..` and `Firebase for ESP32 and ESP8266..`
- Add `ESP32` and `ESP8266` Library. If your ESP32 is undectable then download a driver from [here](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads)
- Choose the ESP32 board you own 
- Save and run the program while holding the boot button .


    
## Screenshots

- Firebase Shows the updated code

![App Screenshot](https://github.com/vegeta2op/ESP-Tempidity/assets/71753965/3c4fea91-b923-490c-813d-d3b9eaba78dc)

### Now go for the other part of Project [here](https://github.com/vegeta2op/Tempidity)  

## Tech Stack

**Language :** C++ for ESP32


## License

[GNU](https://choosealicense.com/licenses/gpl-3.0/)


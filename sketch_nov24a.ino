#include<WiFi.h>
#include <DHT.h>
#include<Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define WIFI_SSID "SSID" //Enter SSID or wifi name
#define WIFI_PASSWORD "password" //Enter the password of wifi
#define API_KEY "API Key" //fetch the API key from firebase during setup
#define DATABASE_URL "URL" //enter the URL of database its being stored in
 
#define SENSOR_PIN 4
#define DHT_SENSOR_PIN 25
#define DHT_SENSOR_TYPE DHT11
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

 FirebaseData fbd;
 FirebaseAuth auth;
 FirebaseConfig config;

 unsigned long sendDataPrevMillis=0;
 bool signupOK = false;
 int state=0;
 float humi  = 0.0f;
 float tempC = 0.0f;

 void setup()
{
 
 
  Serial.begin(115200);
  pinMode(SENSOR_PIN, INPUT);
  dht_sensor.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting Wifi");
   while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  Serial.println();
  config.api_key = API_KEY;
  config.database_url=DATABASE_URL;
  if (Firebase.signUp(&config, &auth ,"","")){
    Serial.println("singUp OK");
    signupOK=true;

  }
  
  config.token_status_callback= tokenStatusCallback;
  Firebase.begin(&config , &auth);
  Firebase.reconnectWiFi(true);

}
void loop()
{
  if(Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 5000 || sendDataPrevMillis== 0))
  {
    sendDataPrevMillis =millis();
    //ir sensor data bruh
    int state = digitalRead(SENSOR_PIN);
    humi  = dht_sensor.readHumidity();
    tempC = dht_sensor.readTemperature();
    if(Firebase.RTDB.setInt(&fbd, "Sensor/IR_data",state))
    {
      Serial.println();
      if (state == LOW) {
        Serial.println("The obstacle is present");
        Serial.print("-successfully saved to : " + fbd.dataPath());
        Serial.println(" (" + fbd.dataType() +  ")" ); 
    }
    else{
      Serial.println("The obstacle is not present");
        Serial.print("-successfully saved to : " + fbd.dataPath());
        Serial.println(" (" + fbd.dataType() +  ")" ); 
    }
    }
    if(Firebase.RTDB.setFloat(&fbd, "Sensor/Humidity",humi))
    {
      Serial.println();
      if ( isnan(humi))
      {
        Serial.println("Failed to read Humidity");
      }else{
        Serial.print("Humidity: ");
        Serial.print(humi);
        Serial.println("%");
        Serial.print("-successfully saved to : " + fbd.dataPath());
      }
    }
    if(Firebase.RTDB.setFloat(&fbd, "Sensor/Temp_sensor",tempC))
    {
      Serial.println();
      if ( isnan(tempC))
      {
        Serial.println("Failed to read temperature");
      }else{
        Serial.print("Temperature: ");
        Serial.print(tempC);
        Serial.println(" C");
        Serial.print("-successfully saved to : " + fbd.dataPath());
      }
    }
    
    else{
      Serial.println("Error reason:" + fbd.errorReason());

    }

  }
}

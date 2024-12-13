// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "01d4c084-75c9-4681-ba0c-a10961c2f7c4";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onTeaTypeChange();
void onAmbientTemperatureChange();
void onOptimalTemperatureChange();
void onWaterTemperatureChange();
void onCoolingTimeChange();
void onWaterReadyChange();
void onReadyTimeChange();
void onStartTimeChange();

String teaType;
float ambient_temperature;
float optimal_temperature;
float water_temperature;
int cooling_time;
bool waterReady;
CloudTime ready_time;
CloudTime start_time;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(teaType, READWRITE, ON_CHANGE, onTeaTypeChange);
  ArduinoCloud.addProperty(ambient_temperature, READWRITE, 10 * SECONDS, onAmbientTemperatureChange);
  ArduinoCloud.addProperty(optimal_temperature, READWRITE, ON_CHANGE, onOptimalTemperatureChange);
  ArduinoCloud.addProperty(water_temperature, READWRITE, 5 * SECONDS, onWaterTemperatureChange);
  ArduinoCloud.addProperty(cooling_time, READWRITE, 5 * SECONDS, onCoolingTimeChange);
  ArduinoCloud.addProperty(waterReady, READWRITE, ON_CHANGE, onWaterReadyChange);
  ArduinoCloud.addProperty(ready_time, READWRITE, ON_CHANGE, onReadyTimeChange);
  ArduinoCloud.addProperty(start_time, READWRITE, ON_CHANGE, onStartTimeChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);

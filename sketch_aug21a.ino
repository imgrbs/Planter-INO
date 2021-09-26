#include <TEE_ESP_WIFI.h>

#define pinEN 9

#define ESP_Rx 0

#define ESP_Tx 1

String ssid = "WIFI_SSID";

String pass = "PWD";

String port = "8000";

ESP wifi(ESP_Rx, ESP_Tx, pinEN);

void print_debug(String data)

{
  Serial.print(data);
}

void setup()

{
  Serial.begin(115200);

  wifi.begin(115200);

  Serial.println("EPS8226");

  wifi.Event_debug = print_debug;

  String ip = wifi.myip();

  Serial.print(ip);

}

String data = "";

void loop()

{

  if (wifi.available())

  {

    Serial.write(wifi.read());

  }

  if (Serial.available())

  {

    char input = Serial.read();

    data += input;

    if (input == 0x0D)

    {

      wifi.print(0, data);

      data = "";

    }

  }

  
  String ip = wifi.myip();

  Serial.print(ip);

}

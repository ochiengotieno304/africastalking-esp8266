#include <AfricasTalking.h>


static const char *apiKey = "YOUR_API_KEY";
static const char *username = "YOUR_USERNAME";
static const char *toNumber = "RECEIVER_PHONE";
static const char *message = "Sent from ESP8266";
static const char *fromNumber = "AT_SHORT_CODE";
char wlanSsid[] = "YOUR_WLAN_SSID";
char wlanPass[] = "YOUR_WLAN_PASS";

AfricasTalking *AT;

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to WiFi network ");
  Serial.print(wlanSsid);
  Serial.println("...");
  WiFi.begin(wlanSsid, wlanPass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting...");
    delay(1000);
  }
  Serial.println("Connected!");

  AT = new AfricasTalking(apiKey, username);

  delay(1000);
  bool success = AT->sms(toNumber, fromNumber, message);
  if (success) {
    Serial.println("Request sent successfully!");
  } else {
    Serial.println("Error sending request");
  }
}

void loop() {
}

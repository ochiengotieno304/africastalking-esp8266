#include "AfricasTalking.hpp"

/**
 * @brief Send sms, airtime, and initiate phone calls using AfricasTalking API
 *
 */

WiFiClientSecure client;
HTTPClient http;
const char* fingerprint;

String AfricasTalking::getApiHost() {
  if (username == "sandbox") {
    return "https://api.sandbox.africastalking.com";
  } else {
    return "https://api.africastalking.com";
  }
}

String AfricasTalking::request(const String& endpoint, const String& postData, const int& request) {
  if (username == "sandbox") {
    fingerprint = "8A B3 F1 72 67 EC 90 97 14 60 1C 66 AC 5D E0 05 83 A9 AD EA";
  } else {
    fingerprint = "56 3F C1 7D AD 08 42 59 9C 76 D3 FA D7 66 3D CE 54 A3 E6 70";
  }

  client.setFingerprint(fingerprint);
  http.begin(client, endpoint);
  http.addHeader("Accept", "application/json");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.addHeader("apiKey", apiKey);
  if (request == 1) {
    http.POST(postData);
  } else
    http.GET();
  String payload = http.getString();
  http.end();

  return payload;
}

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

String AfricasTalking::request(const String& endpoint, const String& postData) {
  if (username == "sandbox") {
    fingerprint = "89 93 25 73 B7 93 B8 6F 10 D1 CD DC 4E B7 53 E2 BB 4B 48 9B";
  } else {
    fingerprint = "AE 79 CC 5B 04 BA 30 8A 63 FB A3 DE 9D 08 8C F1 AC B6 69 E6";
  }

  client.setFingerprint(fingerprint);
  http.begin(client, endpoint);
  http.addHeader("Accept", "application/json");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.addHeader("apiKey", apiKey);
  http.POST(postData);
  String payload = http.getString();
  http.end();

  return payload;
}

#ifndef AFRICASTALKING_H
#define AFRICASTALKING_H

#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>
#include "base64.h"
#include "url_coding.hpp"


class AfricasTalking {
public:
  AfricasTalking(
    const char* apiKey,
    const char* username)
    : apiKey(apiKey), username(username) {}

  // Empty destructor
  ~AfricasTalking() = default;

  bool sms(const String& toNumber, const String& fromNumber, const String& message);
  bool airtime(const String recipients[]);
  bool voice(const String& fromNumber, const String& toNumber);

private:
  String request(const String& endpoint, const String& postData);
  String getApiHost();
  String getSmsUrl();
  String getAirtimeUrl();
  String getVoiceUrl();
  String getVoiceHost();
  // String getFingerprint();
  String apiKey;
  String username;
  WiFiClientSecure client;
};


#endif

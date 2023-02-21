#include "AfricasTalking.hpp"

/**
 * Initiate phone calls using Africa,s Talking voice API
 *
 * Inputs:
 *  - fromNumber : Your Africa’s Talking phone number (in international format i.e. +XXXYYYYYY)
 *  - toNumber : A comma separated string of recipients’ phone numbers
 *
 * Outputs:
 *  - bool (method) : Whether the request was sent successfully
 */

bool AfricasTalking::voice(const String& fromNumber, const String& toNumber) {
  String url = getVoiceUrl();

  String postData = "to=" + urlencode(toNumber) + "&from=" + urlencode(fromNumber) + "&username=" + username;

  String payload = request(url, postData);

  if (payload.length() > 1) {
    Serial.println(payload);
    return true;
  } else return false;
}

String AfricasTalking::getVoiceHost() {
  if (username == "sandbox") {
    return "https://voice.sandbox.africastalking.com";
  } else {
    return "https://voice.africastalking.com";
  }
}

String AfricasTalking::getVoiceUrl() {
  return getVoiceHost() + "/call";
}

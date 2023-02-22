#include "AfricasTalking.hpp"

/**
 * Send messages using Africa,s Talking SMS API
 *
 * Inputs:
 *  - toNumber : Number to send the message to
 *  - fromNumber : Africa's Talking-provide shortcode
 *  - message : Text to send in the message
 *
 * Outputs:
 *  - bool (method) : Whether the request was sent successfully
 */

bool AfricasTalking::sms(
  const String& toNumber,
  const String& fromNumber,
  const String& message) {

  String encodedMessage = urlencode(message);
  const String url = getSmsUrl();

  String postData = "to=" + urlencode(toNumber) + "&from=" + urlencode(fromNumber) + "&message=" + encodedMessage + "&username=" + username;
  String payload = request(url, postData);

  if (payload.length() > 1) {
    Serial.println(payload);
    return true;
  } else return false;
}

String AfricasTalking::getSmsUrl() {
  return getApiHost() + "/version1/messaging";
}

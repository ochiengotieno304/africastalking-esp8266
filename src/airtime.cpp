#include "AfricasTalking.hpp"

/**
 * @brief Airtime using Africa, s Talking airtime API
 *
 * Inputs:
 *  - recipients : A url json array of recipients,
 *    the format of this string is: [{"phoneNumber":"+254711XXXYYY",currencyCode:"KES","amount":"X"}]
 *
 * Outputs:
 *  - bool (method) : Whether the request was sent succesfully
 */

String recipientsFormated;

bool AfricasTalking::airtime(const String recipients[]) {
  const String url = getAirtimeUrl();
  for (auto i : recipientsFormated) {
    recipientsFormated += (recipients->isEmpty() ? "" : ",") + (String)(i);
  }

  Serial.println(recipientsFormated);
  String finalRecipients = "[" + recipientsFormated + "]";

  String postData = "username=" + username + "&recipients=" + urlencode(finalRecipients);
  String payload = request(url, postData);

  if (payload.length() > 1) {
    Serial.println(payload);
    return true;
  } else return false;
}

String AfricasTalking::getAirtimeUrl() {
  return getApiHost() + "/version1/airtime/send";
}

#include "AfricasTalking.hpp"

String AfricasTalking::applicationData() {
  String url = getApplicationDataUrl();
  String payload = (String)request(url, " ", 2);
  return payload;
}

String AfricasTalking::getApplicationDataUrl() {
  return getApiHost() + "/version1/user?username=" + username;
}

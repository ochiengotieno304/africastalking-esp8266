# Africa's Talking ESP8266 Library

>
 Provides convenient access to the Africa's Talking API from esp8266 module written in C++.
>
## Installation

 Download the zip package from [here](https://github.com/ochiengotieno304/africastalking-esp8266/releases/download/1.0.0/AfricasTalking.zip).

### Manually install the library

Once you get the library, just 3 steps are required before you can use it:

1. Extract the archive.
2. Place the library folder in Arduino/libraries/.
3. Restart the Arduino IDE.

### Install from the IDE

 In you Arduino IDE got to **Sketch > Include Library > Add .ZIP Library** and browse to find your .zip archive.

## Usage

The library needs to be instantiated using your username and API key, which you can get from the [dashboard](https://account.africastalking.com).

You can use this library for either production or sandbox apps. For sandbox, the app username is **ALWAYS** sandbox.

## Initialization

In your .ino file:

```cpp
  #include <AfricasTalking.h>

  static const char *apiKey = "YOUR_API_KEY";
  static const char *username = "YOUR_USERNAME";

  AfricasTalking *AT;
  AT = new AfricasTalking(apiKey, username);
```

### Application

```cpp
  String appData = AT->applicationData();
 ```

### Airtime

```cpp
  String recipients[] = { "{ \"phoneNumber\":\"+254XXXXXXXXX\",\"currencyCode\":\"KES\",\"amount\":\"5\" }" };

  bool success = AT->airtime(recipients);
 ```

- `recipients`: string array with recipient info `REQUIRED`
  - `phoneNumber`: phone number that will be topped up `REQUIRED`
  - `currencyCode`: currency code `REQUIRED`
  - `amount`: value of airtime to send

### SMS

```cpp
  bool success = AT->sms(toNumber, fromNumber, message);
 ```

- `toNumber`: message recipient phone number, comma seperated for bulk send `REQUIRED`
- `fromNumber`: Africa's Talking provide short code`REQUIRED`
- `message`: message to sender`REQUIRED`

### Voice

#### Make Call

```cpp
  bool success = AT->voice(fromNumber, toNumber);
 ```

- `toNumber`: call destination phone number `REQUIRED`
- `fromNumber`: Africa's Talking provide phone number `REQUIRED`

## Development

## Contributing

Bug reports and pull requests are welcome on GitHub at <https://github.com/ochiengotieno304/africastalking-esp8266/issues>.

## License

The library is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT).

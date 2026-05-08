#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int buzzer = 9;
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
int i, a = 0;
float spd;

SoftwareSerial ss(RXPin, TXPin);
String stringVal = "";

void setup()
{
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  ss.begin(GPSBaud);
  delay(2000);
  gsm_init();
  Serial.println("AT+CNMI=2,2,0,0,0");
  delay(2000);
}

void loop()
{
  while (ss.available() > 0)
  {
    gps.encode(ss.read());
    tracking();
  }
}

void gsm_init()
{
  boolean at_flag = 1;
  while (at_flag)
  {
    Serial.println("AT");
    delay(1);
    while (Serial.available() > 0)
    {
      if (Serial.find("OK"))
        at_flag = 0;
    }
    delay(1000);
  }

  boolean echo_flag = 1;
  while (echo_flag)
  {
    Serial.println("ATE0");
    while (Serial.available() > 0)
    {
      if (Serial.find("OK"))
        echo_flag = 0;
    }
    delay(1000);
  }

  boolean net_flag = 1;
  while (net_flag)
  {
    Serial.println("AT+CPIN?");
    while (Serial.available() > 0)
    {
      if (Serial.find("+CPIN: READY"))
        net_flag = 0;
    }
    delay(1000);
  }
}

void init_sms()
{
  Serial.println("AT+CMGF=1");
  delay(400);
  Serial.println("AT+CMGS=\"YOUR_PHONE_NUMBER\"");
  delay(400);
}

void send_data(String message)
{
  Serial.print(message);
  delay(200);
}

void send_sms()
{
  Serial.write(26);
}

void tracking()
{
  spd = gps.speed.kmph();
  if (spd >= 50)
  {
    tone(buzzer, 1000);
    delay(5000);
    noTone(buzzer);
    delay(5000);
    a++;
  }

  if (a > 1)
  {
    init_sms();
    send_data("Vehicle Overspeed Alert:");
    Serial.println(" ");
    send_data("Location of the vehicle where the driver has exceeded the set speed:");
    Serial.println(" ");
    Serial.print("Latitude: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print("\nLongitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("https://www.google.com/maps/@");
    Serial.print(gps.location.lat(), 6);
    Serial.print(',');
    Serial.print(gps.location.lng(), 6);
    Serial.print(",14z");
    send_sms();
    delay(2000);
  }
}

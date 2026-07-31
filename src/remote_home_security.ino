#include <ArduinoJson.h>
#include <SimpleTimer.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "YOUR_FIREBASE_HOST"
#define FIREBASE_AUTH "YOUR_FIREBASE_AUTH"
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

SimpleTimer t1, t2, t3;

const char *month_arr[13] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

const char *day_arr[7] = {
    "Sun", "Mon", "Tue", "Wen", "Thu", "Fri", "Sat"
};

char buf[40];
char *time_cut = 0;
char *time_val[8] = {0};
char DaysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int pin1 = 2;
int pin2 = 14;
int pin3 = 12;

void setup(void)
{
    Serial.begin(115200);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("connecting");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }

    Serial.println();
    Serial.print("connected: ");
    Serial.println(WiFi.localIP());

    Firebase.begin(FIREBASE_HOST);

    pinMode(pin1, INPUT_PULLUP);
    pinMode(pin2, INPUT_PULLUP);
    pinMode(pin3, INPUT_PULLUP);

    t1.setInterval(1000, fn1);
    t2.setInterval(1000, fn2);
    t3.setInterval(1000, fn3);
}

void loop(void)
{
    t1.run();
    t2.run();
    t3.run();

    delay(1000);
}

/* 나머지 함수는 기존 소스와 동일하며 공개 저장소에서는
   인증 정보와 무선망 정보를 반드시 제거해야 합니다. */

// INCLUDES:
#include "HardwareSerial.h"
#include "esp_sleep.h"
#include <Arduino.h>
//#include <ESP8266WiFi.h>
#include <esp_wifi.h>
#include <WiFi.h>
#include <cstring>
#include <esp_now.h>

// MAC ADDDRESS OF RECEIVER1:
// uint8_t peerAddr[] = {0x94, 0xB9, 0x7E, 0x18, 0x2B, 0xEA};
typedef struct {
    uint32_t left;
    uint32_t right;
} message_struct;

#define IOPin 15
#define ADC_1 36
#define DAC_1 4
#define WINDOW_SIZE 5
#define CH 0

#define LEFT_MODE 12
#define RIGHT_MODE 14


int avg = 0;
int analogVal = 0;

int vib_on = 0;
int vib_off = 0;
int intensity = 0;
static int iters = 0;
int read_val = 0;
int pulse_delay = 0;

int swStatus = 0;

bool ledState = false;
message_struct message;

void onDataRecv(const uint8_t * mac, const  uint8_t *incomingData, int len)
{
    memcpy(&message, incomingData, sizeof(message));

    swStatus = digitalRead(LEFT_MODE);

    if (swStatus == 1)
    {
        read_val = message.left;
        Serial.println("left switch : ");
    } else if (swStatus == 0)
    {
        read_val = message.right;
        Serial.println("right switch : ");
    }

    intensity = read_val;

    if (read_val >= 200)
    {
        vib_on = 150;
        vib_off = 50;
        pulse_delay = 500 ;
    }
    else if (read_val >= 50)
    {
        vib_on = 500;
        vib_off = 200;
        pulse_delay = 1000;
    }
    else
    {
        vib_on = 100;
        vib_off = 100;
        pulse_delay = 0;
        intensity = 0;

    }

}

void setup()
{
    Serial.begin(115200);
    WiFi.mode( WIFI_STA );
    esp_now_init();

    Serial.println(WiFi.macAddress());
    esp_now_register_recv_cb(onDataRecv);

}

void loop() {
   analogWrite(DAC_1, 120);
   delay(400);
//   Serial.println(message);
   analogWrite(DAC_1, 0);
   delay(200);
   analogWrite(DAC_1, 120);
   delay(400);
   analogWrite(DAC_1, 0);
   delay(2000);

//   analogWrite(DAC_1, intensity);
//    esp_sleep_enable_timer_wakeup(vib_on*1000);
//    esp_light_sleep_start();
//   analogWrite(DAC_1, 0);
//    esp_sleep_enable_timer_wakeup(vib_off*1000);
//    esp_light_sleep_start();
//   analogWrite(DAC_1, intensity);
//    esp_sleep_enable_timer_wakeup(vib_on*1000);
//    esp_light_sleep_start();
//   analogWrite(DAC_1, 0);
//    esp_sleep_enable_timer_wakeup(pulse_delay*1000);
//    esp_light_sleep_start();

//   if (digitalRead(LEFT_MODE) == 1) {
//     Serial.println("LEFT MODE");
//     analogWrite(DAC_1, 255);
//   }
//   else {
//     Serial.println("RIGHT MODE");
//     analogWrite(DAC_1, 0);
//}

}

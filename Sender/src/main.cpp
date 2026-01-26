
#include "WiFiType.h"
#include "esp32-hal-adc.h"
#include "esp_err.h"
#include "esp_random.h"
#include <Arduino.h>
#include <cstdint>
#include <vector>

#include <WiFi.h>
#include <esp_now.h>
using namespace std;
#define POT1  36 // ESP32 pin GPIO36 (ADC0) connected to VRX pin


typedef struct {
    uint32_t left;
    uint32_t right;
} message_struct;




uint32_t pot1_av = 0;
uint32_t pot1_raw = 0;
vector<uint32_t> pot1_window;

esp_now_peer_info_t peerInfo;
message_struct message;
uint32_t test_message;


//uint8_t peerAddr[] = {0x40, 0x22, 0xD8, 0xEA, 0x75, 0x10};
uint8_t peerAddr[] = {0x40, 0x22, 0xD8, 0xEB, 0x0B, 0xCC};
//uint8_t peerAddr[] = {0xCC, 0xDB, 0xA7, 0x62, 0x0A, 0xD4};
//uint8_t peerAddr[] = {0xE4, 0x65, 0xB8, 0x0C, 0x22, 0x88};
void setup() {
  Serial.begin(115200) ;
  
   
  WiFi.mode(WIFI_STA);
  esp_now_init();

  memcpy(peerInfo.peer_addr, peerAddr, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

    for (int i = 0; i < 10; i++)
    {
        pot1_window.push_back(0);
    }

   if (esp_now_add_peer(&peerInfo) != ESP_OK)
   {
       Serial.println("uh ohh");
       return;
   }
}

void loop() {
    delay(50);
    pot1_raw = analogRead(POT1); 
    pot1_raw = map(pot1_raw, 0, 4095, 0, 255 );


    pot1_window.erase(pot1_window.begin()); // pop the
    pot1_window.push_back(pot1_raw);

    pot1_av = 0;
    for (int i = 0; i<pot1_window.size(); i++)
    {
        pot1_av += pot1_window[i];
    }
    pot1_av = (int)(pot1_av / 10);

    Serial.printf("Sending message: left=%d", pot1_av);
    Serial.println();
            

  esp_err_t result = esp_now_send(peerAddr, (uint8_t *) &pot1_av, sizeof(pot1_av));





}

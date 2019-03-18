#include <ESP8266WiFi.h>
#include "estruturas.h"

const uint8_t nodeID = 1;
uint16_t _pktID;
mac802_t mac;
beacon_t beacon;

void setup() {
  Serial.begin(115200);
  wifi_set_opmode(STATION_MODE);            // Promiscuous works only with station mode
  wifi_set_channel(10);
  wifi_get_macaddr(0x00, mac.sa);
  beacon.actual_channel = wifi_get_channel();
  wifi_promiscuous_enable(false);
  wifi_station_disconnect();
  wifi_promiscuous_enable(true);
  memcpy(&mac.frame_body, &beacon, sizeof(beacon));
}

void loop() {

  
  if(!wifi_send_pkt_freedom((uint8_t *) &mac, sizeof(mac), false))
    Serial.printf("Pacote de dados enviado.\n");
  else
    Serial.println("Pacote não enviado.");
  
  delay(100);

}

#include <stdint.h>

typedef struct {
    uint8_t protocol_version:2;
    uint8_t type:2;
    uint8_t subType:4;
    uint8_t toDs:1;
    uint8_t fromDs:1;
    uint8_t moreFrag:1;
    uint8_t retry:1;
    uint8_t pwrMngmt:1;
    uint8_t moreData:1;
    uint8_t protFrame:1;
    uint8_t order:1;
} __attribute__((packed)) frameControl_t;

typedef struct {
    frameControl_t fc = {0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};    
    uint16_t duration = 0;
    uint8_t  da[6] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    uint8_t  sa[6] = {0x2C,0xF3,0x45,0x43,0x91,0xA7};
    uint8_t  bss[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
    uint16_t sequence = 0;      
    uint8_t  frame_body[763] = {0}; //88 | 1372
    uint32_t fcs = 0;    
} __attribute__((packed)) mac802_t;

typedef struct {
    uint64_t timestamp = 0;

    uint16_t beacon_interval = 0x0064;
    uint16_t capability = 0x0401; //0x4010; 0x0401;
    
    uint8_t id_meaning_ssid = 0x00;
    uint8_t ssid_lenght = 0x06;
    char identificador[6] = {0x70, 0x70, 0x70, 0x70, 0x70, 0x70};

    uint8_t id_meaning_rates = 0x01;
    uint8_t ssid_rates = 0x8;
    uint8_t supported_rates[8] = {0x82,0x84,0x8b,0x96,0x24,0x30,0x48,0x6c};

    uint8_t id_meaning_channel = 0x03;
    uint8_t lenght_channel = 0x01;
    uint8_t actual_channel = 0x04;
} __attribute__((packed)) beacon_t;

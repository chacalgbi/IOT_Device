WiFiClient client;
WebServer server(80);
Preferences preferences;

#define FORMAT_SPIFFS_IF_FAILED true
const size_t JSON_SIZE = JSON_OBJECT_SIZE(10) + 524;

SSD1306Wire display1(0x3c, 21, 22);

#define config_wifi 23 // Input
//#define Reset_Sinal  4 // Input
#define led         19 // LED indicador de conexão
#define rele1       18 // Output
//#define rele2       18 // Output
//#define rele3        5 // Output
//#define rele4       17 // Output
//#define rele5       16 // Output

#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();

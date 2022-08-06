bool modo_config = false;
bool TemRede = false;
bool TemInternet = false;
bool inverter = false;

byte rele_selecionado = 0;
uint8_t indice_eeprom = 0;
const int QTD_EEPROM = 20;
uint8_t QTD_RELES = 5;
uint8_t hora_lig[QTD_EEPROM];
uint8_t minuto_lig[QTD_EEPROM];
uint8_t hora_desl[QTD_EEPROM];
uint8_t minuto_desl[QTD_EEPROM];
String conexao = "";

char ssid[30];   // Rede WiFi
char pw[30];     // Senha da Rede WiFi
char device[30]; // Nome do dispositivo
char servidor[150]; // Nome do servidor
String device_str = "";
String pw_str = "";
String ssid_str = "";
String server_str = "";

String NomeRede = "Kau";

int long segundos_1 = 0;
int long segundos_5 = 0;
int long segundos_10 = 0;
int long segundos_60 = 0;

int temp_int = 0;

// Inclusão das configurações do servidor NTP
const char* ntpServer = "time.google.com"; // endereço servidor
struct tm timeinfo;         // estrutura armazenará dados de hora, minuto, segundo, etc. atuais obtidos do servidor NTP

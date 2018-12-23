 /* AUTOR: JOHNATAM RENAN HORST - 14
 * DATA: 23/12/2018
 * DESCRISAO: PROJETO DE ESPELHO DOS NIVEIS LOGICOS DAS PORTAS DE 1 DADO ESP PARA OUTRO
 *            UTILIZANDO COMUNICAO WIRELESS E PROTOCOLO UDP
 * 
 *CODIGO UTILIZANDO: https://portal.vidadesilicio.com.br/comunicacao-wireless-esp-protocolo-udp/ 
 */
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Ticker.h>

WiFiUDP     udp;
Ticker      timeSerial;
int         msg;
String      req;
const char* ssid          = "ESP";            //ssid da rede criada pelo host
const char* pwd           = "12345678";       //password da rede criada pelo host
int         port          = 555;
IPAddress   ip            (192,168,0,125);
IPAddress   gateway       (192,168,0,1);
IPAddress   subnet        (255,255,255,0);


void setup() {
  Serial.begin(115200);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid,pwd);                      //cria a rede com o parametro para configuração
  WiFi.softAPConfig(ip, gateway, subnet);  
  Serial.println("");      
  Serial.println(WiFi.softAPIP());
  udp.begin(port);
}

void loop() {
  if(udp.parsePacket() > 0){
    req = "";
    while(udp.available() > 0){
      char z = udp.read();
      req += z;  
    }
    Serial.println(req);
    msg = atoi(req.c_str());
    if(bitRead(msg,0) == 1){
      digitalWrite(D0,0); 
    }else{
      digitalWrite(D0,1);
    }
    if(bitRead(msg,1) == 1){
      digitalWrite(D1,0); 
    }else{
      digitalWrite(D1,1);
    }
    if(bitRead(msg,2) == 1){
      digitalWrite(D2,0); 
    }else{
      digitalWrite(D2,1);
    }
    if(bitRead(msg,3) == 1){
      digitalWrite(D3,0); 
    }else{
      digitalWrite(D3,1);
    }
    if(bitRead(msg,4) == 1){
      digitalWrite(D4,0); 
    }else{
      digitalWrite(D4,1);
    }
    if(bitRead(msg,5) == 1){
      digitalWrite(D5,0); 
    }else{
      digitalWrite(D5,1);
    }
    if(bitRead(msg,6) == 1){
      digitalWrite(D6,0); 
    }else{
      digitalWrite(D6,1);
    }
    if(bitRead(msg,7) == 1){
      digitalWrite(D7,0); 
    }else{
      digitalWrite(D7,1);
    }
    if(bitRead(msg,8) == 1){
      digitalWrite(D8,0); 
    }else{
      digitalWrite(D8,1);
    }    
  }
}

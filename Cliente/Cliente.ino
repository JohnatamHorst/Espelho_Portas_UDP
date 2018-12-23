/*****************************************************************************************
 * AUTOR: JOHNATAM RENAN HORST
 * DATA: 23/12/2018
 * DESCRISAO: PROJETO DE ESPELHO DOS NIVEIS LOGICOS DAS PORTAS DE 1 DADO ESP PARA OUTRO
 *            UTILIZANDO COMUNICAO WIRELESS E PROTOCOLO UDP
 * 
 *CODIGO UTILIZANDO: https://portal.vidadesilicio.com.br/comunicacao-wireless-esp-protocolo-udp/ 
 */
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Ticker.h>

WiFiUDP       udp;
Ticker        timeSerial;
int           msg;

const char*   ssid            = "ESP";           //ssid da rede criada pelo host
const char*   pwd             = "12345678";       //password da rede criada pelo host
const char*   ip              = "192.168.0.125";
int           port            = 555;

void setup() {
  pinMode(D0,INPUT_PULLUP);
  pinMode(D1,INPUT_PULLUP);
  pinMode(D2,INPUT_PULLUP);
  pinMode(D3,INPUT_PULLUP);
  pinMode(D4,INPUT_PULLUP);
  pinMode(D5,INPUT_PULLUP);
  pinMode(D6,INPUT_PULLUP);
  pinMode(D7,INPUT_PULLUP);
  pinMode(D8,INPUT_PULLUP);
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  Serial.println("inicio Setup");
  
}


void loop() {
//****Conecção
  if(WiFi.status() != WL_CONNECTED){
    WiFi.begin(ssid,pwd);
    while(WiFi.status() != WL_CONNECTED){
      Serial.println(".");
      delay(500);
    }
    Serial.println("Conectado");
  }
//Formação e Envio da mensagem
  if(WiFi.status() == WL_CONNECTED){
    msg = 0;
    if(digitalRead(D0)==1){
      bitSet(msg,0); 
    }
    if(digitalRead(D1)==1){
      bitSet(msg,1); 
    }
    if(digitalRead(D2)==1){
      bitSet(msg,2); 
    }
    if(digitalRead(D3)==1){
      bitSet(msg,3); 
    }
     if(digitalRead(D4)==1){
      bitSet(msg,4); 
    }
    if(digitalRead(D5)==1){
      bitSet(msg,5); 
    }
    if(digitalRead(D6)==1){
      bitSet(msg,6); 
    }
    if(digitalRead(D7)==1){
      bitSet(msg,7); 
    }
    if(digitalRead(D8)==1){
      bitSet(msg,8); 
    }
    udp.beginPacket(ip,port);
    udp.println(msg);
    udp.endPacket();
    Serial.println(msg,BIN);
  }
}








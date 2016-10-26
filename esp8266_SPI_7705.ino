#include <AD770X.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

// Connect AD7705 using SPI
// ESP8266 -- NodeMCU -> Pin
// GPIO15  --   D8    -> CS
// GPIO13  --   D7    -> MOSI
// GPIO12  --   D6    -> MISO
// GPIO14  --   D5    -> SCLK
// GPIO05  --   D1    -> RESET hard

// Example based on NodeMCU
AD770X TM7705(2.5, D8, D7, D6, D5, D1);



void setup() {
    // put your setup code here, to run once:
    Serial.begin(74880);    // set to ESP8266 bootloader baudrate, so that you can see the boot info

    TM7705.resetHard();
    TM7705.reset();
    
    Serial.println();
    Serial.println("--Start--");
    
    TM7705.init(AD770X::CHN_AIN1, AD770X::CLK_DIV_1, AD770X::BIPOLAR, AD770X::GAIN_4, AD770X::UPDATE_RATE_50);
    TM7705.init(AD770X::CHN_AIN2, AD770X::CLK_DIV_1, AD770X::BIPOLAR, AD770X::GAIN_4, AD770X::UPDATE_RATE_50);
    Serial.println("--Init Done--");
}

void loop() {
    // put your main code here, to run repeatedly:
    static int i = 0;
    double v1 = 0.0;
    double v2 = 0.0;
    
    Serial.print("#");
    Serial.print(i++);
    Serial.print(": ");
    
    //read twice to improve reliability
    Serial.print("CH1: ");
    while (!TM7705.dataReady(AD770X::CHN_AIN1)) {
        ;
    }
    v1 = TM7705.readADResult(AD770X::CHN_AIN1, 1.25); // ref offest = 125
    while (!TM7705.dataReady(AD770X::CHN_AIN1)) {
        ;
    }
    v1 = TM7705.readADResult(AD770X::CHN_AIN1, 1.25);
    Serial.print(v1, 5);
    
    //read twice to improve reliability
    Serial.print("  CH2: ");
    while (!TM7705.dataReady(AD770X::CHN_AIN2)) {
        ;
    }
    v2 = TM7705.readADResult(AD770X::CHN_AIN2, 1.25);
    while (!TM7705.dataReady(AD770X::CHN_AIN2)) {
        ;
    }
    v2 = TM7705.readADResult(AD770X::CHN_AIN2, 1.25);
    Serial.println(v2, 5);
    
    delay(1000);
}

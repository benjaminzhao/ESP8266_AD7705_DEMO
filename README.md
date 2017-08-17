# ESP8266 + AD7705

# Connect to AD7705 using SPI
ESP8266 -- NodeMCU -> Pin
GPIO15  --   D8    -> CS
GPIO13  --   D7    -> MOSI
GPIO12  --   D6    -> MISO
GPIO14  --   D5    -> SCLK
GPIO05  --   D1    -> RESET hard

# Example based on NodeMCU
AD770X TM7705(2.5, D8, D7, D6, D5, D1);

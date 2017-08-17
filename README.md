# ESP8266 + AD7705

# Connect to AD7705 using SPI
ESP8266 -- NodeMCU -> Pin <br />
GPIO15  --   D8    -> CS <br />
GPIO13  --   D7    -> MOSI <br /> 
GPIO12  --   D6    -> MISO <br />
GPIO14  --   D5    -> SCLK <br />
GPIO05  --   D1    -> RESET hard <br />

# Example based on NodeMCU
AD770X TM7705(2.5, D8, D7, D6, D5, D1) <br />

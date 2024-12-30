#include "UART.h"

void setup() {
    Serial.begin(9600); 
    UART1_TX_init();    
    UART2_RX_init();    
    while(1){
      UART1_Transmit(0xAA);
      Serial.println("Data transmitted: 0xAA");
      delay(500); // wait for transmission time     
      received = UART2_Receive();
      delay(1000);
    }
}

void loop() {
    
}

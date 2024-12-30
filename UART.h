volatile char *UCSR1_A = 0xC8;
volatile char *UCSR2_A = 0xD0;
volatile char *UDR_1 = 0xCE;
volatile char *UDR_2 = 0xD6;
volatile char received;

void UART1_TX_init(void) {
    volatile char *UCSR1_B =0xC9;
    volatile char *UCSR1_C = 0xCA;
    
    *UCSR1_B = 0x08;  // Enable TX1 (TXEN1)
    *UCSR1_C = 0x06;  // 8-bit data, no parity, 1 stop bit
}
void UART2_RX_init(void) {
    volatile char *UCSR2_B = 0xD1;
    volatile char *UCSR2_C = 0xD2;
    
    *UCSR2_B = 0x10;  // Enable RX2 (RXEN2)
    *UCSR2_C = 0x06;  // 8-bit data, no parity, 1 stop bit
}
void UART1_Transmit(char data) {
    while (!(*UCSR1_A & (1 << 5)));
    *UDR_1 = data;  
}
char UART2_Receive(void) {
    while (!(*UCSR2_A & (1 << 7)));
    return *UDR_2;  
}

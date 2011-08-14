#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega88) || defined(__AVR_ATmega8__) || defined(__AVR_ATmega88__)
/* Onboard LED is connected to pin PB5 in Arduino NG, Diecimila, and Duemilanove */ 
#ifdef NANODE
#define LED_DDR     DDRD
#define LED_PORT    PORTD
#define LED_PIN     PIND
#define LED         PIND6

#define DBG_LED1         PIND4
#define DBG_LED2         PIND5
#define DBG_LED1_ON  PORTD &= ~(1<<PORTD4)
#define DBG_LED1_OFF  PORTD |= (1<<PORTD4)
#define DBG_LED2_ON  PORTD &= ~(1<<PORTD5)
#define DBG_LED2_OFF  PORTD |= (1<<PORTD5)


#ifdef NANODE_SRAM
#define setupSPI SPCR = 0x50      //Master mode, MSB first, SCK phase low, SCK idle low, clock/4
#define setupDDRB DDRB |= 0x2d    //set  SCK(13) MOSI(11), SS(10) and 9 as output 
#define selectSS PORTB &= ~0x02   //set the SS to 0 to select MSH:use pin 9 for sram instead of 10
#define deselectSS PORTB |= 0x02  //set the SS to 1 to deselect 
#define SS9 9
#endif

#else
#define LED_DDR     DDRB
#define LED_PORT    PORTB
#define LED_PIN     PINB
#define LED         PINB5
#endif

/* Ports for soft UART */
#ifdef SOFT_UART
#define UART_PORT   PORTD
#define UART_PIN    PIND
#define UART_DDR    DDRD
#define UART_TX_BIT 1
#define UART_RX_BIT 0
#endif
#endif

#if defined(__AVR_ATmega8__)
  //Name conversion R.Wiersma
  #define UCSR0A        UCSRA
  #define UDR0          UDR
  #define UDRE0         UDRE
  #define RXC0          RXC
  #define TIFR1         TIFR
  #define WDTCSR        WDTCR
#endif

/* Luminet support */
#if defined(__AVR_ATtiny84__)
/* Red LED is connected to pin PA4 */ 
#define LED_DDR     DDRA
#define LED_PORT    PORTA
#define LED_PIN     PINA
#define LED         PINA4
/* Ports for soft UART - left port only for now. TX/RX on PA2/PA3 */
#ifdef SOFT_UART
#define UART_PORT   PORTA
#define UART_PIN    PINA
#define UART_DDR    DDRA
#define UART_TX_BIT 2
#define UART_RX_BIT 3
#endif
#endif

/* Sanguino support */
#if defined(__AVR_ATmega644P__)
/* Onboard LED is connected to pin PB0 on Sanguino */ 
#define LED_DDR     DDRB
#define LED_PORT    PORTB
#define LED_PIN     PINB
#define LED         PINB0

/* Ports for soft UART */
#ifdef SOFT_UART
#define UART_PORT   PORTD
#define UART_PIN    PIND
#define UART_DDR    DDRD
#define UART_TX_BIT 1
#define UART_RX_BIT 0
#endif
#endif

/* Mega support */
#if defined(__AVR_ATmega1280__)
/* Onboard LED is connected to pin PB7 on Arduino Mega */ 
#define LED_DDR     DDRB
#define LED_PORT    PORTB
#define LED_PIN     PINB
#define LED         PINB7

/* Ports for soft UART */
#ifdef SOFT_UART
#define UART_PORT   PORTE
#define UART_PIN    PINE
#define UART_DDR    DDRE
#define UART_TX_BIT 1
#define UART_RX_BIT 0
#endif
#endif


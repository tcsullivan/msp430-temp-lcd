#include "board.h"
#include "delay.h"
#include "lcd.h"

static void lcdPulseE(void);
static void lcdSetDAT(uint8_t value);
static void lcdSendCommand(uint8_t command);
static void lcdSendData(uint8_t data);

void lcdInit(void)
{
    // Give time for LCD to prepare itself
    delay(100);
    lcdSendCommand(0x38);
    lcdSendCommand(0x10);
    lcdSendCommand(0x0D);
    delay(5);
    lcdClear();
}

void lcdClear(void)
{
    lcdSendCommand(0x01);
    delay(2);
}

void lcdPuts(const char *s)
{
	lcdSendCommand(0x06);
	while (*s != '\0')
		lcdSendData(*s++);
}

void lcdPulseE(void)
{
    P2OUT |= LCD_E;
    delay(2);
    P2OUT &= ~(LCD_E);
}

void lcdSetDAT(uint8_t value)
{
    P2OUT &= ~(LCD_DATH);
    P2OUT |= (value >> 4) & LCD_DATH;
    P1OUT &= ~(LCD_DATL);
    P1OUT |= value & LCD_DATL;
}

void lcdSendCommand(uint8_t command)
{
    P1OUT &= ~(LCD_RS);
    lcdSetDAT(command);
    lcdPulseE();
}

void lcdSendData(uint8_t data)
{
    P1OUT |= LCD_RS;
    lcdSetDAT(data);
    lcdPulseE();
}

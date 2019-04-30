/**
 * @file board.c
 * Provides board configuration and initialization.
 *
 * Copyright (C) 2019  Clyne Sullivan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "board.h"

static void boardInitWatchdog(void);
static void boardInitPins(void);

void boardInit(void)
{
	// Slow down needed for LCD
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ; 

	boardInitWatchdog();
	boardInitPins();
}

void boardInitWatchdog(void)
{
	WDTCTL = WDTHOLD | WDTPW;
}

void boardInitPins(void)
{
	// All pins are output
	P1DIR = PORT1_PINS;
	P2DIR = PORT2_PINS;

	// All pins should start at a low state
	P1OUT = 0;
	P2OUT = 0;

	// Set I2C pins to the proper mode
	P1SEL |= TEMP_SDA | TEMP_SCL;
	P1SEL2 |= TEMP_SDA | TEMP_SCL;
}


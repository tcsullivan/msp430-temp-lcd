/**
 * @file main.c
 * Main program entry point.
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
#include "delay.h"
#include "lcd.h"
#include "temp.h"

#include <stdio.h>

int main(void)
{
	// Prepare processor and IO
	boardInit();

	delayInit();
	_NOP();
	__enable_interrupt();

	lcdInit();

	if (tempInit() != 0) {
	    lcdPuts("Sensor broken.");
	    while (1);
	}

	char buf[32];
	while (1) {
	    lcdClear();
	    int16_t temp = tempGetDieTemperature();
	    int16_t vobj = tempGetObjVoltage();
	    sprintf(buf, "T: %4d V: %4d", temp, vobj);
	    lcdPuts(buf);
	    delay(1000);
	}

	return 0;
}


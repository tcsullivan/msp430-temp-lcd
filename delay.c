/**
 * @file delay.c
 * Delay support using a timer.
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

volatile unsigned int delayTicks = 0;

void delayInit(void)
{
	TACCTL0 |= CCIE;
	TACCR0 = 128;
	TACTL |= TASSEL_2 | MC_1 | ID_3;
}

void delay(unsigned int ms)
{
    unsigned int target = delayTicks + ms;
    while (delayTicks < target);
}

__attribute__((__interrupt__(TIMER0_A0_VECTOR)))
static void delayInterruptHandler(void)
{
    delayTicks++;
}

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
#include "temp.h"

void main(void)
{
	// Prepare processor and IO
	boardInit();

	delayInit();
	__enable_interrupt();

	// Prepare temperature sensor
	//if (tempInit() != 0)
	//	while (1); // Sensor error, halt

	while (1);
}


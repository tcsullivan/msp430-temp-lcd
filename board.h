/**
 * @file board.h
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

#ifndef BOARD_H_
#define BOARD_H_

#include <msp430.h>
#include <stdint.h>

// Port 1 pins
#define LED      (1 << 0)
#define TEMP_SCL (1 << 6)
#define TEMP_SDA (1 << 7)

#define PORT1_PINS (LED | TEMP_SCL | TEMP_SDA)

// Port 2 pins
#define LCD_DAT (0x0F)
#define LCD_E   (1 << 4)
#define LCD_RW  (1 << 5)
#define LCD_RS  (1 << 6)

#define PORT2_PINS (LCD_DAT | LCD_E | LCD_RW | LCD_RS)

/**
 * Initializes pins and core functionality.
 */
void boardInit(void);

#endif // BOARD_H_

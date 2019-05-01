/**
 * @file temp.c
 * Provides support for the TMP006 temperature sensor.
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
#include "i2c.h"

// TMP006 I2C address
#define TEMP_ADDR (0x40)

// TMP006 registers
#define TMP006_CONFIG (0x02)
#define TMP006_VOBJ   (0x00)
#define TMP006_TAMB   (0x01)
#define TMP006_MANID  (0xFE)
#define TMP006_DEVID  (0xFF)

// TMP006 CONFIG register parameters
#define TMP006_CFG_RESET    (0x8000)
#define TMP006_CFG_MODEON   (0x7000)
#define TMP006_CFG_1SAMPLE  (0x0000)
#define TMP006_CFG_2SAMPLE  (0x0200)
#define TMP006_CFG_4SAMPLE  (0x0400)
#define TMP006_CFG_8SAMPLE  (0x0600)
#define TMP006_CFG_16SAMPLE (0x0800)
#define TMP006_CFG_DRDYEN   (0x0100)
#define TMP006_CFG_DRDY     (0x0080)

static void tempI2CWrite(uint8_t reg, uint16_t value);
static uint16_t tempI2CRead(uint8_t reg);

int tempInit(void)
{
	// Prepare I2C
	I2C_init(TEMP_ADDR);

	// Initialize the TMP006 sensor
	tempI2CWrite(TMP006_CONFIG, TMP006_CFG_MODEON | TMP006_CFG_DRDYEN |
		TMP006_CFG_16SAMPLE);

	// Check that the device is in fact the TMP006
	uint16_t manid = tempI2CRead(TMP006_MANID);
	uint16_t devid = tempI2CRead(TMP006_DEVID);
	if (manid != 0x5449 || devid != 0x67)
		return 1;

	return 0;
}

int16_t tempGetDieTemperature(void)
{
    int16_t raw = tempI2CRead(TMP006_TAMB);
    return (raw >> 2) / 32;
}

int16_t tempGetObjVoltage(void)
{
	return tempI2CRead(TMP006_VOBJ);
}

void tempI2CWrite(uint8_t reg, uint16_t value)
{
	uint8_t data[3] = {
		reg,
		value >> 8,
		value & 0xFF
	};
	I2C_write(3, data);
}

uint16_t tempI2CRead(uint8_t reg)
{
	uint8_t data[2] = {
		reg,
		0
	};
	I2C_write(1, data);
	I2C_read(2, data);
	return (data[0] << 8) | data[1];
}


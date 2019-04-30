/**
 * @file temp.h
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

#ifndef TEMP_H_
#define TEMP_H_

/**
 * Attempts to initialize the TMP006 temperature sensor.
 * @return Zero on success, non-zero on failure
 */
int tempInit(void);

int16_t tempGetDieTemperature(void);

#endif // TEMP_H_


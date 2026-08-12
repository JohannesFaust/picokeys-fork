/*
 * This file is part of the Pico Keys SDK distribution (https://github.com/polhenarejos/pico-keys-sdk).
 * Copyright (c) 2022 Pol Henarejos.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>
#include <stdbool.h>

#if defined(ESP_PLATFORM)
#define BOOT_PIN GPIO_NUM_0
#endif

#if defined(PICO_PLATFORM)
#ifndef BUTTON_GPIO_PIN
#define BUTTON_GPIO_PIN 14
#endif

#ifndef BUTTON_ACTIVE_LEVEL
#define BUTTON_ACTIVE_LEVEL 0
#endif
#endif

#ifndef PRESENCE_DEBOUNCE_MS
#define PRESENCE_DEBOUNCE_MS 50
#endif

extern int button_wait(void);
extern volatile uint32_t button_pressed_duration;
extern void button_task(void);
extern volatile bool cancel_button;
extern bool touch_accept_button;
extern volatile bool force_button_wait;

#endif // BUTTON_H

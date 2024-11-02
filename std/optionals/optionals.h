/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <stdlib.h>
#include <stdbool.h>

#define func(name, params, res) res (*name)params

typedef struct optional_t optional_t;

typedef struct optionals_mod {
    // Constructors
    func(some, (const void *value, const size_t size), optional_t*);
    func(none, (void), optional_t*);

    // Getters
    func(value, (const optional_t *optional), void*);
    func(size, (const optional_t *optional), size_t);

    // Checkers
    func(is_some, (const optional_t *optional), bool);
    func(is_none, (const optional_t *optional), bool);

} optionals_mod;

extern const optionals_mod optionals;

#undef func
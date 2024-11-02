/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <iso646.h>
#include <stdlib.h>
#include <stdbool.h>

#include "optionals.h"

#define new(name, type) type *name = malloc(sizeof(type))

struct optional_t
{
    enum { OPTIONAL_SOME, OPTIONAL_NONE } status;
    size_t mem_layout;
    void *value;
};

optional_t *some(const void *value, const size_t size) {
    new(some, optional_t);

    some->status = OPTIONAL_SOME;
    some->mem_layout = size;
    some->value = value;

    return some;
}

optional_t *none() {
    new(none, optional_t);

    none->status = OPTIONAL_NONE;
    none->mem_layout = 0;
    none->value = NULL;
    
    return none;
}

void* value(const optional_t *optional) {
    return optional->value;
}

size_t size(const optional_t *optional) {
    return optional->mem_layout;
}


bool is_some(const optional_t *optional) {
    return optional->status == OPTIONAL_SOME;
}

bool is_none(const optional_t *optional) {
    return optional->status == OPTIONAL_NONE;
}


const optionals_mod optionals = {
    .some = some,
    .none = none,
    .of = some,
    .empty = none,
    
    .value = value,
    .size = size,

    .is_some = is_some,
    .is_none = is_none
};
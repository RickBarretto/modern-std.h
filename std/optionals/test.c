/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <assert.h>
#include <iso646.h>
#include <strings.h>
#include <stdio.h>

#include <std/unitc/unitc.h>

#include "optionals.h"

optional_t *some_optional() {
    return optionals.some(10, sizeof(10));
}

optional_t *empty_optional() {
    return optionals.none();
}


test("Some Optionals") {    
    optional_t *actual = some_optional();
    
    it("Should be some") {
        assert(optionals.is_some(actual));
        assert(not optionals.is_none(actual));
    }

    it("Should have original value") {
        assert(10 == optionals.value(actual));
    }

    it("Should have original size") {
        assert(sizeof(10) == optionals.size(actual));
    }
}


test("Empty Optionals") {    
    optional_t *actual = empty_optional();
    
    it("Should be none") {
        assert(optionals.is_none(actual));
        assert(not optionals.is_some(actual));
    }

    it("Should have nil value") {
        assert(NULL == optionals.value(actual));
    }

    it("Should have no size") {
        assert(0 == optionals.size(actual));
    }
}


test("Alternative constructors") {
    it("optionals::of should be optionals::some") {
        int value = 10;
        optional_t *expected = optionals.some(value, sizeof value);
        optional_t *actual = optionals.of(value, sizeof value);

        assert(optionals.is_some(expected) == optionals.is_some(actual));
        assert(optionals.value(expected) == optionals.value(actual));
    }
    
    it("optionals::empty should be optionals::none") {
        optional_t *expected = optionals.none();
        optional_t *actual = optionals.empty();

        assert(optionals.is_some(expected) == optionals.is_some(actual));
        assert(optionals.value(expected) == optionals.value(actual));
    }
}


int main() {
    run_tests("Test results.h module");
    return 0;
}
#include <assert.h>
#include <iso646.h>
#include <strings.h>
#include <stdio.h>

#include "../unitc/unitc.h"

#include "results.h"

result_t *ok_result() {
    return results.ok((void *)10, sizeof(10));
}

result_t *err_result() {
    char message[] = "Unexpected error";
    return results.err(message, sizeof(message));
}

test("Should return the equivalent status") {
    it("Should be ok") {
        result_t *actual = ok_result();

        assert(results.is_ok(actual));
        assert(not results.is_err(actual));
    }

    it("Should be an error") {
        result_t *actual = err_result();

        assert(not results.is_ok(actual));
        assert(results.is_err(actual));
    }
}

test("Should return same wrapped value") {
    it("Should be the same for Ok") {
        result_t *actual = ok_result();

        assert(10 == results.value(actual));
        assert(sizeof(10) == results.size(actual));
    }
    
    it("Should be the same for Error") {
        char expected[] = "Unexpected error";
        result_t *actual = err_result();
        
        assert(0 == strcmp(expected, results.value(actual)));
        assert(sizeof(expected) == results.size(actual));
    }
}


int main() {
    run_tests("Test results.h module");
    return 0;
}
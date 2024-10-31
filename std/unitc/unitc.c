#include <stdio.h>
#include <stdint.h>

#include "unitc.h"

struct unitc_tests {
    uint_fast16_t assert_count;   
    uint_fast8_t suite_count;   
    test_t all[100];
    char * descriptions[100];
};

struct unitc_tests __unitc_tests = {
    .assert_count = 0,
    .suite_count = 0
};

void add_test(test_t func, const char *description) {
    __unitc_tests.all[__unitc_tests.suite_count] = func;
    __unitc_tests.descriptions[__unitc_tests.suite_count] = description;
    __unitc_tests.suite_count++;
}

void display_it(char *description) {
    printf("    #%d: %s\n", __unitc_tests.assert_count + 1, description);
    __unitc_tests.assert_count++;
}

void run_tests(char *description) {
    printf("%s\n\n", description);
    for (int i = 0; i < __unitc_tests.suite_count; i++) {
        printf("* Suite #%d: %s...\n", i + 1, __unitc_tests.descriptions[i]);
        __unitc_tests.all[i]();
        __unitc_tests.assert_count = 0;
        printf("\n");
    }
}

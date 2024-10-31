#pragma once

#define CONCAT(a, b) a ## _ ## b
#define UNIQUE_NAME(name, line) CONCAT(name, line)

#define test(description)                               \
    void UNIQUE_NAME(test_func_, __LINE__)(void);       \
    __attribute__((constructor))                        \
    void UNIQUE_NAME(register_func_, __LINE__)(void) {  \
        add_test(                                       \
            UNIQUE_NAME(test_func_, __LINE__),          \
            description                                 \
        );                                              \
    }                                                   \
    void UNIQUE_NAME(test_func_, __LINE__)(void)

#define it(description) display_it(description);

typedef void (*test_t)(void);

void display_it();
void add_test(test_t func, const char *description);
void run_tests();
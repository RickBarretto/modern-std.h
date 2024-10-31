#include <stdlib.h>
#include <stdbool.h>

#define func(name, params, res) res (*name)params

// Type definition
typedef struct result_t result_t;


// Module definition
typedef struct results_mod {
    // Constructors
    func(ok, (const void * value, const size_t size), struct result_t*);
    func(err, (const void * value, const size_t size), struct result_t*);

    // Getters
    func(value, (const result_t *result), void*);
    func(size, (const result_t *result), size_t);
    
    // Checkers
    func(is_ok, (const result_t *result), bool);
    func(is_err, (const result_t *result), bool);
 
    // Functional
    func(or_else, (const result_t *result, const void *value, const size_t size), result_t*);
    func(then, (const result_t *result, func(callback, (void * value), void)), void);
} results_mod;

extern const results_mod results;

#undef func
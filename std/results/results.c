#include <iso646.h>
#include <stdlib.h>
#include <stdbool.h>

#include "results.h"

#define func(name, params, res) res (*name)params
#define new(name, type) type *name = malloc(sizeof(type))

struct result_t
{
    enum { RESULT_OK, RESULT_ERR } status;
    size_t mem_layout;
    union { void *error; void *value; };
};


result_t *ok(const void *value, const size_t size) {
    new(ok, result_t);

    ok->status = RESULT_OK;
    ok->mem_layout = size;
    ok->value = value;
    
    return ok;
}

result_t *err(const void *value, const size_t size) {
    new(err, result_t);

    err->status = RESULT_ERR;
    err->mem_layout = size;
    err->error = value;
    
    return err;
}

void* value(const result_t *result) {
    return result->value;
}

void* error(const result_t *result) {
    return result->error;
}

size_t size(const result_t *result) {
    return result->mem_layout;
}


bool is_ok(const result_t *result) {
    return result->status == RESULT_OK;
}

bool is_err(const result_t *result) {
    return result->status == RESULT_ERR;
}


result_t *or_else(const result_t *result, const void *value, const size_t size) {
    return (is_ok(result))? result : ok(value, size);
}

void then(const result_t *result, func(callback, (void * value), void)) {
    if (is_ok(result))
        callback(value);
}

const results_mod results = {
    .ok = ok,
    .err = err,
    
    .value = value,
    .size = size,
    
    .is_ok = is_ok,
    .is_err = is_err,
    
    .or_else = or_else,
    .then = then
};
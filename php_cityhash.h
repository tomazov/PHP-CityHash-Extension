#ifndef PHP_CITYHASH_H
#define PHP_CITYHASH_H

#define PHP_CITYHASH_EXTNAME  "cityhash"
#define PHP_CITYHASH_EXTVER   "1.0"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif 

extern "C" {
#include "php.h"
}

extern zend_module_entry cityhash_module_entry;
#define phpext_cityhash_ptr &cityhash_module_entry;

PHP_FUNCTION(cityhash64);
PHP_FUNCTION(cityhash128);

typedef struct {
        char *input;
} cityhash64;

typedef struct {
        char *input;
} cityhash128;

#endif /* PHP_CITYHASH_H */

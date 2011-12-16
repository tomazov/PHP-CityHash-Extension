#include "php_cityhash.h"
#include "city.h"

/* {{{ cityhash_functions[]
 */
zend_function_entry cityhash_functions[] = {
        PHP_FE(cityhash64,      NULL)
        PHP_FE(cityhash128,     NULL)
        {NULL, NULL, NULL}
};
/* }}} */

zend_module_entry cityhash_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_CITYHASH_EXTNAME,
    cityhash_functions,	   /* FUNCTIONS */
    NULL,                  /* MINIT */
    NULL,                  /* MSHUTDOWN */
    NULL,                  /* RINIT */
    NULL,                  /* RSHUTDOWN */
    NULL,                  /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_CITYHASH_EXTVER,
#endif
    STANDARD_MODULE_PROPERTIES
};

/* {{{ proto string cityhash64( string str )
   Returns the CityHash64 of the input */
PHP_FUNCTION(cityhash64)
{
        char *str;
        int str_len;
	uint64 result;
	char p[16];
        if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
                return;
        }
	result = CityHash64(str, str_len);
	sprintf(p, "%Lx", result);
	RETURN_STRING(p, 1);
}
/* }}} */

/* {{{ proto string cityhash128( string str )   Returns the CityHash128 of the input */
PHP_FUNCTION(cityhash128)
{
        char *str;
        int str_len, i = 0;
	uint128 result;
	char p[32];
        if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &str, &str_len) == FAILURE) {
                return;
        }
	result = CityHash128(str, str_len);
	sprintf(p, "%Lx%Lx", result.first, result.second);
	RETURN_STRING(p, 1);
}
/* }}} */

#ifdef COMPILE_DL_CITYHASH
extern "C" {
ZEND_GET_MODULE(cityhash)
}
#endif

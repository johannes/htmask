/*
  +----------------------------------------------------------------------+
  | HashTable Dumper                                                     |
  +----------------------------------------------------------------------+
  | Copyright (c) 2015 Johannes Schlüter                                 |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Johannes Schlüter <johannes@php.net>                         |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_htmask.h"

/* {{{ proto int zend_hash_table_mask(array $ht)
   Return the array's table_mask */
PHP_FUNCTION(zend_hash_table_mask)
{
	HashTable *table;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "h", &table) == FAILURE) {
		return;
	}

	RETURN_LONG(table->nTableMask);
}
/* }}} */

/* {{{ proto int zend_hash_func(string $text)
   Return the hash for the value as used in Zend HashTables */
PHP_FUNCTION(zend_hash_func)
{
	char *text;
	int text_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &text, &text_len) == FAILURE) {
		return;
	}

	RETURN_LONG(zend_inline_hash_func(text, text_len+1));
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(htmask)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "htmask support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ htmask_functions[] */
const zend_function_entry htmask_functions[] = {
	PHP_FE(zend_hash_table_mask, NULL)
	PHP_FE(zend_hash_func, NULL)
	PHP_FE_END
};
/* }}} */

/* {{{ htmask_module_entry
 */
zend_module_entry htmask_module_entry = {
	STANDARD_MODULE_HEADER,
	"htmask",
	htmask_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_MINFO(htmask),
	PHP_HTMASK_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HTMASK
ZEND_GET_MODULE(htmask)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

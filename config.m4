PHP_ARG_ENABLE(htmask, whether to enable htmask support,
[  --enable-htmask           Enable htmask support])

if test "$PHP_HTMASK" != "no"; then
  PHP_NEW_EXTENSION(htmask, htmask.c, $ext_shared)
fi

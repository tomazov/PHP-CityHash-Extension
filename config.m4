PHP_ARG_ENABLE(cityhash,
    [Enable Google's CityHash methods],
    [  --enable-cityhash      Enable CityHash support])

if test $PHP_CITYHASH != "no"; then
    PHP_REQUIRE_CXX()
    PHP_SUBST(CITYHASH_SHARED_LIBADD)
    PHP_ADD_LIBRARY(stdc++, 1, CITYHASH_SHARED_LIBADD)
    PHP_NEW_EXTENSION(cityhash, cityhash.cc city.cc, $ext_shared)
fi

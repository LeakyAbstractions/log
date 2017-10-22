#
# log
#
# Copyright (c) 2017 Guillermo Calvo
# Licensed under the GNU Lesser General Public License
#

AUTOMAKE_OPTIONS = foreign subdir-objects

AM_CFLAGS = -Wall -Wextra -Werror --pedantic -std=c11 -coverage -O0 -I$(LOG_PATH)
AM_LDFLAGS = -L/usr/local/lib
LDADD = -lfmt


# Library

LOG_PATH            = src
LOG_LIBRARY         = lib/liblog.a


# Install

lib_LIBRARIES =                         \
    $(LOG_LIBRARY)

include_HEADERS =                       \
    src/log.h


# Cleanup

CLEANFILES =                            \
    *.log


# log library

lib_liblog_a_CFLAGS                     = -Wall -Wextra -Werror --pedantic -std=c11
lib_liblog_a_SOURCES                    = src/log.c

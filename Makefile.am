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


# Documentation

docdir = $(datadir)/doc/log
doc_DATA = doc/*


# Cleanup

CLEANFILES =                            \
    *.log                               \
    *.gcda                              \
    *.gcno                              \
    *.gcov                              \
    src/*.gcda                          \
    src/*.gcno                          \
    src/*.gcov                          \
    test/*.gcda                         \
    test/*.gcno                         \
    test/*.gcov


# Check

check_PROGRAMS =                        \
	bin/check/config_init_00            \
	bin/check/config_init_01            \
	bin/check/config_init_02            \
	bin/check/config_init_03            \
	bin/check/config_init_04            \
	bin/check/config_init_05            \
	bin/check/config_final_00           \
	bin/check/config_final_01           \
	bin/check/config_final_02           \
	bin/check/config_final_03           \
	bin/check/config_final_04           \
	bin/check/config_final_05           \
	bin/check/config_final_06           \
	bin/check/loggers_init_00           \
	bin/check/loggers_init_01           \
	bin/check/loggers_init_02           \
	bin/check/loggers_init_03           \
	bin/check/loggers_init_04           \
	bin/check/loggers_init_05           \
	bin/check/loggers_init_06           \
	bin/check/loggers_init_07           \
	bin/check/loggers_init_08           \
	bin/check/loggers_init_09           \
	bin/check/loggers_init_10           \
	bin/check/loggers_init_11           \
	bin/check/loggers_init_12           \
	bin/check/loggers_init_13           \
	bin/check/loggers_final_00          \
	bin/check/loggers_final_01          \
	bin/check/loggers_final_02          \
	bin/check/loggers_final_03          \
	bin/check/loggers_final_04          \
	bin/check/loggers_final_05          \
	bin/check/loggers_final_06          \
	bin/check/loggers_final_07          \
	bin/check/loggers_final_08          \
	bin/check/loggers_final_09          \
	bin/check/loggers_final_10          \
	bin/check/loggers_final_11          \
	bin/check/event_new_00              \
	bin/check/event_new_01              \
	bin/check/event_new_02              \
	bin/check/event_new_03              \
	bin/check/event_new_04              \
	bin/check/event_new_05              \
	bin/check/event_new_06              \
	bin/check/event_new_07              \
	bin/check/event_new_08              \
	bin/check/event_new_09              \
	bin/check/event_new_10              \
	bin/check/event_new_11              \
	bin/check/event_new_12              \
	bin/check/event_new_13              \
	bin/check/event_new_14              \
	bin/check/event_new_15              \
	bin/check/event_new_16              \
	bin/check/event_new_17              \
	bin/check/event_new_18              \
	bin/check/event_new_19              \
	bin/check/event_new_20

TESTS =                                 \
	bin/check/config_init_00            \
	bin/check/config_init_01            \
	bin/check/config_init_02            \
	bin/check/config_init_03            \
	bin/check/config_init_04            \
	bin/check/config_init_05            \
	bin/check/config_final_00           \
	bin/check/config_final_01           \
	bin/check/config_final_02           \
	bin/check/config_final_03           \
	bin/check/config_final_04           \
	bin/check/config_final_05           \
	bin/check/config_final_06           \
	bin/check/loggers_init_00           \
	bin/check/loggers_init_01           \
	bin/check/loggers_init_02           \
	bin/check/loggers_init_03           \
	bin/check/loggers_init_04           \
	bin/check/loggers_init_05           \
	bin/check/loggers_init_06           \
	bin/check/loggers_init_07           \
	bin/check/loggers_init_08           \
	bin/check/loggers_init_09           \
	bin/check/loggers_init_10           \
	bin/check/loggers_init_11           \
	bin/check/loggers_init_12           \
	bin/check/loggers_init_13           \
	bin/check/loggers_final_00          \
	bin/check/loggers_final_01          \
	bin/check/loggers_final_02          \
	bin/check/loggers_final_03          \
	bin/check/loggers_final_04          \
	bin/check/loggers_final_05          \
	bin/check/loggers_final_06          \
	bin/check/loggers_final_07          \
	bin/check/loggers_final_08          \
	bin/check/loggers_final_09          \
	bin/check/loggers_final_10          \
	bin/check/loggers_final_11          \
	bin/check/event_new_00              \
	bin/check/event_new_01              \
	bin/check/event_new_02              \
	bin/check/event_new_03              \
	bin/check/event_new_04              \
	bin/check/event_new_05              \
	bin/check/event_new_06              \
	bin/check/event_new_07              \
	bin/check/event_new_08              \
	bin/check/event_new_09              \
	bin/check/event_new_10              \
	bin/check/event_new_11              \
	bin/check/event_new_12              \
	bin/check/event_new_13              \
	bin/check/event_new_14              \
	bin/check/event_new_15              \
	bin/check/event_new_16              \
	bin/check/event_new_17              \
	bin/check/event_new_18              \
	bin/check/event_new_19              \
	bin/check/event_new_20


tests: check


# log library

lib_liblog_a_CFLAGS                     = -Wall -Wextra -Werror --pedantic -std=c11
lib_liblog_a_SOURCES                    = src/log.c


# log tests

bin_check_config_init_00_SOURCES        = src/log.c test/config_init_00.c
bin_check_config_init_01_SOURCES        = src/log.c test/config_init_01.c
bin_check_config_init_02_SOURCES        = src/log.c test/config_init_02.c
bin_check_config_init_03_SOURCES        = src/log.c test/config_init_03.c
bin_check_config_init_04_SOURCES        = src/log.c test/config_init_04.c
bin_check_config_init_05_SOURCES        = src/log.c test/config_init_05.c
bin_check_config_final_00_SOURCES       = src/log.c test/config_final_00.c
bin_check_config_final_01_SOURCES       = src/log.c test/config_final_01.c
bin_check_config_final_02_SOURCES       = src/log.c test/config_final_02.c
bin_check_config_final_03_SOURCES       = src/log.c test/config_final_03.c
bin_check_config_final_04_SOURCES       = src/log.c test/config_final_04.c
bin_check_config_final_05_SOURCES       = src/log.c test/config_final_05.c
bin_check_config_final_06_SOURCES       = src/log.c test/config_final_06.c
bin_check_loggers_init_00_SOURCES       = src/log.c test/loggers_init_00.c
bin_check_loggers_init_01_SOURCES       = src/log.c test/loggers_init_01.c
bin_check_loggers_init_02_SOURCES       = src/log.c test/loggers_init_02.c
bin_check_loggers_init_03_SOURCES       = src/log.c test/loggers_init_03.c
bin_check_loggers_init_04_SOURCES       = src/log.c test/loggers_init_04.c
bin_check_loggers_init_05_SOURCES       = src/log.c test/loggers_init_05.c
bin_check_loggers_init_06_SOURCES       = src/log.c test/loggers_init_06.c
bin_check_loggers_init_07_SOURCES       = src/log.c test/loggers_init_07.c
bin_check_loggers_init_08_SOURCES       = src/log.c test/loggers_init_08.c
bin_check_loggers_init_09_SOURCES       = src/log.c test/loggers_init_09.c
bin_check_loggers_init_10_SOURCES       = src/log.c test/loggers_init_10.c
bin_check_loggers_init_11_SOURCES       = src/log.c test/loggers_init_11.c
bin_check_loggers_init_12_SOURCES       = src/log.c test/loggers_init_12.c
bin_check_loggers_init_13_SOURCES       = src/log.c test/loggers_init_13.c
bin_check_loggers_final_00_SOURCES      = src/log.c test/loggers_final_00.c
bin_check_loggers_final_01_SOURCES      = src/log.c test/loggers_final_01.c
bin_check_loggers_final_02_SOURCES      = src/log.c test/loggers_final_02.c
bin_check_loggers_final_03_SOURCES      = src/log.c test/loggers_final_03.c
bin_check_loggers_final_04_SOURCES      = src/log.c test/loggers_final_04.c
bin_check_loggers_final_05_SOURCES      = src/log.c test/loggers_final_05.c
bin_check_loggers_final_06_SOURCES      = src/log.c test/loggers_final_06.c
bin_check_loggers_final_07_SOURCES      = src/log.c test/loggers_final_07.c
bin_check_loggers_final_08_SOURCES      = src/log.c test/loggers_final_08.c
bin_check_loggers_final_09_SOURCES      = src/log.c test/loggers_final_09.c
bin_check_loggers_final_10_SOURCES      = src/log.c test/loggers_final_10.c
bin_check_loggers_final_11_SOURCES      = src/log.c test/loggers_final_11.c
bin_check_event_new_00_SOURCES          = src/log.c test/event_new_00.c
bin_check_event_new_01_SOURCES          = src/log.c test/event_new_01.c
bin_check_event_new_02_SOURCES          = src/log.c test/event_new_02.c
bin_check_event_new_03_SOURCES          = src/log.c test/event_new_03.c
bin_check_event_new_04_SOURCES          = src/log.c test/event_new_04.c
bin_check_event_new_05_SOURCES          = src/log.c test/event_new_05.c
bin_check_event_new_06_SOURCES          = src/log.c test/event_new_06.c
bin_check_event_new_07_SOURCES          = src/log.c test/event_new_07.c
bin_check_event_new_08_SOURCES          = src/log.c test/event_new_08.c
bin_check_event_new_09_SOURCES          = src/log.c test/event_new_09.c
bin_check_event_new_10_SOURCES          = src/log.c test/event_new_10.c
bin_check_event_new_11_SOURCES          = src/log.c test/event_new_11.c
bin_check_event_new_12_SOURCES          = src/log.c test/event_new_12.c
bin_check_event_new_13_SOURCES          = src/log.c test/event_new_13.c
bin_check_event_new_14_SOURCES          = src/log.c test/event_new_14.c
bin_check_event_new_15_SOURCES          = src/log.c test/event_new_15.c
bin_check_event_new_16_SOURCES          = src/log.c test/event_new_16.c
bin_check_event_new_17_SOURCES          = src/log.c test/event_new_17.c
bin_check_event_new_18_SOURCES          = src/log.c test/event_new_18.c
bin_check_event_new_19_SOURCES          = src/log.c test/event_new_19.c
bin_check_event_new_20_SOURCES          = src/log.c test/event_new_20.c


# coverage

coverage: check log.c.gcov

log.c.gcov:
	gcov src/log.c --object-directory src/*

coverage-html: check coverage.html

.PHONY: coverage.html
coverage.html:
	gcov src/log.c
	gcovr --html --html-details -r src -o coverage.html

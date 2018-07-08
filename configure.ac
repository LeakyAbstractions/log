#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.


# Autoconf requirements
AC_PREREQ([2.68])


# Initialize package
AC_INIT([log], [1.0.0.0], [log@guillermo.in], [log], [https://github.com/LeakyAbstractions/log/])


# Information on the package
AC_COPYRIGHT([Copyright 2018 Guillermo Calvo])
AC_REVISION([$PACKAGE_VERSION])
AC_MSG_NOTICE([
 _             
| |            
| | ___   __ _ 
| |/ _ \ / _` |
| | (_) | (_| |
|_|\___/ \__, |
 Logging  __/ |
 library |___/ 
])


# Check if the source folder is correct
AC_CONFIG_SRCDIR([src/log.c])


# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_RANLIB
AM_PROG_AR


# Checks for header files.
AC_HEADER_STDC
AC_HEADER_STDBOOL
AC_CHECK_HEADERS([stdarg.h])
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_HEADERS([stddef.h])
AC_CHECK_HEADERS([stdint.h])
AC_CHECK_HEADERS([string.h])


# Checks for types
AC_TYPE_SIZE_T


# Checks for compiler characteristics
AC_LANG([C])

dnl BEGIN variadic macro support
AC_MSG_CHECKING([for variadic macro support])
AC_COMPILE_IFELSE(AC_LANG_PROGRAM(
    [[
#include <stdio.h>
#include <string.h>
#define asprint(buffer, format, args...) asprintf(buffer, format, ## args)
    ]], [[AC_LANG_SOURCE([
char * buf;
asprint(buf, "testing %s %s\n", "variadic", "macros");
return( strcmp("testing variadic macros", buf) );
    ])]]),
    [ support_macro_varargs=yes ],
    [ support_macro_varargs=no ])
if test "x$support_macro_varargs" = xyes; then
AC_DEFINE(HAVE_VARIADIC_MACROS)
AC_MSG_RESULT(yes)
else
AC_MSG_RESULT(no)
fi
dnl END variadic macro support

dnl BEGIN function name support
AC_MSG_CHECKING([for __func__ support])
AC_COMPILE_IFELSE(AC_LANG_PROGRAM(
    [[
#include <stdio.h>
    ]], [[AC_LANG_SOURCE([
char * name = __func__;
printf("testing function name: %s\n", name);
return( strcmp("main", name) );
    ])]]),
    [ support_function_name=yes ],
    [ support_function_name=no ])
if test "x$support_function_name" = xyes; then
AC_DEFINE(HAVE_FUNC)
AC_MSG_RESULT(yes)
else
AC_MSG_RESULT(no)
fi
dnl END function name support


# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([vfprintf])
AC_CHECK_FUNCS([vsnprintf])
AC_CHECK_FUNCS([timespec_get])


# The config file is generated but not used by the source code
#AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
    log.pc
    Makefile
])


# Automake initialisation
AM_INIT_AUTOMAKE([
    -Wall
    -Werror
    foreign
	subdir-objects
    no-define
])


AC_OUTPUT

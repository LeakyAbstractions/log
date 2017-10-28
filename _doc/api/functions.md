
/** Register a new formatter */
extern int fmt_register_formatter(fmt_formatter formatter, const char * id);

/** Print formatted */
extern int fmt_print(struct fmt_stream * out, const char * format, ...);

/** Print formatted (native parameters only) */
extern int fmt_print_native(struct fmt_stream * out, const char * format, ...);

/** Print formatted variable list arguments */
extern int fmt_vprint(struct fmt_stream * out, const char * format, va_list * arg);

/** Print formatted variable list arguments (native parameters only) */
extern int fmt_vprint_native(struct fmt_stream * out, const char * format, va_list * arg);


# define FMT_ERROR                                      ( (int)-1 )
# define FMT_STREAM(FILE, BUFFER, BYTES, TYPE)          {(FILE), (BUFFER), (BYTES), 0, (TYPE)}
# define FMT_FILE(FILE)                                 FMT_STREAM((FILE), NULL, 0, FMT_STREAM_FILE)
# define FMT_STDOUT                                     FMT_STREAM(NULL, NULL, 0, FMT_STREAM_STDOUT)
# define FMT_STDERR                                     FMT_STREAM(NULL, NULL, 0, FMT_STREAM_STDERR)
# define FMT_BUFFER(BUFFER, BYTES)                      FMT_STREAM(NULL, (BUFFER), (BYTES), FMT_STREAM_BUFFER)

# if __STDC_VERSION__ >= 199901L                        
#   define FMT_PRINT(STREAM, ...)                       fmt_print( (struct fmt_stream)(STREAM), __VA_ARGS__ )
#   define FMT_VPRINT(STREAMT, FORMAT, ARG)             fmt_vprint( (struct fmt_stream)(STREAM), (FORMAT), (ARG) )
#   define fmt_snprintf(BUFFER, BYTES, ...)             FMT_PRINT(FMT_BUFFER((BUFFER), (BYTES)), __VA_ARGS__)
#   define fmt_fprintf(FILE, ...)                       FMT_PRINT(FMT_FILE(FILE), __VA_ARGS__)
#   define fmt_printf(...)                              FMT_PRINT(FMT_FILE(stdout), __VA_ARGS__)
#   define fmt_vsnprintf(BUFFER, SIZE, FORMAT, ARGS)    FMT_VPRINT(FMT_BUFFER((BUFFER), (BYTES)), (FORMAT), &(ARGS))
#   define fmt_vfprintf(FILE, FORMAT, ARGS)             FMT_VPRINT(FMT_FILE(FILE), (FORMAT), &(ARGS))
#endif

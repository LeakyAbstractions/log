
/** Output stream type */
enum fmt_stream_type { FMT_STREAM_BUFFER, FMT_STREAM_FILE, FMT_STREAM_STDOUT, FMT_STREAM_STDERR };

/** Output stream */
struct fmt_stream{

	FILE *  file;
	char *  buffer;
	size_t  bytes;
	int     written;
	char    type;
};

/** Custom formatter */
typedef int (*fmt_formatter)(struct fmt_stream * out, const char * id, const char * options, va_list * arg);

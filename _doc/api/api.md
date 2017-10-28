
# API


## Functions

- `fmt_register_formatter`: Register a new formatter
- `fmt_print`: Print formatted
- `fmt_print_native`: Print formatted (native parameters only)
- `fmt_vprint`: Print formatted variable list arguments
- `fmt_vprint_native`: Print formatted variable list arguments (native parameters only)


##　Types

- `fmt_formatter`: Represents a function that can be registered as a custom formatter
- `fmt_stream`: Represents an output stream
- `fmt_stream_type`: Represents a specific kind output stream
  - `FMT_STREAM_BUFFER`: It is used for streams channeled to a string buffer
  - `FMT_STREAM_FILE`: It is used for streams channeled to a regular file
  - `FMT_STREAM_STDOUT`: It is used for streams channeled to standard output
  - `FMT_STREAM_STDERR`: It is used for streams channeled to standard error

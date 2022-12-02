# File Access Pointers

- Both istream and ostream provide member functions for repositioning the file-position pointer. These member functions are seekg ("seek get") for istream and seekp ("seek put") for ostream.
- The argument to seekg and seekp normally is a long integer. A second argument can be specified to indicate the seek direction. The seek direction can be ios::beg (the default) for positioning relative to the beginning of a stream, ios::cur for positioning relative to the current position in a stream or ios::end for positioning relative to the end of a stream.
  // position to the nth byte of fileObject (assumes ios::beg)
- fileObject.seekg( n );
  // position n bytes forward in fileObject
- fileObject.seekg( n, ios::cur );
  // position n bytes back from end of fileObject
- fileObject.seekg( n, ios::end );
  // position at end of fileObject
- fileObject.seekg( 0, ios::end );

## Testing Errors during File Operations

- eof(): returns non-zero (true value) if end-of-file is encountered while reading, otherwise returns zero (false value).
- fail(): returns non-zero when an input or output operation has failed.
- good(): returns non-zero if no error has occurred.
- bad(): returns non-zero if an invalid operation is attempted.

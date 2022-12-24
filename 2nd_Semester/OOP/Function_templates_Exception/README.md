# Standard Exceptions in C++

- There are some standard exceptions in C++ under <"exception"> which we can use in our programs.
  -hey are arranged in a parent-child class hierarchy which is depicted below:
- std::exception - Parent class of all the standard C++ exceptions.
- logic_error - Exception happens in the internal logical of a program.
- domain_error - Exception due to use of invalid domain.
- invalid argument - Exception due to invalid argument.
- out_of_range - Exception due to out of range i.e. size requirement exceeds allocation.
- length_error - Exception due to length error.
- runtime_error - Exception happens during runtime.
- range_error - Exception due to range errors in internal computations.
- overflow_error - Exception due to arithmetic overflow errors.
- underflow_error - Exception due to arithmetic underflow errors
- bad_alloc - Exception happens when memory allocation with new() fails.
- bad_cast - Exception happens when dynamic cast fails.
- bad_exception - Exception is specially designed to be listed in the dynamic-exception-specifier.
- bad_typeid - Exception thrown by typeid.

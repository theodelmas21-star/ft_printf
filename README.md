# ft_printf

> A C programming project at 42 School that recreates the standard printf function.

## Overview

**ft_printf** is a library project designed to recode the standard `printf` function from the C standard library. It introduces variable argument lists (`stdarg`) and custom format parsing, reinforcing code modularity and rigorous testing.

## Features

- **Custom Implementation**: Recreates `printf` behavior without using the original `printf`.
- **Supported Format Specifiers**:
  - `%c` (character)
  - `%s` (string)
  - `%p` (void * pointer address in hexadecimal)
  - `%d` / `%i` (signed decimal integer)
  - `%u` (unsigned decimal integer)
  - `%x` / `%X` (lowercase / uppercase hexadecimal integer)
  - `%%` (percent sign)
- **Modular Architecture**: Built with clear separation of concerns for parsing, formatting, and buffer management.

## Compilation & Usage

### Compilation

Compile the project using the provided `Makefile` to generate the `libftprintf.a` static library:

```bash
git clone git@github.com:your-username/ft_printf.git
cd ft_printf
make
```

### Integration

Include the header in your C source files and link the static library during compilation:

```bash
gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o test_printf
```

## Allowed Functions

- `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`
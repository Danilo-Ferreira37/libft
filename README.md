_This project has been created as part of the 42 curriculum by dosorio-_

[![Language](https://img.shields.io/badge/Language-C-blue.svg?style=flat&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))

# 📖 Libft

**Libft** is a custom C library built from scratch as part of the [42](https://www.42.fr/) curriculum. It re-implements the most essential functions from the C standard library (`libc`), plus a collection of extra utilities for string handling, memory management, I/O, linked lists, a custom `ft_printf`, and `get_next_line`.

The goal is to deeply understand how these fundamental building blocks work under the hood, and to have a reliable, reusable foundation for all future 42 projects.

---

## 📦 Table of Contents

- [Function Reference](#-function-reference)
  - [1. Character Analysis](#1-character-analysis)
  - [2. Memory Manipulation](#2-memory-manipulation)
  - [3. String Manipulation](#3-string-manipulation)
  - [4. Allocation, Conversion & Extras](#4-allocation-conversion--extras)
  - [5. File Descriptor Output](#5-file-descriptor-output)
  - [6. get\_next\_line](#6-get_next_line)
  - [7. ft\_printf](#7-ft_printf)
  - [8. Bonus — Linked Lists](#8-bonus--linked-lists)
- [Compilation](#️-compilation)
- [How to Use in Your Project](#️-how-to-use-in-your-project)
- [File Structure](#-file-structure)
- [Author](#-author)
- [Notes & Best Practices](#-notes--best-practices)

---

## 🔧 Function Reference

### 1. Character Analysis

> Functions that test or convert a single character. All accept an `int` and return non-zero (true) or 0 (false).

| Function | Description |
|---|---|
| `ft_isalpha(c)` | Returns true if `c` is an alphabetic letter (a–z or A–Z). |
| `ft_isdigit(c)` | Returns true if `c` is a decimal digit (0–9). |
| `ft_isalnum(c)` | Returns true if `c` is alphanumeric (letter or digit). |
| `ft_isascii(c)` | Returns true if `c` is a valid ASCII character (0–127). |
| `ft_isprint(c)` | Returns true if `c` is a printable character (including space). |
| `ft_isspace(c)` | Returns true if `c` is a space character (`' '`). |
| `ft_isoperator(c)` | Returns true if `c` is a common arithmetic operator. |
| `ft_toupper(c)` | Converts lowercase letter to uppercase; other chars pass through unchanged. |
| `ft_tolower(c)` | Converts uppercase letter to lowercase; other chars pass through unchanged. |

---

### 2. Memory Manipulation

> Functions for low-level byte-level operations on memory blocks.

| Function | Description |
|---|---|
| `ft_memset(b, c, len)` | Fills the first `len` bytes of memory area `b` with the byte value `c`. |
| `ft_bzero(s, n)` | Sets the first `n` bytes of `s` to zero. |
| `ft_memcpy(dst, src, n)` | Copies `n` bytes from `src` to `dst`. Behaviour is undefined for overlapping areas. |
| `ft_memmove(dst, src, len)` | Copies `len` bytes from `src` to `dst`, safe for overlapping memory regions. |
| `ft_memchr(s, c, n)` | Scans the first `n` bytes of `s` for the byte `c`; returns a pointer to the match or NULL. |
| `ft_memcmp(s1, s2, n)` | Compares the first `n` bytes of `s1` and `s2`; returns 0 if equal, or the difference. |
| `ft_calloc(count, size)` | Allocates `count * size` bytes of zeroed memory. Returns NULL on failure. |

---

### 3. String Manipulation

> Functions for searching, comparing, and copying C strings.

| Function | Description |
|---|---|
| `ft_strlen(s)` | Returns the length of string `s` (not counting the null terminator). |
| `ft_strlcpy(dst, src, size)` | Copies up to `size - 1` characters from `src` to `dst`, always null-terminating `dst`. Returns the length of `src`. |
| `ft_strlcat(dst, src, size)` | Appends `src` to `dst` up to `size - 1` total characters. Returns the intended total length. |
| `ft_strchr(s, c)` | Finds the first occurrence of character `c` in string `s`. Returns a pointer or NULL. |
| `ft_strrchr(s, c)` | Finds the last occurrence of character `c` in string `s`. Returns a pointer or NULL. |
| `ft_strncmp(s1, s2, n)` | Compares at most `n` characters of `s1` and `s2`. Returns 0 if equal. |
| `ft_strnstr(hay, needle, len)` | Finds the first occurrence of `needle` in `hay`, searching at most `len` characters. |
| `ft_strdup(s)` | Allocates and returns a duplicate of string `s`. |
| `ft_strndup(s, n)` | Allocates and returns a duplicate of at most `n` characters of `s`. |

---

### 4. Allocation, Conversion & Extras

> Functions that create new strings, convert data types, or apply transformations.

| Function | Description |
|---|---|
| `ft_substr(s, start, len)` | Allocates and returns a substring of `s` starting at index `start` with maximum length `len`. |
| `ft_strjoin(s1, s2)` | Allocates and returns a new string which is the concatenation of `s1` and `s2`. |
| `ft_strtrim(s1, set)` | Allocates and returns a copy of `s1` with leading and trailing characters from `set` removed. |
| `ft_split(s, c)` | Splits string `s` by delimiter character `c` and returns a null-terminated array of strings. |
| `ft_itoa(n)` | Converts integer `n` to a newly allocated string (handles negatives and `INT_MIN`). |
| `ft_atoi(str)` | Converts the initial portion of `str` to an `int`, skipping whitespace and handling sign. |
| `ft_strmapi(s, f)` | Creates a new string by applying function `f(index, char)` to each character of `s`. |
| `ft_striteri(s, f)` | Applies function `f(index, &char)` to each character of `s` in-place (no return value). |
| `ft_putnbr_base(nbr, base)` | Outputs integer `nbr` in the given base (e.g. binary, octal, hex). |

---

### 5. File Descriptor Output

> Functions to write characters, strings, and numbers to any file descriptor (stdout, stderr, files, etc.).

| Function | Description |
|---|---|
| `ft_putchar_fd(c, fd)` | Writes character `c` to file descriptor `fd`. |
| `ft_putstr_fd(s, fd)` | Writes string `s` to file descriptor `fd`. |
| `ft_putendl_fd(s, fd)` | Writes string `s` followed by a newline (`\n`) to file descriptor `fd`. |
| `ft_putnbr_fd(n, fd)` | Writes integer `n` as a string to file descriptor `fd`. |

---

### 6. `get_next_line`

> Reads one line at a time from a file descriptor. Particularly useful for reading files or standard input line by line without loading the whole file into memory.

| Function | Description |
|---|---|
| `get_next_line(fd)` | Reads and returns the next line (including `\n`) from `fd`. Returns `NULL` at EOF or on error. The returned string must be `free()`d by the caller. |

**Behavior:**
- On each successive call, returns the next unread line.
- Returns `NULL` when no more lines are available or if an error occurs.
- The buffer size can be set at compile time with `-D BUFFER_SIZE=<n>` (default: `42`).

**Example — reading a file line by line:**

```c
#include "libft.h"
#include <fcntl.h>

int main(void)
{
    int   fd;
    char  *line;

    fd = open("data.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

**Compile with a custom buffer size:**

```sh
cc -D BUFFER_SIZE=128 main.c -L. -lft -o my_program
```

---

### 7. `ft_printf`

> A custom re-implementation of the standard `printf` function using variadic arguments (`stdarg.h`). Supports the most commonly used format specifiers.

| Specifier | Description |
|---|---|
| `%c` | Prints a single character. |
| `%s` | Prints a null-terminated string. |
| `%d` / `%i` | Prints a signed decimal integer. |
| `%u` | Prints an unsigned decimal integer. |
| `%x` | Prints an unsigned integer in lowercase hexadecimal. |
| `%X` | Prints an unsigned integer in uppercase hexadecimal. |
| `%p` | Prints a pointer address in hexadecimal. |
| `%%` | Prints a literal `%` character. |

**Returns** the total number of characters printed (like the real `printf`).

**Example:**

```c
#include "libft.h"

int main(void)
{
    char  *name = "42Lisboa";
    int   score = 100;
    void  *ptr = &score;

    ft_printf("Project: %s\n", name);
    ft_printf("Score: %d / 100\n", score);
    ft_printf("Address: %p\n", ptr);
    ft_printf("Hex: 0x%x | 0x%X\n", score, score);
    return (0);
}
```

Output:
```
Project: 42Lisboa
Score: 100 / 100
Address: 0x7ffee1234abc
Hex: 0x64 | 0x64
```

---

### 8. Bonus — Linked Lists

> A full singly-linked list API. Enabled by compiling with `make bonus`. The list node type is `t_list`:

```c
typedef struct s_list
{
    void          *content;   // pointer to any data
    struct s_list *next;      // pointer to the next node
}   t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew(content)` | Allocates and returns a new node with `content` set and `next` as NULL. |
| `ft_lstadd_front(lst, new)` | Inserts `new` at the beginning of list `*lst`. |
| `ft_lstadd_back(lst, new)` | Appends `new` to the end of list `*lst`. |
| `ft_lstsize(lst)` | Counts and returns the number of nodes in the list. |
| `ft_lstlast(lst)` | Returns a pointer to the last node of the list. |
| `ft_lstdelone(lst, del)` | Frees one node's content using `del`, then frees the node itself (does not touch `next`). |
| `ft_lstclear(lst, del)` | Deletes and frees every node of the list using `del`, sets `*lst` to NULL. |
| `ft_lstiter(lst, f)` | Iterates the list and applies function `f` to each node's `content`. |
| `ft_lstmap(lst, f, del)` | Creates a new list by applying `f` to each node's `content`; uses `del` on failure. |

**Example — building and traversing a list:**

```c
#include "libft.h"

void  print_node(void *content)
{
    ft_printf("-> %s\n", (char *)content);
}

int main(void)
{
    t_list *lst;

    lst = ft_lstnew("first");
    ft_lstadd_back(&lst, ft_lstnew("second"));
    ft_lstadd_back(&lst, ft_lstnew("third"));

    ft_printf("List size: %d\n", ft_lstsize(lst));
    ft_lstiter(lst, print_node);

    ft_lstclear(&lst, NULL); // pass NULL if content doesn't need freeing
    return (0);
}
```

Output:
```
List size: 3
-> first
-> second
-> third
```

---

## ⚙️ Compilation

Clone the repository and use the provided `Makefile`:

```sh
git clone https://github.com/Danilo-Ferreira37/libft.git
cd libft
```

| Command | Effect |
|---|---|
| `make` | Compiles all standard source files into `libft.a`. |
| `make bonus` | Compiles standard **and** bonus (linked list) files into `libft.a`. |
| `make clean` | Removes all `.o` object files. |
| `make fclean` | Removes all `.o` files **and** the `libft.a` archive. |
| `make re` | Equivalent to `make fclean && make` — full rebuild. |

---

## 🛠️ How to Use in Your Project

1. **Copy** (or `git submodule add`) the `libft` folder into your project.
2. **Include** the header in your source files:

```c
#include "libft.h"
```

3. **Compile** your project linking against `libft.a`:

```sh
cc -Wall -Wextra -Werror main.c -L./libft -lft -o my_program
```

**Full `main.c` example:**

```c
#include "libft.h"

int main(void)
{
    // String utilities
    char *greeting = ft_strjoin("Hello, ", "World!");
    ft_printf("%s\n", greeting);
    free(greeting);

    // Number to string
    char *num_str = ft_itoa(-2147483648);
    ft_printf("INT_MIN as string: %s\n", num_str);
    free(num_str);

    // Split a sentence
    char **words = ft_split("one two three", ' ');
    int  i = 0;
    while (words[i])
    {
        ft_printf("word[%d] = %s\n", i, words[i]);
        free(words[i]);
        i++;
    }
    free(words);

    // Linked list
    t_list *lst = ft_lstnew("node_a");
    ft_lstadd_back(&lst, ft_lstnew("node_b"));
    ft_printf("List has %d nodes\n", ft_lstsize(lst));
    ft_lstclear(&lst, NULL);

    return (0);
}
```

Build and run:

```sh
make -C libft
cc -Wall -Wextra -Werror main.c -L./libft -lft -o my_program
./my_program
```

---

## 📂 File Structure

```
libft/
├── libft.h                   # All prototypes, macros, and the t_list struct
├── Makefile                  # Build rules (all, bonus, clean, fclean, re)
│
├── ft_isalpha.c              # Character analysis
├── ft_isdigit.c
├── ft_isalnum.c
├── ft_isascii.c
├── ft_isprint.c
├── ft_isspace.c
├── ft_isoperator.c
├── ft_toupper.c
├── ft_tolower.c
│
├── ft_memset.c               # Memory manipulation
├── ft_bzero.c
├── ft_memcpy.c
├── ft_memmove.c
├── ft_memchr.c
├── ft_memcmp.c
├── ft_calloc.c
│
├── ft_strlen.c               # String manipulation
├── ft_strlcpy.c
├── ft_strlcat.c
├── ft_strchr.c
├── ft_strrchr.c
├── ft_strncmp.c
├── ft_strnstr.c
├── ft_strdup.c
├── ft_strndup.c
│
├── ft_substr.c               # Allocation, conversion & extras
├── ft_strjoin.c
├── ft_strtrim.c
├── ft_split.c
├── ft_itoa.c
├── ft_atoi.c
├── ft_strmapi.c
├── ft_striteri.c
├── ft_putnbr_base.c
│
├── ft_putchar_fd.c           # File descriptor output
├── ft_putstr_fd.c
├── ft_putendl_fd.c
├── ft_putnbr_fd.c
│
├── get_next_line.c           # get_next_line
├── get_next_line_utils.c
│
├── ft_printf.c               # ft_printf
├── ft_printf_utils.c
│
├── ft_lstnew_bonus.c         # Bonus — linked lists
├── ft_lstadd_front_bonus.c
├── ft_lstadd_back_bonus.c
├── ft_lstsize_bonus.c
├── ft_lstlast_bonus.c
├── ft_lstdelone_bonus.c
├── ft_lstclear_bonus.c
├── ft_lstiter_bonus.c
└── ft_lstmap_bonus.c
```

---

## 👤 Author

| | |
|---|---|
| **dosorio-** | [GitHub](https://github.com/dosorio-) · 42Lisboa student |
| **Danilo-Ferreira37** | [GitHub](https://github.com/Danilo-Ferreira37) · Integration & maintenance |

---

## 📝 Notes & Best Practices

- **Always `free()` memory** returned by functions like `ft_strdup`, `ft_strjoin`, `ft_split`, `ft_itoa`, `ft_substr`, `ft_strtrim`, and `get_next_line`. Memory leaks will fail 42 evaluations.
- **Customise `BUFFER_SIZE`** at compile time for `get_next_line` with `-D BUFFER_SIZE=<n>`. Values that are too small may cause performance issues; too large may waste memory.
- Run **`make bonus`** instead of `make` if you need the linked list functions — they are not included by a plain `make`.
- All code follows the **42 Norm** — one function per file, limited line length, no `for` loops, etc.
- No external library dependencies — only standard POSIX headers.

---

> 💬 **Contributions, issues, and suggestions are welcome!**
> Feel free to open a pull request or leave a comment — every improvement helps make this library better for everyone.

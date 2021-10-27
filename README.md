# Get Next Line

# What is GNL?

*GNL is a project aimed to improve my understanding of static variables.*

## Description

The GNL function uses the `read(2)` function to read a line from a file descriptor (`fd`). Calling this function in a loop will read the text available on the `fd` one line at a time until the end of it.

*Note: when compiling this project with `gcc` is necessary to add the flag `-D BUFFER_SIZE=xx` (the `x` being any number) to specify how many bytes will `read(2)` read each time. However, in my [libft](https://github.com/Javiff8/Libft) I added a `define` in the header [libft.h](https://github.com/Javiff8/Libft/blob/master/inc/libft.h) that allows this function to run with a `BUFFER_SIZE=42` if no `BUFFER_SIZE` is specified.* 

## Return Values

The line read or `NULL` if there was an error or there was no other line to be read.

# Content

The 3 main files for this project are: [get_next_line.c](https://github.com/Javiff8/Get_Next_Line/blob/master/get_next_line.c), [get_next_line.utils.c](https://github.com/Javiff8/Get_Next_Line/blob/master/get_next_line_utils.c), and the header [get_next_line.h](https://github.com/Javiff8/Get_Next_Line/blob/master/get_next_line.h). Here is the content of each file:

### [get_next_line.c](https://github.com/Javiff8/Get_Next_Line/blob/master/get_next_line.c)

This file contains 4 functions:

- `char *get_next_line(int fd)`: The GNL function itself.  It uses a `char *` to store the buffer read with the `read(2)` function. This buffer has a size of `BUFFER_SIZE + 1` to add a `'\0'` at the end of it, making it easier to use in the other functions. It also has a `static char *` to store the data read by using [ft_strdup](https://github.com/Javiff8/Libft/blob/master/src/ft_strdup.c) or a slightly modified [ft_strjoin](https://github.com/Javiff8/Libft/blob/master/src/ft_strjoin.c). When a new line (`'\n'`) is found within the `static char *` variable or `read(2)` returns 0, it stops the loop and returns the output of the next function.
- `static char *ft_fill_result(char **temp)`: This functions receives the `static char *` variable as a parameter and uses it to create the return of GNL, leaving in the static variable the rest of the text from the `'\n'` to the end of it. The next time GNL function is called, it will use the text stored within the static variable to create the next line, reading again from the `fd` only if it is necessary.
- `static char *ft_substr_gnl(char const *s, int start, int len)`: A slightly modified [ft_substr](https://github.com/Javiff8/Libft/blob/master/src/ft_substr.c) to return `NULL` if `start > len`, so that it can set the `static char *` variable to `NULL` when reading the last line of the file.
- `static char *ft_strjoin_gnl(char *temp, char *buf)`:* The modified [ft_strjoin](https://github.com/Javiff8/Libft/blob/master/src/ft_strjoin.c). It allows to free the `temp` variable after using it to create the new `static char *`, which is returned.

### [get_next_line.utils.c](https://github.com/Javiff8/Get_Next_Line/blob/master/get_next_line_utils.c)

This file only contains the [ft_strchr](https://github.com/Javiff8/Libft/blob/master/src/ft_strchr.c), [ft_strdup](https://github.com/Javiff8/Libft/blob/master/src/ft_strdup.c) and [ft_strlen](https://github.com/Javiff8/Libft/blob/master/src/ft_strlen.c) functions of my [libft](https://github.com/Javiff8/Libft). This was because we were not allowed to use our whole [libft](https://github.com/Javiff8/Libft) for this project, so we need to select which specific functions we needed to use.

### [get_next_line.h](https://github.com/Javiff8/Get_Next_Line/blob/master/get_next_line.h)

The header file that contains the prototype of the functions of the [get_next_line.utils.c](https://github.com/Javiff8/Get_Next_Line/blob/master/get_next_line_utils.c) and the GNL function itself.

## Bonus

The bonus part of this project was to:

- Only use **one static variable**, which I also did for the mandatory part.
- To be able to **manage multiple file descriptors** with the GNL function. For example, if the file descriptors 3, 4 and 5 are accessible for reading, calling `get_next_line` once on 3, once on 4, once again on 3, then once on 5, etc. without losing the reading thread on each of the descriptors.

This was simply done by adding a define to the [get_next_line_bonus.h](https://github.com/Javiff8/Get_Next_Line/blob/master/get_next_line_bonus.h) header with the maximum number a `fd` can have on MacOS systems (after a quick search I found that the number was 12288). This number was used to create a `static char **`, so that the `static char *` of each `fd` could be stored in a unique position within the matrix. Check the `get_next_line` function in the [get_next_line_bonus.c](https://github.com/Javiff8/Get_Next_Line/blob/master/get_next_line_bonus.c) file to see it clearer. The rest of the file and the [get_next_line_utils_bonus.c](https://github.com/Javiff8/Get_Next_Line/blob/master/get_next_line_utils_bonus.c) file are the same as those explained before.

# How to use

Simply call this function and send the `fd` of the desired file to read as a parameter. You can obtain the `fd` by using the `open(2)` function or by using others predefined by the system, i.e. if `fd = 0`, `get_next_line` will read from the standard input.

# Status, grade and observations

- Status: Finished.
- Grade: [![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/javferna/get_next_line)](https://github.com/JaeSeoKim/badge42)
- Observations: None.

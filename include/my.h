/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Prototypes of all functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>

#ifndef __MY_H__
#define __MY_H__

// my_atoi.c
char *my_itoa(int number);

// my_concat_params.c
char *my_concat_params(int argc, char **argv);

// my_error.c
int send_error(char *c);

// my_evil_str.c
char *my_evil_str(char *str);

// my_get_color.c
int my_get_color(unsigned char red, unsigned char green, unsigned char blue);

// my_getnbr.c
int my_getnbr(char const *str);
int is_valid_int(long nb);

// my_getnextline.c
#ifndef READ_SIZE
    #define READ_SIZE (1024)
#endif
char *get_next_line(int fd);
char *read_line(char *line, int tmp, char *buffer, int *start);

// my_is_prime.c
int my_is_prime(int nb);

// my_memset.c
char *my_memset(char *str, char c, int size);

// my_printf.c
void my_printf(const char *str, ...);
int check_nextchar(char c);
void my_printf_address(int nbr);
void display_params(va_list va, char str);

// my_putchar.c
void my_putchar(char c);

// my_putnbr_base.c
int my_putnbr_base(int nbr, char const *base);

// my_putnbr.c
int my_putnbr(int nb);

// my_putstr.c
int my_putstr(char const * str);

// my_revstr.c
char *my_revstr(char *str);

// my_show_word_array.c
int my_show_word_array(char * const *tab);

// my_sort_int_array.c
void my_sort_int_array(int *tab, int size);
void my_sort_int_array_check(int *tab, int size);

// my_sort_word_array.c
void my_sort_word_array(char **tab);
void set_value_array(char *x, char **tab, int i, int j);
int sizeof_2d(char **str);

// my_str_isnum.c
int my_str_isnum(char const *str);

// my_str_to_word_array.c
char **my_str_to_word_array(char const *str);
char** arr_alloc(size_t x, size_t y);
int count_word(char const *str);

// my_strcapitalize.c
char *my_strcapitalize(char *str);

// my_strcat.c
char *my_strcat(char *dest, char const *src);

// my_strcmp.c
int my_strcmp(const char *s1, const char *s2);

// my_strcpy.c
char *my_strcpy(char *dest, char const *src);

// my_strdup.c
char *my_strdup(char const *src);

// my_strlen.c
int my_strlen(char const *str);

// my_strlowcase.c
char *my_strlowcase(char *str);

// my_strncat.c
char *my_strncat(char *dest, char const *src, int nb);

// my_strncmp.c
int my_strncmp(char const *s1, char const *s2, int n);

// my_strncpy.c
char *my_strncpy(char *dest, char const *src, int n);

// my_strstr.c
char *my_strstr(char *str, char const *to_find);
int compare(const char *str, const char *to_find);

// my_strupcase.c
char *my_strupcase(char *str);

// my_swap_endian_color.c
int my_swap_endian_color(int color);

// my_swap_int.c
void my_swap_int(int a, int b);

// my_swap.c
void my_swap(int *a, int *b);

#endif /*__MY_H__*/

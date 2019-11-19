/*
** EPITECH PROJECT, 2019
** CPool_bistro-matic_2019
** File description:
** bistro
*/

#ifndef BISTRO_H_
#define BISTRO_H_

#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"


#include "my.h"

typedef struct bistro_s {
    char *base;
    size_t base_len;
    char *operator;
    char *calc;
} bistro_t;

char *eval_expr(bistro_t *data);
char *add_inf(bistro_t *stc, char *s1, char *s2);
char *sub_inf(bistro_t *stc, char *s1, char *s2);
char *mul_inf(bistro_t *stc, char *s1, char *s2);
char *div_inf(bistro_t *stc, char *s1, char *s2);
char *mod_inf(bistro_t *stc, char *s1, char *s2);

char *expression(bistro_t *data, char **expr);
char *format_calc(bistro_t *data);
char *rev_format_calc(bistro_t *data, char *str);
void check_parenthesis(char *str);

char *choice_add(bistro_t *data, char **s, char f1, char f2);
char *choice_sub(bistro_t *data, char **s, char f1, char f2);
char *choice_mul(bistro_t *data, char **s, char f1, char f2);
char *choice_mod(bistro_t *data, char **s, char f1, char f2);
char *choice_div(bistro_t *data, char **s, char f1, char f2);
void quitp(char *, int);

#endif /* !BISTRO_H_ */

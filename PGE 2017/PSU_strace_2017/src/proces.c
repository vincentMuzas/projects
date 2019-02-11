/*
** EPITECH PROJECT, 2018
** strace
** File description:
** proces functions
*/

#include "strace.h"

int child_func(char **ac, char **env, int flags)
{
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    kill(getpid(), SIGSTOP);
    return (execve(ac[1 + (flags / 10)], ac + (1 + (flags / 10)), env));
}

void print_hex(char *names, size_t max, pid_t pid)
{
    size_t i = 1;

    printf("%.*s(", (int)strlen(names) - 2, names);
    while (i <= max) {
        if (i > 1)
            printf(", ");
        printf("%p", (void *)takeinfo(i, pid));
        i++;
    }
    printf(") = ");
}

void print_st(char *names, size_t max, pid_t pid)
{
    size_t i = 1;

    printf("%.*s(", (int)strlen(names) - 2, names);
    while (i <= max) {
        if (i > 1)
            printf(", ");
        if (ptrace(PTRACE_PEEKDATA, pid, takeinfo(i, pid), 0) == -1)
            printf("%ld", (long int)takeinfo(i, pid));
        else
            printf("%s", (char *)ptrace(PTRACE_PEEKDATA,pid,takeinfo(i,pid),0));
        i++;
    }
    printf(") = ");
}

void next_step(pid_t pid, int *st)
{
    ptrace(PTRACE_SINGLESTEP, pid, 0, 0);
    wait4(pid, st, 0, NULL);
}

void tracer(char **name, pid_t pid, int *st, int flags)
{
    long int ret;

    wait4(pid, st, 0, NULL);
    ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD);
    ptrace(PTRACE_ATTACH, pid, 0, 0);
    while (1) {
        next_step(pid, st);
        if (WIFEXITED(*st))
            break;
        if ((ret = ptrace(PTRACE_PEEKUSER, pid,
                sizeof(long) * ORIG_RAX, 0)) != -1) {
            if (flags >= 10)
                print_st(name[ret], name[ret][strlen(name[ret]) - 1] - 48, pid);
            else
                print_hex(name[ret], name[ret][strlen(name[ret]) - 1]- 48, pid);
            next_step(pid, st);
            printf("%#x\n", (unsigned int)takeinfo(0, pid));
        }
    }
}
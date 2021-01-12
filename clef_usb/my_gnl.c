static void init_str(char *str, int max)
{
    for (int i = 0; i < max; i++)
        str[i] = '\0';
}

static char *append_char(char *str, char c)
{
    char *res;
    int i;

    res = malloc(sizeof(char) * (my_strlen(str) + 2));
    init_str(res, my_strlen(str) + 2);
    for (i = 0; str[i] != '\0'; i++)
        res[i] = str[i];
    res[i] = c;
    free(str);
    return (res);
}

char *my_gnl(int fd)
{
    static char st = '\0';
    char *str = malloc(sizeof(char)), c[2] = {0};
    int k;
    str[0] = '\0';
    str = append_char(str, st);
    st = '\0';
    if (str[0] == '\n')
        return (str);
    while (1) {
        k = read(fd, c, 2);
        if (c[0] == '\0' || c[0] == '\n' || c[1] == '\0' || c[1] == '\n'||k < 2)
            break;
        str = append_char(append_char(str, c[0]), c[1]);
    }
    st = (k == 2 && (c[0] == '\0' || c[0] == '\n') && c[1] != '\0') ? c[1] : '\0';
    if (str[0] == '\0' && k < 2) {
        free(str);
        return (NULL);
    }
    return (str);
}

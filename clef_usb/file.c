long long int my_convert_base(char *str, int base)
{
  long long int res;
  int i;
  int pw;

  pw = 0;
  i = my_len(str) - 1;
  res = 0;
  while (i != -1)
    {
      res += (str[i] - 48) * pow(base, pw);
      i -= 1;
      pw += 1;
    }
  return (res);
}

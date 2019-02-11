#include <unistd.h>
void yolo()
{
  write(1, "bonjour!\n", 10);
}

int main()
{
  yolo();
  return (0);
}

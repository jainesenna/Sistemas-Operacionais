#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  printf("Vou chamar o programa cat para ler o conteúdo de /etc/issue.\n");
  system("/bin/cat /etc/issue");
  printf("Esta mensagem será impressa.\n");
  exit(0);      
}

/*
  Para compilar este programa salvo como "system.c"
  $ gcc system.c -o system
  $ ./system
*/
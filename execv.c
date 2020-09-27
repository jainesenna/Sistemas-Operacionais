#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char *cmd[] = { "cat", "/etc/passwd", (char *)0};
  printf("Vou chamar o programa cat para ler o conteudo de /etc/passwd.\n");
  execv("/bin/cat",cmd);
  printf("Esta mensagem não será impressa.\n");
  exit(0);
}

/*
  Para compilar este programa salvo como "execv.c"
  $ gcc execv.c -o execv
  $ ./execv
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int pid;
  printf("Meu número de processo é %d. Vou criar um processo filho.\n",getpid());
  pid = fork(); /* Chamada da primitiva fork */
  if(pid == 0) /* Aqui começam as instruções do processo filho */
  {
    printf("\t\tProcesso filho criado com o PID número %d.\n", getpid());
    printf("\t\tVou ficar executando indefinidamente.\n");
    for(;;); /* Este processo ficará em loop */
  }
  else /* Aqui começam as instruções do processo pai */
  {
    sleep(5);
    printf("O processo pai termina e deixa o filho orfão.\n");
    printf("Veja se o processo filho continua rodando com o comando\n");
    printf("ps\n");
  }
  exit(0);
}

/*
  Para compilar este programa salvo como "fork_loop.c"
  $ gcc fork_loop.c -o fork_loop
  $ ./fork_loop
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
  int id;
  id = fork(); 
  if (id != 0)
  {
    printf("Eu sou o pai e espero pelo meu filho %d\n",id); // id é o PID do filho
    wait(0); // Bloqueia o pai, espera o filho finalizar
    printf("Meu filho acabou de terminar... Vou terminar também!\n");
  }
    else
  {
    printf("Eu sou o filho %d e espero 10 segundos.\n", getpid());
    sleep(10); // Pausa
    printf("Já esperei e vou embora...\n");
  };
};

/*
  Para compilar este programa salvo como "fork_simples.c"
  $ gcc fork_simples.c -o fork_simples
  $ ./fork_simples
*/
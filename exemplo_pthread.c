#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* funcao_thread (void* arg)
{
  printf("Nova thread criaa com PID %d.\n", getpid());
  sleep(20);
  return NULL;
}

int main ()
{
  pthread_t thread;
  printf("Processo pesado PID %d.\n", getpid());
  pthread_create(&thread, NULL, &funcao_thread, NULL);
  printf("Identificador do thread %ld\n", thread);
  sleep(20);
  exit(0);
}

/*
  Para compilar este programa salvo como "exemplo_pthread.c"
  $ gcc -pthread exemplo_pthread.c -o exemplo_pthread
  $ ./exemplo_pthread
*/
//Jaine Senna

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * ProcessoLevel1()
{
  int i;
  for(i=1; i<100000; i++)
  {
    printf("\tThread 1 - %d\n", i);
  }
}
void * ProcessoLevel2()
{
  int i;
  for(i=100000; i<200000; i++)
  {
    printf("\t\tThread 2 - %d\n", i);
  }
}
//pthread_detach(thread1);
//pthread_detach(thread2);

int main(void)
{
  pthread_t thread1,thread2;
  pthread_create (&thread1, NULL, ProcessoLevel1, NULL);
  pthread_create (&thread2, NULL, ProcessoLevel2, NULL);
  pthread_join (thread1, NULL);
  pthread_join (thread2, NULL);
  printf("FIM\n");
}
/*
  Para compilar este programa salvo como "concorrentes.c"
  $ gcc -pthread concorrentes.c -o concorrentes
  $ ./pthread_join
*/
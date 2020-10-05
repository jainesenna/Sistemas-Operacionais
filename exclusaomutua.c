//Jaine Senna

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid1,tid2;
long conta=0;
void * t1()
{
  long i;
  for (i=0; i<1000000; i++)
  {
    conta = conta + 5;
  }
  printf("Encerrei t1\n");
}

void * t2()
{
  long i;
  for (i=0; i<1000000; i++)
  {
    conta = conta + 2;
  }
  printf("Encerrei t2\n");
}

int main ()
{
  pthread_create(&tid1, NULL, t1, NULL);
  pthread_create(&tid2, NULL, t2, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("O valor da variável conta é: %ld\n", conta);
}

/*
  Para compilar este programa salvo como "exclusaomutua.c"
  $ gcc -pthread exclusaomutua.c -o exclusaomutua
  $ ./exclusaomutua
*/


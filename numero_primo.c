//Jaine Senna

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void* procurandonumeroprimo (void * arg)
{
  int numeroprimo = 2;
  int totalnumeros = *((int*) arg);
  printf("Vou calcular os números primos até chegar no %do.\n\n", totalnumeros);
  printf("São primos: ");
  sleep(1);
  while(1)
  {
    int fatordivisao;
    int flagnumeroprimo = 1;
    for (fatordivisao = 2; fatordivisao < numeroprimo; ++fatordivisao)
    if (numeroprimo % fatordivisao == 0) //se não for primo
    {
      flagnumeroprimo = 0;
      break;
    }
    if (flagnumeroprimo) // è primo, pois só divide por 1 e por ele mesmo.
    {
      printf(" %d ", numeroprimo);
      if (--totalnumeros == 0)
      return (void*) (intptr_t)  numeroprimo;
    }
    ++numeroprimo;
  }
  return NULL;
}

int main ()
{
  pthread_t thread;
  int total = 10;
  int primo;
  pthread_create (&thread, NULL,  &procurandonumeroprimo, &total);
  pthread_join (thread, (void*) &primo);
  printf("\n\nO %do número primo é %d.\n", total, primo);
  return 0;
}

/*
  Para compilar este programa salvo como "numeroprimo.c"
  $ gcc -pthread numeroprimo.c -o numeroprimo
  $ ./pthread_join
*/
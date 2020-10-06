//Jaine Senna

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid0,tid1;
int turn;
int shared;
int flag [2];

void * p0()
{
  int i;
  for(i=0; i<10000; i++)
  {
    flag[0] = 1;
    turn = 0;
    while(flag [1] == 1 && turn==0){}
    shared = shared + 5;
    flag [0] = 0;
  }
}

void * p1()
{
  int i;
  for(i=0; i<10000; i++)
  {
    flag[1] = 1;
    turn = 1;
    while(flag [0] == 1 && turn==1){}
    shared = shared + 2;
  flag [1] = 0;
  }
}

int main ()
{
  flag [0] = 0;
  flag [1] = 0;
  pthread_create(&tid0, NULL, p0, NULL);
  pthread_create(&tid1, NULL, p1, NULL);
  pthread_join(tid0, NULL);
  pthread_join(tid1, NULL);
  printf("O valor da variável shared é: %d\n", shared);
}


/*
  Para compilar este programa salvo como "exclusaomutua2.c"
  $ gcc -pthread exclusaomutua2.c -o exclusaomutua2
  $ ./exclusaomutua2
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  printf("Eu sou o processo %d. Meu pai é o %d. O ID do grupo de processo é o %d. \n" ,getpid(), getppid(), getpgrp());
  sleep(120);
  exit(0);
};


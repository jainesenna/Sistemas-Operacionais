#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int value = 5;
int main(){
  pid_t pid;
  pid = fork(); //Clona
   if (pid == 0) // Processo filho
   {
     value += 15;
     return 0;
   }
   else if (pid > 0){ // Processo pai
     wait(NULL); 
     printf("PARENT: value = %d\n", value); // LINHA A
     return 0;
   }
}
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/wait.h>
#define MAX 10
  
int main()
{
  
  int fd[2], i = 0;
  pipe(fd);
  pid_t pid = fork();
  
   if(pid > 0) {
      wait(NULL);

     // closing the standard output
      close(0);
      close(fd[1]); 
  

      dup(fd[0]); 
      int arr[MAX];
 
      int n = read(fd[0], arr, sizeof(arr));
      for ( i = 0;i < n/4; i++)
  
         // printing the array received from child process
          printf("%d ", arr[i]); 
  } 
  else if( pid == 0 ) {
      int arr[] = {1, 2, 3, 4, 5};
  
      
      close(fd[0]); 
      close(1);    
  
      // duplicating fd[0] with standard output 1
      dup(fd[1]);  
      write(1, arr, sizeof(arr));
  } 
  
  else {
      perror("error\n"); //fork()
  }
} 

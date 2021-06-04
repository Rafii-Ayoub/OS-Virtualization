#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/* Global variables */
int x = 0;
int y = 0;
sem_t sem1;
sem_t sem2;
/* Thread function */


static void* func(void* i){
     int nb = (int *) i;
 
  printf("i=%d\n",nb);
  sem_wait(&sem1);
  x++;
  printf("X = %d\n", x);
  sem_post(&sem1);

}


void main ()
{

    pthread_t thread1[10];
    /* semaphore sync should be initialized by 0 */
    if (sem_init(&sem1, 0, 1) == -1) {
        perror("Could not initialize mylock semaphore");
        exit(2);
    }
    for(int i=0;i<10;i++){
 
        if (pthread_create(&thread1[i], NULL, func,(void *) i) < 0) {
            perror("Error: thread cannot be created");
            exit(1);
        }
    }
    
    /* wait for created thread to terminate */
    for(int i=0;i<10;i++){
        pthread_join(thread1[i], NULL);
    }
    sem_destroy(&sem1);

    exit(0);

}

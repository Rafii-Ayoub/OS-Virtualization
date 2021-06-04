#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <pthread.h>

#include <semaphore.h>

/* Global variables */

sem_t syn1;

sem_t syn2;

/* Thread function */

void a1(){

 printf("a1 is being executed\n");

}

void a2(){

 printf("a2 is being executed\n");


 

}

void b1( ){

 printf("b1 is being executed\n");

}


 

void b2( ){

 printf("b2 is being executed \n");

}


 

void *p1(void *arg)

{ 

 

a1();

sem_post(&syn1);

sem_wait(&syn2);

a2();

 

 


 

}



 

void *p2(void *arg)

{ 

b1();

sem_wait(&syn1);

sem_post(&syn2);

b2();

}




 

void main () {

pthread_t thread1, thread2;

/* semaphore sync should be initialized by 0 */

if (sem_init(&syn1, 0, 0) == -1) {

  perror("Could not initialize mylock semaphore");

  exit(2);

}

 

if (sem_init(&syn2, 0, 0) == -1) {

  perror("Could not initialize mylock semaphore");

  exit(2);

}

if (pthread_create(&thread1, NULL, p1, NULL) < 0) {

  perror("Error: thread cannot be created");

  exit(1);

}

if (pthread_create(&thread2, NULL, p2, NULL) < 0) {

  perror("Error: thread cannot be created");

  exit(1);

}


 

/* wait for created thread to terminate */

pthread_join(thread1, NULL);

pthread_join(thread2, NULL);

/* destroy semaphore sync */

sem_destroy(&syn1);

sem_destroy(&syn2);

exit(0);


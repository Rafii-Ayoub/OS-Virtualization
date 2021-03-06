#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int n;

// function that prints the id of the process and his parent ( it's a chain process)

int func1(const char *character) {
    printf("I am a %s.  My pid is:%d  my ppid is %d\n", character, getpid(), getppid() );
    return 1;
}

// function that creats the chain of processes
int func2(int n) 
{
    if (n == 0)
    { 
        return 0;
    }
    int pid = fork(); 
    if (pid == -1) {
        exit(0);
    }
    if (pid==0) { 
        func1("child");
        n = n-1;
        func2(n);
        exit(0);
    }
    else {
       sleep(3);
    } 
    return 0;   
}

// I made a for loop to visualize how my program  creates a process chain of n processes from n=0 to n= 10

int main()
{
    for(int i=0;10; i++){
    func2(i); 
    
    }
    return 0;
}

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// this program help us to observe a Zombie

int main ()
{
pid_t child_pid;child_pid = fork ();
if (child_pid > 0) {
sleep (60);
}
else {
exit (0);
}
return 0;
}

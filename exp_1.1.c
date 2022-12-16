#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
   pid_t p_id, c_pid, c_ppid;
   p_id = getpid();
   printf("Process id : %d\n", p_id);
   p_id = fork();
   p_id = fork();
   p_id = fork();
   p_id = fork();
   p_id = fork();

   if (p_id < 0)
   {
      perror("x fork() failure\n");
      return 1;
   }

   else if (p_id == 0)
   {
      c_pid = getpid();
      c_ppid = getppid();
      printf("Hey I'm child process, Child PID: %d \t PPID: %d\n", c_pid, c_ppid);
   }
   else
   {
      wait();
      c_pid = getpid();
      c_ppid = getppid();
      printf("Parent process, PID: %d \t PPID: %d\n", c_pid, c_ppid);
      sleep(10);
   }

   _exit(0);
   printf("Terminating process %d \n", p_id);
   return 0;
}

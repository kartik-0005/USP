

// Write a C/C++ program that creates a zombie and then calls system to execute the ps 
// command to Verify that the process is zombie


#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main(){ 
 pid_t pid; 
 if((pid=fork())<0) 
  perror("fork error"); 
 else if (pid==0) 
  _exit(0);  //child 
 sleep(4); // parent 
 system("ps -o pid,ppid,state,tty,command"); 
 _exit(0); 
}
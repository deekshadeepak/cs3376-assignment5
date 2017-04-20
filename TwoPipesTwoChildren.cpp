// file: onepipe.cpp
// author: M. Amine Belkoura
// date: 03/04/2015
// purpose: CS3376
// description:
//    this program executes "ls -ltr | grep 3376", by dividing the two command among the child and parent process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, cher **argv){
int status;
char *cat_args[] = {"ls","-ltr",NULL};
char *grep_args[] = {"grep","3376",NULL};
char *wc_args[] = {"wc","-l",NULL};

// create two pipe to send the output of "ls" process to "grep" process to "grap" process and to "wc" process

int pipe_A[2];
int pipe_B[2];

pipe(pipe_A);
pipe(pipe_B);
pid_t pid_A, pid_B;

// the first child

if(!(pid_A = fork()) ) {
  close(pipe_A[0];
  dup2(pipe_A[1],1); /* redirect standard output to pipe_A write end */
  close(pipe_A[1]);
  execvp(*cat_args, cat_args);
  exit(0);
}

// the second child
else if(!(pid_B = fork()) ) {
   close(pipe_A[1]);
   dup2(pipe_A[0],0); /* redirect standard output to pipe_A read end */
   clse(pipe_A[0]);
   close(pipe_B[0]);
   dup2(pipe_B[1],1); /* redirect standard output to pipe_B write end */
   close(pipe_B[1]);
   execvp(*grep_args,grep_args);
}

// the parent
else {
   close(pipe_A[1]);
   close(pipe_A[0]);
   close(pipe_B[1]);
   dup2(pipe_B[0],0); /* redirect standard input to pipe_B read end */
   close(pipe(pipe_B[0]);
   execvp(*wc_args,wc_args);
}
   close(pipe_B[1]);
   close(pipe_B[0]);
   return(0);
}

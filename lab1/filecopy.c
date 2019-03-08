//name: zhang boen
//lab 01
//cs444 spring 2018
//2018/3/5
//program that copy a file to another file
//problem: I try to do create output file and make that file able to read from and write to.
//---------but when it get created, I'm not able to access it, but it seems end fin when output file already get created.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
  int pipefd[2];
  pid_t pid;
  char buffer1[100];//use in parent process
  char buffer2[100];//use in child process

  if(argc !=3){
    printf("please input: filiecopy 'copy file' 'copyTo file'\n");
    exit(0);//check input
  }
  char* inputFile=argv[1];
  char* outputFile=argv[2];
  pipe(pipefd);
  pid=fork();


  if(pid<0){
    printf("error during fork()\n");
    exit(0);//check fork error
  }

  else if(pid>0){//parent process
	close(pipefd[0]);//nothing to read from the pipe
	int inputDesc = open(inputFile, O_RDONLY);//open a read only input file
	ssize_t inputByte=read(inputDesc,buffer1,sizeof(buffer1));//read byte from input file
	write(pipefd[1],buffer1,inputByte);//write into the pipe
	close(pipefd[1]);
  }

  else{//chile process
	close(pipefd[1]);//don't need to write in pipe anymore
	ssize_t childByte=read(pipefd[0],buffer2,sizeof(buffer2));//read byte from pipe
	int outputDesc=open(outputFile, O_CREAT | O_RDWR);//setup the output file
	write(outputDesc,buffer2,childByte);//write data into output file
	close(pipefd[0]);//finish using read from pipe
   }

   return 0;
}


 



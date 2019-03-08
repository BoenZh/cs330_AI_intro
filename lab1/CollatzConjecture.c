//name: zhang boen
//lab 01
//cs444 spring 2018
//2018/3/5
//program that print collatz conjecture

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int k=0;
	pid_t pid;
	printf("please input an integer greater than 0\n");
	scanf("%d", &k);
	if(k<=0){
		printf("input is not an >0 int\n");
		exit(0);}//check if input int >0 or not

	pid=fork();
	if(pid<0){
		printf("error on fork process\n");
		exit(0);//error check on fork
		}
	else if(pid==0){
		printf("child process\n gererating int list\n");
		printf("%d\n",k);
		while(k!=1){
			if(k%2==0)
				k=k/2;
			else
				k=k*3+1;
			printf("%d\n",k);
		}
		printf("child finish\n");
		}
	else{
		printf("parent process invoke wait()\n");
		wait();
		printf("parent process finish\n");
		}
	


return 0;
}
	

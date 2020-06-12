#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#define ID "18520051"
int loop=1;

void on_signint()
{

printf("You are pressed CTRL C,Closed gedit");
//printf("You are pressed CTRL C,Goodbye")
loop = 0;
}


int main(){

printf("Welcome to IT007, I am %s\n", ID);
sleep(1);
system("gedit abcd.txt");
loop = 1;
signal(SIGINT,on_signint) ;
while (loop){}


return 0;
}

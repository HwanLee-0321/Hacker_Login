#include <stdio.h>

//gcc -fno-stack-protector -o chall chall.c
void win(){

execve("/bin/sh",0,0);

}
void init(){
      setvbuf(stdin, (char *)NULL, _IONBF, 0);
      setvbuf(stdout, (char *)NULL, _IONBF, 0);
      setvbuf(stderr, (char *)NULL, _IONBF, 0);
}

int main(){

	
	char arr[0x40];
	int num=1024;
	init();
	printf("Here is Address win() = %p\n",win);
	printf("Input : ");
	read(0,arr,0x400);
	if(num!=1024)
	{
		printf("Oops!\n");
		exit(-1);
		
	}
	return 0;

}

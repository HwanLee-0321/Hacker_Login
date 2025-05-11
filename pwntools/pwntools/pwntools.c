#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//gcc -o pwntools pwntools.c
void init(){
      setvbuf(stdin, (char *)NULL, _IONBF, 0);
      setvbuf(stdout, (char *)NULL, _IONBF, 0);
      setvbuf(stderr, (char *)NULL, _IONBF, 0);
}

void get_flag(){
	char flag[30]={'\0',};
	int fd = open("./flag.txt",0,0);
	read(fd, flag,30);
	
	printf("flag = %s\n",flag);	
}

int main(){
        init();
        srand(time(NULL));
        int ran1, ran2;
        int input;
        int i;

        for(i = 0;i<10000;i++){
                ran1 = rand()%10000;
                ran2 = rand()%10000;
                printf("%d + %d = ",ran1,ran2);
                scanf("%d",&input);

                if(input != (ran1+ran2)){
                                printf("wrong!\n");
                                return 0;
                }
        }
        get_flag();
}



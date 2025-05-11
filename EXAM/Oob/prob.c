#include <stdio.h>
#include <stdlib.h>
//gcc -no-pie -fno-stack-protector -Wl,-z,relro -o prob prob.c
long buf[400];

void win(){

	execve("/bin/sh",0,0);
}
int main() {
    long n;
    int i=0;

    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    while (1) {
        printf("val: ");
        scanf("%lu", &n);
        buf[i] =n;
        i = buf[i];
    }

    return 0;
}


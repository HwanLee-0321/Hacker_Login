#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buf[112];
    const char *filename = "./flag.txt";
    FILE *file;
    int c;

    puts("flag is ./flag.txt");
    printf("Input Buffer : ");
    if (scanf("%111s", buf) != 1)
        return 1;

    file = fopen(filename, "r");
    if (file) {
        while ((c = fgetc(file)) != EOF)
            putchar(c);
        fclose(file);
    } else {
        printf("%s\n", buf);
    }

    return 0;
}

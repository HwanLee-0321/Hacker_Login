#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void create_password(char *password, int len) {
    int fd = open("/dev/urandom", O_RDONLY);

    for (int i = 0; i < len; ) {
        char c;

        read(fd, &c, 1);
        if (0x20 < c && c < 0x7e)
            password[i++] = c;
    }
    close(fd);
}

int main() { // <-- 여기가 중단점이 되는거임 아직 아무것도 안 뜨는게 정상
    char buf[16] = { 0 }, password[16] = { 0 };
    int len = sizeof(password) - 1;

    // ignore this
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    // create password with random bytes
    create_password(password, len);

    printf("Enter password : ");
    read(0, buf, sizeof(buf) - 1);

    if (!strcmp(buf, password))
        printf("Correct!\n");
    else
        printf("Wrong!\n");

    return 0;
}
#include <stdio.h>

int main() {
    // 어셈블리 메모리 그대로 정의 (0x400000 ~ 0x40001A까지 실제는 26바이트)
    unsigned char data[26] = {
        0x67, 0x55, 0x5c, 0x53, 0x5f, 0x5d, 0x55, 0x10,
        0x44, 0x5f, 0x10, 0x51, 0x43, 0x43, 0x55, 0x5d,
        0x52, 0x5c, 0x49, 0x10, 0x47, 0x5f, 0x42, 0x5c,
        0x54, 0x11  // 마지막 0x11이 '!'로 바뀜
    };

    // XOR 0x30 연산 수행
    for (int i = 0; i < 26; i++) {
        data[i] ^= 0x30;
    }

    // 문자열로 출력 (마지막에 널 문자 추가)
    char output[27];
    for (int i = 0; i < 26; i++) {
        output[i] = (char)data[i];
    }
    output[26] = '\0';

    printf("%s\n", output);  // 결과 출력

    return 0;
}

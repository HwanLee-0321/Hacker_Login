#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *roundText[4] = {
        aRound1Choices,
        aRound2Choices,
        aRound3Choices,
        aRound4Choices
    };

    const char *selectText[4] = {
        aSelectChoice1,
        aSelectChoice2,
        aSelectChoice3,
        aSelectChoice4
    };

    const char *invalidText[4] = {
        aInvalidInput,
        aInvalidInput_0,
        aInvalidInput_1,
        aInvalidInput_2
    };

    const char *choices[4][10] = {
        { a3842, a9274, a5123, a1049, a2765, a8301, a4927, a6590, a7358, a1846 },
        { a5830, a2104, a7639, a4982, a6571, a8023, a1394, a2458, a9701, a3265 },
        { a1749, a3820, a9465, a5810, a2037, a4952, a8601, a7213, a5096, a1348 },
        { a9871, a2034, a5476, a7812, a3650, a4901, a6582, a1407, a8239, a2715 }
    };

    int correctAnswers[4] = { 3, 1, 9, 4 };
    int correct = 1, choice;

    for (int round = 0; round < 4; round++) {
        printf("%s", roundText[round]);
        for (int i = 0; i < 10; i++)
            printf("%2d. %s\n", i + 1, choices[round][i]);

        printf("%s", selectText[round]);
        if (scanf("%d", &choice) != 1) {
            printf("%s\n", invalidText[round]);
            return 1;
        }
        if (choice != correctAnswers[round])
            correct = 0;

        putchar('\n');
    }

    if (correct) {
        printf("%s", aCorrect);
        system(Command);
    } else {
        printf("%s", aIncorrect);
        system(aPause_0);
    }

    return 0;
}

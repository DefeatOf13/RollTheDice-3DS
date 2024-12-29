#include <3ds.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawDice(int roll) {
    consoleClear();

    printf("Roll the Dice Game\n");

    printf("You rolled a: %d\n", roll);

    switch (roll) {
        case 1:
            printf("   *   \n");
            break;
        case 2:
            printf(" *     \n");
            printf("     * \n");
            break;
        case 3:
            printf(" *     \n");
            printf("   *   \n");
            printf("     * \n");
            break;
        case 4:
            printf(" *   * \n");
            printf("       \n");
            printf(" *   * \n");
            break;
        case 5:
            printf(" *   * \n");
            printf("   *   \n");
            printf(" *   * \n");
            break;
        case 6:
            printf(" *   * \n");
            printf(" *   * \n");
            printf(" *   * \n");
            break;
    }
    
    printf("\nPress A to roll again, B to exit.\n");
}

int main() {
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);
    
    srand(time(NULL));

    printf("Welcome to the Roll the Dice Game!\n");
    printf(" \n");

    char choice;
    do {
        int roll = (rand() % 6) + 1;

        drawDice(roll);

        while (1) {
            hidScanInput();
            u32 kDown = hidKeysDown();
            if (kDown & KEY_A) {
                choice = 'y';
                break;
            } else if (kDown & KEY_B) {
                choice = 'n';
                break;
            }
        }

        consoleClear();
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for playing!\n");

	printf(" \n");

	printf("App made by DefeatOf13\n");

	printf("(defeatof13.github.io)\n");

    printf("\x1b[30;16HPress START to exit.");

    while (aptMainLoop()) {
        hidScanInput();
        u32 kDown = hidKeysDown();
        if (kDown & KEY_START) break;

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}

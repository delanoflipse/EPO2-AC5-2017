#include <stdio.h>
#include "challenge12.h"
#include "challenge3.h"
#include "debug.h"
#include "serial.h"

char state = 0b00001000;

int main() {
    if (!serialInit()) {
        printf("------------------------------------------------------------------\n");
        printf("- !!!! ERROR: NO SERIAL CONNECTION\n");
    }

    writeByte(&state); // Reset robot by sending unused state identifier

    char opt;
    while (1) {
        // Send initial options
        printf("\n------------------------------------------------------------------\n");
        printf("- AC5 SMART ROBOT CHALLENGE\n");
        printf("------------------------------------------------------------------\n\n");
        printf("Choose what to do:\n");
        printf("1: Challenge 1. Go to a number of checkpoints\n");
        printf("2: Challenge 2. Go to checkpoints with mines in the way\n");
        printf("3: Challenge 3. Treasure hunt\n");
        printf("4: Serial debug\n");
        printf("other: Exit\n");
        printf("Your choice: ");
        scanf("%c", &opt);

        if (opt == '1' || opt == '2') {
            // Run assignment one
            challenge1();
        } else if (opt == '3') {
            // Run assignment one
            challenge3(0);
        } else if (opt == '4') {
            // Run assignment one
            debug();
        } else {
            break;
        }

    }

    // End, say goodbye
    closeSerial();

    return 0;
}
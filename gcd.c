#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, remainder, large, small, control;
    char cont;

    while (1) {
        printf("Enter the two numbers to find the GCD:\n");

        if (scanf("%d %d", &num1, &num2) != 2) {
            printf("Invalid input. Please enter integers.\n");
            // Clear input buffer
            while (getchar() != '\n'); 
            continue; 
        }
        
        control = 0;

        if (num1 <= 0 || num2 <= 0) {
            printf("GCD is not defined for these numbers.\n");
            
            printf("Do you want to continue? (Yes --> y, No --> n)\n");
            scanf(" %c", &cont);
            
            if (cont == 'n' || cont == 'N') {
                printf("Program terminated. Goodbye!\n");
                break;
            } else if (cont == 'y' || cont == 'Y') {
                continue;
            } else {
                printf("Invalid choice. Continuing the program.\n");
                continue;
            }
        }

        if (num1 >= num2) {
            large = num1;
            small = num2;
        } else if (num2 >= num1) {
            large = num2;
            small = num1;
        }

        do {
            remainder = large % small;
            large = small;
            small = remainder;
        } while (small != 0);
        
        if (control != 1) {
            printf("The GCD of %d and %d is = %d\n", num1, num2, large);
            printf("Do you want to continue? (Yes --> y, No --> n)\n");
        }

        scanf(" %c", &cont);
        
        switch (cont) {
            case 'n':
            case 'N':
                printf("Program terminated. Goodbye!\n");
                return 0; 
            case 'y':
            case 'Y':
                break; 
            default:
                printf("Invalid choice. Continuing the program.\n");
                break;
        }
    }

    return 0;
}

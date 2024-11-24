
/******************
Name: Dan Sonnenblick
ID: 345287882
Assignment: ex2
*******************/
#include <stdio.h>

int main(void) {
    int selection;
    do {
        printf("Choose an option:\n");
        printf("    1. Happy Face\n");
        printf("    2. Balanced Number\n");
        printf("    3. Generous Number\n");
        printf("    4. Circle Of Joy\n");
        printf("    5. Happy Numbers\n");
        printf("    6. Festival Of Laughter\n");
        printf("    7. Exit\n");
        scanf("%d", &selection);
        switch (selection) {
            case 1:
                // Case 1: Draw Happy Face with given symbols for eyes, nose and mouse*/
                char eyes, nose, mouth;
            int faceSize;
            printf ("Enter symbols for the eyes, nose, and mouth: \n");
            scanf (" %c %c %c", &eyes, &nose, &mouth);
            printf ("Enter face size: \n");
            scanf (" %d", &faceSize);
            while (faceSize%2 == 0 || faceSize <= 0) {
                printf ("The face's size must be an odd and positive number, please try again: \n");
                scanf("%d", &faceSize);
            }
            // Draw the happy face using the input symbols
            for (int i = 0; i <= faceSize+1; i++) {
                if (i == 0 || i == faceSize+1) {
                    printf ("%c", eyes);
                } else {
                    // Prints spaces between the eyes
                    printf (" ");
                }
            }
            printf ("\n");
            for (int i = 0; i <= faceSize+1; i++) {
                if (i == (faceSize/2 + 1)) {
                    // Prints the nose in the middle of the face
                    printf ("%c", nose);
                }
                else {
                    printf (" ");
                }
            }
            printf ("\n");
            for (int i = 0; i <= faceSize+1; i++) {
                if (i == 0) {
                    // Left side of the mouth
                    printf ("\\");
                }
                if (i == faceSize+1) {
                    // Right side of the mouth
                    printf ("/\n");
                }
                else {
                    printf ("%c", mouth);
                }
            }
            break;
            case 2:
                // Case 2: determine whether the sum of all digits to the left of the middle digit(s)
                // and the sum of all digits to the right of the middle digit(s) are equal
                int num;
            int sum1 = 0;
            int sum2 = 0;
            int mid = 0;
            printf("Enter a number: \n");
            scanf("%d", &num);
            while (num < 0) {
                printf("Only positive number is allowed, please try again: \n");
                scanf("%d", &num);
            }
            // Calculates the number of digits
            int digitCount = 0;
            int temp = num;
            while (temp > 0) {
                digitCount++;
                temp = temp / 10;
            }
                if (digitCount <10){
                    printf ("This number is balanced and brings harmony!\n");
                }
            mid = digitCount / 2;
            if (digitCount % 2 == 1) {
                // If the number of digits is odd, adjust the middle index
                mid++;
            }
            int temp2 = num;
            // Sums digits to the left of the middle
            for (int i = 0; i < mid-1; i++) {
                sum1 += temp2 % 10;
                temp2 = temp2 / 10;
            }
            if (digitCount % 2 == 1) {
                // Skips the middle digit if the count is odd
                temp2 = temp2 / 10;
            }

            // Sums digits to the right of the middle
            while (temp2 > 0) {
                sum2 += temp2 % 10;
                temp2 = temp2 / 10;
            }
            if (sum1 == sum2) {
                printf ("This number is balanced and brings harmony! \n");
            } else {
                printf("This number isn't balanced and destroys harmony! \n");
            }
            break;
            case 3:
                // Case 3: determine whether the sum of the proper divisors (of an integer) is greater than the number itself
                int generous;
            int sum5 = 0;
            printf("Enter a number: \n");
            scanf("%d", &generous);
            while (generous <= 0) {
                printf ("Only positive number is allowed, please try again: \n");
                scanf("%d", &generous);
            }
            // Sum the proper divisors of the number
            for (int i = 1; i < generous; i++) {
                if (generous % i == 0) {
                    sum5 += i;
                }
            }
            // Check if the sum of divisors is greater than the number itself
            if (sum5> generous)
                printf ("This number is generous!\n");
            else
                printf ("This number does not share.\n");
            break;
            case 4:
                // Case 4: determine wether a number is a prime.
                int circleJoy;
            int primeNum = 1;
            printf("Enter a number: \n");
            scanf("%d", &circleJoy);
            while (circleJoy <= 0) {
                printf("Only positive number is allowed, please try again: \n");
                scanf("%d", &circleJoy);
            }if (circleJoy == 1)
            {
                printf("The circle remains incomplete.\n");
                return 0;
            }
            // Checks if the number is prime
            for (int i = 2; i <=circleJoy/2; i++)
            {
                if (circleJoy % i == 0) {
                    primeNum = 0;
                    break;
                }
            }

            // Checks if the flipped number is also prime
            if (primeNum) {
                int flipped=0;
                int temp =0;
                int primeNum2 = 1;
                while (circleJoy > 0) {
                    temp = circleJoy%10;
                    flipped = flipped*10 + temp;
                    circleJoy /= 10;
                }
                for (int i = 2; i <=flipped/2; i++)
                {
                    if (flipped % i == 0) {
                        primeNum2 = 0;
                        break;
                    }
                }
                if (primeNum2) {
                    printf("This number completes the circle of joy! \n");
                } else {
                    printf ("The circle remains incomplete. \n");
                }
            } else {
                printf ("The circle remains incomplete. \n");
            }
            break;
            case 5:
                // case 5: Happy numbers: Print all the happy numbers between 1 to the given number.
                    // Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
                int input;
            printf("Enter a number: \n");
            scanf("%d", &input);
            while (input < 0) {
                printf("Only positive number is allowed, please try again: \n");
                scanf("%d", &input);
            }
            printf("Between 1 and %d only these numbers bring happiness: ", input);
            // Iterate over all numbers from 1 to input
            for (int i = 1; i <= input; i++) {
                int updatedInput = i;
                int checker = 0;
                // Check if the number is happy (sum of squares of digits eventually leads to 1)
                while (updatedInput != 1 && updatedInput!= 4) {
                    checker = 0;
                    while (updatedInput>0) {
                        int lastNum = updatedInput%10;
                        checker += lastNum * lastNum;
                        updatedInput /= 10;
                    }
                    updatedInput = checker;
                }
                if (updatedInput ==1){
                    printf(" %d", i);
                }
            }


            printf("\n");
            break;
            case 6:
                // Festival of Laughter: Prints all the numbers between 1 the given number:
                // and replace with "Smile!" every number that divided by the given smile number
                // and replace with "Cheer!" every number that divided by the given cheer number
                // and replace with "Festival!" every number that divided by both of them
                int cheer, smile;
            int maxNum;
            printf("Enter a smile and cheer number: \n");
            while (1) {
                int check = scanf("smile: %d, cheer: %d", &smile, &cheer);
                if (check == 2) {
                    break;
                }
                printf ("Only 2 different positive numbers in the given format are allowed for the festival, please try again: \n");
                // Clear the invalid input
                scanf("%*[^\n]");
                // Clear the newline
                scanf("%*c");
            }
            printf("Enter maximum number for the festival: \n");
            scanf("%d", &maxNum);
            while (maxNum <= 0) {
                printf("Only positive maximum number is allowed, please try again: \n");
                scanf("%*[^\n]");
                scanf("%*c");
                scanf("%d", &maxNum);
            }
            // Prints based on divisibility rules
            for (int i = 1; i <= maxNum; i++) {
                if (i % smile == 0 && i % cheer != 0) {
                    printf ("Smile!\n");
                }else if (i % smile != 0 && i % cheer == 0) {
                    printf ("Cheer!\n");
                }else if (i % smile == 0 && i % cheer == 0) {
                    printf ("Festival!\n");
                }else {printf("%d \n", i); }
            }
            break;
            case 7:
                printf("Thank you for your journey through Numeria!");
                break;
            default:
                printf("This option is not available, please try again.");
        }
    }while (selection != 7); // Loop until user chooses to exit
    return 0;
}




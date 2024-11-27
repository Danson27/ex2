
/******************
Name: Dan Sonnenblick
ID: 345287882
Assignment: ex2
*******************/
#include <stdio.h>
// for case 1:
#define MIN_FACE_SIZE 1
#define ODD_DIVISOR 2
#define FACE_BORDER 1
#define UNEVEN_REMAINDER 1
#define EVEN_REMAINDER 0
#define EVEN_CHECK 2
#define POSITIVE 0

// for case 2
#define SINGLE_DIGIT 10
#define TAKE_AWAY_LAST_DIGIT 10
#define MID_INDEX 2
#define UNEVEN_REMAINDER 1
#define EVEN_REMAINDER 0
#define EVEN_CHECK 2
#define POSITIVE 0

 // for case 3

#define EVEN_CHECK 2
#define POSITIVE 0
#define IS_DIVISOR 0

// for case 4
#define POSITIVE 0
#define IS_DIVISOR 0
#define ONE_DEFUALT_CASE_INCOMPLETE 1
#define NOT_PRIME 0
#define TAKE_AWAY_LAST_DIGIT 10
#define MAKE_LAST_DIGIT_ZERO 10

 // for case 5:
#define HAPPY_NUMBER 1
#define TAKE_AWAT_LAST_DIGIT 10
#define POSITIVE 0
#define UNHAPPY_CYCLE_START 4

// for case 6
#define POSITIVE 0
#define DIVISIBLE 0



int main(void) {
   int selection;
   do {
       printf("Choose an option: \n");
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
           while (faceSize%EVEN_CHECK == EVEN_REMAINDER || faceSize <= POSITIVE) {
               printf ("The face's size must be an odd and positive number, please try again: \n");
               scanf("%d", &faceSize);
           }
           // Draw the happy face using the input symbols
           for (int i = 0; i <= faceSize + FACE_BORDER; i++) {

               if (i == 0 || i == faceSize+1) {
                   printf ("%c", eyes);
               } else {
                   // Prints spaces between the eyes
                   printf (" ");
               }
           }
           printf ("\n");
           for (int i = 0; i <= faceSize; i++) {
               // Calculate nose position once
               int nosePosition = faceSize / 2 +1;
               if (i == (nosePosition)) {
                   // Prints the nose in the middle of the face
                   printf ("%c", nose);
               }
               else {
                   printf (" ");
               }
           }
           printf ("\n");
           for (int i = 0; i <= faceSize; i++) {
               if (i == 0) {
                   // Left side of the mouth
                   printf ("\\");
               }
               if (i == faceSize) {
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
   int digitCount = 0;
   int mid = 0;


   printf("Enter a number: \n");
   scanf("%d", &num);


   // Ensure the number is positive
   while (num <= POSITIVE) {
       printf("Only positive number is allowed, please try again: \n");
       scanf("%d", &num);
   }


   // Single-digit numbers are automatically harmonious
   if (num < SINGLE_DIGIT) {
       printf("This number is balanced and brings harmony!\n");
       break;
   }
   // Count the digits in the input
   int temp = num;
   while (temp > POSITIVE) {
       digitCount++;
       temp = temp/TAKE_AWAY_LAST_DIGIT;


   }

   // Determine the middle point
   mid = digitCount / MID_INDEX;
   // Calculate sums for both halves of an uneven number
   if (digitCount % EVEN_CHECK == UNEVEN_REMAINDER) {
       // Include the middle digit in the first half
       mid++;
       temp = num;
       for (int i = 0; i < digitCount; i++) {
           // Get the rightmost digit
           int half = temp % TAKE_AWAY_LAST_DIGIT;
           // Remove the rightmost digit
           temp /= TAKE_AWAY_LAST_DIGIT;
           if ((i >= mid )){
               // Add to the first half sum
               sum1 += half;
           } if (i<(mid-1)) {
               // Add to the second half sum
               sum2 += half;
           }
       }
   }
   // calculate if there are an even amount of digits
   else if (digitCount % EVEN_CHECK == EVEN_REMAINDER) {
       temp = num;
       for (int i = 0; i < digitCount; i++) {
           // Get the rightmost digit
           int half = temp % TAKE_AWAY_LAST_DIGIT;
           // Remove the rightmost digit
           temp /= TAKE_AWAY_LAST_DIGIT;
           if ((i >= mid )){
               // Add to the first half sum
               sum1 += half;
           } if (i<mid) {
               // Add to the second half sum
               sum2 += half;
           }
       }


   }
   // Compare sums

   if (sum1 == sum2) {
       printf("This number is balanced and brings harmony!\n");
   } else {
       printf("This number isn't balanced and destroys harmony!\n");
   }
           break;



           case 3:
               // Case 3: determine whether the sum of the proper divisors (of an integer) is greater than the number itself
            int generous;
           int sumCase3 = 0;
           printf("Enter a number: \n");
           scanf("%d", &generous);
           while (generous <= POSITIVE) {
               printf ("Only positive number is allowed, please try again: \n");
               scanf("%d", &generous);
           }
           // Sum the proper divisors of the number
           for (int i = 1; i < generous; i++) {
               if (generous % i == IS_DIVISOR) {
                   sumCase3 += i;
               }
           }
           // Check if the sum of divisors is greater than the number itself
           if (sumCase3 > generous)
               printf ("This number is generous!\n");
           else
               printf ("This number does not share.\n");
           break;



           case 4:
               // Case 4: determine wether a number is a prime.
            int circleJoy;
           int primeNum = 1;
         int checkPossibleDivisors = circleJoy/2;
           printf("Enter a number: \n");
           scanf("%d", &circleJoy);
           while (circleJoy <= POSITIVE) {
               printf("Only positive number is allowed, please try again: \n");
               scanf("%d", &circleJoy);
           }if (circleJoy == ONE_DEFUALT_CASE_INCOMPLETE)
           {
               printf("The circle remains incomplete.\n");
               break;
           }
           // Checks if the number is prime
           for (int i = 2; i <= checkPossibleDivisors; i++)
           {
               if (circleJoy % i == IS_DIVISOR) {
                   primeNum = NOT_PRIME;
                   break;
               }
           }


           // Checks if the flipped number is also prime
           if (primeNum) {
               int flipped=0;
               int temp =0;
               int primeNum2 = 1;
              // flip the original by removing the last digit of the original number and adding it to the new number, each time multiplying the new number by ten
              while (circleJoy > POSITIVE) {
                   temp = circleJoy % TAKE_AWAY_LAST_DIGIT;
                   flipped = flipped*MAKE_LAST_DIGIT_ZERO + temp;
                   circleJoy /= TAKE_AWAY_LAST_DIGIT;
               }
              // here we check if the flipped number is prime
              int checkFlipDivisors = flipped/2;
               for (int i = 2; i <=checkFlipDivisors; i++)
               {
                   if (flipped % i == POSITIVE) {
                       primeNum2 = NOT_PRIME;
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

         // for case 5:
              #define HAPPY_NUMBER 1
              #define TAKE_AWAT_LAST_DIGIT 10
              #define POSITIVE 0
              #define UNHAPPY_CYCLE_START 4

           case 5:
               // case 5: Happy numbers: Print all the happy numbers between 1 to the given number.
                   // Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
          int input;
           printf("Enter a number: \n");
           scanf("%d", &input);
              // ensure input is positive
           while (input <= POSITIVE) {
               printf("Only positive number is allowed, please try again: \n");
               scanf("%d", &input);
           }
           printf("Between 1 and %d only these numbers bring happiness: ", input);
           // Iterate over all numbers from 1 to the given input
           for (int i = 1; i <= input; i++) {
               int updatedInput = i;
               int checker = 0;
               // Check if the number is happy (sum of squares of digits eventually leads to 1)
               while (updatedInput != HAPPY_NUMBER && updatedInput!= UNHAPPY_CYCLE_START) {
                   checker = 0;
                  // calculates the sum of the squares of the digits
                   while (updatedInput > POSITIVE) {
                      // extract last digits
                       int lastNum = updatedInput % TAKE_AWAT_LAST_DIGIT;
                       checker += lastNum * lastNum;
                       updatedInput /= TAKE_AWAY_LAST_DIGIT;
                   }
                   updatedInput = checker;
               }
               if (updatedInput == HAPPY_NUMBER){
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
               int check = scanf(" smile: %d, cheer: %d", &smile, &cheer);
               if (check == 2 && smile > 0 && cheer > 0 && smile!=cheer) {
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
           while (maxNum <= POSITIVE) {
               printf("Only positive maximum number is allowed, please try again: \n");
               scanf("%*[^\n]");
               scanf("%*c");
               scanf("%d", &maxNum);
           }
           // Prints based on divisibility rules
           for (int i = 1; i <= maxNum; i++) {
               // Prints "smile!" if the number is divisible by the given smile number
              if (i % smile == DIVISIBLE && i % cheer != DIVISIBLE) {
                   printf ("Smile!\n");
               // Prints "cheer!" if the number is divisible by the given cheer number
               }else if (i % smile != DIVISIBLE && i % cheer == DIVISIBLE) {
                   printf ("Cheer!\n");
                 // Prints "Festival!" if divisible by both the given cheer and smile numbers
               }else if (i % smile == DIVISIBLE && i % cheer == DIVISIBLE) {
                   printf ("Festival!\n");
               }else {printf("%d \n", i); }
           }
           break;
           case 7:
               printf("Thank you for your journey through Numeria!\n");
               break;
           default:
               printf("This option is not available, please try again.\n");
       }
   }while (selection != 7); // Loop until user chooses to exit
   return 0;
}

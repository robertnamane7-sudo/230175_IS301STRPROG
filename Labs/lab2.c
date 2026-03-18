/**
 * Author: Robert Namane
 * Student ID: 230175
 * Date: 17th March 2026
 * Unit: IS301 Structured Programming
 *
 * Description: Number Guessing Game
 * The computer generates a random number between 1-20.
 * User has 5 attempts to guess it.
 *
 * ALGORITHM FOR NUMBER GUESSING GAME
 * ===================================
 * 1. START
 * 2. Generate a random number between 1 and 20 (secretNumber)
 * 3. Set maxAttempts = 5
 * 4. FOR attempt = 1 TO maxAttempts
 *        CALL getUserGuess() to get player's guess
 *        
 *        IF guess == secretNumber THEN
 *            CALL printSuccessMessage()
 *            EXIT loop (game ends)
 *        ELSE IF guess < secretNumber THEN
 *            PRINT "Your guess is low. Try again:"
 *        ELSE
 *            PRINT "Your guess is high. Try again:"
 *        END IF
 *        
 *        IF attempt == maxAttempts THEN
 *            CALL printSorryMessage(secretNumber)
 *        END IF
 *    END FOR
 * 5. END
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int getUserGuess(int attempt);
void printSuccessMessage();
void printSorryMessage(int secretNumber);
void printHintMessage(int guess, int secretNumber);

int main() {
    // Variable declaration
    int secretNumber;      // The number computer thinks of
    int guess;             // User's current guess
    int maxAttempts = 5;   // Maximum number of tries
    int i;                 // Loop counter
    
    // Seed the random number generator
    // This ensures we get different numbers each time we run
    srand(time(0));
    
    // Generate random number between 1 and 20
    secretNumber = (rand() % 20) + 1;
    
    // Welcome message
    printf("===============================\n");
    printf("WELCOME TO THE NUMBER GUESSING GAME!\n");
    printf("===============================\n");
    printf("I am thinking of a number between 1 and 20.\n");
    printf("You have %d attempts to guess it.\n", maxAttempts);
    printf("Let's begin\n\n");
    
    // Main game loop - give user 5 attempts
    for (i = 1; i <= maxAttempts; i++) {
        
        // Get user's guess (using our function)
        guess = getUserGuess(i);
        
        // Check if guess is correct
        if (guess == secretNumber) {
            printSuccessMessage();
            break; // Exit loop immediately - game over, user won!
        }
        else {
            // If not correct, give a hint
            printHintMessage(guess, secretNumber);
            
            // If this was the last attempt, print sorry message
            if (i == maxAttempts) {
                printSorryMessage(secretNumber);
            }
        }
    }
    
    printf("\nThanks for playing!\n");
    printf("============================\n");
    
    return 0; // Program ended successfully
}

/**
 * Function: getUserGuess
 * Purpose:  Prompts user for a guess and returns it
 * Parameter: attempt - current attempt number
 * Returns:   The user's guess (integer)
 */
int getUserGuess(int attempt) {
    int guess;
    
    if (attempt == 1) {
        printf("Can you guess what it is? ");
    } else {
        printf("Try again: ");
    }
    
    scanf("%d", &guess);
    return guess;
}
/**
 * Function: printSuccessMessage
 * Purpose:  Prints a congratulatory message when user guesses correctly
 * Parameters: none
 * Returns:   nothing
 */
void printSuccessMessage() {
    printf("\n Congratulations! You did it! \n");
    printf("You guessed the number correctly!\n");
}

/**
 * Function: printSorryMessage
 * Purpose:  Prints a message when user fails to guess in 5 attempts
 * Parameter: secretNumber - the number they should have guessed
 * Returns:   nothing
 */
void printSorryMessage(int secretNumber) {
    printf("\nSorry. The number was %d.\n", secretNumber);
    printf("You should have gotten it by now.\n");
    printf("Better luck next time.\n");
}

/**
 * Function: printHintMessage
 * Purpose:  Tells user if their guess was too high or too low
 * Parameters: guess - user's guess
 *             secretNumber - the actual number
 * Returns:   nothing
 */
void printHintMessage(int guess, int secretNumber) {
    if (guess < secretNumber) {
        printf("Your guess is low. ");
    } else {
        printf("Your guess is high. ");
    }
}

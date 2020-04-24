#include <stdio.h>
#include <stdbool.h>

#define AT_SIGN '@'
#define EVEN_DIGIT 2
#define CHOICE_PIZZA 0
#define CHOICE_RISOTTO 1
#define CHOICE_PASTA 2

void LoopLogic(char current, char previous, int numOdd, int numEven, int sum, bool monotone);

void CheckConditions(int numOdd, int numEven, int sum, bool monotone);

bool CheckDrinkConditions(int sum);

void PrintChoice(bool drink, int food);

void PrintBeerChoices(int food);

void PrintWineChoices(int food);

void AskBobForAliceMessage();

void PrintPizzaAndBeer();

void PrintPastaAndBeer();

void PrintRisottoAndBeer();

void PrintPizzaAndWine();

void PrintPastaAndWine();

void PrintRisottoAndWine();

int main() {
    char current, previous = 0;
    int numOdd = 0, numEven = 0, sum = 0;
    bool monotone = true;
    AskBobForAliceMessage();
    scanf(" %c", &current);
    LoopLogic(current, previous, numOdd, numEven, sum, monotone);
    return 0;
}

/**
 * Receives input from the user until an @ is detected
 * @param current The current input char
 * @param previous The previous input char
 * @param numOdd Number of odd characters
 * @param numEven Number og even characters
 * @param sum Sum of character values
 * @param monotone Whether the input was rising monotone
 */
void LoopLogic(char current, char previous, int numOdd, int numEven, int sum, bool monotone) {
    while (current != AT_SIGN) {
        sum += current;
        if (current % EVEN_DIGIT == 0) {
            numEven++;
        } else {
            numOdd++;
        }
        if (current < previous) {
            monotone = false;
        }
        previous = current;
        scanf(" %c", &current);
    }
    CheckConditions(numOdd, numEven, sum, monotone);
}

/**
 * Checks the conditions to determine food and drinks
 * @param numOdd Number of odd characters
 * @param numEven Number og even characters
 * @param sum Sum of character values
 * @param monotone Whether the input was rising monotone
 */
void CheckConditions(int numOdd, int numEven, int sum, bool monotone) {
    bool drink = CheckDrinkConditions(sum);
    int food = 0;
    if (numEven >= numOdd && monotone) {
        food = CHOICE_PIZZA;
    } else if (numEven >= numOdd) {
        food = CHOICE_PIZZA;
    } else if (monotone) {
        food = CHOICE_RISOTTO;
    } else {
        food = CHOICE_PASTA;
    }
    PrintChoice(drink, food);
}

/**
 * Receives the sum of characters received as input and determines the drink
 * @param sum the sum of characters
 * @return true for beer, false for wine
 */
bool CheckDrinkConditions(int sum) {
    if (sum % EVEN_DIGIT == 1) {
        return false;
    }
    return true;
}

/**
 * Receives the conditions results and prints the correct message
 * @param drink The drink choice
 * @param food The food choice
 */
void PrintChoice(bool drink, int food) {
    if (drink) {
        PrintBeerChoices(food);
    } else {
        PrintWineChoices(food);
    }
}

/**
 * Receives the food choice to go with beer
 * @param food Food choice to go with beer
 */
void PrintBeerChoices(int food) {
    if (food == CHOICE_PIZZA) {
        PrintPizzaAndBeer();
    } else if (food == CHOICE_PASTA) {
        PrintPastaAndBeer();
    } else {
        PrintRisottoAndBeer();
    }
}

/**
 * Receives the food choice to go with wine
 * @param food Food choice to go with wine
 */
void PrintWineChoices(int food) {
    if (food == CHOICE_PIZZA) {
        PrintPizzaAndWine();
    } else if (food == CHOICE_PASTA) {
        PrintPastaAndWine();
    } else {
        PrintRisottoAndWine();
    }
}

void AskBobForAliceMessage() {
    printf("Hey Bob, Please enter Alice's message:\n");
}

void PrintPizzaAndBeer() {
    printf("Alice wants to eat Pizza and drink Beer this evening.");
}

void PrintPastaAndBeer() {
    printf("Alice wants to eat Pasta and drink Beer this evening.");
}

void PrintRisottoAndBeer() {
    printf("Alice wants to eat Risotto and drink Beer this evening.");
}

void PrintPizzaAndWine() {
    printf("Alice wants to eat Pizza and drink Wine this evening.");
}

void PrintPastaAndWine() {
    printf("Alice wants to eat Pasta and drink Wine this evening.");
}

void PrintRisottoAndWine() {
    printf("Alice wants to eat Risotto and drink Wine this evening.");
}
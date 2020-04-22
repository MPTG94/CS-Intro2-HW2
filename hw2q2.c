#include <stdio.h>

#define ARR_SIZE 32
#define EXCLAMATION_MARK '!'
#define CHAR_S 'S'
#define CHAR_ZERO '0'
#define NUM_2 2

void GetBinaryDigit(int arr[], int length);

void ShiftTillRight(int arr[], int length, int count);

void ShiftArray(int arr[], int length);

void PrintArray(int arr[], int length);

void ContinueByChoice(int arr[], int length, char choice);

void ShiftArrayAndPrint(int arr[], int length);

void CalculateArrayValue(int arr[], int length);

unsigned int Power(int num, int exponent);

void PrintEnterMessage();

void PrintScannedBinaryNumberIs();

void PrintOperationChoiceMessage();

void PrintShiftedBinaryNumberIs();

void PrintUnsignedIntRepresentationIs();

int main() {
    PrintEnterMessage();
    int arr[ARR_SIZE] = {0};
    GetBinaryDigit(arr, ARR_SIZE);
    PrintScannedBinaryNumberIs();
    PrintArray(arr, ARR_SIZE);
    PrintOperationChoiceMessage();
    char choice;
    scanf(" %c", &choice);
    ContinueByChoice(arr, ARR_SIZE, choice);
    return 0;
}

/**
 * Takes as input the binary number from the user
 * @param arr The array to store the binary number
 * @param length The length of the array
 */
void GetBinaryDigit(int arr[], int length) {
    char input;
    int count = 0;
    scanf("%c", &input);
    while (input != EXCLAMATION_MARK) {
        arr[count] = input - CHAR_ZERO;
        count++;
        scanf("%c", &input);
    }
    ShiftTillRight(arr, length, ARR_SIZE - count);
}

/**
 * Shifts the binary representation until the number starts at the rightmost part of the array
 * @param arr The array containing the representation
 * @param length The length of the array
 * @param count The number of times to shift the representation
 */
void ShiftTillRight(int *arr, int length, int count) {
    for (int i = count; i > 0; --i) {
        ShiftArray(arr, length);
    }
}

/**
 * Checks the user choice and proceeds accordingly
 * @param arr The array containing the input binary
 * @param length The length of the array
 * @param choice The choice of the user
 */
void ContinueByChoice(int arr[], int length, char choice) {
    if (choice == CHAR_S) {
        ShiftArrayAndPrint(arr, length);
    } else {
        CalculateArrayValue(arr, length);
    }
}

/**
 * Shifts a binary number to the right once
 * @param arr The array storing the binary representation
 * @param length The length of the array
 */
void ShiftArray(int arr[], int length) {
    for (int i = length - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = 0;
}

/**
 * Shifts the array to the right once and prints the binary representation
 * @param arr The array to shift and print
 * @param length The length of the array
 */
void ShiftArrayAndPrint(int arr[], int length) {
    ShiftArray(arr, length);
    PrintShiftedBinaryNumberIs();
    PrintArray(arr, length);
}

/**
 * Calculates the decimal value of the number stored in the array
 * @param arr The array storing the binary representation
 * @param length The length of the array
 */
void CalculateArrayValue(int arr[], int length) {
    unsigned int sum = 0;
    for (int i = length - 1; i > -1; --i) {
        if (arr[i] == 1) {
            unsigned int powerResult = Power(NUM_2, length - 1 - i);
            sum += arr[i] * powerResult;
        }
    }
    PrintUnsignedIntRepresentationIs();
    printf("%u\n", sum);
}

/**
 * Calculates the number raised to the provided exponent
 * @param num The number of calculate power for
 * @param exponent The exponent to raise the number to
 * @return The value of the calculation
 */
unsigned int Power(int num, int exponent) {
    unsigned int result = 1;
    while (exponent != 0) {
        result *= num;
        exponent--;
    }
    return result;
}

/**
 * Prints a number array
 * @param arr The array to print
 * @param length The length of the array
 */
void PrintArray(int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d", arr[i]);
    }
}

void PrintEnterMessage() {
    printf("Please enter a binary digit:\n");
}

void PrintScannedBinaryNumberIs() {
    printf("Scanned binary number is:\n");
}

void PrintOperationChoiceMessage() {
    printf("\nEnter S for shift-right or D of unsigned int representation:\n");
}

void PrintShiftedBinaryNumberIs() {
    printf("Shifted binary number is:\n");
}

void PrintUnsignedIntRepresentationIs() {
    printf("Unsigned int representation is:\n");
}
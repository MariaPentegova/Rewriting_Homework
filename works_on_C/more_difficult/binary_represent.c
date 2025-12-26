#include <stdio.h>
#include <stdint.h>

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" "); // для удобства
    }
    printf("\n");
}

void printComplementCode(int num) {
    printBinary(num);
}

unsigned int addBinary(int a, int b, int *carry_out) {
    unsigned int result = 0;
    int carry = 0;
    for (int i=0; i<32; i++) {
        int bitA = (a >> i) & 1;
        int bitB = (b >> i) & 1;

        int sum = bitA ^ bitB ^ carry; // сложение без переноса
        carry = (bitA & bitB) | (bitA & carry) | (bitB & carry); // перенос

        result |= (sum << i);
    }
    *carry_out = carry;
    return result;
}

int main() {
    int num1, num2;
    printf("Введите первое число (целое): ");
    scanf("%d", &num1);
    printf("Введите второе число (целое): ");
    scanf("%d", &num2);

    printf("Первое число в двоичном виде: ");
    printComplementCode(num1);
    printf("%d/n", printBinary(num));
    printf("Второе число в двоичном виде: ");
    printComplementCode(num2);

    int carry = 0;
    unsigned int sum = addBinary(num1, num2, &carry);

    printf("Сумма в двоичном виде: ");
    printBinary(sum);
    printf("Перенос после сложения (если есть): %d\n", carry);

    printf("Сумма в десятичном виде: %d\n", (int)sum);

    return 0;
}

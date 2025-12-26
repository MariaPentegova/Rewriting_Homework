#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

char stack[MAX_LEN];
int top = -1;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void push(char c) {
    if (top < MAX_LEN - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) return stack[top--];
    return '\0'; // если стек пуст
}

char peek() {
    if (top >= 0) return stack[top];
    return '\0';
}

int is_operator(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/');
}

void infix_to_postfix(const char *infix, char *postfix) {
    int j = 0; // индекс для postfix
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isspace(c)) { // пропускаем пробелы
            continue;
        }

        if (isdigit(c)) {
            // Добавляем число в постфиксную строку
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // разделитель
            i--; 
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top >= 0 && peek() != '(') {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            pop();
        } else if (is_operator(c)) {
            // извлекаем из стека все операторы с более высоким или равным приоритетом
            while (top >= 0 && is_operator(peek()) && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(c);
        }
    }

    while (top >= 0) {
        if (peek() == '(') {
            pop();
        } else {
            postfix[j++] = pop();
            postfix[j++] = ' ';
        }
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_LEN];
    char postfix[MAX_LEN*2];

    printf("Введите выражение: ");
    fgets(infix, MAX_LEN, stdin);
  
    size_t len = strlen(infix);
    if (len > 0 && infix[len-1] == '\n') {
        infix[len-1] = '\0';
    }

    infix_to_postfix(infix, postfix);

    printf("Постфиксная форма: %s\n", postfix);
    return 0;
}

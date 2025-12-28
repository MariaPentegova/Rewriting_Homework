#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infix_to_postfix(const char *infix, char *postfix) {
    // стек для операторов
    char stack[MAX_LEN];
    int top = -1; // стек пуст

    int j = 0; // индекс для postfix

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isspace(c)) { 
            continue;
        }

        if (isdigit(c)) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; 
            i--; 
        } else if (c == '(') {
            if (top < MAX_LEN - 1) {
                stack[++top] = c;
            }
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        } else if (is_operator(c)) {
            while (top >= 0 && is_operator(stack[top]) && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = stack[top--];
                postfix[j++] = ' ';
            }
            if (top < MAX_LEN - 1) {
                stack[++top] = c;
            }
        }
    }

    while (top >= 0) {
        if (stack[top] == '(') {
            top--; 
        } else {
            postfix[j++] = stack[top--];
            postfix[j++] = ' ';
        }
    }

    postfix[j] = '\0'; 
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main() {
    char infix[MAX_LEN];
    char postfix[MAX_LEN * 2]; // резерв для разделителей и чисел

    printf("Enter: ");
    fgets(infix, MAX_LEN, stdin);
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    infix_to_postfix(infix, postfix);
    printf("Postfix form: %s\n", postfix);
    return 0;
}

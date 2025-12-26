#define MAX_STACK_SIZE 100

#include <stdio.h>

char stack[MAX_STACK_SIZE];
int top = -1;

int check_string(const char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        char c = string[i];

        if ((c == '(') || (c == '[') || (c == '{')) {
            if (top >= MAX_STACK_SIZE - 1) return 0;
            stack[++top] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (top < 0) return 0;
            char open = stack[top--];
            if ((open == '(' && c != ')') || (open == '[' && c != ']') || (open == '{' && c != '}'))
                return 0;
        }
    }
    return top == -1;
}

int main() {
    printf("%d\n", check_string("({)}"));    // должно быть 0
    printf("%d\n", check_string("({})"));    // должно быть 1
    return 0;
}

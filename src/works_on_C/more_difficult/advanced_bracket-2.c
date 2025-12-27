#include <stdio.h>

#define MAX_STACK_SIZE 100

int check_string(const char *string, char *stack, int *top) {
    *top = -1;
    for (int i = 0; string[i] != '\0'; i++) {
        char c = string[i];

        if (c == '(' || c == '[' || c == '{') {
            if (*top >= MAX_STACK_SIZE - 1) return 0; // переполнение стека
            stack[++(*top)] = c;
        } else if (c == ')' || c == ']' || c == '}') {
            if (*top < 0) return 0; // стек пуст, неправильная последовательность
            char open = stack[(*top)--];
            if ((open == '(' && c != ')') ||
                (open == '[' && c != ']') ||
                (open == '{' && c != '}'))
                return 0;
        }
    }
    return (*top == -1);
}

int main() {
    char stack[MAX_STACK_SIZE];
    int top;

    printf("%d\n", check_string("({)}", stack, &top)); // должно быть 0
    printf("%d\n", check_string("({})", stack, &top)); // должно быть 1
    return 0;
}

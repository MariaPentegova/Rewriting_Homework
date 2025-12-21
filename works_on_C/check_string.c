#include <stdio.h>

int check_string(char *string, char l_bracket) {
    char r_bracket;
    if (l_bracket == '(')
        r_bracket = ')';
    else if (l_bracket == '[')
        r_bracket = ']';
    else if (l_bracket == '{')
        r_bracket = '}';
    else
        return 0;

    int c = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == l_bracket)
            c++;
        else if (string[i] == r_bracket) {
            if (c == 0)
                return 0;
            c--;
        }
    }
    return c == 0;
}

int main() {
    printf("%d\n", check_string("при((ве)т)", '('));
    printf("%d\n", check_string("пр[ив[ет]]", '['));
    printf("%d\n", check_string("пр}ив{е}{т", '{'));
    return 0;
}

#include <stdio.h>
#include <string.h>

int count(char *S, char *S1){
    int c = 0;
    char *pos = S;
    while ((pos = strstr(pos, S1))!=NULL){
        ++c;
        ++pos;
    }
    return c;
}
int main(void){
    char S[32000], S1[32000];
    printf('enter string S:');
    fgets(S, sizeof(S), stdin);

    printf('enter string S1:');
    fgets(S, sizeof(S1), stdin);

    S[stcspn(S, '\n')]='\0';
    S1[stcspn(S1, '\n')]='\0';
    
    int res = count(S, S1);
    printf('%d', res);
    return 0;
}

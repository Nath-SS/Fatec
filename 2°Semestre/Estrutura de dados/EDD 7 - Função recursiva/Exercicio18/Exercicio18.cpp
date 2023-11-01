#include <stdio.h>
#include <ctype.h>
#include <string.h>

int palRec(char s[], int p, int u) {
    if (p >= u) { // condi��o de parada: quando n�o h� mais caracteres para comparar
        return 1; // a string � pal�ndroma
    } else {
        // ignorando brancos
        while (isspace(s[p])) {
            p++;
        }
        while (isspace(s[u])) {
            u--;
        }
        if (tolower(s[p]) != tolower(s[u])) { // se os caracteres s�o diferentes, a string n�o � pal�ndroma
            return 0;
        } else { // se os caracteres s�o iguais, chama a fun��o recursivamente para verificar o restante da string
            return palRec(s, p+1, u-1);
        }
    }
}

int pal(char s[]) {
    return palRec(s, 0, strlen(s)-1);
}

int main() {
    char s1[] = "A base do teto desaba";
    char s2[] = "A sacada da casa";
    char s3[] = "Roma me tem amor";
    char s4[] = "Ovo";
    char s5[] = "Ame a ema";
    
    printf("%s: %d\n", s1, pal(s1));
    printf("%s: %d\n", s2, pal(s2));
    printf("%s: %d\n", s3, pal(s3));
    printf("%s: %d\n", s4, pal(s4));
    printf("%s: %d\n", s5, pal(s5));
    
    return 0;
}


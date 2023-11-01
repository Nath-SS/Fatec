#include <stdio.h>
#include <string.h>

char *inv(char *s, int p, int u) {
    if(p >= u) return s;
    char temp = s[p];
    s[p] = s[u];
    s[u] = temp;
    inv(s, p+1, u-1);
    return s;
}

int main(void) {
    char str[100];
    int p, u;
    printf("Digite uma string: ");
    scanf("%s", str);
    printf("Digite as posicoes inicial e final para inverter: ");
    scanf("%d %d", &p, &u);
    inv(str, p, u);
    printf("String invertida: %s\n", str);
    return 0;
}


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char word[]) {
    char keywords[5][10] = {"int", "float", "if", "else", "while"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char str[100] = "int a = b + 5;";
    char word[20];
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (isalnum(str[i])) {
            word[j++] = str[i];
        } else {
            word[j] = '\0';
            j = 0;
            if (strlen(word) > 0) {
                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else
                    printf("Identifier: %s\n", word);
            }

            if (str[i] == '+' || str[i] == '-' || str[i] == '=')
                printf("Operator: %c\n", str[i]);
        }
        i++;
    }

    return 0;
}

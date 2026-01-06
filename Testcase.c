#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reviseString(const char *input, char *output)
{
    if (input == NULL || strlen(input) == 0) {
        strcpy(output, "Invalid Input");
        return;
    }

    char temp[200];
    strcpy(temp, input);

    char *token = strtok(temp, "_");
    int wordCount = 0;
    output[0] = '\0';

    while (token != NULL) {
        if (strlen(token) == 0) {
            token = strtok(NULL, "_");
            continue;
        }

        char word[50];
        int i;

        if (wordCount == 0) {
            for (i = 0; token[i]; i++)
                word[i] = toupper(token[i]);
            word[i] = '\0';
        } else {
            word[0] = toupper(token[0]);
            for (i = 1; token[i]; i++)
                word[i] = tolower(token[i]);
            word[i] = '\0';
        }

        strcat(output, word);
        strcat(output, " ");

        wordCount++;
        token = strtok(NULL, "_");
    }

    if (wordCount > 0) {
        output[strlen(output) - 1] = '.';
    }
}

int main()
{
    char input[200];
    char output[200];

    printf("Enter the string: ");
    scanf("%199s", input);    

    reviseString(input, output);

    printf("Revised String: %s\n", output);

    return 0;
}

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

//./synthesize "John" "1)JohnDriverhacJohnJohnJohnJohnJohnJohnJohnker; \n2) John Doe;\n3) John Foo;\n" "LAMBDA"
int main(int argc, char *argv[])
{
    // Read Arguments
    char *re = argv[1];
    char *str = argv[2];
    char *replacementStr = argv[3];

//    str = "1) John DriverhacJohnJohnJohnJohnJohnJohnJohnker; \n2) John Doe;\n3) John Foo;\n";
//    re = "John";
//    replacementStr = "LAMBDA";

    char *s = str;
    regex_t regex;
    regmatch_t pmatch[1];

    if (regcomp(&regex, re, 0))
    {
        exit(EXIT_FAILURE);
    }

    printf("String = \n\"%s\"\n", str);
//    char *buf = malloc(strlen(str) * 2 + strlen(replacementStr) * 2);
    char *buf = malloc(strlen(str) * 2);
    for (int i = 0;; i++)
    {
        if (regexec(&regex, s, ARRAY_SIZE(pmatch), pmatch, 0))
        { break; }
        buf = realloc(buf, strlen(str) *  2 + (i + 1) * strlen(replacementStr));
        char *buf2 = malloc(strlen(str) * 2);
        strncpy(buf2, s, pmatch[0].rm_so);
        strcat(buf, buf2);
        strcat(buf, replacementStr);
        s += pmatch[0].rm_eo; //Put the next character offset. (26 ---> 39) IT holds the pointer to all characters of the string not just the string
    }
    char *buf2 = malloc(strlen(str) * 2);
    strncpy(buf2, s, pmatch[0].rm_so);
    strcat(buf, buf2);
    printf("String after Replacement:\n");
    printf("%s", buf);
    exit(EXIT_SUCCESS);

    return 0;
}
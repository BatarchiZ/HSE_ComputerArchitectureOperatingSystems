#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

//int match(const char *string, char *pattern) {
//    int    status;
//    regex_t    re;
//
//    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
//        return 0;
//    }
//    status = regexec(&re, string, (size_t) 0, NULL, 0);
//    regfree(&re);
//    if (status != 0) {
//        return 0;
//    }
//    return 1;
//}

//int main(int argc, char *argv[]) {
//    char* regex = argv[1];
//    char* name = argv[2];
//    if (match(name, regex)) {
//        printf("'%s' matches '%s'\n", name, regex);
//    } else {
//        printf("'%s' mismatches '%s'\n", name, regex);
//    }
//    return 0;
//}

//int* findMatches(char* regEx, char* text, char* replacementStr)
//{
//    int* start = arr[10];
//}
//./prog "John" "1)JohnDriverhacJohnJohnJohnJohnJohnJohnJohnker; \n2) John Doe;\n3) John Foo;\n" "LAMBDA"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

int main(int argc, char *argv[])
{
    // Read Arguments
    char *re = argv[1];
    char *str = argv[2];
    char *replacementStr = argv[3];


    char *s = str;
    regex_t regex;
    regmatch_t pmatch[1];
    regoff_t off, len;

    if (regcomp(&regex, re, 0))
    {
        exit(EXIT_FAILURE);
    }

    printf("String = \"%s\"\n", str);
//    printf("Matches:\n");

    char *buf = malloc(strlen(str));
    for (int i = 0;; i++)
    {
        if (regexec(&regex, s, ARRAY_SIZE(pmatch), pmatch, 0))
        { // No match
            break;
        }
        strncpy(buf,s, pmatch[0].rm_so);
        printf("THIS IS BUF\n");
        printf(buf);
        printf("\n\n");
//        if (i == 0)
//        {
//
//        }

        off = pmatch[0].rm_so + (s - str);
        len = pmatch[0].rm_eo - pmatch[0].rm_so;
        s += pmatch[0].rm_eo;
    }
    exit(EXIT_SUCCESS);


    return 0;
}
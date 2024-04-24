#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

static const char *const str =
        "1) John Driverhacker; \n2) John Doe;\n3) John Foo;\n";
static const char *const re = "John.*o";

int main(void)
{
    static const char *s = str;
    regex_t regex;
    regmatch_t pmatch[1];
    regoff_t off, len;

    char *pattern = "LAMBDAAAAAAAAA";


    if (regcomp(&regex, re, REG_NEWLINE))
    {
        exit(EXIT_FAILURE);
    }

//    printf("String = \"%s\"\n", str);
//    printf("Matches:\n");

    char *buf = malloc(strlen(str) * 2);
    for (int i = 0;; i++)
    {
        if (regexec(&regex, s, ARRAY_SIZE(pmatch), pmatch, 0))
        {
            break;
        }
        char *buf2 = malloc(strlen(str) * 2);
        strncpy(buf2, s, pmatch[0].rm_so);
        strcat(buf, buf2);
        strcat(buf, pattern);
//        printf("THIS IS BUF\n");
//        printf(buf);
//        printf("\n\n");


//        char *buf2 = malloc(strlen(str));
//        if (i == 0)
//        {
//            regoff_t copyLen = (s - str) - pmatch[0].rm_eo;
//            strncpy(buf2, str, (intmax_t) copyLen);
//            printf(buf2);
//            printf("\n");
//        }

        off = pmatch[0].rm_so + (s - str);
        len = pmatch[0].rm_eo - pmatch[0].rm_so;
//        printf("#%d:\n", i);
//        printf("offset = %jd; length = %jd\n", (intmax_t) off, (intmax_t) len);
//        printf("substring = \"%.*s\"\n", len, s + pmatch[0].rm_so); //number of chars and the start

        s += pmatch[0].rm_eo; //Put the next character offset. (26 ---> 39) IT holds the pointer to all characters of the string not just the string
//        printf("s is :");
//        printf(s);
//        printf("\n");
    }
    char *buf2 = malloc(strlen(str));
    strncpy(buf2, s, pmatch[0].rm_so);
    strcat(buf, buf2);
    printf("String after Replacement:\n");
    printf(buf);
    exit(EXIT_SUCCESS);
}
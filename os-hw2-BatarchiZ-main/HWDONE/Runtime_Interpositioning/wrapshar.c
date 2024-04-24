#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void bill(char* arg)
{
    void (*pbill)(char *);
    char *error;

    pbill = dlsym(RTLD_NEXT, "bill"); /* Get addr of libc malloc */
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    pbill(arg); /* Call libc malloc */
    printf("Bill is called in wrapper\n");
}

/* free wrapper function */
void sam(double arg)
{
    void (*samp)(double) = NULL;
    char *error;

    samp = dlsym(RTLD_NEXT, "sam"); /* Get address of libc free */
    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(1);
    }
    samp(arg); /* Call libc free */
    printf("Sam Wrapper F'n\n");
}


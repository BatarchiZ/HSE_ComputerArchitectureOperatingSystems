//
// Created by Iskander Sergazin on 10/06/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void fill_arr(int* array, int length, int max)
{
    for (int i = 0; i < length; ++i)
    {
        array[i] = (rand() % max) + 1;
    }
}

int sum_arr(int* array, int length)
{
    int sum = 0;
    for (int i = 0; i < length; ++i)
    {
        sum += array[i];
    }
    return sum;
}

struct arguments_struct {
    int left, right;
//    int* arr;
};



static int SUM = 0;
//int s1, s2, s3, s4;
int * ARR = NULL;
static int SUMnoMUTEX = 0;

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void* calcFunc(struct arguments_struct* struc)
{
//    int left = *((int *) s1);
//    int right = *((int *) s2);
//    arguments_struct s = ((arguments_struct) struc)
    int left = struc->left;
    int right = struc->right;
//    int* a = (int *) arr;
    int s;
    for(int i = left; i < right; ++i)
    {
        s = pthread_mutex_lock(&mtx);
        if (s != 0) {
            perror("pthread_mutex_lock");
            return NULL;
        }
        SUM += ARR[i];
        s = pthread_mutex_unlock(&mtx);
        if (s != 0) {
            perror("pthread_mutex_unlock");
            return NULL;
        }
    }
    for(int i = left; i < right; ++i)
    {
        SUMnoMUTEX += ARR[i];
    }
}
int main(int argc, char *argv[]) {

    /// 1
    printf("hello world\n");
    int length = atoi(argv[1]);

    printf("the size of array is %d\n", length);

    ///2
    srand(time(NULL));
    int * ptr = (int*)malloc(length * sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    fill_arr(ptr, length, 100);
//    printf("\nthe REAL sum is %d\n", sum_arr(ptr, length));
//    for(int i = 0; i < length; ++i)
//    {
//        printf("%d ", ptr[i]);
//    }
//    printf("\n");

    ///3
    int split = length/4;
    printf("split is : %d\n", split);
    int s1, s2, s3, s4, s5;
    s1 = 0;
    s2 = s1 + split;
    s3 = s2 + split;
    s4 = s3 + split;
    s5 = length;
    struct arguments_struct struct1, struct2, struct3, struct4;
    struct1.left = s1;
    struct1.right = s2;
    ARR = ptr;
    struct2.left = s2;
    struct2.right = s3;
    struct3.left = s3;
    struct3.right = s4;
    struct4.left = s4;
    struct4.right = s5;

    ///4
    pthread_t t1,t2,t3,t4;
//    struct3.right = s4;
    int s;
    s = pthread_create(&t1, NULL, calcFunc, &struct1);
    if(s != 0)
    {
        perror("1 : pthread_create");
        return -1;
    }
//    s = pthread_join(t1, NULL);
    s = pthread_create(&t2, NULL, calcFunc, &struct2);
    if(s != 0)
    {
        perror("2 : pthread_create");
        return -1;
    }
//    s = pthread_join(t2, NULL);
    s = pthread_create(&t3, NULL, calcFunc, &struct3);
    if(s != 0)
    {
        perror("3 : pthread_create");
        return -1;
    }
//    s = pthread_join(t3, NULL);
    s = pthread_create(&t4, NULL, calcFunc, &struct4);
    if(s != 0)
    {
        perror("4 : pthread_create");
        return -1;
    }
    ///5
    s = pthread_join(t1, NULL);
    s = pthread_join(t2, NULL);
    s = pthread_join(t4, NULL);
    s = pthread_join(t3, NULL);

    printf("The following are the array contents: \n");
    for(int i = 0; i < length; ++i)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    printf("\nthe REAL sum is %d\n", sum_arr(ptr, length));
    printf("sum CALCULATED: %d \n", SUM);
    printf("sum w/o mutex: %d \n", SUMnoMUTEX);
    printf("\nprogram success\n");
    return 0;
}
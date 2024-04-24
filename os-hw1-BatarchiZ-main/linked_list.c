
#include <stdio.h>
#include <stdlib.h>
/// Works for non-square matrices. For square matrices would have been matrix[i][j] = matrix[j][i]
struct Node{
    struct Node* next;
    struct Node* prev;
    int index;
};

int main()
{
    int n;
    /// Must have at least one element == head
    scanf("%d", &n);
    struct Node* head;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->index = n;
    head->prev = NULL;
    struct Node* prev;
    prev = head;
    scanf("%d", &n);
    while(n != 0)
    {
        struct Node* element;
        element = (struct Node*)malloc(sizeof(struct Node));
        element->index = n;
        element->next = NULL;
        element->prev = prev;
        prev->next = element;
        prev = element;
        scanf("%d", &n);
    }

    /// Reverse
    // Head case
    struct Node* element = head;
    struct Node* next = element ->next;
    while(next != NULL)
    {
        element->next = element -> prev;
        element->prev = next;
        element = next;
        next = element -> next;
    }
    // Tail Case
    head = element;
    element->next = element -> prev;
    element->prev = next;


    // Print
    element = head;
    while(element->next)
    {
        printf("%d ", element->index);
        element = element->next;
    }
    printf("%d ", element->index);

    // Free memory
    while(head)
    {
        element = head;
        head = element->next;
        free(element);
        element = NULL;
    }
//    free(element);
//    element = NULL;
    return 0;
}

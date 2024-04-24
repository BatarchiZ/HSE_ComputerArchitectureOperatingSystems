
#include <stdio.h>
#include <stdlib.h>
struct Node{
    struct Node* next;
//    struct Node* prev;
    int index;
};

int main()
{
    int n;
    /// Must have at least one element == head
    /// ReadInput();
    scanf("%d", &n);
    struct Node* head;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->index = n;
    struct Node* prev;
    prev = head;
    scanf("%d", &n);
    while(n != 0)
    {
        struct Node* element;
        element = (struct Node*)malloc(sizeof(struct Node));
        element->index = n;
        element->next = NULL;
        prev->next = element;
        prev = element;
        scanf("%d", &n);
    }
    prev = NULL;


    /// Reverse();
    struct Node* element = head;
    prev = NULL;
    struct Node* next = element->next;
    while(element->next!=NULL)
    {
        element ->next = prev;
        prev = element;
        element = next;
        next = element->next;
        head = element;
    }
    head ->next = prev;
    element = NULL;
    prev = NULL;
    next = NULL;


    /// Print();
    element = head;
    while(element->next)
    {
        printf("%d ", element->index);
        element = element->next;
    }
    printf("%d ", element->index);

    /// Free memory
    while(head)
    {
        element = head;
        head = element->next;
        free(element);
        element = NULL;
    }
    return 0;
}

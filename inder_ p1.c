#include <stdio.h>
#include <stdlib.h>

struct node
{
    int datum;
    struct node *next;
};

struct node *create_node(int datum)
{
    struct node *new_address = (struct node *)malloc(sizeof(struct node));
    new_address->datum = datum;
    new_address->next = NULL;
    return new_address;
}

void disp(struct node *head)
{
    printf("\n");
    struct node *start = head;
    if (start != NULL)
    {

        while (start != NULL)
        {
            printf(" %d ", start->datum);

            start = start->next;
        }
    }
    else
    {

        printf("\nEmpty !!!!");
    }
}

void makeLL(struct node **head, int datum)
{
    struct node *newn = create_node(datum);
    newn->next = *head;
    *head = newn;
}

struct node *insert_node(struct node *sorted_list, struct node *nod)
{
    struct node *curr = sorted_list, *prev;
    if (sorted_list == NULL)
    {
        sorted_list = nod;
        return sorted_list;
    }

    if (nod->datum < curr->datum)
    {
        nod->next = curr;
        curr = nod;
        return curr;
    }

    while (curr != NULL && nod->datum > curr->datum)
    {
        prev = curr;
        curr = curr->next;
    }

    nod->next = prev->next;
    prev->next = nod;

    return sorted_list;
}

struct node *LLsort(struct node *start)
{
    disp(start);
    if (start == NULL)
    {
        printf("Empty !!!");
        return NULL;
    }
    struct node *sorted = NULL, *nod = NULL;
    while (start != NULL)
    {
        nod = start;
        start = start->next;
        nod->next = NULL;
        sorted = insert_node(sorted, nod);
    }
    disp(sorted);
    return sorted;
}

int main()
{
    int arr[] = {2, 9, 1, 5, 6, 3, 8, 4, 7};
    struct node *head = NULL;
   
    makeLL(&head, arr[0]);
    makeLL(&head, arr[1]);
    makeLL(&head, arr[2]);
    makeLL(&head, arr[3]);
    makeLL(&head, arr[4]);
    makeLL(&head, arr[5]);
    makeLL(&head, arr[6]);
    makeLL(&head, arr[7]);
    makeLL(&head, arr[8]);

    head = LLsort(head);

    return 0;
}
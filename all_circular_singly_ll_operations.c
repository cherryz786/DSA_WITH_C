// CIRCULAR SINGLY LINKED LIST
// CREATED BY PHOENIXX-3

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node // self refrential structure
{
    int data;
    struct node *next;
};
struct node *start = NULL; // start points at NULL as there is no ll created initially
struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
int main()
{
    int option;
    do
    {
        printf("\n\n ===== MAIN MENU =====");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a node from the beginning");
        printf("\n 6: Delete a node from the end");
        printf("\n 7: Delete a node after a given node");
        printf("\n 8: Delete the entire list");
        printf("\n 9: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_cll(start);
            printf("\n CIRCULAR LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = delete_beg(start);
            break;
        case 6:
            start = delete_end(start);
            break;
        case 7:
            start = delete_after(start);
            break;
        case 8:
            start = delete_list(start);
            printf("\n CIRCULAR LINKED LIST DELETED");
            break;
        }
    } while (option != 9);
    return 0;
}
struct node *create_cll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL) // when the node is being created for the first time
        {
            new_node->next = new_node; // new node points to itself as it is circular
            start = new_node;
        }
        else // when a node has been created at least once
        {
            ptr = start;
            while (ptr->next != start)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = start; // we point to start from here again as its a circular singly ll remember?
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start) // traverse till you reach head again and keep printing data
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\t %d", ptr->data); // print the remaining element
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = start;
    start = new_node; // this is what differentiates the insert_beg function from the insert_end
    // just put start at the element added now to make it the first element ez!
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = start; // or dont point start to that element to make it ze last element ez as well!
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
        ptr = ptr->next;
    ptr->next = start->next; // first point ptr to start's next element
    free(start);             // then free start
    start = ptr->next;       // point start to the new element
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != start)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next; // point preptr to ptr's next
    free(ptr);                // the free ptr
    return start;
}
struct node *delete_after(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &val);
    ptr = start;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    if (ptr == start)
        start = preptr->next;
    free(ptr);
    return start;
}
struct node *delete_list(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
        start = delete_end(start); // keep calling delete end until you have nothing to delete!
    free(start);
    return start;
}
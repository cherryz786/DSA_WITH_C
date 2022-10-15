/* C Program To Delete a Node before given node In singly linked list */

#include <stdio.h>
#include <malloc.h>
struct node *create(int);
void display(struct node *);
struct node *delete_node_before_given_node(struct node *);

// Declaring node
struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n;
    struct node *head;
    printf("Enter number of nodes : ");
    scanf("%d", &n);

    // Calling function to create node
    head = create(n);

    // Calling function to display list
    display(head);

    // Code to delete a node before a given node
    head = delete_node_before_given_node(head);
    printf("\nThe linked list after deletion of a node before given node - \n");

    // Calling function to display list after deletion of a node before given node
    display(head);

    return 0;
}

struct node *create(int n)
{
    int i;
    struct node *head = NULL;
    struct node *ptr, *newNode;

    for (i = 0; i < n; i++)
    {

        // Creating a new node
        newNode = (struct node *)malloc(sizeof(struct node *));

        // Assigning data to newly created node
        printf("Enter the value of %d node : ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        /*If list is empty assign the address of newly created node to head*/
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {

            /* If list already have few elements then loop through
            list and add newly created node after given node*/
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *ptr;

    // If list is empty
    if (head == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {

        /*If list has elements then loop through the loop and
        print elements one by one in sequential manner*/
        ptr = head;
        while (ptr != NULL)
        {
            printf("The node value = %d and their address = %u\n", ptr->data, ptr);
            ptr = ptr->next;
        }
    }
}

// Function to delete a node before a given node
struct node *delete_node_before_given_node(struct node *head)
{
    int val;
    struct node *address, *preAddress, *tempAddress;

    printf("\nEnter the value before which node to delete : ");
    scanf("%d", &val);

    // If list is empty, show message
    if (head == NULL)
    {
        printf("\nNo node available to delete!!");
    }

    // If list has only one node
    else if (head->next == NULL)
    {
        printf("No any previous node available to delete!!");
    }

    // If list has more than one elements
    else
    {
        address = head;
        tempAddress = head;
        preAddress = head;

        // Traverse the list to reach the given node
        while (address->data != val)
        {
            tempAddress = preAddress;
            preAddress = address;
            address = address->next;
        }

        // If need to delete node before second node means to delete first node
        if (address == head->next)
        {
            head = address;
            free(preAddress);
        }

        // If trying to delete first node.
        else if (address == head)
        {
            printf("No any previous node available to delete!!");
        }

        // For rest of the condition
        else
        {
            tempAddress->next = address;
            free(preAddress);
        }
    }
    return head;
}

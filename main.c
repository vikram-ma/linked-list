#include <stdio.h>
#include <stdlib.h>
//Prgrams that perform some basic operations on singly-linked list;

/// structure representing node.
struct node
{
    int data;
    struct node* link;
};

/// method that creates a new node, sets data to given parameter and returns the same.
struct node* creat_node(int n)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->link = NULL;
    return temp;
}

/// given a node, prints all the nodes till the tail.
void print_nodes(struct node* head)
{
    printf("nodes are ");
    while(head!=NULL)
    {
        printf("%d ", head->data);
        head = head->link;
    }

    printf("\n");
}

/// reverses the linked list.
void reverse_nodes(struct node** head)
{
    struct node* next_node;
    struct node* prev_node = *head;
    struct node* curr_node = prev_node == NULL ? NULL : prev_node->link;
    while(prev_node != NULL && curr_node != NULL)
    {
        next_node = curr_node->link;
        curr_node->link = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    if(*head!=NULL)
    {
        (*head)->link = NULL;
    }

    *head = prev_node;
}

/// frees all the nodes till the tail given a node.
void free_nodes(struct node** head, struct node* del_node)
{
    struct node* prev_node = *head;
    struct node* curr_node;
    curr_node = *head;

    while(curr_node!=NULL && curr_node != del_node)
    {
        prev_node = curr_node;
        curr_node = curr_node->link;
    }

    struct node* next_node;
    int isHead = *head == del_node ? 1 : 0;
    while(curr_node != NULL)
    {
        next_node = curr_node->link;
        free(curr_node);
        curr_node = next_node;
    }

    if(isHead)
    {
        *head = NULL;
    }
    else
    {
        prev_node->link = NULL;
    }


}

/// Deletes the a given node, in given linked list.
void delete_node(struct node** head, struct node* del_node)
{
    struct node* prev_node;
    struct node* curr_node;
    curr_node = *head;
    while(curr_node!=NULL && curr_node != del_node)
    {
        prev_node = curr_node;
        curr_node = curr_node->link;
    }

    if(curr_node != NULL)
    {
        if(curr_node == *head)
        {
            *head = curr_node->link;
        }
        else if(prev_node != NULL)
        {
            prev_node->link = curr_node->link;
        }

        free(curr_node);
    }
}

///Finds the middle node given a linked-list.
struct node* middle_node(struct node* head)
{
    struct node* tortoise = head;
    struct node* hare = head;
    int speed = -1;
    while(hare != NULL)
    {
        speed++;
        if(speed == 2)
        {
            tortoise = tortoise->link;
            speed = -1;
        }
        else
        {
            hare = hare->link;
        }
    }

    printf("middle node is %d\n", tortoise->data);
    return tortoise;
}

int main()
{
    struct node* head = creat_node(0);
    struct node* temp = head;
    int i;
    for(i=1;i<10;i++)
    {
        temp->link = creat_node(i);
        temp = temp->link;
    }

    print_nodes(head);
    reverse_nodes(&head);
    print_nodes(head);

    middle_node(head);

    delete_node(&head, head);//->link->link->link->link->link->link->link->link->link);
    print_nodes(head);

    middle_node(head);

    free_nodes(&head,head->link->link->link->link->link->link->link->link);
    print_nodes(head);

    return 0;
}

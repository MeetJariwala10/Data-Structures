// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* Write a program to
implement following operations on Doubly Linked List.

(a)   Insert a node at the front
of the Linked List

(b)  Insert a node at the
end of the Linked List

(c)   Delete a last node of
the Linked List

(d)  Delete a node before
specified position */

# include<stdio.h> 
# include<stdlib.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *create();
int count_nodes(struct node *head);
void display(struct node *head);
struct node *insert_front(int data);
struct node *insert_last(int data);
struct node *delete_first();
struct node *delete_last();
struct node *delete_before_pos(int pos);

int main()
{
    struct node* linkedlist = NULL;

    int choice, data, position;

    printf("\n Code Prepared by : Meet Jariwala (ET22BTCO046)\n");

    printf("\n Operations\n");
    printf("\n 1 -> Create \n 2 -> Insert at front \n 3 -> Insert at end \n 4 -> Delete first node \n 5 -> Delete last node \n 6 -> Delete a node before specified position \n 7 -> Display \n 8 -> Exit \n");

    while(1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            // Create double linked list
            case 1:
            {
                linkedlist = create();
                break;
            }

            // Insert at front 
            case 2:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                linkedlist = insert_front(data);
                break;
            }

            // Insert at last
            case 3:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                linkedlist = insert_last(data);
                break;
            }

            // Delete first node
            case 4:
            {
                linkedlist = delete_first();
                break;
            }

            // Delete last node
            case 5:
            {
                linkedlist = delete_last();
                break;
            }

            case 6:
            {
                printf("\n Enter position: ");
                scanf("%d", &position);

                if(position > count_nodes(linkedlist) || position == 1)
                {
                    printf("\n ENTER VALID POSITION \n");
                    break;
                }
                else
                {
                    linkedlist = delete_before_pos(position);
                }
                break;
            }

            // Display
            case 7:
            {
                display(linkedlist);
                break;
            }

            // Exit
            case 8:
            {
                exit(0);
            }

            default:
            {
                printf("\n Enter proper choice \n");
                break;
            }
        }
    }
    return 0;
}

// Create linked list
struct node *create()
{
    struct node *new = (struct node *) malloc(sizeof(struct node));

    int data;
    printf("\n Enter data : ");
    scanf("%d", &data);

    new->info = data;

    if(head == NULL)
    {
        head = tail = new;
        new->prev = NULL;
        new->next = NULL;
        return head;
    }
    else
    {
        tail->next = new;
        new->next = NULL;
        new->prev = tail;
        tail = new;
        return head;
    }
}

// Count number of nodes
int count_nodes(struct node *head)
{
    int count;
    if(head == NULL)
    {
        count = 0;
        return count;
    }

    count = 1;
    struct node *save = head;

    while(save != NULL)
    {
        save = save->next;
        count++;
    }

    return count;
}

// Insert at front
struct node *insert_front(int data)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));

    new->info = data;
    new->prev = NULL;
    new->next = NULL;

    new->next = head;
    head->prev = new;
    head = new;
    return head;
}

// Insert at last 
struct node *insert_last(int data)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));

    new->info = data;
    new->prev = NULL;
    new->next = NULL;

    tail->next = new;
    new->prev = tail;
    tail = new;
    return head;
}

// Delete first node
struct node *delete_first()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("Linked List is empty\n");
        return head;
    }
    if(head->prev == NULL && head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return head;
    }
}

// Delete last node
struct node *delete_last()
{
    struct node *temp;

    if(tail == NULL)
    {
        printf("Linked List is empty\n");
        return tail;
    }
    if(head->prev == NULL && head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(temp);
        return head;
    }
}

// Delete a node before specified position
struct node *delete_before_pos(int pos)
{
    if(head == NULL)
    {
        printf("Linked List is empty\n");
        return head;
    }
    if(pos == 2)
    {
        struct node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        return head;
    }
    else if(pos > 2)
    {
        struct node *save = head;
        struct node *pred = NULL;

        for(int i = 1; i <= pos - 2; i++)
        {
            pred = save;
            save = save->next;
        }   

        pred->next = save->next;
        save->next->prev = pred;
        free(save);
        return head;
    }
}

// Display linkedlist
void display(struct node *head)
{
    if(head == NULL)
    {
        printf("\n No node is present\n");
        return;
    }

    printf("\n Data : ");
    while(head != NULL)
    {
        printf("%5d", head->info);
        head = head->next;
    }
}

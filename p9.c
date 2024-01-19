// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* Write a menu driven program to implement following operations on Singly Linked List.
(a) Insert a node at the front of the Linked List
(b) Insert a node at the end of the Linked List
(c) Insert a node such that the Linked List is in ascending order (According to INFO field)
(d) Delete a first node of the Linked List
(e) Delete a node before specified position
(f) Delete a node after specified position */

# include<stdio.h>
# include<stdlib.h> 
            
struct node
{
    int info;
    struct node *link;
};

void display(struct node *first);
int count_nodes(struct node *first);
struct node *insert(struct node *first, int x);
struct node *insend(struct node *first, int x);
struct node *insord(struct node *first, int x);
struct node *delete_first(struct node *first);
struct node *del_before_position(struct node *first, int pos);
struct node *del_after_position(struct node *first, int pos);

int main()
{
    printf("\n Code Prepared by : Meet Jariwala (ET22BTCO046)");

    int choice, data, position;
    struct node *linkedList1 = NULL;

    printf("\n Operations\n");
    printf("\n 1 -> Insert \n 2 -> Insend \n 3 -> Insord \n 4 -> Delete first node \n 5 -> Delete a node before specified position \n 6 -> Delete a node after specified position \n 7 -> Display \n 8 -> Exit \n");

    while(1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            // Insert
            case 1:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                linkedList1 = insert(linkedList1, data);
                break;
            }

            // Insend
            case 2:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                linkedList1 = insend(linkedList1, data);
                break;
            }

            // Insord
            case 3:
            {
                printf("\n Enter data : ");
                scanf("%d", &data);

                linkedList1 = insord(linkedList1, data);
                break;
            }

            // Delete a first node of the Linked List
            case 4:
            {
                linkedList1 = delete_first(linkedList1);
                break;
            }

            // Delete a node before specified position
            case 5:
            {
                printf("\n Enter position : ");
                scanf("%d", &position);
                
                if(position > count_nodes(linkedList1) || position == 1)
                {
                    printf("\n ENTER VALID POSITION \n");
                    break;
                }

                linkedList1 = del_before_position(linkedList1, position);
                break;
            }

            // Delete a node after specified position
            case 6:
            {
                printf("\n Enter position : ");
                scanf("%d", &position);

                if(position >= count_nodes(linkedList1))
                {
                    printf("\n ENTER VALID POSITION \n");
                    break;
                }

                linkedList1 = del_after_position(linkedList1, position);
                break;
            }

            // Display
            case 7:
            {
                display(linkedList1);
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

// Display
void display(struct node *first)
{
    // If no node is present 
    if(first == NULL)
    {
        printf("\n No Node is present\n");
        return;
    }

    // Traversal in linked list while link of node is not equal to NULL
    printf("\n Data : ");
    while(first != NULL)
    {
        printf("%5d", first->info);
        first = first->link;
    }
}

// Count the number of nodes
int count_nodes(struct node *first)
{
    int count;
    if(first == NULL)
    {
        count = 0;
        return count;
    }

    count = 1;
    struct node *save = first;

    while(save->link != NULL)
    {
        save = save->link;
        count++;
    }

    return count;
}

// Insert a node at the front of the Linked List
struct node *insert(struct node *first, int x)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->info = x;
    new->link = first;
    return new;
}

// Insert a node at the end of the Linked List
struct node *insend(struct node *first, int x)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->info = x;
    new->link = NULL;

    if(first == NULL)
    {
        return new;
    }

    struct node *save = first;

    while(save->link != NULL)
    {
        save = save->link;
    }
    save->link = new;

    return first;
}

// Insert a node such that the Linked List is in ascending order (According to INFO field)
struct node *insord(struct node *first, int x)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->info = x;
    
    // If no node is present
    if(first == NULL)
    {
        new->link = NULL;
        return new;
    }

    // if the new node is smaller than first node 
    if(new->info <= first->info)
    {
        new->link = first;
        return new;
    }

    struct node *save = first;
    while(save->link != NULL && new->info >= save->link->info)
    {
        save = save->link;
    }

    new->link = save->link;
    save->link = new;
       
    return first;
}

// Delete a first node of the Linked List
struct node *delete_first(struct node *first)
{
	if(first == NULL)
	{
		printf("No node present Cannot perform delete_first operation\n");
        return NULL;
	}
	
	struct node *save = first;
	first = first->link;
	free(save);
	return first;
}

// Delete a node before specified position
struct node *del_before_position(struct node *first, int pos)
{
    if(first == NULL)
	{
		printf("No node present Cannot perform del_before_position operation\n");
	}

    struct node *save = first;
    struct node *pred = NULL;
    int i;
    
    if(pos == 2) /* If first node is to be deleted */
    {
        first = first->link;
        free(save);
        return first;
    }
    for(i = 1; i <= pos - 2; i++)
    {
        pred = save;
        save = save->link;
    }
    
    pred->link = save->link;
    free(save);
    return first;
}

// Delete a node after specified position
struct node *del_after_position(struct node *first, int pos)
{
    if(first == NULL)
	{
		printf("No node present Cannot perform del_before_position operation\n");
	}

    struct node *save = first;
    struct node *pred = NULL;
    int i;
    
    for(i = 1; i < pos + 1; i++)
    {
        pred = save;
        save = save->link;

        // If last node is to be deleted
        if(save->link == NULL) 
        {
            pred->link = NULL;
            free(save);
            return first;
        }
    }
    
    pred->link = save->link;
    free(save);
    return first;
}
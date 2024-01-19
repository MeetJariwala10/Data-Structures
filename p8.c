/* Circular Queue using Array */

// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

# include<stdio.h> 
# include<conio.h> 
# include<stdlib.h> 

# define SIZE 5

void cqInsert(int Q[], int *F, int *R, int data);
int cqDelete(int Q[], int *F, int *R);
void display(int Q[], int *F, int *R);
void display_new(int Q[], int *F, int *R); /* Another way to display elements in Circular queue */

int main()
{
    int queue[SIZE], front = -1, rear = -1, choice, element;

   while(1)
   {
        printf("\nOperations that can be performed :\n 1 -> Insert \n 2 -> Delete \n 3 -> Display \n 4 -> Exit \n 5 -> New Display method \n");
        printf("\nEnter Operation : ");
        scanf("%d", &choice);

        switch(choice)
        {
            // Choice for Insertion
            case 1:
            {
                printf("\nEnter element to be inserted : ");
                scanf("%d", &element);
                cqInsert(queue, &front, &rear, element);
                getch();
                break;
            }

            // Choice for Deletion
            case 2:
            {
                int delete = cqDelete(queue, &front, &rear);
                if(delete != -1)
                {
                    printf("\nDeleted element is : %d\n", delete);
                    getch();
                }
                break;
            }

            // Choice for Displaying
            case 3:
            {
                display(queue, &front, &rear);
                getch();
                break;
            }

            // Choice for exit
            case 4:
            {
                exit(0);
            }

            // New display method
            case 5:
            {
                display_new(queue, &front, &rear);
                getch();
                break;
            }

            // Default choice
            default:
            {
                printf("\nEnter valid Operation !\n");
                getch();
                break;
            }
        }
    }
    return 0;
}

void cqInsert(int Q[], int *F, int *R, int data)
{
    if((*R + 1) % SIZE == *F)
    {
        printf("Queue Overflow\n");
        return;
    }

    *R = (*R + 1) % SIZE;
    Q[*R] = data;

    if(*F == -1)
    {
        *F = 0;
    }
}

int cqDelete(int Q[], int *F, int *R)
{
    if(*F == -1 && *R == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int element = Q[*F];

    if(*F == *R)
    {
        *F = *R = -1;
    }
    else
    {
        *F = (*F + 1) % SIZE;
    }
    
    return element;
}

void display(int Q[], int *F, int *R)
{
    if(*F == -1 && *R == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        if(*R >= *F)
        {
            for(int i = *F; i <= *R; i++)
            {
                printf("%d  ", Q[i]);
            }
        }
        else
        {
            for(int i = *F; i <= SIZE - 1; i++)
            {
                printf("%d  ", Q[i]);
            }
            for(int i = 0; i <= *R; i++)
            {
                printf("%d  ", Q[i]);
            }
        }
    }
}

void display_new(int Q[], int *F, int *R)
{
    int i = *F;
    if(*F == -1 && *R == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        printf("Queue is : \n");
        while (i != *R)
        {
            printf("%d  ", Q[i]);
            i = (i+1) % SIZE;
        }
        printf("%d  ", Q[*R]);
    }
}
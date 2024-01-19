// Name : Meet P Jariwala
// Enrollment no. : ET22BTCO046

/* (1) Implement Dequeue using an
array */

# include<stdio.h>
# include<stdlib.h>
# define SIZE 5

void DQInsert_Rear(int Q[], int *F, int *R, int element);
void DQInsert_Front(int Q[], int *F, int *R, int element);
int DQDelete_Front(int Q[], int *F, int *R);
int DQDelete_Rear(int Q[], int *F, int *R);
void Display(int Q[], int *F, int *R);

int main()
{
    int Queue[SIZE], front = -1, rear = -1, data, choice, element;

    printf("Code Prepared by : Meet Jariwala (ET22BTCO046)\n");

    printf("\n Operations that can be performed :\n 1 -> Insert at Rear \n 2 -> Insert at Front \n 3 -> Delete from Front \n 4 -> Delete from Rear \n 5 -> Display \n 6 -> Exit \n");

    while(1)
   {
        printf("\nEnter Operation : ");
        scanf("%d", &choice);

        switch(choice)
        {
            // Choice for Insertion at rear
            case 1:
            {
                printf("\nEnter element to be inserted : ");
                scanf("%d", &element);
                DQInsert_Rear(Queue, &front, &rear, element);
                break;
            }

            // Choice for Insertion at front
            case 2:
            {
                printf("\nEnter element to be inserted : ");
                scanf("%d", &element);
                DQInsert_Front(Queue, &front, &rear, element);
                break;
            }

            // Choice for Deletion from front
            case 3:
            {
                int delete = DQDelete_Front(Queue, &front, &rear);
                if(delete != -1)
                {
                    printf("\nDeleted element is : %d\n", delete);
                }
                break;
            }

            // Choice for Deletion from rear
            case 4:
            {
                int delete = DQDelete_Rear(Queue, &front, &rear);
                if(delete != -1)
                {
                    printf("\nDeleted element is : %d\n", delete);
                }
                break;
            }

            // Choice for Displaying
            case 5:
            {
                Display(Queue, &front, &rear);
                break;
            }

            // Choice for exit
            case 6:
            {
                exit(0);
            }

            // Default choice
            default:
            {
                printf("\nEnter valid Operation !\n");
                break;
            }
        }
    }
    return 0;
}

void DQInsert_Rear(int Q[], int *F, int *R, int element)
{
    if(*R == SIZE - 1)
    {
        printf("\nQueue Overflow !\n");
        return;
    }

    *R = *R + 1;
    Q[*R] = element;

    if(*F == -1)
    {
        *F = 0;
        return;
    }
}

void DQInsert_Front(int Q[], int *F, int *R, int element)
{
    if(*R == SIZE - 1)
    {
        printf("\nQueue Overflow !\n");
        return;
    }

    if(*F - 1 == -1 || *F == -1)
    {
        printf("\nInsertion not possible\n");
        return;
    }

    *F = *F - 1;
    Q[*F] = element;
    return;
}

int DQDelete_Front(int Q[], int *F, int *R)
{
    int element;
    if(*F == -1)
    {
        printf("\nQueue Underflow !\n");
        return -1;
    }
    
    element = Q[*F];

    if(*F == *R)
    {
        *F = *R = -1;
    }
    else
    {
        *F = *F + 1;
    }
    return element;
}

int DQDelete_Rear(int Q[], int *F, int *R)
{
    int element;
    if(*F == -1)
    {
        printf("\nQueue Underflow !\n");
        return -1;
    }

    element = Q[*R];

    if(*F == *R)
    {
        *F = *R = -1;
    }
    else
    {
        *R = *R - 1;
    }
    return element;
}

void Display(int Q[], int *F, int *R)
{
    if(*F == -1)
    {
        printf("\nQueue Empty !\n");
        return;
    }
    printf("\nQueue Contents : \n");
    for(int i = *F; i <= *R; i++)
    {
        printf("%5d", Q[i]);
    }
}
/* NOT COMPLETED */

# include<stdio.h>
# include<stdlib.h>

struct node 
{
    int coeff;
    int power;
    struct node *link;
};

void insert(struct node **head, int x, int y)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));

    if(*head == NULL)
    {
        new->coeff = x;
        new->power = y;
        *head = new;
        return;
    }

    new->coeff = x;
    new->power = y;
    new->link = *head;
}

struct node *add(struct node *head1, struct node *head2)
{
    if(head1 == NULL && head2 == NULL)
    {
        return NULL;
    }

    if(head1->power == head2->power)
    {
        head1->coeff = head1->coeff + head2->coeff;
        return head1;
    }

}

void display(struct node *first)
{
    if(first == NULL)
    {
        return;
    }

    struct node *save = first;
    while(save != NULL)
    {
        printf("%d, %d", save->coeff, save->power);
        save = save->link;
    }
}

int main()
{
    struct node *linkedList1 = NULL, *linkedList2 = NULL;

    insert(&linkedList1, 5, 1);
    insert(&linkedList2, 2, 1);

    linkedList1 = add(linkedList1, linkedList2);

    display(linkedList1);

    return 0;
}
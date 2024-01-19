# include<stdio.h> 
# include<stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

// Creating node
struct node *create_node(int data)
{
    struct node *newNode = (struct node *) malloc(sizeof(struct node));

    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inserting a node
struct node *insert(struct node *root, int data)
{
    if(root == NULL)
    {
        root = create_node(data);
    }
    else if(data <= root->info)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Searching a node
int search(struct node *root, int data)
{
    if(root == NULL)
    {
        return -1;
    }

    while(root)
    {
        if(root->info == data)
        {
            return 1;
        }
        else if(root->info < data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
} 

// Recursive Preorder Traversal
void preorder_recursive(struct node *root)
{
    if(root == NULL)
    {
        printf("\n Tree is empty \n");
        return;
    }

    printf("\n Data : %d", root->info);

    if(root->left != NULL)
    {
        preorder_recursive(root->left);
    }

    if(root->right != NULL)
    {
        preorder_recursive(root->right);
    }
}

// Recursive Inorder Traversal
void inorder_recursive(struct node *root)
{
    if(root == NULL)
    {
        printf("\n Tree is empty \n");
        return;
    }

    if(root->left != NULL)
    {
        inorder_recursive(root->left);
    }

    printf("\n Data : %d", root->info);

    if(root->right != NULL)
    {
        inorder_recursive(root->right);
    }
}

// Recursive Postorder Traversal
void postorder_recursive(struct node *root)
{
    if(root == NULL)
    {
        printf("\n Tree is empty \n");
        return;
    }

    if(root->left != NULL)
    {
        postorder_recursive(root->left);
    }

    if(root->right != NULL)
    {
        postorder_recursive(root->right);
    }

    printf("\n Data : %5d", root->info);
}

int min_element(struct node *root)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->left != NULL)
    {
        min_element(root->left);
    }
    else
    {
        return root->info;
    }
}

int max_element(struct node *root)
{
    if(root == NULL)
    {
        return -1;
    }
    if(root->right != NULL)
    {
        max_element(root->right);
    }
    else
    {
        return root->info;
    }
}



int main()
{
    struct node *root = NULL;

    root = create_node(5);

    // preorder_recursive(root);
    // postorder_recursive(root);

    inorder_recursive(root);

    root = insert(root, 1);
    root = insert(root, 25);
    root = insert(root, 5);
    root = insert(root, 40);
    root = insert(root, 4);

    printf("\n");
    inorder_recursive(root);

    printf("\n %d", search(root, 99));

    printf("\n Min : %d\n", min_element(root));
    printf("\n Max : %d\n", max_element(root));

    return 0;
}
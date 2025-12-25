#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left_child;
    struct node *right_child;
};

struct node* create_node(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

struct node* insert_bst(struct node *root, int value)
{
    if (root == NULL)
        return create_node(value);

    if (value < root->data)
        root->left_child = insert_bst(root->left_child, value);
    else if (value > root->data)
        root->right_child = insert_bst(root->right_child, value);

    return root;
}

struct node* find_min(struct node *root)
{
    while (root && root->left_child != NULL)
        root = root->left_child;

    return root;
}

struct node* delete_bst(struct node *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->data)
        root->left_child = delete_bst(root->left_child, value);
    else if (value > root->data)
        root->right_child = delete_bst(root->right_child, value);
    else
    {
        if (root->left_child == NULL)
        {
            struct node *temp = root->right_child;
            free(root);
            return temp;
        }
        else if (root->right_child == NULL)
        {
            struct node *temp = root->left_child;
            free(root);
            return temp;
        }

        struct node *min_node = find_min(root->right_child);
        root->data = min_node->data;
        root->right_child = delete_bst(root->right_child, min_node->data);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left_child);
    printf("%d ", root->data);
    inorder(root->right_child);
}

int main()
{
    struct node *root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Inorder (sorted)\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert_bst(root, value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            root = delete_bst(root, value);
            break;

        case 3:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}


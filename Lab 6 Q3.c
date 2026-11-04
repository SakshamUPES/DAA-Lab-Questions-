//Write a C program to implement Huffman Coding using 
//the Greedy approach to generate optimal prefix codes 
//for given characters based on their frequencies.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    int freq;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(char data, int freq)
{
    struct Node* node =
        (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Find two nodes with minimum frequency
void findTwoMin(struct Node* nodes[], int n, int *min1, int *min2)
{
    *min1 = -1;
    *min2 = -1;

    for (int i = 0; i < n; i++)
    {
        if (nodes[i] == NULL)
            continue;

        if (*min1 == -1 ||
            nodes[i]->freq < nodes[*min1]->freq)
        {
            *min2 = *min1;
            *min1 = i;
        }
        else if (*min2 == -1 ||
                 nodes[i]->freq < nodes[*min2]->freq)
        {
            *min2 = i;
        }
    }
}

// Print Huffman codes
void printCodes(struct Node* root, int code[], int top)
{
    if (root->left)
    {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right)
    {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    // Leaf node
    if (root->left == NULL && root->right == NULL)
    {
        printf("%c : ", root->data);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    struct Node* nodes[100];

    printf("Enter character and frequency:\n");

    for (int i = 0; i < n; i++)
    {
        char ch;
        int freq;

        printf("Character %d: ", i + 1);
        scanf(" %c %d", &ch, &freq);

        nodes[i] = createNode(ch, freq);
    }

    int size = n;

    // Construct Huffman Tree
    while (1)
    {
        int min1, min2;

        findTwoMin(nodes, size, &min1, &min2);

        if (min2 == -1)
            break;

        struct Node* newNode =
            createNode('$',
                       nodes[min1]->freq +
                       nodes[min2]->freq);

        newNode->left = nodes[min1];
        newNode->right = nodes[min2];

        nodes[min1] = newNode;
        nodes[min2] = NULL;
    }

    struct Node* root = NULL;

    for (int i = 0; i < size; i++)
    {
        if (nodes[i] != NULL)
        {
            root = nodes[i];
            break;
        }
    }

    int code[100];

    printf("\nHuffman Codes:\n");
    printCodes(root, code, 0);

    return 0;
}

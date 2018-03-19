#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
} node;

node *newNode (int data) {
    node *new_node = calloc(1, sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    return (new_node);
}

void inorder_print (node *root) {

    if (root == NULL) return;

    inorder_print(root->left);
    printf("%d ", root->data);
    inorder_print(root->right);
}

void postorder_print (node *root) {

    if (root == NULL) return;
    postorder_print(root->left);
    postorder_print(root->right);
    printf("%d ", root->data);
}

int tree_size (node *root) {

    if (root == NULL) return (0);

    return (tree_size(root->left) +
            tree_size(root->right) + 1);
}

int max (int a, int b) {
    return (a>b? a : b);
}

int maxDepth (node *root) {
    if (root == NULL) return (0);

    return (max(maxDepth(root->left),maxDepth(root->right)) + 1);
}

/* Min and Max value APIs don't take NULL trees */
int minValue (node *root) {
    if (root != NULL && root->left != NULL) {
        return (minValue(root->left));
    }
    return (root->data);
}

int maxValue (node *root) {
    if (root != NULL && root->right != NULL) {
        return (maxValue(root->right));
    }
    return (root->data);
}

int hasPathSum (node *root, int sum) {

    int has_sum = 0;
    if (root == NULL || root->data > sum) return (0);
    if (root->data == sum && root->left == NULL && root->right == NULL) {
        //printf("%d ", root->data);
        return (1);
    }
    has_sum = hasPathSum(root->left, sum - root->data) ||
        hasPathSum(root->right, sum - root->data);
    //if (has_sum) printf("%d ", root->data);
    return (has_sum);
}

void printPathRecur(node *root, int *arr, int idx) {
    if (root != NULL) {
        arr[++idx] = root->data;
        if (!root->left && !root->right) {
            for (int i = 0; i <= idx; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
        printPathRecur(root->left, arr, idx);
        printPathRecur(root->right, arr, idx);
    }
    return;
}

void printPaths (node *root) {
    int max_depth = maxDepth(root);
    int *arr = calloc(max_depth, sizeof(int));
    int idx  = -1;
    printPathRecur(root, arr, idx);
}

void mirror_tree (node *root) {
    if (root == NULL) return;
    node *temp = root->right;
    root->right = root->left;
    root->left  = temp;
    mirror_tree(root->left);
    mirror_tree(root->right);
    return;
}

void doubleTree (node *root) {
    if (root == NULL) return;
    doubleTree(root->left);
    doubleTree(root->right);
    node *temp = root->left;
    root->left = newNode(root->data);
    root->left->left = temp;
    return;
}

int sameTree (node *root1, node *root2) {
    if (root1 == NULL && root2 == NULL) return 1;
    if (root1->data == root2->data) {
        return(sameTree(root1->left, root2->left) &&
               sameTree(root1->right, root2->right));
    }
    return 0;
}

int countTrees (int n) {

    int sum = 1, index = 1;
    while(index < n) {
        sum = 2*sum + (sum-1);
        index++;
    }
    return (sum);
}
    

int main () {

    /* Problem 1 - build123()*/
    node *root;
    node *root1;
    root = newNode(4);
    root->left = newNode(2);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right = newNode(5);

    root1 = newNode(4);
    root1->left = newNode(2);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);
    root1->right = newNode(5);

    /* Problem 2 - size()*/
    printf("Size of tree is %d\n", tree_size(root));

    /* Problem 3 - maxDepth()*/
    printf("Max Depth of tree is %d\n", maxDepth(root));

    /* Problem 4 - minValue()*/
    printf("Min value of node in the tree is %d\n", minValue(root));

    printf("Max value of node in the tree is %d\n", maxValue(root));

    /* Problem 5 - inorder_print()*/
    inorder_print(root);
    printf("\n");
    /* Problem 6 - postorder_print()*/
    postorder_print(root);
    printf("\n");

    /* Problem 7 - hasPathSum()*/
    int sum = 7;
    printf("The tree %s a path sum of %d\n", hasPathSum(root, sum)? "has": "does not have", sum);

    /* Problem 8 - printPaths()*/
    printPaths(root);

    /* Problem 9 - mirror()*/
    mirror_tree(root);
    inorder_print(root);
    printf("\n");

    /* Problem 10 - doubleTree()*/
    doubleTree(root);
    inorder_print(root);
    printf("\n");

    /* Problem 11 - sameTree()*/
    printf("Trees pointed by root1 and root2 are %s\n", sameTree(root, root1)? "same":"not same");

    /* Problem 12 - countTrees() - Count structurally unique trees provided number of unique nodes*/
    int unique_nodes = 4;
    printf("Number of structurally unique tress with %d unique nodes is %d\n", unique_nodes, countTrees(unique_nodes));

    return (0);
}

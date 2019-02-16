#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

ListNode *newNode (int data) 
{
    ListNode *node = malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    return (node);
}

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *parent;
} TreeNode;

TreeNode *newTreeNode (int data) 
{
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void construct_BST_from_pre_order_traversal (int *arr, int arr_start, int arr_end)
{
    int lst = arr_start;
    if (arr_start < arr_end) {
        for (int i = arr_start + 1; i <= arr_end; i++) {
            if (arr[i] < arr[arr_start]) {
                lst++;
            } else break;
        }
        construct_BST(arr, arr_start+1, lst); // left sub-tree
        printf("%d ", arr[arr_start]); // node
        construct_BST(arr, lst+1, arr_end); // right sub-tree
    } else if (arr_start > arr_end){
        // pass
    } else {
        printf("%d ", arr[arr_start]); // node
    }
}

TreeNode *BST_from_sorted_ll_recursion_helper (ListNode *root, int start, int end)
{
    if (start > end) {
        return NULL;
    }
    ListNode *temp = root;
    int mid = (end - start)/2;
    for (int i = 0; (i < mid) && temp; i++) {
        temp = temp->next;
    }
    TreeNode *node = newTreeNode(temp->data);
    node->left = BST_from_sorted_ll_recursion_helper(root, start, mid-1);
    node->right = BST_from_sorted_ll_recursion_helper(root, mid+1, end);
    return (node);
}

TreeNode *construct_BST_from_sorted_ll (ListNode *root)
{
    int node_count = 0;
    TreeNode *tree_root = NULL;
    ListNode *temp = root;
    while (temp != NULL) {
        node_count++;
        temp = temp->next;
    }
    tree_root = BST_from_sorted_ll_recursion_helper(root, 0, node_count);
}

int main ()
{
    int arr[] = {10, 5, 2, 1, 3, 4, 7,6,9,8,15,12,13,14,18};
    construct_BST_from_pre_order_traversal(arr, 0, 14);

    /* BST from sorted LL */
    ListNode *temp = NULL;
    ListNode *root = newNode(1);
    root->next = newNode(2);
    temp = root->next;
    temp->next = newNode(3);
    temp = temp->next;
    temp->next = newNode(4);
    temp = temp->next;
    temp->next = newNode(5);
    TreeNode *tree_root = construct_BST_from_sorted_ll (root);
}
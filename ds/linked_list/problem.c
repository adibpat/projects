#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* newNode(int data) {
    Node *temp = malloc(sizeof(Node));
    temp->next = NULL;
    temp->data = data;
    return (temp);
}

int get_ll_length (Node *current) {
    int count = 0;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return (count);
}

void print_nodes (Node *current) {
    while (current) {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

void print_nodes_v2 (Node *current) {
    for (; current != NULL; current = current->next)
        printf("%d ", current->data);
    printf("\n");
}

void push_node (Node **headref, int data) {
    Node *temp = newNode(data);
    temp->next = *headref;
    *headref = temp;
}

Node *add_to_tail (Node *head, int data) {
    Node *current = head;
    Node *newnode = newNode(data);
    if (current == NULL) return (newnode);
    for (; current->next; current = current->next);
    current->next = newnode;
    return (head);
}

int count (Node *head, int data) {
    Node *iter = head;
    int count  = 0;
    while (iter) {
        if (iter->data == data) count++;
    }
    return (count);
}

int get_n_th( Node *head, int pos) {
    Node *iter = head;
    while(pos > 0) {
        assert(iter != NULL);
        iter = iter->next;
        pos = pos - 1;
    }
    return (iter->data);
}

void DeleteList (Node **head) {
    Node *iter = *head, *temp = NULL;
    while(iter) {
        temp = iter->next;
        free(iter);
        iter = temp;
    }
    *head = NULL;
}

int pop (Node **head) {
    Node *temp = (*head)->next;
    int data = (*head)->data;
    free(*head);
    *head = temp;
    return (data);
}

void InsertNth (Node **head, int pos, int data) {
    Node *temp = NULL;
    if (*head == NULL || pos == 0) {
        temp = newNode(data);
        temp->next = *head;
        *head = temp;
        return;
    }
    Node *iter = *head;
    while(pos > 1) {
        assert(iter != NULL);
        iter = iter->next;
        pos = pos - 1;
    }
    temp = newNode(data);
    temp->next = iter->next;
    iter->next = temp;
    return;
}

void SortedInsert (Node **head, Node *node) {
    if (*head == NULL || ((*head)->data > node->data)) {
        node->next = *head;
        *head = node;
        return;
    }
    Node *current = *head;
    while (current->next && current->next->data < node->data) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    return;
}

void InsertSort (Node **head) {
    Node *sortedList = NULL, *current = *head;
    while(current) {
        Node *temp = current->next;
        SortedInsert(&sortedList, current);
        current = temp;
    }
    *head = sortedList;
    return;
}

void Append (Node **aref, Node **bref) {
    if (*aref == NULL) {
        *aref = *bref;
        *bref = NULL;
        return;
    }
    Node *iter = *aref;
    while (iter->next) {
        iter = iter->next;
    }
    iter->next = *bref;
    *bref = NULL;
}

void FrontBackSplit (Node *head, Node **front, Node **back) {
    if (head == NULL || head->next == NULL) {
        *front = head;
        *back = NULL;
    }
    Node *slow = head, *fast = head;
    while (fast) {
        fast = fast->next;
        if (fast == NULL || fast->next == NULL) {
            break;
        }
        fast = fast->next;
        slow = slow->next;
    }
    *back = slow->next;
    slow->next = NULL;
    *front = head;
    return;
}
    
void RemoveDuplicates (Node *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    Node *current = head;
    while (current->next) {
        if (current->data == current->next->data) {
            Node *temp = current->next->next;
            free(current->next);
            current->next = temp;
        } else {
            current = current->next;
        }
    }
    return;
}

void MoveNode (Node **aref, Node **bref) {
    if (*bref == NULL) return;
    Node *temp = *bref;
    *bref = temp->next;
    temp->next = *aref;
    *aref = temp;
    return;
}

void AlternateSplit (Node *head, Node **aref, Node **bref) {
    int count = 0;
    while (head) {
        if (count%2) {
            MoveNode(aref, &head);
            count++;
        } else {
            MoveNode(bref, &head);
            count++;
        }
    }
    return;
}

Node* SortedMerge (Node *a, Node *b) {
    Node sorted;
    Node *sorted_p = &sorted;
    while(1) {
        if (a && b) {
            if (a->data > b->data) {
                MoveNode(&(sorted_p->next), &b);
                //print_nodes_v2(b);
            } else {
                MoveNode(&(sorted_p->next), &a);
                //print_nodes_v2(a);
            }
            sorted_p = sorted_p->next;
        } else break;
    }
    if (a) {
        sorted_p->next = a;
    } else {
        sorted_p->next = b;
    }
    return (sorted.next);
}

void MergeSort (Node *sorted) {
    Node *fh, *bh;
    FrontBackSplit(sorted, &fh, &bh);
    if (fh->next == NULL && bh->next == NULL) {
        SortedMerge(
    
int main () {


    Node *head = newNode(1);
    head = add_to_tail(head, 2);
    head = add_to_tail(head, 3);
    head = add_to_tail(head, 4);
    head = add_to_tail(head, 5);
    
    print_nodes(head);
    printf("get_ll_length: # of nodes in the llist is %d\n", get_ll_length(head));

    push_node(&head, 5);
    print_nodes_v2(head);

    printf("get_n_th: Element at position %d in the list is %d\n", 1, get_n_th(head, 1));

    printf("DeleteList\n");
    Node *head2 = newNode(1);
    head2 = add_to_tail(head2, 2);
    head2 = add_to_tail(head2, 3);
    head2 = add_to_tail(head2, 4);
    head2 = add_to_tail(head2, 5);
    print_nodes_v2(head2);
    DeleteList(&head2);
    print_nodes_v2(head2);

    printf("pop: Data %d popped out from the list\n", pop(&head));
    print_nodes_v2(head);

    InsertNth(&head, 4, 6);
    printf("InsertNth: This is the list after adding %d at positon %d\n", 6, 4);
    print_nodes_v2(head);

    Node *sorted = newNode(5);
    printf("SortedInsert: This is the list after adding 5\n");
    SortedInsert(&head, sorted);
    print_nodes_v2(head);

    Node *unsorted = newNode(6);
    unsorted = add_to_tail(unsorted, 4);
    unsorted = add_to_tail(unsorted, 7);
    unsorted = add_to_tail(unsorted, 12);
    unsorted = add_to_tail(unsorted, 1);
    printf("InsertSort:\n");
    print_nodes_v2(unsorted);
    InsertSort(&unsorted);
    print_nodes_v2(unsorted);

    Node *test = NULL;
    printf("Append:\n");
    Append(&head, &unsorted);
    print_nodes_v2(head);

    Node *fh, *bh;
    printf("FrontbackSplit\n");
    FrontBackSplit(head, &fh, &bh);
    print_nodes_v2(fh);
    print_nodes_v2(bh);
    printf("RemoveDuplicates\n");
    Append(&fh, &bh);
    head = fh;
    InsertSort(&head);
    print_nodes_v2(head);
    RemoveDuplicates(head);
    print_nodes_v2(head);

    printf("MoveNode\n");
    FrontBackSplit(head, &fh, &bh);
    print_nodes_v2(fh);
    print_nodes_v2(bh);
    MoveNode(&fh, &bh);
    print_nodes_v2(fh);
    print_nodes_v2(bh);

    printf("AlternateSplit:\n");
    Append(&fh, &bh);
    head2 = fh;
    print_nodes_v2(head2);
    fh = NULL, bh = NULL;
    AlternateSplit(head2, &fh, &bh);
    print_nodes_v2(fh);
    print_nodes_v2(bh);

    printf("SortedMerge:\n");
    head2 = newNode(1);
    head2 = add_to_tail(head2, 2);
    head2 = add_to_tail(head2, 3);
    head2 = add_to_tail(head2, 4);
    head2 = add_to_tail(head2, 5);
    print_nodes_v2(head2);

    Node *head3 = newNode(1);
    head3 = add_to_tail(head3, 2);
    head3 = add_to_tail(head3, 3);
    head3 = add_to_tail(head3, 4);
    head3 = add_to_tail(head3, 5);
    print_nodes_v2(head3);
    
    Node * sorted2 = SortedMerge(head2, head3);
    print_nodes_v2(sorted2);

    printf("Shuffling the deck for sorting\n");
    fh = NULL, bh = NULL;
    AlternateSplit(sorted2, &fh, &bh);
    print_nodes_v2(fh);
    print_nodes_v2(bh);
    Append(&fh, &bh);
    sorted2 = fh;
    fh = NULL, bh = NULL;
    AlternateSplit(sorted2, &fh, &bh);
    Append(&fh, &bh);
    sorted2 = fh;
    print_nodes_v2(sorted2);
    
    
    return (0);
}

#include <stdio.h>
#include <stdlib.h>

#define ASK_INT(msg, i) do { printf(msg); \
    scanf("%d", &i); } while (0)
#define XOR(prev, next) ((struct node *)((size_t) prev ^ (size_t) next))

typedef struct node {
    int data;
    struct node *link;
} xnode;

void print (xnode *head);
xnode *insert (xnode *head, int d, int pos);
xnode *delete (xnode *head, int pos);

int main (void)
{
    int pos, data;
    char choice;
    xnode *head = NULL;

    do {
        printf("Options:\n\t[i] Insert\n\t[d] Delete\n\tOthers to exit\n");
        choice = getchar();
        switch (choice) {
            case 'i':
                ASK_INT("Insert position: ", pos);
                ASK_INT("Insert data: ", data);
                head = insert(head, data, pos);
                break;
            case 'd':
                ASK_INT("Insert position: ", pos);
                head = delete(head, pos);
                break;
            default:
                choice = '\0';
                break;
        }
        getchar();
    } while (choice != '\0');

    return 0;
}

void print (xnode *head)
{
    xnode *curr = head, *prev = NULL, *next;
    while (curr) {
        printf("%d<->", curr->data);
        next = XOR(prev, curr->link);
        prev = curr;
        curr = next;
    }
    printf("NULL\n");
}

xnode *insert (xnode *head, int d, int pos)
{
    xnode *curr = head, *prev = NULL, *next;
    xnode *new = malloc(sizeof(xnode));
    new->data = d;
    while (curr && pos > 0) {
        next = XOR(prev, curr->link);
        prev = curr;
        curr = next;
        pos--;
    }
    if (pos > 0) {
        perror("ERROR: Position exceeding the length\n");
        free(new);
        return head;
    } else {
        if (head == curr) {
            if (head)
                head->link = XOR(new, head->link);
            new->link = head;
            return new;
        } else if (!curr) {
            new->link = prev;
            prev->link = XOR(prev->link, new);
        } else {
            new->link = XOR(prev, curr);
            prev->link = XOR(XOR(prev->link, curr), new);
            curr->link = XOR(new, XOR(prev, curr->link));
        }
    }
    return head;
}

xnode *delete (xnode *head, int pos)
{
    xnode *curr = head, *prev = NULL, *next;
    if (!head) {
        perror("ERROR: list is empty\n");
        return head;
    }
    while (pos > 0 && (next = XOR(prev, curr->link)) != NULL) {
        prev = curr;
        curr = next;
        pos--;
    }
    if (pos > 0) {
        perror("ERROR: Position exceeding the length\n");
        return head;
    } else {
        if (curr == head && head) {
            next = curr->link;
            if (next) {
                head = next;
                next->link = XOR(curr, next->link);
            } else {
                head = NULL;
            }
        } else {
            next = XOR(prev, curr->link);
            if (!next) {
                prev->link = XOR(prev->link, curr);
            } else {
                prev->link = XOR(XOR(prev->link, curr), next);
                next->link = XOR(XOR(next->link, curr), prev);
            }
        }
    }
    free(curr);
    return head;
}

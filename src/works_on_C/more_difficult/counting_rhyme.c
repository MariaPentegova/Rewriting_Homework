#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int number;          
    struct Node *next;   
} Node;

// циклический список из n воинов
Node* create_circle(int n) {
    Node *head = NULL, *prev = NULL;
    for (int i = 1; i <= n; i++) {
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->number = i;
        if (head == NULL) {
            head = new_node;
        } else {
            prev->next = new_node;
        }
        prev = new_node;
    }
    prev->next = head; 
    return head;
}

Node* delete_node(Node *node, Node *prev) {
    prev->next = node->next;
    free(node);
    return prev->next;
}

int to_end(int n, int m) {
    Node *circle = create_circle(n);
    Node *current = circle;
    Node *prev = NULL;

    while (prev == NULL || prev->next != current) {
        prev = current;
        current = current->next;
        if (current == circle && prev->next != current) {
            break;
        }
    }

    while (current->next != current) {
        for (int count = 1; count < m; count++) {
            prev = current;
            current = current->next;
        }
        printf("Убит воин #%d\n", current->number);
        current = delete_node(current, prev);
    }

    int survivor = current->number;
    free(current); 
    return survivor;
}

int main() {
    int n = 41; 
    int m;

    printf("Введите число, соответствующее убивающего каждого m-го: ");
    scanf("%d", &m);

    int last = to_end(n, m);
    printf("Последним остается воин #%d\n", last);
    return 0;
}

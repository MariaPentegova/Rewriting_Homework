#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Функция для вставки элемента в отсортированный список
void insert_sorted(Node** head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void delete_value(Node** head, int value) {
    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL && current->value != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Значение %d не найден.\n", value);
        return;
    }

    if (prev == NULL) {
        // Удаляем головой списка
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Значение %d удалено.\n", value);
}

void print_list(Node* head) {
    printf("Список: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void free_list(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node* head = NULL;
    int choice;
    int value;

    while (1) {
        printf("\nМеню:\n");
        printf("0 - выйти\n");
        printf("1 - добавить значение\n");
        printf("2 - удалить значение\n");
        printf("3 - распечатать список\n");
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                free_list(head);
                printf("Выход...\n");
                return 0;
            case 1:
                printf("Введите значение для добавления: ");
                scanf("%d", &value);
                insert_sorted(&head, value);
                break;
            case 2:
                printf("Введите значение для удаления: ");
                scanf("%d", &value);
                delete_value(&head, value);
                break;
            case 3:
                print_list(head);
                break;
            default:
                printf("Некорректный выбор.\n");
        }
    }

    return 0;
}

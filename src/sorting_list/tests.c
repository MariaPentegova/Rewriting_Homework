#include <stdio.h>
#include <assert.h>
#include "main.c" 

void test_insert_into_empty() {
    Node* head = NULL;
    insert_sorted(&head, 5);
    assert(head != NULL && head->value == 5 && head->next == NULL);
    free_list(head);
}

void test_insert_smaller() {
    Node* head = NULL;
    insert_sorted(&head, 10);
    insert_sorted(&head, 5);
    assert(head != NULL && head->value == 5);
    assert(head->next != NULL && head->next->value == 10);
    free_list(head);
}

void test_insert_larger() {
    Node* head = NULL;
    insert_sorted(&head, 5);
    insert_sorted(&head, 10);
    assert(head != NULL && head->value == 5);
    assert(head->next != NULL && head->next->value == 10);
    free_list(head);
}

void test_insert_multiple() {
    Node* head = NULL;
    insert_sorted(&head, 20);
    insert_sorted(&head, 10);
    insert_sorted(&head, 15);
    insert_sorted(&head, 5);
    // Проверка порядка
    assert(head->value == 5);
    assert(head->next->value == 10);
    assert(head->next->next->value == 15);
    assert(head->next->next->next->value == 20);
    free_list(head);
}

void test_delete_existing() {
    Node* head = NULL;
    insert_sorted(&head, 10);
    insert_sorted(&head, 20);
    delete_value(&head, 10);
    assert(head != NULL && head->value == 20);
    free_list(head);
}

void test_delete_nonexistent() {
    Node* head = NULL;
    insert_sorted(&head, 10);
    delete_value(&head, 999);
    assert(head != NULL && head->value == 10);
    free_list(head);
}

void test_delete_from_empty() {
    Node* head = NULL;
    delete_value(&head, 5);
    assert(head == NULL);
}

void run_tests() {
    printf("Запуск тестов...\n");
    test_insert_into_empty();
    test_insert_smaller();
    test_insert_larger();
    test_insert_multiple();
    test_delete_existing();
    test_delete_nonexistent();
    test_delete_from_empty();
    printf("Все тесты пройдены!\n");
}

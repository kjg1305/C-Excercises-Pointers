#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct Node {
    char data[50];
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode== NULL) {
        printf("Error: memoria no reservada\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode("Karen");
    struct Node* second = createNode("Pedro");
    struct Node* third = createNode("Ana");

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printList(head);

    free(third);
    free(second);
    free(head);
    return 0;
}

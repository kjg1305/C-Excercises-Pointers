#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo
struct Node {
    int data;          // 4 bytes
    struct Node* next; // Puntero al siguiente nodo
};

// Función para crear un nuevo nodo
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: memoria no reservada");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Función para imprimir la lista
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Función para crear una lista de 1000 nodos
struct Node* createLargeList() {
    struct Node* head = createNode(10); // Primer nodo con valor 10
    struct Node* current = head;
    
    // Crear 999 nodos más y enlazarlos
    for (int i = 11; i < 100000000; i++) {
        struct Node* newNode = createNode(i);
        current->next = newNode; // Enlazar el nodo actual con el nuevo
        current = newNode;       // Avanzar al nuevo nodo
    }

    return head;
}

int main() {
    struct Node* head = createLargeList(); // Crear una lista con 1000 nodos

    // Imprimir la lista (puedes comentar esto si solo necesitas crear la lista)
    printList(head);

    // Liberar memoria
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}




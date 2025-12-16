#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Coach {
    char name[10];
    struct Coach* prev;
    struct Coach* next;
};

struct Coach* head = NULL;

// Create a new coach
struct Coach* createCoach(char name[]) {
    struct Coach* newNode = (struct Coach*)malloc(sizeof(struct Coach));
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(char name[]) {
    struct Coach* newNode = createCoach(name);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Coach* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at beginning
void insertBeginning(char name[]) {
    struct Coach* newNode = createCoach(name);

    if (head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Delete a coach
void deleteCoach(char name[]) {
    if (head == NULL) {
        printf("\nTrain Empty!\n");
        return;
    }

    struct Coach* temp = head;

    while (temp != NULL && strcmp(temp->name, name) != 0)
        temp = temp->next;

    if (temp == NULL) {
        printf("\nCoach %s not found!\n", name);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("\nCoach %s removed successfully!\n", name);
}

// Display Forward
void displayForward() {
    if (head == NULL) {
        printf("\nTrain Empty!\n");
        return;
    }

    struct Coach* temp = head;
    struct Coach* t = head;
    int length = 4;
    int i;

    while (t != NULL) {
        length += strlen(t->name);
        if (t->next != NULL)
            length += 6;
        t = t->next;
    }

    printf("\n");
    for (i = 0; i < length; i++) printf("=");
    printf("\n");

    printf("|  ");
    temp = head;
    while (temp != NULL) {
        printf("%s", temp->name);
        if (temp->next != NULL)
            printf("  ->  ");
        temp = temp->next;
    }
    printf("  |\n");

    for (i = 0; i < length; i++) printf("=");
    printf("\n");
}

// Display Backward
void displayBackward() {
    if (head == NULL) {
        printf("\nTrain Empty!\n");
        return;
    }

    struct Coach* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    struct Coach* t = temp;
    int length = 4;
    int i;

    while (t != NULL) {
        length += strlen(t->name);
        if (t->prev != NULL)
            length += 6;
        t = t->prev;
    }

    printf("\n");
    for (i = 0; i < length; i++) printf("=");
    printf("\n");

    printf("|  ");
    while (temp != NULL) {
        printf("%s", temp->name);
        if (temp->prev != NULL)
            printf("  ->  ");
        temp = temp->prev;
    }
    printf("  |\n");

    for (i = 0; i < length; i++) printf("=");
    printf("\n");
}

// ?? DEFAULT TRAIN LAYOUT OPTION
void defaultLayout() {
    head = NULL;  // Clear old train layout

    insertEnd("D1");
    insertEnd("D2");
    insertEnd("S1");
    insertEnd("S2");
    insertEnd("S3");
    insertEnd("B1");
    insertEnd("B2");
    insertEnd("C1");
    insertEnd("A1");
    insertEnd("H1");

    printf("\nDefault Train Layout Created Successfully!\n");
}

int main() {
    int choice;
    char name[10];

    while (1) {
        printf("\n========== TRAIN COACH CONNECTION SIMULATOR ==========\n");
        printf("1. Add Coach at Front\n");
        printf("2. Add Coach at End\n");
        printf("3. Remove Coach\n");
        printf("4. Display Train (Front to Back)\n");
        printf("5. Display Train (Back to Front)\n");
        printf("6. Create Default Train Layout\n");  // ? ADDED
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Coach Name (e.g., D1, S1, B1): ");
                scanf("%s", name);
                insertBeginning(name);
                break;

            case 2:
                printf("\nEnter Coach Name (e.g., D1, S1, B1): ");
                scanf("%s", name);
                insertEnd(name);
                break;

            case 3:
                printf("\nEnter Coach Name to Remove: ");
                scanf("%s", name);
                deleteCoach(name);
                break;

            case 4:
                displayForward();
                break;

            case 5:
                displayBackward();
                break;

            case 6:
                defaultLayout();
                break;

            case 7:
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}


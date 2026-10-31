#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 1024

// Structure representing one memory block
typedef struct Block {
    int start;
    int size;
    int isFree;
    struct Block *next;
} Block;

// Display all memory blocks
void displayMemory(Block *head) {
    Block *current = head;

    printf("\n========== MEMORY STATUS ==========\n");

    while (current != NULL) {
        printf("Start: %4d | Size: %4d | Status: %s\n",
               current->start,
               current->size,
               current->isFree ? "FREE" : "ALLOCATED");

        current = current->next;
    }

    printf("===================================\n");
}

// Allocate memory using First Fit
void allocateMemory(Block *head, int requestedSize) {
    Block *current = head;

    while (current != NULL) {

        // Find the first free block large enough
        if (current->isFree && current->size >= requestedSize) {

            // Split the block if it is larger than required
            if (current->size > requestedSize) {

                Block *newBlock = (Block *)malloc(sizeof(Block));

                if (newBlock == NULL) {
                    printf("Memory allocation failed!\n");
                    return;
                }

                newBlock->start = current->start + requestedSize;
                newBlock->size = current->size - requestedSize;
                newBlock->isFree = 1;
                newBlock->next = current->next;

                current->next = newBlock;
                current->size = requestedSize;
            }

            current->isFree = 0;

            printf("\nMemory allocated successfully!\n");
            printf("Starting address: %d\n", current->start);
            printf("Allocated size: %d\n", current->size);

            return;
        }

        current = current->next;
    }

    printf("\nNo suitable memory block available!\n");
}

// Free a memory block
void freeMemory(Block *head, int startAddress) {
    Block *current = head;

    while (current != NULL) {

        if (current->start == startAddress) {

            if (current->isFree) {
                printf("\nThis memory block is already free.\n");
            } else {
                current->isFree = 1;
                printf("\nMemory block freed successfully!\n");
            }

            return;
        }

        current = current->next;
    }

    printf("\nNo memory block found at address %d.\n", startAddress);
}

// Free all dynamically allocated memory
void cleanupMemory(Block *head) {
    Block *current = head;

    while (current != NULL) {
        Block *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {

    // Create the initial memory block
    Block *head = (Block *)malloc(sizeof(Block));

    if (head == NULL) {
        printf("Failed to initialize memory!\n");
        return 1;
    }

    head->start = 0;
    head->size = MEMSIZE;
    head->isFree = 1;
    head->next = NULL;

    int choice;
    int size;
    int startAddress;

    printf("=====================================\n");
    printf("   MEMORY MANAGEMENT SIMULATOR\n");
    printf("=====================================\n");

    while (1) {

        printf("\n1. Allocate Memory (First Fit)\n");
        printf("2. Free Memory\n");
        printf("3. Display Memory Status\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            break;
        }

        switch (choice) {

            case 1:
                printf("Enter memory size to allocate: ");
                scanf("%d", &size);

                if (size <= 0 || size > MEMSIZE) {
                    printf("Invalid memory size!\n");
                } else {
                    allocateMemory(head, size);
                }

                break;

            case 2:
                printf("Enter starting address to free: ");
                scanf("%d", &startAddress);

                freeMemory(head, startAddress);

                break;

            case 3:
                displayMemory(head);
                break;

            case 4:
                printf("\nExiting Memory Management Simulator...\n");

                cleanupMemory(head);

                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    cleanupMemory(head);

    return 0;
}
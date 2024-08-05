#include <stdio.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        printf("Enter Book ID: ");
        scanf("%d", &library[bookCount].id);
        printf("Enter Book Title: ");
        scanf(" %[^\n]%*c", library[bookCount].title);  // to allow spaces in input
        printf("Enter Book Author: ");
        scanf(" %[^\n]%*c", library[bookCount].author);
        bookCount++;
        printf("Book added successfully!\n");
    } else {
        printf("Library is full!\n");
    }
}

void displayBooks() {
    if (bookCount > 0) {
        printf("ID\tTitle\t\tAuthor\n");
        printf("-----------------------------------\n");
        for (int i = 0; i < bookCount; i++) {
            printf("%d\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author);
        }
    } else {
        printf("No books in the library.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

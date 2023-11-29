// Main file 

#include<stdio.h>
#include<stdlib.h>
#include "book.h"


int main() {
    struct Book database[100];
    int count = 0;
    int choice;
    
    while (1) {
        printf("\n *** Book Management System *** \n");
        printf("\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book by ID\n");
        printf("4. Search Book by Name\n");
        printf("5. Show Author's Books\n");
        printf("6. Update Book Data\n");
        printf("7. Display Top 3 Books\n");
        printf("8. Display All Books\n");
        printf("9. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(database, &count);
                break;
            case 2: {
                int bookID;
                printf("Enter Book ID to remove: ");
                scanf("%d", &bookID);
                removeBook(database, &count, bookID);
                break;
            }
            case 3: {
                int bookID;
                printf("Enter Book ID to search: ");
                scanf("%d", &bookID);
                searchBookByID(database, count, bookID);
                break;
            }
            case 4: {
                char bookName[100];
                printf("Enter Book Name to search: ");
                scanf(" %[^\n]", bookName);
                searchBookByName(database, count, bookName);
                break;
            }
            case 5: {
                char authorName[100];
                printf("Enter Author Name: ");
                scanf(" %[^\n]", authorName);
                showAuthorBooks(database, count, authorName);
                break;
            }
            case 6: {
                int bookID;
                float newPrice, newRating;
                printf("Enter Book ID to update: ");
                scanf("%d", &bookID);
                printf("Enter new Price: ");
                scanf("%f", &newPrice);
                printf("Enter new Rating: ");
                scanf("%f", &newRating);
                updateBookData(database, count, bookID, newPrice, newRating);
                break;
            }
            case 7:
                displayTopBooks(database, count);
                break;
            case 8:
                displayAllBooks(database, count);
                break;
            case 9:
            	printf("Exiting...\n");
                
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                
        }
    }

    return 0;

   
}

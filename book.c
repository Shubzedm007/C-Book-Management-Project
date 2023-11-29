// function definition file 


#include<stdio.h>
#include<stdlib.h>
#include "book.h"
#include<string.h>





void addBook(struct Book database[], int *count) {
    struct Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.book_id);
    printf("Enter Book Name: ");
    scanf(" %[^\n]", newBook.book_name);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", newBook.author_name);
    printf("Enter Price: ");
    scanf("%f", &newBook.price);
    printf("Enter Rating: ");
    scanf("%f", &newBook.rating);

    database[(*count)++] = newBook;
    printf("Book added successfully!\n");
}

// Function to remove a book by Book ID
void removeBook(struct Book database[], int *count, int bookID) {
    int found = 0;
    int i;
    for ( i = 0; i < *count; i++) {
        if (database[i].book_id == bookID) {
        	int j;
            for (j = i; j < *count - 1; j++) {
                database[j] = database[j + 1];
            }
            (*count)--;
            found = 1;
            printf("Book with Book ID %d removed successfully!\n", bookID);
            break;
        }
    }
    if (!found) {
        printf("Book with Book ID %d not found in the database.\n", bookID);
    }
}

// Function to search for a book by Book ID
void searchBookByID(struct Book database[], int count, int bookID) {
    int found = 0 , i;
    for ( i = 0; i < count; i++) {
        if (database[i].book_id == bookID) {
            printf("Book ID: %d\n", database[i].book_id);
            printf("Book Name: %s\n", database[i].book_name);
            printf("Author Name: %s\n", database[i].author_name);
            printf("Price: %.2f\n", database[i].price);
            printf("Rating: %.2f\n", database[i].rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book with Book ID %d not found in the database.\n", bookID);
    }
}

// Function to search for a book by Book Name
void searchBookByName(struct Book database[], int count, const char *bookName) {
    int found = 0,i;
    for ( i = 0; i < count; i++) {
        if (strcmp(database[i].book_name, bookName) == 0) {
            printf("Book ID: %d\n", database[i].book_id);
            printf("Book Name: %s\n", database[i].book_name);
            printf("Author Name: %s\n", database[i].author_name);
            printf("Price: %.2f\n", database[i].price);
            printf("Rating: %.2f\n", database[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("Book with name '%s' not found in the database.\n", bookName);
    }
}

// Function to show all books written by a specific author
void showAuthorBooks(struct Book database[], int count, const char *authorName) {
    int found = 0 , i;
    printf("Books by author %s:\n", authorName);
    for ( i = 0; i < count; i++) {
        if (strcmp(database[i].author_name, authorName) == 0) {
            printf("Book ID: %d\n", database[i].book_id);
            printf("Book Name: %s\n", database[i].book_name);
            printf("Price: %.2f\n", database[i].price);
            printf("Rating: %.2f\n", database[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No books by author '%s' found in the database.\n", authorName);
    }
}

// Function to update the price and rating of a book by Book ID
void updateBookData(struct Book database[], int count, int bookID, float newPrice, float newRating) {
    int found = 0, i;
    for (i = 0; i < count; i++) {
        if (database[i].book_id == bookID) {
            database[i].price = newPrice;
            database[i].rating = newRating;
            printf("Book with Book ID %d updated successfully!\n", bookID);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book with Book ID %d not found in the database.\n", bookID);
    }
}

// Function to display the top 3 books based on price and rating
void displayTopBooks(struct Book database[], int count) {
    if (count < 3) {
        printf("Not enough books in the database to display top 3.\n");
        return;
    }

    printf("Top 3 books based on Price:\n");
    // Sort by price
    int i;
    
    for ( i = 0; i < count - 1; i++) {
    	int j;
        for ( j = 0; j < count - i - 1; j++) {
            if (database[j].price < database[j + 1].price) {
                struct Book temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
            }
        }
    }
    for ( i = 0; i < 3; i++) {
        printf("Book Name: %s, Price: %.2f\n", database[i].book_name, database[i].price);
    }

    printf("Top 3 books based on Rating:\n");
    // Sort by rating
    for ( i = 0; i < count - 1; i++) {
    	int j;
        for ( j = 0; j < count - i - 1; j++) {
            if (database[j].rating < database[j + 1].rating) {
                struct Book temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
            }
        }
    }
    for ( i = 0; i < 3; i++) {
        printf("Book Name: %s, Rating: %.2f\n", database[i].book_name, database[i].rating);
    }
}

// Function to display details of all books in the database
void displayAllBooks(struct Book database[], int count) {
    printf("All books in the database:\n");
    int i;
    for ( i = 0; i < count; i++) {
        printf("Book ID: %d\n", database[i].book_id);
        printf("Book Name: %s\n", database[i].book_name);
        printf("Author Name: %s\n", database[i].author_name);
        printf("Price: %.2f\n", database[i].price);
        printf("Rating: %.2f\n", database[i].rating);
    }
}

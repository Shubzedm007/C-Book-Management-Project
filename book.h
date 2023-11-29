// header file 

#define BOOK_H

// Structure to represent a book
struct Book {
    int book_id;
    char book_name[100];
    char author_name[100];
    float price;
    float rating;
};

// Function declarations
void addBook(struct Book database[], int *count);
void removeBook(struct Book database[], int *count, int bookID);
void searchBookByID(struct Book database[], int count, int bookID);
void searchBookByName(struct Book database[], int count, const char *bookName);
void showAuthorBooks(struct Book database[], int count, const char *authorName);
void updateBookData(struct Book database[], int count, int bookID, float newPrice, float newRating);
void displayTopBooks(struct Book database[], int count);
void displayAllBooks(struct Book database[], int count);

#ifndef LIBRARY_PROTOTYPE_H
#define LIBRARY_PROTOTYPE_H

#include <string>
using namespace std;

#define MAX_SIZE 1000

typedef struct st_book {
    int id;
    int quantity;
    string name;
    int total_borrowed;
} books;

typedef struct st_user {
    int id;
    string name;
} users;

struct who_borrowed_what {
    string book_name;
    string user_name;
};

bool compare_ids(books &book1, books &book2);
bool compare_names(books &book1, books &book2);

void add_book();
void search_books_by_prefix();
void print_who_borrowed_book_by_name();
void print_library_by_ID();
void print_library_by_name();
void add_user();
bool user_borrow_book();
void user_return_book();
void print_users();
void console_based_menu();
void register_borrow_operation(string user_name, string book_name);

#endif // LIBRARY_PROTOTYPE_H

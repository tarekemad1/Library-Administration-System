#include <iostream>
#include <algorithm>
#include "library_prototype.h"
using namespace std;

books book[MAX_SIZE];
int added = 0; // Incrementing iterator tracing the # of books added
users user[MAX_SIZE];
int cnt_usrs = 0; // Incrementing iterator tracing the # of users added
who_borrowed_what WBW[MAX_SIZE];
int cnt_borrowed = 0; // Incrementing iterator tracing the # of books borrowed

bool compare_ids(books &book1, books &book2) {
    return book1.id < book2.id;
}

bool compare_names(books &book1, books &book2) {
    return book1.name < book2.name;
}

void console_based_menu() {
    int choice;
    bool borrow_success;
    while (true) {
        cout << "Enter your menu choice [1 - 10] : " << endl;
        cin >> choice;
        if (choice == 1)
            add_book();
        else if (choice == 2)
            search_books_by_prefix();
        else if (choice == 3)
            print_who_borrowed_book_by_name();
        else if (choice == 4)
            print_library_by_ID();
        else if (choice == 5)
            print_library_by_name();
        else if (choice == 6)
            add_user();
        else if (choice == 7)
            borrow_success = user_borrow_book();
        else if (choice == 8)
            user_return_book();
        else if (choice == 9)
            print_users();
        else if (choice == 10)
            break;
        else
            cout << "Incorrect choice, try again\n";
    }
}

void add_book() {
    cout << "Enter book info: id, name, and quantity" << endl;
    cin >> book[added].id >> book[added].name >> book[added].quantity;
    book[added].total_borrowed = 0;
    added++;
}

void search_books_by_prefix() {
    cout << "Enter book name prefix:" << endl;
    string ip_prefix;
    cin >> ip_prefix;
    for (int i = 0; i < added; i++) {
        if (book[i].name.find(ip_prefix) == 0) {
            cout << book[i].name << endl;
        }
    }
}

void print_who_borrowed_book_by_name() {
    string book_name;
    cout << "Enter the book name:" << endl;
    cin >> book_name;
    for (int i = 0; i < cnt_borrowed; i++) {
        if (WBW[i].book_name == book_name) {
            cout << WBW[i].user_name << endl;
        }
    }
}

void print_library_by_ID() {
    sort(book, book + added, compare_ids);
    for (int i = 0; i < added; i++) {
        cout << "id: " << book[i].id << ", name: " << book[i].name 
             << ", total quantity: " << book[i].quantity 
             << ", total borrowed: " << book[i].total_borrowed << endl;
    }
}

void print_library_by_name() {
    sort(book, book + added, compare_names);
    for (int i = 0; i < added; i++) {
        cout << "id: " << book[i].id << ", name: " << book[i].name 
             << ", total quantity: " << book[i].quantity 
             << ", total borrowed: " << book[i].total_borrowed << endl;
    }
}

void add_user() {
    cout << "Enter User name and National ID: ";
    cin >> user[cnt_usrs].name >> user[cnt_usrs].id;
    cnt_usrs++;
}

void print_users() {
    for (int i = 0; i < cnt_usrs; i++) {
        cout << "Name: " << user[i].name << ", NID: " << user[i].id << endl;
    }
}

bool user_borrow_book() {
    string user_name;
    string book_name;
    bool user_found = false, book_found = false;
    cout << "Enter User name and Book name:" << endl;
    cin >> user_name >> book_name;

    for (int i = 0; i < cnt_usrs; i++) {
        if (user[i].name == user_name) {
            user_found = true;
            break;
        }
    }

    if (!user_found) {
        cout << "User not Found\n";
        return false;
    }

    for (int i = 0; i < added; i++) {
        if (book[i].name == book_name) {
            if (book[i].quantity > 0) {
                book[i].quantity--;
                book[i].total_borrowed++;
                register_borrow_operation(user_name, book_name);
                book_found = true;
                break;
            }
        }
    }

    if (!book_found) {
        cout << "Book not Exist or Out of Stock\n";
        return false;
    }

    return true;
}

void register_borrow_operation(string user_name, string book_name) {
    WBW[cnt_borrowed].book_name = book_name;
    WBW[cnt_borrowed].user_name = user_name;
    cnt_borrowed++;
}

void user_return_book() {
    string user_name;
    string book_name;
    cout << "Enter User name and Book name:" << endl;
    cin >> user_name >> book_name;

    for (int i = 0; i < cnt_borrowed; i++) {
        if (WBW[i].user_name == user_name && WBW[i].book_name == book_name) {
            for (int j = i; j < cnt_borrowed - 1; j++) {
                WBW[j] = WBW[j + 1];
            }
            cnt_borrowed--;

            for (int j = 0; j < added; j++) {
                if (book[j].name == book_name) {
                    book[j].quantity++;
                    book[j].total_borrowed--;
                    break;
                }
            }
            break;
        }
    }
}

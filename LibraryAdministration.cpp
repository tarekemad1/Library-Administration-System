#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX_SIZE 1000;
typedef struct st_book
{
    int id;
    int quantity;
    string name;
    int total_borrowed;
} books;
typedef struct st_user
{
    int id;
    string name;
} users;
struct who_borrowed_what
{
    string book_name;
    string user_name;
};
books book[1000];
int added = 0; // incrementing iterator tracing the #of books added
users user[1000];
int cnt_usrs = 0; // incrementing iterator tracing the #of users added
who_borrowed_what WBW[1000];
int cnt_borrowed = 0; // incrementing iterator tracing the #of books borrowed
bool compare_ids(books &book1, books &book2)
{
    return book1.id < book2.id;
}
bool compare_names(books &book1, books &book2)
{
    return book1.name < book2.name;
}

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
int main()
{
    console_based_menu();
    return 0;
}

void console_based_menu()
{
    int choice;
    bool borrow_success;
    while (true)
    {
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
            cout << "Incorrect choice try again\n";
    }
}
void add_book()
{
    cout << "Enter book info : id & name and quantity" << endl;
    cin >> book[added].id >> book[added].name >> book[added].quantity;
    book[added].total_borrowed = 0;
    added++;
}
void search_books_by_prefix()
{
    cout << "Enter book name prefix:" << endl;
    string ip_prefix;
    cin >> ip_prefix;
    string arr_match[4];
    int cnt = 0;
    for (int i = 0; i < added; i++)
    {
        int checker = 0;
        for (int j = 0; j < ip_prefix.length(); j++)
        {
            if (book[i].name[j] != ip_prefix[j])
                break;
            else
                checker++;
            continue;
        }
        if (checker == ip_prefix.length())
            arr_match[cnt++] = book[i].name;
    }
    for (int i = 0; i < cnt; i++)
        cout << arr_match[i] << endl;
}
void print_who_borrowed_book_by_name()
{
    for (int i = 0; i < cnt_borrowed; i++)
        cout << WBW[i].user_name << " : " << WBW[i].book_name << endl;
}

void print_library_by_ID()
{
    sort(book, book + added, compare_ids);
    for (int i = 0; i < added; i++)
     {
           cout << "id :" << book[i].id << " name : " 
            << book[i].name << " total quantity : " 
            << book[i].quantity << " total borrowed : " 
            << book[i].total_borrowed << endl;
     }
}

void print_library_by_name()
{
    sort(book, book + added, compare_names);
    for (int i = 0; i < added; i++)
    {
        cout << "id :" << book[i].id << " name : " 
            << book[i].name << " total quantity : " 
            << book[i].quantity << " total borrowed : " 
            << book[i].total_borrowed << endl;
    }
}

void add_user()
{
    cout << endl
         << "Enter User name and National ID : ";
    cin >> user[cnt_usrs].name >> user[cnt_usrs].id;
    cnt_usrs++;
}

void print_users()
{
    for (int i = 0; i < cnt_usrs; i++)
        cout << "Name : " << user[i].name << "  NID " << user[i].id << endl;
}


bool user_borrow_book()
{
    string user_name;
    string book_name;
    bool flag0 = 0, flag1 = 0;
    cout << "\nEnter User name and Book name" << endl;
    cin >> user_name >> book_name;
    for (int i = 0; i < cnt_usrs; i++)
    {
        if (user_name != user[i].name)
            continue;
        else
        {
            flag0 = 1;
            break;
        }
    }
    if (!flag0)
    {
        cout << "User not Found\n";
        return 0;
    }
    for (int i = 0; i < added; i++)
    {
        if (book_name != book[i].name)
            continue;
        else
        {
            if (book[i].quantity)
            {
                book[i].quantity--;
                book[i].total_borrowed++;
                register_borrow_operation(user_name, book_name);
                flag1 = 1;
            }
        }
    }
    if (!flag1)
    {
        cout << "\nBook not Exist";
        return 0;
    }
    return 1;
}

void register_borrow_operation(string user_name, string book_name)
{
    WBW[cnt_borrowed].book_name = book_name;
    WBW[cnt_borrowed].user_name = user_name;
    cnt_borrowed++;
}

void user_return_book()
{
    string user_name;
    string book_name;
    int usr_idx;
    cout << "\nEnter User name and Book name" << endl;
    cin >> user_name >> book_name;
    for (int i = 0; i < cnt_borrowed; i++)
    {
        if (user_name != WBW[i].user_name)
            continue;
        else
            usr_idx = i;
        break;
    }
    for (int i = usr_idx; i <= cnt_borrowed; i++)
        WBW[i] = WBW[i + 1];
    for (int i = 0; i < added; i++)
    {
        if (book_name == book[i].name)
        {
            book[i].quantity++;
            book[i].total_borrowed--;
        }
    }
}
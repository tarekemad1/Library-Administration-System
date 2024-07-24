#include <iostream>
using namespace std ;

void add_book(){};
void search_books_by_prefix(){};
void print_who_borrowed_book_by_name(){};
void print_library_by_ID(){};
void print_library_by_name(){};
void add_user(){};
void user_borrow_book(){};
void user_return_book(){};
void print_users(){};
void console_based_menu();

int main(){
    console_based_menu();
    return 0;
}


void console_based_menu(){
    int choice ;
    while(true)
    {
        cout<<"Enter your menu choice [1 - 10] : "<<endl;
        cin>>choice;
        if(choice == 1 )
            add_book();
        else if(choice ==2)
            search_books_by_prefix();
        else if(choice ==3)
            print_who_borrowed_book_by_name();
        else if(choice ==4)
            print_library_by_ID();
        else if(choice==5)
            print_library_by_name();
        else if(choice ==6 )
            add_user();
        else if(choice == 7)
            user_borrow_book();
        else if(choice == 8)
            user_return_book();
        else if(choice ==9)
            print_users();
        else if(choice ==10)
            break;
        else 
            cout<<"Incorrect choice try again\n";
    }
}
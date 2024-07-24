# Library-Administration-System
Overview
The Library Administration System is designed to help manage a library's operations. This includes adding and searching for books, maintaining information about borrowed books, and managing user data. The main user for this system is an admin who can perform various operations through a console-based menu.
Features
Menu Operations
Library Menu:
1. Add Book
2. Search Books by Prefix
3. Print Who Borrowed Book by Name
4. Print Library by ID
5. Print Library by Name
6. Add User
7. User Borrow Book
8. User Return Book
9. Print Users
10. Exit

System Flow:
The system starts with a menu displaying all possible choices.
The admin selects a choice to perform an operation.
After the operation is performed, the main menu is displayed again.
Book Operations
1. Adding a Book: 
Each book has an ID (integer), name, and quantity.
Example: 101, CppHowToProgram, 7
2. Searching for a Book:
Books can be searched using a prefix of the book name.
Examples queries :
Cpp ⇒ CppHowToProgram, CppForDummies, CppForAdvancedLevels
Core ⇒ CoreJava
Listing Books: 
Books can be listed and sorted by either ID or name.
Example entries:
Sorted by name: ArabicLiterature, Math1, Math2
Sorted by ID: Math2, Math1, ArabicLiterature
4. Listing Users Who Borrowed a Book 
Input: Book name (e.g., Math1)
Output: List of user names who borrowed the book (e.g., Mostafa, John, Mark, Ali)
User Operations 
1. Add a User: 
Each user has an ID (integer) and name.
Additional information (e.g., email, address) can be added.
2. Borrow a Book: 
A user can borrow a book if the quantity is greater than 0.
The system will decrease the book quantity by 1 and mark the user as having borrowed the book.
3. Return a Book: 
A user can return a book, which will increase the book quantity by 1 and mark the user as having returned the book.
4. Additional User Features:
List system users, ordered by name or ID.
List borrowed books of a specific user.



















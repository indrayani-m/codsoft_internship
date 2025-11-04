#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Book{
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;
    time_t borrowDate;  

public:
    Book(const string& t, const string& a, const string& i, bool isA = true){
        title = t;
        author = a;
        isbn = i;
        isAvailable = isA;
        borrowDate = 0;
    }

    friend class Library;
    void display() const{
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

class Library{
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author, const string& isbn){
        books.push_back(Book(title, author, isbn));
        cout << "Book added successfully!\n";
    }

    void borrowBook(const string& isbn){
        for (int i = 0; i < books.size(); i++){
            if (books[i].isbn == isbn) {
                if (books[i].isAvailable) {
                    books[i].isAvailable = false;
                    books[i].borrowDate = time(0); // record borrow time
                    cout << "Book borrowed successfully!\n";
                } else {
                    cout << "Book is already borrowed.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(const string& isbn){
        for (int i = 0; i < books.size(); i++){
            if (books[i].isbn == isbn) {
                if (!books[i].isAvailable){
                    // Fine Calculation
                    time_t now = time(0);
                    double seconds = difftime(now, books[i].borrowDate);
                    int days = seconds / (60 * 60 * 24);
                    if (days > 7){
                        int fine = (days - 7) * 5; // ₹5 per day after 7 days
                        cout << "Book returned after " << days 
                             << " days. Fine: ₹" << fine << endl;
                    } else{
                        cout << "Book returned on time. No fine.\n";
                    }

                    books[i].isAvailable = true;
                    books[i].borrowDate = 0;
                } else{
                    cout << "Book is already available.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void searchBook(const string& keyword) const{
        bool found = false;
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title.find(keyword) != string::npos ||
                books[i].author.find(keyword) != string::npos ||
                books[i].isbn.find(keyword) != string::npos) {
                books[i].display();
                found = true;
            }
        }
        if(!found)
            cout << "No matching books found.\n";
    }

    void displayBooks() const{
        cout << "\nAvailable Books:\n";
        for (int i = 0; i < books.size(); i++){
            if (books[i].isAvailable){
                books[i].display();
            }
        }
    }
};

int main() {
    Library l;
    int choice;
    string title, author, isbn, keyword;

    while (1) {
        cout << "\n==== Library Management System ====\n";
        cout << "1. Add a book\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Display available books\n";
        cout << "5. Search a book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                l.addBook(title, author, isbn);
                break;

            case 2:
                cout << "Enter ISBN to borrow: ";
                getline(cin, isbn);
                l.borrowBook(isbn);
                break;

            case 3:
                cout << "Enter ISBN to return: ";
                getline(cin, isbn);
                l.returnBook(isbn);
                break;

            case 4:
                l.displayBooks();
                break;

            case 5:
                cout << "Enter title/author/ISBN to search: ";
                getline(cin, keyword);
                l.searchBook(keyword);
                break;

            case 6:
                exit(0);
                break;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
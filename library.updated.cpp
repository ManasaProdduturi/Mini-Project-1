#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// --- Step 1: Define the Book Structure ---
class Book {
public:
    int id;
    string title;
    string author;

    Book(int i, string t, string a) : id(i), title(t), author(a) {}

    void display() const {
        cout << "  ID: " << id << " | Title: " << title << " | Author: " << author << endl;
    }
};

// --- Step 2: File Handling (Persistence) ---
void saveToFile(const vector<Book>& library) {
    ofstream outFile("library_data.txt");
    for (const auto& b : library) {
        // Using '|' as a delimiter to handle titles with spaces
        outFile << b.id << "|" << b.title << "|" << b.author << endl;
    }
    outFile.close();
}

void loadFromFile(vector<Book>& library) {
    ifstream inFile("library_data.txt");
    if (!inFile) return; // No file yet, start with empty library

    string line, title, author;
    int id;
    
    // Read ID, skip delimiter, read Title until next delimiter, read Author
    while (inFile >> id) {
        inFile.ignore(); // skip the '|'
        getline(inFile, title, '|');
        getline(inFile, author);
        if (!title.empty()) {
            library.push_back(Book(id, title, author));
        }
    }
    inFile.close();
}

// --- Step 3: Library Operations ---
void addBook(vector<Book>& library) {
    int id;
    string title, author;
    cout << "\nEnter Book ID (Numeric): ";
    cin >> id;
    cin.ignore(); // Clear buffer
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);

    library.push_back(Book(id, title, author));
    cout << ">> Book added successfully!\n";
}

void deleteBook(vector<Book>& library) {
    int idToDelete;
    cout << "\nEnter ID of the book to delete: ";
    cin >> idToDelete;

    // Using an iterator to find and remove the book
    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->id == idToDelete) {
            library.erase(it);
            cout << ">> Book ID " << idToDelete << " has been removed.\n";
            return;
        }
    }
    cout << ">> Error: Book ID not found.\n";
}

void showLibrary(const vector<Book>& library) {
    if (library.empty()) {
        cout << "\n>> The library is currently empty.\n";
        return;
    }
    cout << "\n--- Current Library Inventory ---\n";
    for (const auto& b : library) {
        b.display();
    }
    cout << "---------------------------------\n";
}

// --- Step 4: Main Controller ---
int main() {
    vector<Book> library;
    loadFromFile(library);

    int choice = 0;
    while (choice != 4) {
        cout << "\n==== MINI LIBRARY SYSTEM ====";
        cout << "\n1. Add New Book";
        cout << "\n2. View All Books";
        cout << "\n3. Delete a Book";
        cout << "\n4. Save and Exit";
        cout << "\nSelect Option: ";
        
        if (!(cin >> choice)) { // Handle non-numeric input
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: addBook(library); break;
            case 2: showLibrary(library); break;
            case 3: deleteBook(library); break;
            case 4: 
                saveToFile(library);
                cout << "Data saved to 'library_data.txt'. Exiting...\n";
                break;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
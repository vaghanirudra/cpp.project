#include <iostream>

using namespace std;

const int MAX_ITEMS = 100;

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

protected:
    bool isCheckedOut;

public:
    LibraryItem(string t, string a, string d)
    {
        title = t;
        author = a;
        dueDate = d;
        isCheckedOut = false;
    }

    string getTitle() const
    {
        return title;
    }

    string getAuthor() const
    {
        return author;
    }

    string getDueDate() const
    {
        return dueDate;
    }

    void setTitle(string newTitle)
    {
        title = newTitle;
    }

    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }

    void setDueDate(string newDueDate)
    {
        dueDate = newDueDate;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
private:
    string isbn;

public:
    Book(string t, string a, string d, string i)
        : LibraryItem(t, a, d)
    {
        isbn = i;
    }

    void checkOut() override
    {
        if (!isCheckedOut)
        {
            isCheckedOut = true;
            cout << "Book Checked Out Successfully.\n";
        }
        else
        {
            cout << "Book Already Checked Out.\n";
        }
    }

    void returnItem() override
    {
        if (isCheckedOut)
        {
            isCheckedOut = false;
            cout << "Book Returned Successfully.\n";
        }
        else
        {
            cout << "Book Was Not Checked Out.\n";
        }
    }

    void displayDetails() const override
    {
        cout << "\n===== BOOK DETAILS =====\n";
        cout << "Title    : " << getTitle() << endl;
        cout << "Author   : " << getAuthor() << endl;
        cout << "Due Date : " << getDueDate() << endl;
        cout << "ISBN     : " << isbn << endl;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d)
    {
        duration = dur;
    }

    void checkOut() override
    {
        cout << "DVD Checked Out Successfully.\n";
    }

    void returnItem() override
    {
        cout << "DVD Returned Successfully.\n";
    }

    void displayDetails() const override
    {
        cout << "\n===== DVD DETAILS =====\n";
        cout << "Title      : " << getTitle() << endl;
        cout << "Author     : " << getAuthor() << endl;
        cout << "Due Date   : " << getDueDate() << endl;
        cout << "Duration   : " << duration << " Minutes\n";
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d)
    {
        issueNumber = issue;
    }

    void checkOut() override
    {
        cout << "Magazine Checked Out Successfully.\n";
    }

    void returnItem() override
    {
        cout << "Magazine Returned Successfully.\n";
    }

    void displayDetails() const override
    {
        cout << "\n===== MAGAZINE DETAILS =====\n";
        cout << "Title        : " << getTitle() << endl;
        cout << "Author       : " << getAuthor() << endl;
        cout << "Due Date     : " << getDueDate() << endl;
        cout << "Issue Number : " << issueNumber << endl;
    }
};

int main()
{
    LibraryItem* libraryItems[MAX_ITEMS];

    int count = 0;
    int choice;

    do
    {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Add DVD\n";
        cout << "3. Add Magazine\n";
        cout << "4. Display All Items\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";

        cin >> choice: ";
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid Input!\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
        {
            string title, author, dueDate, isbn;

            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "Enter Due Date: ";
            getline(cin, dueDate);

            cout << "Enter ISBN: ";
            getline(cin, isbn);

            libraryItems[count++] =
                new Book(title, author, dueDate, isbn);

            cout << "Book Added Successfully!\n";

            break;
        }

        case 2:
        {
            string title, author, dueDate;
            int duration;

            cout << "Enter DVD Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "Enter Due Date: ";
            getline(cin, dueDate);

            cout << "Enter Duration: ";
            cin >> duration;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            libraryItems[count++] =
                new DVD(title, author, dueDate, duration);

            cout << "DVD Added Successfully!\n";

            break;
        }

        case 3:
        {
            string title, author, dueDate;
            int issue;

            cout << "Enter Magazine Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "Enter Due Date: ";
            getline(cin, dueDate);

            cout << "Enter Issue Number: ";
            cin >> issue;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            libraryItems[count++] =
                new Magazine(title, author, dueDate, issue);

            cout << "Magazine Added Successfully!\n";

            break;
        }

        case 4:
        {
            if (count == 0)
            {
                cout << "No Items Available.\n";
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    cout << "\nItem ID: " << i << endl;
                    libraryItems[i]->displayDetails();
                }
            }

            break;
        }

        case 5:
        {
            cout << "Program Exited.\n";
            break;
        }

        default:
        {
            cout << "Invalid Choice!\n";
        }
        }

    } while (choice != 5);

    for (int i = 0; i < count; i++)
    {
        delete libraryItems[i];
    }
}

/*
	output
	
	========== LIBRARY MANAGEMENT SYSTEM ==========
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Exit
Enter Choice: 1
Enter Book Title: sapanose safalata tak ki sidi
Enter Author: dhyey kakadiya
Enter Due Date: 2 4 2026
Enter ISBN: 6246666
Book Added Successfully!

========== LIBRARY MANAGEMENT SYSTEM ==========
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Exit
Enter Choice: 2
Enter DVD Title: sucses jourany
Enter Author: bhano 
Enter Due Date: 3 5 2026
Enter Duration: 444
DVD Added Successfully!

========== LIBRARY MANAGEMENT SYSTEM ==========
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Exit
Enter Choice: 3
Enter Magazine Title: rich dad poor dad
Enter Author: robot d. kiyosaki
Enter Due Date: 3 5 2026
Enter Issue Number: 55435646
Magazine Added Successfully!

========== LIBRARY MANAGEMENT SYSTEM ==========
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Exit
Enter Choice: 4

Item ID: 0

===== BOOK DETAILS =====
Title    : sapanose safalata tak ki sidi
Author   : dhyey kakadiya
Due Date : 2 4 2026
ISBN     : 6246666

Item ID: 1

===== DVD DETAILS =====
Title      : sucses jourany
Author     : bhano
Due Date   : 3 5 2026
Duration   : 444 Minutes

Item ID: 2

===== MAGAZINE DETAILS =====
Title        : rich dad poor dad
Author       : robot d. kiyosaki
Due Date     : 3 5 2026
Issue Number : 55435646

========== LIBRARY MANAGEMENT SYSTEM ==========
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Exit
Enter Choice: 5
Program Exited.

--------------------------------
Process exited after 147.9 seconds with return value 0
Press any key to continue . . .

*/

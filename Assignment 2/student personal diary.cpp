#include <iostream>
#include <string>

using namespace std;

const int Max = 20;

string title[Max];
string content[Max];

string username = "";
string password = "";

int totalEntries = 0;

void registerAccount()
{
    cout << "\nRegister\n";

    cout << "Enter Username: ";
    getline(cin, username);

    if (username == "")
    {
        cout << "Username cannot be empty.\n";
        return;
    }

    cout << "Enter Password: ";
    getline(cin, password);

    if (password == "")
    {
        cout << "Password cannot be empty.\n";
        return;
    }

    cout << "Account Created.\n";
}

bool login()
{
    string user;
    string pass;

    cout << "\nLogin\n";

    cout << "Username: ";
    getline(cin, user);

    cout << "Password: ";
    getline(cin, pass);

    if (user == username && pass == password)
    {
        cout << "Login Success.\n";
        return true;
    }

    cout << "Wrong Username or Password.\n";
    return false;
}

void addNote()
{
    if (totalEntries >= Max)
    {
        cout << "Diary is full.\n";
        return;
    }

    cout << "\nAdd Diary\n";

    cout << "Title: ";
    getline(cin, title[totalEntries]);

    if (title[totalEntries] == "")
    {
        cout << "Title cannot be empty.\n";
        return;
    }

    cout << "Content: ";
    getline(cin, content[totalEntries]);

    totalEntries++;

    cout << "Diary Added.\n";
}

void showNotes()
{
    if (totalEntries == 0)
    {
        cout << "\nNo diaries found.\n";
        return;
    }

    cout << "\nDiary List\n";

    for (int i = 0; i < totalEntries; i++)
    {
        cout << i + 1 << ". " << title[i] << endl;
    }
}

void readNote()
{
    if (totalEntries == 0)
    {
        cout << "\nNo diaries found.\n";
        return;
    }

    int num;

    showNotes();

    cout << "\nEnter diary number: ";
    cin >> num;
    cin.ignore();

    if (num < 1 || num > totalEntries)
    {
        cout << "Invalid number.\n";
        return;
    }

    cout << "\nTitle: " << title[num - 1] << endl;
    cout << "Content: " << content[num - 1] << endl;
}

void updateNote()
{
    if (totalEntries == 0)
    {
        cout << "\nNo diaries found.\n";
        return;
    }

    int num;

    showNotes();

    cout << "\nEnter diary number: ";
    cin >> num;
    cin.ignore();

    if (num < 1 || num > totalEntries)
    {
        cout << "Invalid number.\n";
        return;
    }

    cout << "New Title: ";
    getline(cin, title[num - 1]);

    if (title[num - 1] == "")
    {
        cout << "Title cannot be empty.\n";
        return;
    }

    cout << "New Content: ";
    getline(cin, content[num - 1]);

    cout << "Diary Updated.\n";
}

void removeNote()
{
    if (totalEntries == 0)
    {
        cout << "\nNo diaries found.\n";
        return;
    }

    int num;

    showNotes();

    cout << "\nEnter diary number: ";
    cin >> num;
    cin.ignore();

    if (num < 1 || num > totalEntries)
    {
        cout << "Invalid number.\n";
        return;
    }

    for (int i = num - 1; i < totalEntries - 1; i++)
    {
        title[i] = title[i + 1];
        content[i] = content[i + 1];
    }

    totalEntries--;

    cout << "Diary Deleted.\n";
}

void clearNotes()
{
    if (totalEntries == 0)
    {
        cout << "\nNo diaries found.\n";
        return;
    }

    char choice;

    cout << "\nDelete all diaries? (Y/N): ";
    cin >> choice;
    cin.ignore();

    if (choice == 'Y' || choice == 'y')
    {
        totalEntries = 0;
        cout << "All Diaries Deleted.\n";
    }
}

void menu()
{
    int choice = 0;

    while (choice != 7)
    {
        cout << "\nStudent Diary\n";
        cout << "1. Add Diary\n";
        cout << "2. Show Diaries\n";
        cout << "3. Read Diary\n";
        cout << "4. Edit Diary\n";
        cout << "5. Delete Diary\n";
        cout << "6. Delete All Diaries\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            addNote();
            break;

        case 2:
            showNotes();
            break;

        case 3:
            readNote();
            break;

        case 4:
            updateNote();
            break;

        case 5:
            removeNote();
            break;

        case 6:
            clearNotes();
            break;

        case 7:
            cout << "Program Closed.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }
    }
}

int main()
{
    int choice;
    bool loggedIn = false;

    while (!loggedIn)
    {
        cout << "\nStudent Diary\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            registerAccount();
            break;

        case 2:
            if (username == "")
            {
                cout << "Please register first.\n";
            }
            else
            {
                loggedIn = login();
            }
            break;

        case 3:
            cout << "Program Closed.\n";
            return 0;

        default:
            cout << "Invalid Choice.\n";
        }
    }

    menu();

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string data;
    bool complete;
    Node *next;

    Node(string d) : data(d), complete(false), next(nullptr) {}
};

class TodoList
{
public:
    Node *head;

    TodoList()
    {
        head = nullptr;
    }

    void Add(string item)
    {
        Node *newNode = new Node(item);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void RemoveLast()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot remove." << endl;
            return;
        }
        Node *curr = head;
        Node *prev = nullptr;
        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev != nullptr)
        {
            prev->next = nullptr;
            delete curr;
        }
        else
        {
            delete head;
            head = nullptr;
        }
        cout << "Last node removed." << endl;
    }

    void RemoveMiddle(int n)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot remove." << endl;
            return;
        }

        Node *curr = head;
        Node *prev = nullptr;
        int count = 0;

        while (curr != nullptr && count != n)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr == nullptr)
        {
            cout << "Node at position " << n << " not found." << endl;
            return;
        }

        if (prev != nullptr)
        {
            prev->next = curr->next;
            delete curr;
            cout << "Node at position " << n << " removed." << endl;
        }
        else
        {
            head = head->next;
            delete curr;
            cout << "Node at position " << n << " removed." << endl;
        }
    }

    void Display()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " - " << (curr->complete ? "Complete" : "Pending") << endl;
            curr = curr->next;
        }
        cout << endl;
    }

    void MarkTasks()
    {
        if (head == nullptr)
        {
            cout << "Todo list is empty." << endl;
            return;
        }

        Node *curr = head;
        while (curr != nullptr)
        {
            int ans;
            cout << "Mark " << curr->data << " as done? (0 -> No or 1 -> Yes): ";
            cin >> ans;

            switch (ans)
            {
            case 0:
                curr->complete = false;
                cout << curr->data << " marked as pending " << endl;
                break;
            case 1:
                curr->complete = true;
                cout << curr->data << " marked as completed " << endl;
                break;
            default:
                cout << "Invalid input. Please enter 0 or 1." << endl;
                break;
            }
            curr = curr->next; // Move to the next node
        }
    }
};

int main()
{
    TodoList myList;
    int choice;

    // Interactive menu
    do
    {
        cout << "Menu:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Mark tasks" << endl;
        cout << "3. Display tasks" << endl;
        cout << "4. Remove last task" << endl;
        cout << "5. Remove task at position" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string task;
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, task);
            myList.Add(task);
            break;
        }
        case 2:
            myList.MarkTasks();
            break;
        case 3:
            cout << "List of tasks:" << endl;
            myList.Display();
            break;
        case 4:
            myList.RemoveLast();
            break;
        case 5:
        {
            int position;
            cout << "Enter position: ";
            cin >> position;
            myList.RemoveMiddle(position);
            break;
        }
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}

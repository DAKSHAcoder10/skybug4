
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task { string description; bool completed; };

int main() {
    vector<Task> tasks;
    char choice;

    do {
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': { string description; cout << "Enter task description: "; cin.ignore(); getline(cin, description); tasks.push_back({description, false}); break; }
            case '2': for (int i = 0; i < tasks.size(); ++i) cout << i+1 << ". " << tasks[i].description << " - " << (tasks[i].completed ? "Completed" : "Pending") << endl; break;
            case '3': { int index; cout << "Enter the index of the task to mark as completed: "; cin >> index; if (index > 0 && index <= tasks.size()) tasks[index-1].completed = true; break; }
            case '4': { int index; cout << "Enter the index of the task to remove: "; cin >> index; if (index > 0 && index <= tasks.size()) tasks.erase(tasks.begin() + index-1); break; }
            case '5': cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != '5');

    return 0;
}



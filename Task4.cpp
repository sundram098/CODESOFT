#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();          
    getline(cin, desc);
    tasks.push_back({desc, false});
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markCompleted() {
    int num;
    viewTasks();
    cout << "Enter task number to mark as completed: ";
    cin >> num;
    if (num > 0 && num <= tasks.size()) {
        tasks[num - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask() {
    int num;
    viewTasks();
    cout << "Enter task number to remove: ";
    cin >> num;
    if (num > 0 && num <= tasks.size()) {
        tasks.erase(tasks.begin() + num - 1);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting To-Do List. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

// Function to add a task
void addTask() {
    Task newTask;

    cout << "\nEnter task: ";
    cin.ignore();
    getline(cin, newTask.description);

    newTask.completed = false;
    tasks.push_back(newTask);

    cout << "Task added successfully!\n";
}

// Function to view tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n----- TO-DO LIST -----\n";

    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". "
             << tasks[i].description
             << " ["
             << (tasks[i].completed ? "Completed" : "Pending")
             << "]\n";
    }
}

// Function to mark a task as completed
void markCompleted() {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    viewTasks();

    int taskNumber;
    cout << "\nEnter task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber >= 1 &&
        taskNumber <= static_cast<int>(tasks.size())) {

        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Function to remove a task
void removeTask() {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    viewTasks();

    int taskNumber;
    cout << "\nEnter task number to remove: ";
    cin >> taskNumber;

    if (taskNumber >= 1 &&
        taskNumber <= static_cast<int>(tasks.size())) {

        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== TO-DO LIST MANAGER =====\n";
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
                cout << "\nThank you for using the To-Do List Manager!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
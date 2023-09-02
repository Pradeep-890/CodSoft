#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a new task to the list
void AddTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

// Function to view tasks with their status
void ViewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << (i + 1) << ". ";
            if (tasks[i].completed) {
                cout << "[Completed] ";
            }
            cout << tasks[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void MarkAsCompleted(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed: " << tasks[index - 1].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task from the list
void RemoveTask(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        cout << "Task removed: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;
    string description; // Declare description outside of the switch

    while (true) {
        cout << "\nTO-DO LIST SETUP" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Clear the input buffer
                cout << "Enter task description: ";
                getline(cin, description); // Assign a value to description
                AddTask(tasks, description);
                break;
            case 2:
                ViewTasks(tasks);
                break;
            case 3:
                cout << "Enter the task number to mark as completed: ";
                int markIndex;
                cin >> markIndex;
                MarkAsCompleted(tasks, markIndex);
                break;
            case 4:
                cout << "Enter the task number to remove: ";
                int removeIndex;
                cin >> removeIndex;
                RemoveTask(tasks, removeIndex);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

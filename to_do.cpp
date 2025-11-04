#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task{

    string description;
    bool done;

public:
    Task(string desc){
        description=desc;
        done=false;
    }

    string getDescription() const{
        return description;
    }

    bool isDone() const{
        return done;
    }

    void markAsDone(){
        done=true;
    }
};

class ToDoList{
private:
    vector<Task>t;

public:
    void addTask(const string &desc){
        t.push_back(Task(desc));
        cout <<"Task added successfully!\n";
    }

    void viewTasks(){
        if (t.empty()) {
            cout <<"No tasks available!\n";
            return;
        }

        cout << "\n--- To-Do List ---\n";
        for(int i=0;i<t.size();i++){
            cout << i + 1 << ". " << t[i].getDescription()
                 << " [" << (t[i].isDone() ? "Completed" : "Pending") << "]\n";
        }
    }

    void markCompleted(int index){
        if (index < 1 || index > t.size()) {
            cout << "Invalid task number!\n";
            return;
        }
        t[index - 1].markAsDone();
        cout << "Task marked as completed!\n";
    }

    void removeTask(int index) {
        if (index < 1 || index > t.size()){
            cout << "Invalid task number!\n";
            return;
        }
        t.erase(t.begin() + (index - 1));
        cout << "Task removed successfully!\n";
    }
};

int main() {
    ToDoList todo;
    int choice;
    string desc;
    int index;

    while (true) {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear buffer

        switch (choice) {
        case 1:
            cout << "Enter task description: ";
            getline(cin, desc);
            todo.addTask(desc);
            break;
        case 2:
            todo.viewTasks();
            break;
        case 3:
            cout << "Enter task number to mark as Done: ";
            cin >> index;
            todo.markCompleted(index);
            break;
        case 4:
            cout << "Enter task number to remove: ";
            cin >> index;
            todo.removeTask(index);
            break;
        case 5:
            cout<<"Thank you for using our To-Do App!\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

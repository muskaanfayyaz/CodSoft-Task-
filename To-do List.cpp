#include <iostream>
using namespace std;
#include <string>


const int MAX_TASKS = 100; // Maximum number of tasks

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};


// Function to add a task to To-do List
void addTask(Task tasks[], int &taskCount, const string &description){
   if (taskCount < MAX_TASKS)	{
   	tasks[taskCount].description = description;
   	tasks[taskCount].completed = false;
   	++taskCount;
   	cout<< "Task Added successfully. "<< endl;
   }
   else {
   	cout<< "Cannot add task. Task list is full. "<<endl;
   }
}



// Function to view all tasks
void viewTasks(const Task tasks[], int taskCount) {
    cout << "Tasks:" << endl;
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". " << tasks[i].description << " - ";
        if (tasks[i].completed) {
            cout << "Completed" << endl;
        } else {
            cout << "Pending" << endl;
        }
    }
}


// Function to mark a task as completed
void markCompleted(Task tasks[], int taskCount, int index){
    if (index>=1 && index <=taskCount) {
    	tasks[index-1].completed = true;
    	cout << "Task marked as completed." << endl;
	}
	else {
		cout << "Invalid task index. "<< endl;
	}
}


// Function to remove a task
void removeTask(Task tasks[], int &taskCount, int index) {
    if (index >= 1 && index <= taskCount) {
        for (int i = index - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        --taskCount;
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main(){
	Task tasks[MAX_TASKS]; // Array to store tasks
    int taskCount = 0; // Current number of tasks
    int choice;
    string description;
    int index;

    do {
    	cout<<"...........Welcome To TO-DO list..........."<<"\n";
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                addTask(tasks, taskCount, description);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                cout << "Enter index of task to mark as completed: ";
                cin >> index;
                markCompleted(tasks, taskCount, index);
                break;
            case 4:
                cout << "Enter index of task to remove: ";
                cin >> index;
                removeTask(tasks, taskCount, index);
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please try again.";
        }
    } while (choice != 5);

    return 0;
}
	


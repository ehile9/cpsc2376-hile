#include <iostream>
#include <list>
#include <string>
#include <limits>

int main() {
    std::list<std::string> tasks;

    while (true) 
    {
        std::cout << "1. Add Task\n"
            << "2. Remove Task\n"
            << "3. Show Tasks\n"
            << "4. Exit\n"
            << "Choice: ";

        int choice;
        if (!(std::cin >> choice))
            break;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) 
        {
        case 1: 
        {
            std::cout << "Enter task: ";
            std::string task;
            std::getline(std::cin, task);
            tasks.push_back(task);
            std::cout << "Task added!\n\n";
            break;
        }
        case 2: 
        {
            if (tasks.empty()) 
            {
                std::cout << "No tasks to remove.\n\n";
                break;
            }
            std::cout << "Enter task number to remove: ";
            size_t num;
            std::cin >> num;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (num >= 1 && num <= tasks.size()) 
            {
                auto it = tasks.begin();
                std::advance(it, num - 1);
                tasks.erase(it);
                std::cout << "Task removed!\n\n";
            }
            else 
            {
                std::cout << "Invalid task number.\n\n";
            }
            break;
        }
        case 3: 
        {
            std::cout << "Tasks:\n";
            if (tasks.empty()) 
            {
                std::cout << "(none)\n";
            }
            else 
            {
                size_t idx = 1;
                for (const auto& t : tasks) 
                {
                    std::cout << idx++ << ". " << t << "\n";
                }
            }
            std::cout << "\n";
            break;
        }
        case 4:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice.\n\n";
            break;
        }
    }

    return 0;
}

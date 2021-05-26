#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <utility> // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
#include <iostream>

class Employee {
    public:
        std::string firstName;
        std::string lastName;
        std::string id;
        std::string position;
};

void viewEmployeeInfo() {
    // Create an input filestream
    std::ifstream directoryFile("directory.csv");
    std::vector<Employee> employees;
    std::string line;

    // Make sure the file is open
    if(!directoryFile.is_open()) throw std::runtime_error("Could not open file");

    // Read data, line by line
    while(std::getline(directoryFile, line))
    {
        Employee newEmployee;

        // Create a stringstream of the current line
        std::stringstream ss(line);
        std::getline(ss, newEmployee.lastName, ',');
        std::getline(ss, newEmployee.firstName, ',');
        std::getline(ss, newEmployee.id, ',');
        std::getline(ss, newEmployee.position, ',');

        employees.push_back(newEmployee);
    }

    int count = 1;
    for (auto & employee : employees) {
        std::cout << "Employee #" << count << " "
            << employee.firstName << " " << employee.lastName << ".\n";
        count++;
    }

    int choice;
    do {
        std::cout << "Please enter employee # for full information.\n"
            "Enter 0 to exit back to main menu.\n"
            "> ";
        std::cin >> choice;

        std::cout << "Employee #" << choice << ":\n";
        std::cout << "First Name: " << employees[choice-1].firstName << std::endl;
        std::cout << "Last Name: " << employees[choice-1].lastName << std::endl;
        std::cout << "ID: " << employees[choice-1].id << std::endl;
        std::cout << "Position: " << employees[choice-1].position << std::endl;
        std::cout << std::endl;
    } while (choice != 0);
    

    // Close file
    directoryFile.close();

    std::cout << "ViewInfoFunc\n";
}

int main() {
    std::string menu = "Welcome to the directory database.\n"
        "Please select from the following options:\n"
        "0. Exit\n"
        "1. Enter employee information\n"
        "2. Edit employee information\n"
        "3. View employee information\n";

    int choice;

    do {
        std::cout << menu;
        std::cout << "> ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Option 1 selected\n";
                break;
            case 2:
                std::cout << "Option 2 selected\n";
                break;
            case 3:
                viewEmployeeInfo();
                break;
        }
    } while (choice != 0);

    return 0;
}
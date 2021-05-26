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

std::vector<Employee> getEmployeeData() {
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

    directoryFile.close();

    return employees;
}

void addEmployeeInfo() {
    char choice;
    Employee newEmployee;

    do {
        std::cout << "Enter new employee information:\n";
        std::cout << "First Name: ";
        std::cin >> newEmployee.firstName;
        std::cout << "Last Name: ";
        std::cin >> newEmployee.lastName;
        std::cout << "ID: ";
        std::cin >> newEmployee.id;
        std::cout << "Position: ";
        std::cin.ignore(256,'\n');
        std::getline (std::cin, newEmployee.position);

        std::cout << "\nWould you like you add a new employee? (y/n): ";
        std::cin >> choice;
        std::cout << std::endl;
    } while (choice != 'n');

    // file pointer
    std::fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("directory.csv", std::ios::out | std::ios::app);

    fout << newEmployee.firstName << ',';
    fout << newEmployee.lastName << ',';
    fout << newEmployee.id << ',';
    fout << newEmployee.position << '\n';

    fout.close();
}

void deleteEmployeeInfo() {
    std::vector<Employee> employees = getEmployeeData();

    int choice;
    int count = 1;
    do {
        for (auto & employee : employees) {
            std::cout << "Employee #" << count << " "
                << employee.firstName << " " << employee.lastName << ".\n";
            count++;
        }

        std::cout << "Please enter employee # you would like to delete.\n"
            "Enter 0 to exit back to main menu: ";
        std::cin >> choice;
        std::cout << std::endl;

        if (choice > 0) {
            employees.erase( employees.begin() + (choice - 1) );
            count --;
            std::cout << "count:" << count << std::endl;
        }
    } while (choice != 0);

    // removing the existing file
    remove("directory.csv");

    // file pointer
    std::fstream fout;
  
    // opens an existing csv file or creates a new file.
    fout.open("directory.csv", std::ios::out | std::ios::app);

    for (int i = 0; i < count; i++) {
        fout << employees[i].firstName << ',';
        fout << employees[i].lastName << ',';
        fout << employees[i].id << ',';
        fout << employees[i].position << '\n';
    }

    fout.close();
}

void viewEmployeeInfo() {
    std::vector<Employee> employees = getEmployeeData();
    int count = 1;
    for (auto & employee : employees) {
        std::cout << "Employee #" << count << " "
            << employee.firstName << " " << employee.lastName << ".\n";
        count++;
    }

    int choice;
    do {
        std::cout << "\nPlease enter employee # for full information.\n"
            "Enter 0 to exit back to main menu.\n"
            "> ";
        std::cin >> choice;
        
        if (choice > 0) {
            std::cout << "Employee #" << choice << ":\n";
            std::cout << "First Name: " << employees[choice-1].firstName << std::endl;
            std::cout << "Last Name: " << employees[choice-1].lastName << std::endl;
            std::cout << "ID: " << employees[choice-1].id << std::endl;
            std::cout << "Position: " << employees[choice-1].position << std::endl;
        }
    } while (choice != 0);

    std::cout << std::endl;
}

int main() {
    std::string menu = "Welcome to the directory database.\n"
        "Please select from the following options:\n"
        "0. Exit\n"
        "1. Enter employee information\n"
        "2. Delete employee information\n"
        "3. View employee information\n";

    int choice;

    do {
        std::cout << menu;
        std::cout << "> ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                addEmployeeInfo();
                break;
            case 2:
                deleteEmployeeInfo();
                break;
            case 3:
                viewEmployeeInfo();
                break;
        }
    } while (choice != 0);

    return 0;
}
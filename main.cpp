#include <iostream>

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
                std::cout << "Option 3 selected\n";
                break;
        }
    } while (choice != 0);

    return 0;
}


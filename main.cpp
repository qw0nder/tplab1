#include "Keeper.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"
#include <iostream>
#include <limits>

void showMenu() {
    std::cout << "\n=== Garage Management System ===" << std::endl;
    std::cout << "1. Add vehicle" << std::endl;
    std::cout << "2. Remove vehicle" << std::endl;
    std::cout << "3. Display all vehicles" << std::endl;
    std::cout << "4. Edit vehicle" << std::endl;
    std::cout << "5. Save to file" << std::endl;
    std::cout << "6. Load from file" << std::endl;
    std::cout << "7. Show vehicle count" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

Base* createVehicle() {
    int type;
    std::cout << "\nSelect vehicle type:" << std::endl;
    std::cout << "1. Car" << std::endl;
    std::cout << "2. Motorcycle" << std::endl;
    std::cout << "3. Bus" << std::endl;
    std::cout << "Choose type: ";
    std::cin >> type;
    std::cin.ignore();

    switch (type) {
    case 1: return new Car();
    case 2: return new Motorcycle();
    case 3: return new Bus();
    default:
        throw std::invalid_argument("Invalid vehicle type");
    }
}

int main() {
    Keeper garage;
    int choice;

    std::cout << "Welcome to Garage Management System!" << std::endl;

    do {
        try {
            showMenu();
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
            case 1: {
                Base* newVehicle = createVehicle();
                newVehicle->edit();
                garage.addVehicle(newVehicle);
                std::cout << "Vehicle added successfully!" << std::endl;
                break;
            }
            case 2: {
                if (garage.getSize() == 0) {
                    std::cout << "Garage is empty!" << std::endl;
                    break;
                }
                std::cout << "Enter vehicle number to remove (1-" << garage.getSize() << "): ";
                int index;
                std::cin >> index;
                std::cin.ignore();
                garage.removeVehicle(index - 1);
                std::cout << "Vehicle removed successfully!" << std::endl;
                break;
            }
            case 3: {
                garage.displayAll();
                break;
            }
            case 4: {
                if (garage.getSize() == 0) {
                    std::cout << "Garage is empty!" << std::endl;
                    break;
                }
                std::cout << "Enter vehicle number to edit (1-" << garage.getSize() << "): ";
                int index;
                std::cin >> index;
                std::cin.ignore();
                garage.editVehicle(index - 1);
                std::cout << "Vehicle edited successfully!" << std::endl;
                break;
            }
            case 5: {
                std::string filename;
                std::cout << "Enter filename to save: ";
                std::getline(std::cin, filename);
                garage.saveToFile(filename);
                break;
            }
            case 6: {
                std::string filename;
                std::cout << "Enter filename to load: ";
                std::getline(std::cin, filename);
                garage.loadFromFile(filename);
                break;
            }
            case 7: {
                std::cout << "Total vehicles in garage: " << garage.getSize() << std::endl;
                break;
            }
            case 0: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again." << std::endl;
                break;
            }
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice != 0);

    return 0;
}
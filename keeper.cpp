#include "Keeper.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

Keeper::Keeper() : vehicles(nullptr), size(0), capacity(0) {
    std::cout << "Keeper default constructor called" << std::endl;
}

Keeper::Keeper(const Keeper& other) : size(other.size), capacity(other.capacity) {
    std::cout << "Keeper copy constructor called" << std::endl;
    vehicles = new Base * [capacity];
    for (int i = 0; i < size; ++i) {
        // Здесь должна быть логика копирования объектов (опущена для краткости)
        vehicles[i] = nullptr;
    }
}

Keeper::~Keeper() {
    std::cout << "Keeper destructor called" << std::endl;
    clear();
}

void Keeper::addVehicle(Base* vehicle) {
    if (size >= capacity) {
        resize();
    }
    vehicles[size++] = vehicle;
}

void Keeper::removeVehicle(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Invalid index: vehicle not found");
    }

    delete vehicles[index];
    for (int i = index; i < size - 1; ++i) {
        vehicles[i] = vehicles[i + 1];
    }
    --size;
}

void Keeper::displayAll() const {
    if (size == 0) {
        std::cout << "Garage is empty" << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << "Vehicle #" << (i + 1) << ":" << std::endl;
        vehicles[i]->display();
    }
}

void Keeper::editVehicle(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Invalid index: vehicle not found");
    }
    vehicles[index]->edit();
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    file << size << "\n";
    for (int i = 0; i < size; ++i) {
        vehicles[i]->saveToFile(file);
    }
    file.close();
    std::cout << "Data saved to " << filename << std::endl;
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for reading: " + filename);
    }

    clear();

    int fileSize;
    file >> fileSize;
    file.ignore();

    for (int i = 0; i < fileSize; ++i) {
        std::string type;
        std::getline(file, type);

        Base* vehicle = nullptr;

        if (type == "Car") {
            vehicle = new Car();
        }
        else if (type == "Motorcycle") {
            vehicle = new Motorcycle();
        }
        else if (type == "Bus") {
            vehicle = new Bus();
        }
        else {
            throw std::runtime_error("Unknown vehicle type in file: " + type);
        }

        vehicle->loadFromFile(file);
        addVehicle(vehicle);
    }
    file.close();
    std::cout << "Data loaded from " << filename << std::endl;
}

int Keeper::getSize() const {
    return size;
}

void Keeper::resize() {
    capacity = (capacity == 0) ? 2 : capacity * 2;
    Base** newVehicles = new Base * [capacity];

    for (int i = 0; i < size; ++i) {
        newVehicles[i] = vehicles[i];
    }

    delete[] vehicles;
    vehicles = newVehicles;
}

void Keeper::clear() {
    for (int i = 0; i < size; ++i) {
        delete vehicles[i];
    }
    delete[] vehicles;
    vehicles = nullptr;
    size = 0;
    capacity = 0;
}
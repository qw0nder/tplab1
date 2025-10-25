#include "Car.h"
#include <iostream>

Car::Car() : Base(), color("Unknown"), transmissionType("Unknown") {
    std::cout << "Car default constructor called" << std::endl;
}

Car::Car(const std::string& brand, const std::string& model, double engineVolume,
    const std::string& color, const std::string& transmissionType)
    : Base(brand, model, engineVolume), color(color), transmissionType(transmissionType) {
    std::cout << "Car parameterized constructor called" << std::endl;
}

Car::Car(const Car& other)
    : Base(other), color(other.color), transmissionType(other.transmissionType) {
    std::cout << "Car copy constructor called" << std::endl;
}

Car::~Car() {
    std::cout << "Car destructor called" << std::endl;
}

void Car::display() const {
    std::cout << "Type: Car" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Engine Volume: " << engineVolume << "L" << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Transmission Type: " << transmissionType << std::endl;
    std::cout << "------------------------" << std::endl;
}

void Car::edit() {
    std::cout << "Editing Car:" << std::endl;

    std::cout << "Enter brand: ";
    std::getline(std::cin, brand);

    std::cout << "Enter model: ";
    std::getline(std::cin, model);

    std::cout << "Enter engine volume: ";
    std::cin >> engineVolume;
    std::cin.ignore();

    std::cout << "Enter color: ";
    std::getline(std::cin, color);

    std::cout << "Enter transmission type: ";
    std::getline(std::cin, transmissionType);
}

std::string Car::getType() const {
    return "Car";
}

void Car::saveToFile(std::ostream& os) const {
    os << "Car\n";
    os << brand << "\n" << model << "\n" << engineVolume << "\n";
    os << color << "\n" << transmissionType << "\n";
}

void Car::loadFromFile(std::istream& is) {
    std::getline(is, brand);
    std::getline(is, model);
    is >> engineVolume;
    is.ignore();
    std::getline(is, color);
    std::getline(is, transmissionType);
}

void Car::setColor(const std::string& color) {
    this->color = color;
}

void Car::setTransmissionType(const std::string& transmissionType) {
    this->transmissionType = transmissionType;
}

std::string Car::getColor() const {
    return color;
}

std::string Car::getTransmissionType() const {
    return transmissionType;
}
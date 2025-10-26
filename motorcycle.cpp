#include "Motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle() : Base(), enginePower(0.0), terrainType("Unknown") {
    std::cout << "Motorcycle default constructor called" << std::endl;
}

Motorcycle::Motorcycle(const std::string& brand, const std::string& model, double engineVolume,
    double enginePower, const std::string& terrainType)
    : Base(brand, model, engineVolume), enginePower(enginePower), terrainType(terrainType) {
    std::cout << "Motorcycle parameterized constructor called" << std::endl;
}

Motorcycle::Motorcycle(const Motorcycle& other)
    : Base(other), enginePower(other.enginePower), terrainType(other.terrainType) {
    std::cout << "Motorcycle copy constructor called" << std::endl;
}

Motorcycle::~Motorcycle() {
    std::cout << "Motorcycle destructor called" << std::endl;
}

void Motorcycle::display() const {
    std::cout << "Type: Motorcycle" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Engine Volume: " << engineVolume << "L" << std::endl;
    std::cout << "Engine Power: " << enginePower << "HP" << std::endl;
    std::cout << "Terrain Type: " << terrainType << std::endl;
    std::cout << "------------------------" << std::endl;
}

void Motorcycle::edit() {
    std::cout << "Editing Motorcycle:" << std::endl;

    std::cout << "Enter brand: ";
    std::getline(std::cin, brand);

    std::cout << "Enter model: ";
    std::getline(std::cin, model);

    std::cout << "Enter engine volume: ";
    std::cin >> engineVolume;
    std::cin.ignore();

    std::cout << "Enter engine power: ";
    std::cin >> enginePower;
    std::cin.ignore();

    std::cout << "Enter terrain type: ";
    std::getline(std::cin, terrainType);
}

std::string Motorcycle::getType() const {
    return "Motorcycle";
}

void Motorcycle::saveToFile(std::ostream& os) const {
    os << "Motorcycle\n";
    os << brand << "\n" << model << "\n" << engineVolume << "\n";
    os << enginePower << "\n" << terrainType << "\n";
}

void Motorcycle::loadFromFile(std::istream& is) {
    std::getline(is, brand);
    std::getline(is, model);
    is >> engineVolume;
    is.ignore();
    is >> enginePower;
    is.ignore();
    std::getline(is, terrainType);
}

void Motorcycle::setEnginePower(double power) {
    if (power < 0) {
        throw std::invalid_argument("Engine power cannot be negative");
    }
    this->enginePower = power;
}

void Motorcycle::setTerrainType(const std::string& terrainType) {
    this->terrainType = terrainType;
}

double Motorcycle::getEnginePower() const {
    return enginePower;
}

std::string Motorcycle::getTerrainType() const {
    return terrainType;
}
#include "Bus.h"
#include <iostream>

Bus::Bus() : Base(), seatedPassengers(0), totalPassengers(0), destination("Unknown") {
    std::cout << "Bus default constructor called" << std::endl;
}

Bus::Bus(const std::string& brand, const std::string& model, int seatedPassengers,
    int totalPassengers, const std::string& destination)
    : Base(brand, model, 0.0), seatedPassengers(seatedPassengers),
    totalPassengers(totalPassengers), destination(destination) {
    std::cout << "Bus parameterized constructor called" << std::endl;
}

Bus::Bus(const Bus& other)
    : Base(other), seatedPassengers(other.seatedPassengers),
    totalPassengers(other.totalPassengers), destination(other.destination) {
    std::cout << "Bus copy constructor called" << std::endl;
}

Bus::~Bus() {
    std::cout << "Bus destructor called" << std::endl;
}

void Bus::display() const {
    std::cout << "Type: Bus" << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Seated Passengers: " << seatedPassengers << std::endl;
    std::cout << "Total Passengers: " << totalPassengers << std::endl;
    std::cout << "Destination: " << destination << std::endl;
    std::cout << "------------------------" << std::endl;
}

void Bus::edit() {
    std::cout << "Editing Bus:" << std::endl;

    std::cout << "Enter brand: ";
    std::getline(std::cin, brand);

    std::cout << "Enter model: ";
    std::getline(std::cin, model);

    std::cout << "Enter seated passengers: ";
    std::cin >> seatedPassengers;
    std::cin.ignore();

    std::cout << "Enter total passengers: ";
    std::cin >> totalPassengers;
    std::cin.ignore();

    std::cout << "Enter destination: ";
    std::getline(std::cin, destination);
}

std::string Bus::getType() const {
    return "Bus";
}

void Bus::saveToFile(std::ostream& os) const {
    os << "Bus\n";
    os << brand << "\n" << model << "\n" << engineVolume << "\n";
    os << seatedPassengers << "\n" << totalPassengers << "\n" << destination << "\n";
}

void Bus::loadFromFile(std::istream& is) {
    std::getline(is, brand);
    std::getline(is, model);
    is >> engineVolume;
    is.ignore();
    is >> seatedPassengers;
    is.ignore();
    is >> totalPassengers;
    is.ignore();
    std::getline(is, destination);
}

void Bus::setSeatedPassengers(int passengers) {
    if (passengers < 0) {
        throw std::invalid_argument("Seated passengers cannot be negative");
    }
    this->seatedPassengers = passengers;
}

void Bus::setTotalPassengers(int passengers) {
    if (passengers < 0) {
        throw std::invalid_argument("Total passengers cannot be negative");
    }
    this->totalPassengers = passengers;
}

void Bus::setDestination(const std::string& destination) {
    this->destination = destination;
}

int Bus::getSeatedPassengers() const {
    return seatedPassengers;
}

int Bus::getTotalPassengers() const {
    return totalPassengers;
}

std::string Bus::getDestination() const {
    return destination;
}
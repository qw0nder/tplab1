#include "Base.h"

Base::Base() : brand("Unknown"), model("Unknown"), engineVolume(0.0) {
    std::cout << "Base default constructor called" << std::endl;
}

Base::Base(const std::string& brand, const std::string& model, double engineVolume)
    : brand(brand), model(model), engineVolume(engineVolume) {
    std::cout << "Base parameterized constructor called" << std::endl;
}

Base::Base(const Base& other)
    : brand(other.brand), model(other.model), engineVolume(other.engineVolume) {
    std::cout << "Base copy constructor called" << std::endl;
}

Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}

void Base::setBrand(const std::string& brand) {
    this->brand = brand;
}

void Base::setModel(const std::string& model) {
    this->model = model;
}

void Base::setEngineVolume(double volume) {
    if (volume < 0) {
        throw std::invalid_argument("Engine volume cannot be negative");
    }
    this->engineVolume = volume;
}

std::string Base::getBrand() const {
    return brand;
}

std::string Base::getModel() const {
    return model;
}

double Base::getEngineVolume() const {
    return engineVolume;
}
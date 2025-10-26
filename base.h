#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>

class Base {
public:
    Base();
    Base(const std::string& brand, const std::string& model, double engineVolume);
    Base(const Base& other);
    virtual ~Base();

    virtual void display() const = 0;
    virtual void edit() = 0;
    virtual std::string getType() const = 0;
    virtual void saveToFile(std::ostream& os) const = 0;
    virtual void loadFromFile(std::istream& is) = 0;

    // Set и Get методы
    void setBrand(const std::string& brand);
    void setModel(const std::string& model);
    void setEngineVolume(double volume);
    std::string getBrand() const;
    std::string getModel() const;
    double getEngineVolume() const;

protected:
    std::string brand;
    std::string model;
    double engineVolume;
};

#endif
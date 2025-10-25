#ifndef CAR_H
#define CAR_H

#include "Base.h"
#include <string>

class Car : public Base {
public:
    Car();
    Car(const std::string& brand, const std::string& model, double engineVolume,
        const std::string& color, const std::string& transmissionType);
    Car(const Car& other);
    ~Car() override;

    void display() const override;
    void edit() override;
    std::string getType() const override;
    void saveToFile(std::ostream& os) const override;
    void loadFromFile(std::istream& is) override;

    // Set и Get методы
    void setColor(const std::string& color);
    void setTransmissionType(const std::string& transmissionType);
    std::string getColor() const;
    std::string getTransmissionType() const;

private:
    std::string color;
    std::string transmissionType;
};

#endif
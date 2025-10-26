#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Base.h"
#include <string>

class Motorcycle : public Base {
public:
    Motorcycle();
    Motorcycle(const std::string& brand, const std::string& model, double engineVolume,
        double enginePower, const std::string& terrainType);
    Motorcycle(const Motorcycle& other);
    ~Motorcycle() override;

    void display() const override;
    void edit() override;
    std::string getType() const override;
    void saveToFile(std::ostream& os) const override;
    void loadFromFile(std::istream& is) override;

    // Set и Get методы
    void setEnginePower(double power);
    void setTerrainType(const std::string& terrainType);
    double getEnginePower() const;
    std::string getTerrainType() const;

private:
    double enginePower;
    std::string terrainType;
};

#endif
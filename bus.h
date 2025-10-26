#ifndef BUS_H
#define BUS_H

#include "Base.h"
#include <string>

class Bus : public Base {
public:
    Bus();
    Bus(const std::string& brand, const std::string& model, int seatedPassengers,
        int totalPassengers, const std::string& destination);
    Bus(const Bus& other);
    ~Bus() override;

    void display() const override;
    void edit() override;
    std::string getType() const override;
    void saveToFile(std::ostream& os) const override;
    void loadFromFile(std::istream& is) override;

    // Set и Get методы
    void setSeatedPassengers(int passengers);
    void setTotalPassengers(int passengers);
    void setDestination(const std::string& destination);
    int getSeatedPassengers() const;
    int getTotalPassengers() const;
    std::string getDestination() const;

private:
    int seatedPassengers;
    int totalPassengers;
    std::string destination;
};

#endif
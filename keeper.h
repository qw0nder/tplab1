#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"

class Keeper {
public:
    Keeper();
    Keeper(const Keeper& other);
    ~Keeper();

    void addVehicle(Base* vehicle);
    void removeVehicle(int index);
    void displayAll() const;
    void editVehicle(int index);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    int getSize() const;

private:
    Base** vehicles;
    int size;
    int capacity;

    void resize();
    void clear();
};

#endif
#ifndef C_PROJECT_FLOWER_H
#define C_PROJECT_FLOWER_H

#include <string>
#include <iostream>


class Flower {
private:
    std::string type;
    std::string color;
    std::string description;

public:

    Flower(std::string t, std::string c, std::string desc);

    std::string getType();

    std::string getColor() const;

    std::string getDescription() const;

    void setType(std::string t);

    void setColor(std::string c);

    void setDescription(std::string desc);

    bool operator==(const Flower& other) const;

    void display() const;
};

#endif //C_PROJECT_FLOWER_H

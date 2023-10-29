#include "Flower.h"

// Constructor definition
Flower::Flower(std::string t, std::string c, std::string desc) : type(t), color(c), description(desc) {}

// Getter functions for flower details
 std::string Flower::getType() { return type; }
std::string Flower::getColor() const { return color; }
std::string Flower::getDescription() const { return description; }

// Setter functions for flower details
void Flower::setType(std::string t) { type = t; }

[[maybe_unused]] void Flower::setColor(std::string c) { color = c; }
void Flower::setDescription(std::string desc) { description = desc; }

// Function to check if two flowers are the same
bool Flower::operator==(const Flower& other) const {
    return type == other.type && color == other.color && description == other.description;
}

// Function to display flower details
void Flower::display() const {
    std::cout << "Type: " << type << "\nColor: " << color << "\nDescription: " << description << std::endl;
}
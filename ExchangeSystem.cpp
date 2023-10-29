#include "ExchangeSystem.h"

// Function to register a new user
bool ExchangeSystem::registerUser(std::string uname, std::string pass) {
    // Check if user already exists
    for (User user : users) {
        if (user.checkCredentials(uname, pass)) {
            return false; // User already exists
        }
    }

    // If user doesn't exist, register new user
    User newUser(uname, pass);
    users.push_back(newUser);
    return true;
}

// Function to log in a user
bool ExchangeSystem::loginUser(std::string uname, std::string pass) {
    for (const User& user : users) {
        if (user.checkCredentials(uname, pass)) {
            return true; // User found
        }
    }
    return false; // User not found
}

// Function to post a flower
void ExchangeSystem::postFlower(Flower f) {
    flowers.push_back(f);
}

// Function to search for flowers based on type
std::vector<Flower> ExchangeSystem::searchFlowersByType(std::string type) {
    std::vector<Flower> result;
    for (Flower flower : flowers) {
        if (flower.getType() == type) {
            result.push_back(flower);
        }
    }
    return result;
}

// Function to facilitate flower exchange between two users
bool ExchangeSystem::exchangeFlowers(User& user1, Flower& flower1, User& user2, Flower& flower2) {
    // Check if both users have the respective flowers
    if (!user1.removeFlower(flower1) || !user2.removeFlower(flower2)) {
        return false; // Exchange not possible
    }

    // Exchange the flowers
    user1.postFlower(flower2);
    user2.postFlower(flower1);
    return true;
}

// Function to remove a flower from exchange list
void ExchangeSystem::removeFlowerFromExchange(Flower f) {
    auto it = std::find(flowers.begin(), flowers.end(), f);
    if (it != flowers.end()) {
        flowers.erase(it);
    }
}

// Function to list all flowers available for exchange
void ExchangeSystem::listAllFlowers() const {
    for (const Flower& flower : flowers) {
        flower.display();
    }
}

// Function to list all users (for diagnostics or admin purposes)
void ExchangeSystem::listAllUsers() const {
    for (const User& user : users) {
        std::cout << user.getUsername() << std::endl;
    }
}

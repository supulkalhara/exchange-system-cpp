#include "User.h"
#include "Flower.h"
#include "ExchangeSystem.h"
#include <iostream>

int main() {
    ExchangeSystem system;

    // Register two users
    system.registerUser("Alice", "password123");
    system.registerUser("Bob", "bobpass");

    // Login a user
    bool loginSuccessful = system.loginUser("Alice", "password123");
    if (loginSuccessful) {
        std::cout << "Login successful!" << std::endl;
    } else {
        std::cout << "Login failed!" << std::endl;
    }

    // Post flowers for exchange
    Flower rose("Rose", "Red", "A beautiful red rose.");
    Flower lily("Lily", "White", "A pristine white lily.");
    system.postFlower(rose);
    system.postFlower(lily);

    // Display all flowers
    std::cout << "Flowers available for exchange:" << std::endl;
    system.listAllFlowers();

    // Search for flowers of type "Rose"
    std::cout << "\nSearching for flowers of type 'Rose':" << std::endl;
    auto searchResults = system.searchFlowersByType("Rose");
    for (const Flower& flower : searchResults) {
        flower.display();
    }

    // Facilitate a flower exchange between Alice and Bob
    User alice("Alice", "password123");
    User bob("Bob", "bobpass");
    bool exchangeSuccessful = system.exchangeFlowers(alice, rose, bob, lily);
    if (exchangeSuccessful) {
        std::cout << "\nExchange successful!" << std::endl;
    } else {
        std::cout << "\nExchange failed!" << std::endl;
    }

    // List all users
    std::cout << "\nRegistered users:" << std::endl;
    system.listAllUsers();

    // Change Alice's password and try to log in with the new password
    alice.changePassword("newPassword");
    bool loginWithNewPassword = system.loginUser("Alice", "newPassword");
    if (loginWithNewPassword) {
        std::cout << "\nLogin with new password successful!" << std::endl;
    } else {
        std::cout << "\nLogin with new password failed!" << std::endl;
    }

    return 0;
}

#ifndef C_PROJECT_EXCHANGESYSTEM_H
#define C_PROJECT_EXCHANGESYSTEM_H

#include "User.h"
#include "Flower.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class ExchangeSystem {
private:
    std::vector<User> users; // List of all registered users
    std::vector<Flower> flowers; // All flowers available for exchange

public:
    bool registerUser(std::string uname, std::string pass);
    bool loginUser(std::string uname, std::string pass);
    void postFlower(Flower f);
    std::vector<Flower> searchFlowersByType(std::string type);
    void removeFlowerFromExchange(Flower f);
    bool exchangeFlowers(User& user1, Flower& flower1, User& user2, Flower& flower2);
    void listAllFlowers() const;
    void listAllUsers() const;
};

#endif //C_PROJECT_EXCHANGESYSTEM_H

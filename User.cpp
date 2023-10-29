#include "User.h"
#include <algorithm>

User::User(std::string uname, std::string pass) : username(std::move(uname)), password(std::move(pass)) {}

void User::postFlower(Flower f) {
    userFlowers.push_back(f);
}

bool User::checkCredentials(std::string uname, std::string pass) const {
    return username == uname && password == pass;
}

std::vector<Flower> User::getFlowers() {
    return userFlowers;
}

bool User::removeFlower(Flower f) {
    auto it = std::find(userFlowers.begin(), userFlowers.end(), f);
    if (it != userFlowers.end()) {
        userFlowers.erase(it);
        return true;
    }
    return false;
}

void User::changePassword(std::string newPass) {
    password = std::move(newPass);
}

std::string User::getUsername() const {
    return username;
}

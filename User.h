#ifndef C_PROJECT_USER_H
#define C_PROJECT_USER_H

#include "Flower.h"
#include <string>
#include <vector>

class User {
private:
    std::string username;
    std::string password;
    std::vector<Flower> userFlowers; // Flowers posted by the user

public:
    User(std::string uname, std::string pass);

    void postFlower(Flower f);
    bool checkCredentials(std::string uname, std::string pass) const;
    std::vector<Flower> getFlowers();
    bool removeFlower(Flower f);
    void changePassword(std::string newPass);
    std::string getUsername() const;
};

#endif //C_PROJECT_USER_H

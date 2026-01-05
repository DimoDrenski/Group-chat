#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "User.h"
#include "Message.h"

int main() {
    std::vector<User> users;       // Holds all users
    std::vector<Message> messages; // Holds all messages

    int choice;

    while (true) {
        std::cout << "\n--- Group Chat Menu ---\n";
        std::cout << "1. Add user\n";
        std::cout << "2. Send message\n";
        std::cout << "3. View chat history\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(); // clear the newline from input buffer

        int choice;
        std::cin >> choice; // Loop prevention attempt

        // Input validation shield
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            User user;
            std::cout << "Enter username: ";
            std::getline(std::cin, user.name);
            users.push_back(user);
            std::cout << "User added: " << user.name << "\n";
        }
        else if (choice == 2) {
            if (users.empty()) {
                std::cout << "No users available. Add a user first.\n";
                continue;
            }

            std::cout << "Select user by number:\n";
            for (size_t i = 0; i < users.size(); i++) {
                std::cout << i << ". " << users[i].name << "\n";
            }

            int userIndex;
            std::cin >> userIndex;
            std::cin.ignore();

            if (userIndex < 0 || userIndex >= users.size()) {
                std::cout << "Invalid user.\n";
                continue;
            }

            Message msg;
            msg.sender = users[userIndex].name;

            std::cout << "Enter message: ";
            std::getline(std::cin, msg.content);

            messages.push_back(msg);
            std::cout << "Message sent.\n";
        }
        else if (choice == 3) {
            std::cout << "\n--- Chat History ---\n";
            for (const auto& msg : messages) {
                std::cout << msg.sender << ": " << msg.content << "\n";
            }
            if (messages.empty()) {
                std::cout << "(No messages yet)\n";
            }
        }
        else if (choice == 4) {
            std::cout << "Exiting chat.\n";
            break;
        }
        else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}


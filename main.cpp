#include <iostream>     // For input/output (cin, cout)
#include <vector>       // To store users and messages 
#include <string>       // To work with text (std::string)
#include <ctime>        // For timestamps
#include <limits>       // For safe input handling

// This function returns the current date and time as a formatted string.
std::string currentTime() {
    std::time_t now = std::time(nullptr);   // Get current system time
    char buffer[80];

    // Convert time into readable format: YYYY-MM-DD HH:MM:SS
    std::strftime(buffer, sizeof(buffer),
                  "%Y-%m-%d %H:%M:%S",
                  std::localtime(&now));

    return std::string(buffer);
}

int main() {
    // Vector to store usernames.
    // Vector so data can grow dynamically as new users are added.
    std::vector<std::string> users;

    // Vector to store chat messages.
    // Messages are stored as formatted strings including time and sender.
    std::vector<std::string> messages;

    // Main program loop.
   
    while (true) {
        // Code to display menu options for the user
        std::cout << "\n--- Group Chat Menu ---\n";
        std::cout << "1. Add user\n";
        std::cout << "2. Send message\n";
        std::cout << "3. View chat history\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
// Loop prevention attempt

        // Input validation:
        // If the user enters something that is not a number,
        // cin enters a failed state and must be reset.
        if (std::cin.fail()) {
            std::cin.clear(); // Clears the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue; // Stops the code from looping infinitely and crashing my PC if its interrupted or conflicted....thanks for that Avast
        }

        
        if (choice == 1) {
            std::string username;
            std::cout << "Enter username: ";
            std::cin >> username;

            users.push_back(username); // Store user in vector
            std::cout << "User added successfully.\n";
        }

      
        else if (choice == 2) {
            // Checks if users exist before sending messages
            if (users.empty()) {
                std::cout << "No users available. Add a user first.\n";
                continue;
            }

            // Displays list of users to choose sender
            std::cout << "Select user:\n";
            for (size_t i = 0; i < users.size(); ++i) {
                std::cout << i + 1 << ". " << users[i] << "\n";
            }

            int userChoice;
            std::cin >> userChoice;

            // Validates user selection
            if (userChoice < 1 || userChoice > users.size()) {
                std::cout << "Invalid user selection.\n";
                continue;
            }

            std::cin.ignore(); // Clear leftover newline

            std::string message;
            std::cout << "Enter message: ";
            std::getline(std::cin, message);

            // Formats message with timestamp and username
            std::string fullMessage =
                "[" + currentTime() + "] " +
                users[userChoice - 1] + ": " +
                message;

            messages.push_back(fullMessage); // Stores message
            std::cout << "Message sent.\n";
        }

      
        else if (choice == 3) {
            if (messages.empty()) {
                std::cout << "No messages yet.\n";
            } else {
                std::cout << "\n--- Chat History ---\n";
                for (const auto& msg : messages) {
                    std::cout << msg << "\n";
                }
            }
        }

        
        else if (choice == 4) {
            std::cout << "Goodbye. Chat closed peacefully.\n";
            break; // Exits the while loop and ends the program
        }

        // Any number outside valid menu options returns you to the main screen
        else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0; 
}



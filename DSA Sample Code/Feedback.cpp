#include "Feedback.h"
#include <fstream>

FeedbackManager::FeedbackManager() : head(nullptr), tail(nullptr) {
    loadFeedbackFromFile();
}

void FeedbackManager::addFeedback(int accountNumber, const std::string& customerName, const std::string& message) {
    Feedback* newFeedback = new Feedback(accountNumber, customerName, message);
    if (!head) {
        head = tail = newFeedback;
    } else {
        tail->next = newFeedback;
        newFeedback->prev = tail;
        tail = newFeedback;
    }
    std::cout << "Feedback added successfully.\n";
    saveFeedbackToFile();
}

void FeedbackManager::displayFeedback() {
    if (!head) {
        std::cout << "No feedback available.\n";
        return;
    }

    Feedback* current = head;
    std::cout << "\nCustomer Feedback:\n";
    while (current) {
        std::cout << "Account Number: " << current->accountNumber << "\n"
                  << "Customer Name: " << current->customerName << "\n"
                  << "Message: " << current->message << "\n\n";
        current = current->next;
    }
}

void FeedbackManager::deleteFeedback(int accountNumber) {
    Feedback* current = head;
    while (current) {
        if (current->accountNumber == accountNumber) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;

            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;

            delete current;
            std::cout << "Feedback deleted successfully.\n";
            saveFeedbackToFile();
            return;
        }
        current = current->next;
    }
    std::cout << "Feedback not found.\n";
}

void FeedbackManager::feedbackMenu() {
    char choice;
    do {
        std::cout << "\nFEEDBACK MENU\n"
                  << "1. Add Feedback\n"
                  << "2. View Feedback\n"
                  << "3. Delete Feedback\n"
                  << "4. Return to Main Menu\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1': {
            int accountNumber;
            std::string customerName, message;
            std::cout << "Enter Account Number: ";
            std::cin >> accountNumber;
            std::cin.ignore(); // To clear newline character
            std::cout << "Enter Customer Name: ";
            std::getline(std::cin, customerName);
            std::cout << "Enter Feedback Message: ";
            std::getline(std::cin, message);
            addFeedback(accountNumber, customerName, message);
            break;
        }
        case '2':
            displayFeedback();
            break;

        case '3': {
            int accountNumber;
            std::cout << "Enter Account Number to delete feedback: ";
            std::cin >> accountNumber;
            deleteFeedback(accountNumber);
            break;
        }
        case '4':
            std::cout << "Returning to main menu...\n";
            break;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != '4');
}

FeedbackManager::~FeedbackManager() {
    while (head) {
        Feedback* temp = head;
        head = head->next;
        delete temp;
    }
}

void FeedbackManager::saveFeedbackToFile() {
    std::ofstream outFile("feedback.txt");
    Feedback* current = head;
    while (current) {
        outFile << "Customer Feedback:\n"
                << "Account Number: " << current->accountNumber << "\n"
                << "Customer Name: " << current->customerName << "\n"
                << "Message: " << current->message << "\n\n";
        current = current->next;
    }
    outFile.close();
}

void FeedbackManager::loadFeedbackFromFile() {
    std::ifstream inFile("feedback.txt");
    if (!inFile) return;

    std::string line;
    int accountNumber;
    std::string customerName, message;

    while (std::getline(inFile, line)) {
        if (line == "Customer Feedback:") {
            std::getline(inFile, line); // Skip "Account Number: "
            accountNumber = std::stoi(line.substr(16));
            std::getline(inFile, line); // Skip "Customer Name: "
            customerName = line.substr(15);
            std::getline(inFile, line); // Skip "Message: "
            message = line.substr(9);
            addFeedback(accountNumber, customerName, message);
            std::getline(inFile, line); // Skip empty line
        }
    }
    inFile.close();
}
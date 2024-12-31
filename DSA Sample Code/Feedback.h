#ifndef FEEDBACK_MANAGER_H
#define FEEDBACK_MANAGER_H

#include <string>
#include <iostream>

// Class representing a single feedback node
class Feedback {
public:
    int accountNumber;
    std::string customerName;
    std::string message;
    Feedback* next;
    Feedback* prev;

    Feedback(int accNum, const std::string& name, const std::string& msg)
        : accountNumber(accNum), customerName(name), message(msg), next(nullptr), prev(nullptr) {}
};

// FeedbackManager class
class FeedbackManager {
private:
    Feedback* head;
    Feedback* tail;

    void saveFeedbackToFile();
    void loadFeedbackFromFile();

public:
    FeedbackManager();
    void addFeedback(int accountNumber, const std::string& customerName, const std::string& message);
    void displayFeedback();
    void deleteFeedback(int accountNumber);
    void feedbackMenu();
    ~FeedbackManager();
};

#endif // FEEDBACK_MANAGER_H
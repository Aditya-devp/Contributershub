#include <iostream>
#include <vector>
#include <map>
#include <string>

// Define structures for Train and Ticket
struct Train {
    int trainID;
    std::string name;
    std::string source;
    std::string destination;
    int capacity;
    int availableSeats;
};

struct Ticket {
    int ticketID;
    int trainID;
    std::string passengerName;
};

// Create data structures to store trains and tickets
std::vector<Train> trains;
std::vector<Ticket> tickets;
std::map<int, std::vector<Ticket>> ticketsByTrain;

// Function to add a new train to the system
void addTrain(int trainID, std::string name, std::string source, std::string destination, int capacity) {
    Train train;
    train.trainID = trainID;
    train.name = name;
    train.source = source;
    train.destination = destination;
    train.capacity = capacity;
    train.availableSeats = capacity;
    trains.push_back(train);
}

// Function to book a ticket for a train
bool bookTicket(int trainID, std::string passengerName) {
    for (Train &train : trains) {
        if (train.trainID == trainID && train.availableSeats > 0) {
            Ticket ticket;
            ticket.ticketID = tickets.size() + 1;
            ticket.trainID = trainID;
            ticket.passengerName = passengerName;
            tickets.push_back(ticket);
            train.availableSeats--;
            ticketsByTrain[trainID].push_back(ticket);
            return true;
        }
    }
    return false;
}

// Function to display the list of trains
void displayTrains() {
    std::cout << "Available Trains:\n";
    for (const Train &train : trains) {
        std::cout << "Train ID: " << train.trainID << ", Name: " << train.name << ", Source: " << train.source
                  << ", Destination: " << train.destination << ", Available Seats: " << train.availableSeats << "\n";
    }
}

// Function to display booked tickets for a specific train
void displayTicketsForTrain(int trainID) {
    if (ticketsByTrain.find(trainID) != ticketsByTrain.end()) {
        std::cout << "Booked Tickets for Train " << trainID << ":\n";
        for (const Ticket &ticket : ticketsByTrain[trainID]) {
            std::cout << "Ticket ID: " << ticket.ticketID << ", Passenger Name: " << ticket.passengerName << "\n";
        }
    } else {
        std::cout << "No tickets booked for this train.\n";
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nTrain Management System Menu:\n";
        std::cout << "1. Add Train\n";
        std::cout << "2. Book Ticket\n";
        std::cout << "3. Display Trains\n";
        std::cout << "4. Display Tickets for a Train\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int trainID, capacity;
                std::string name, source, destination;
                std::cout << "Enter Train ID: ";
                std::cin >> trainID;
                std::cout << "Enter Train Name: ";
                std::cin >> name;
                std::cout << "Enter Source: ";
                std::cin >> source;
                std::cout << "Enter Destination: ";
                std::cin >> destination;
                std::cout << "Enter Capacity: ";
                std::cin >> capacity;
                addTrain(trainID, name, source, destination, capacity);
                break;
            }
            case 2: {
                int trainID;
                std::string passengerName;
                std::cout << "Enter Train ID: ";
                std::cin >> trainID;
                std::cout << "Enter Passenger Name: ";
                std::cin >> passengerName;
                if (bookTicket(trainID, passengerName)) {
                    std::cout << "Ticket booked successfully.\n";
                } else {
                    std::cout << "Ticket booking failed. Either the train does not exist or it's fully booked.\n";
                }
                break;
            }
            case 3:
                displayTrains();
                break;
            case 4: {
                int trainID;
                std::cout << "Enter Train ID: ";
                std::cin >> trainID;
                displayTicketsForTrain(trainID);
                break;
            }
            case 5:
                std::cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

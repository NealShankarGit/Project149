#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
#include <ctime>
#include <cmath>
#include <chrono>
#include <iomanip>
#include "minHeap.h"
#include "hashmap.h"

// initialize hashmap of 50 buckets
hashMap hashmap(50);
// initialize heap
minHeap heap;

// function to read any CSV file in
std::vector<Employee> readCSV(const std::string& filename) {
    std::vector<Employee> employees;
    std::ifstream file(filename);
    std::string line, word;

    // checks is file is open
    if (file.is_open()) {
        std::getline(file, line);

        // takes the id and productivity score as input
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            Employee emp;
            std::getline(ss, word, ',');
            emp.id = std::stoi(word);
            std::getline(ss, word, ',');
            emp.productivityScore = std::stoi(word);
            employees.push_back(emp);
        }

        // inserting the id and productivity score into hashmap and heap
        for (const auto& emp : employees) {
            heap.insert(emp);
        }
        for (const auto& emp : employees){
            hashmap.insert(emp.id, emp.productivityScore);
        }

    } 
    else {
        std::cerr << "Could not open the file." << std::endl;
    }

    return employees;
}

// only used for heap
// prints the id and productivity score of one employee
void displayEmployee(const Employee& emp) {
    if (emp.id == -1) {
        std::cout << "\nEmployee not found." << std::endl;
        return;
    }
    std::cout << "\nID: " << emp.id << "\nProductivity Score: " << emp.productivityScore << std::endl;
}

int main() {
    // initializing clock variables
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;
    std::chrono::duration<double> time_span;
    // reads in CSV file
    std::vector<Employee> employees = readCSV("employee_performance_data.csv");
    
    // initializing variables to store output in
    pair <int, int> bottom;
    int choice, id, search;

    // whlle loop through menu
    while (choice != 5) {
        // print menu interface
        std::cout << "\nMenu:\n";
        std::cout << "1. Search by ID using Heap\n";
        std::cout << "2. Display Bottom Performer using Heap\n";
        std::cout << "3. Search by ID using Hashmap\n";
        std::cout << "4. Display Bottom Performer using Hashmap\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        // take input of choice
        std::cin >> choice;

        // switch statements based on user input
        switch (choice) {
            // search id using heap
            case 1:
                std::cout << "Enter ID to search: ";
                std::cin >> id;
                // set start time
                start = std::chrono::high_resolution_clock::now();
                // search for productivity score given the id
                displayEmployee(heap.search(id));
                // set end time
                end = std::chrono::high_resolution_clock::now();
                // calculate time taken
                time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
                std::cout << "Time to search with Heap: " << time_span.count() << std::endl;
                break;
            // search for bottom performer using heap
            case 2:
                // set start time
                start = std::chrono::high_resolution_clock::now();
                // display the productivity score of the worst performer
                displayEmployee(heap.top());
                // set end time
                end = std::chrono::high_resolution_clock::now();
                // calculate time taken
                time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
                std::cout << "Time to search with Heap: " << time_span.count() << std::endl;
                break;
            // search id using hashmap
            case 3:
                std::cout << "Enter ID to search: ";
                std::cin >> id;
                // set start time
                start = std::chrono::high_resolution_clock::now();
                // find the productivity score of the given id
                search = hashmap.searchiD(id);
                std::cout << "ID: " << id << std::endl;
                std::cout << "Productivity Score: " << search << std::endl;
                // set end time
                end = std::chrono::high_resolution_clock::now();
                // calculate time taken
                time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
                std::cout << "Time to search with Hashmap: " << time_span.count() << std::endl;
                break;
            // search for bottom performer using hashmap
            case 4:
                // set start time
                start = std::chrono::high_resolution_clock::now();
                // set the bottom performer pair
                bottom = hashmap.searchforBottom();
                std::cout << "ID: " << bottom.first << std::endl;
                std::cout << "Productivity Score: " << bottom.second << std::endl;
                // set end time
                end = std::chrono::high_resolution_clock::now();
                // calculate time taken
                time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
                std::cout << "Time to search with Hashmap: " << time_span.count() << std::endl;
                break;
            // exit program
            case 5:
                std::cout << "Exiting program." << std::endl;
                break;
            // invalid choice inputted
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}
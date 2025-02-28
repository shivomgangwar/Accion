#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>

using namespace std;

// Employee class representing an employee record
class Employee {
public:
    string name;
    string department;
    int salary;

    // Constructor
    Employee(string n, string d, int s) : name(n), department(d), salary(s) {}

    // Function to convert name to uppercase
    void toUpperCase() {
        transform(name.begin(), name.end(), name.begin(), ::toupper);
    }

    // Function to display employee details in the required format
    void display() const {
        cout << name << " (" << department << "): " << salary << endl;
    }
};

// EmployeeProcessor class to handle file reading and processing
class EmployeeProcessor {
private:
    vector<Employee> employees;

public:
    // Function to read employee data from the file
    void readData(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        string line, name, department;
        int salary;
        
        while (getline(file, line)) {
            stringstream ss(line);
            ss >> name >> department >> salary;
            if (department == "IT") { // Only store IT department employees
                employees.emplace_back(name, department, salary);
            }
        }
        file.close();
    }

    // Function to process and display results
    void processAndDisplay() {
        // Convert names to uppercase
        for (auto& emp : employees) {
            emp.toUpperCase();
        }

        // Sort employees by salary in descending order
        sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
            return a.salary > b.salary;
        });

        // Display the results
        for (const auto& emp : employees) {
            emp.display();
        }
    }
};

// Main function
int main() {
    // Create sample file
    ofstream file("employees.txt");
    file << "Alice HR 55000\nBob IT 70000\nCharlie Finance 65000\nDavid IT 72000\n"
         << "Eve HR 58000\nFrank Finance 67000\nGrace IT 73000\nHank HR 56000\n";
    file.close();

    EmployeeProcessor processor;
    processor.readData("employees.txt");
    processor.processAndDisplay();

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
ofstream outputFile;

int getNumOfEmployees();
int getTotalDaysAbsent(int numEmployees,ofstream&);
double calculateAvgDaysAbsent(int totalDaysOfAbsent, int numEmployees);

int main() {//main function
    const string programmerName = "Daniel David"

    ofstream file("employeeAbsences.txt");//file name

    int numEmployees = getNumOfEmployees();//using the functions
    int totalDaysOfAbsent = getTotalDaysAbsent(numEmployees,file);

    file << "\nThe " << numEmployees << " employees were absent a total of " << totalDaysOfAbsent << " days.\n"//exit calculation message
         << "The average number of days absent is " << calculateAvgDaysAbsent(totalDaysOfAbsent, numEmployees) << " days.\n\n";

    file << "Programmer: " << programmerName << endl;

    file.close();

    system("pause");
    return 0;
}

int getNumOfEmployees() {// num employees function
    int numEmployees;
    cout << "Calculate the average number of days a company's employees are absent.\n\n";
    cout << "Please enter the number of employees in the company: ";
    do {
        cin >> numEmployees;
        if (numEmployees <= 0) {
            cout << "Please re-enter employee ID:";
        }
    } while (numEmployees <= 0);
    return numEmployees;
}

int getTotalDaysAbsent(int numEmployees, ofstream& file) {//ID and days of absent function
    int employeeId = 0;
    int daysOfAbsent = 0;
    int totalDaysOfAbsent = 0;

    file << "EMPLOYEE ABSENCE REPORT:" << endl;
    file << "Employee ID    Days absent" << endl;

    for (int count = 1; count <= numEmployees; count++) {//loop for data insert

        cout << "Please enter an employee ID: ";
        do {
            cin >> employeeId;
            if (employeeId <= 0) {
                cout << "Please re-enter employee ID:";
            }
        } while (employeeId <= 0);
        file << setw(8) << employeeId;

        cout << "Please enter the number of days this employee was absent this year: ";
        do {
            cin >> daysOfAbsent;
            if (daysOfAbsent < 0) {
                cout << "Please re-enter number of days this employee was absent this year: ";
            }
        } while (daysOfAbsent < 0);
        file << setw(8) << daysOfAbsent << endl;

        totalDaysOfAbsent = totalDaysOfAbsent + daysOfAbsent;// total summation of days of absent
    }
    return totalDaysOfAbsent;// return result of total days
}

double calculateAvgDaysAbsent(int totalDaysOfAbsent, int numEmployees) {// calculation of average function
    double averageAbsent;
    averageAbsent = static_cast<double>(totalDaysOfAbsent) / numEmployees;
    return averageAbsent; // return of average
}
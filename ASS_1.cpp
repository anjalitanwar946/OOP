#include <iostream>
using namespace std;

int main() {
    int DCF, UXD, DBMS, OOP, WA;
    int totalMarks;
    double percentage;
    int failedSubjects = 0;

    cout << "Enter marks for DCF: ";
    cin >> DCF;
    cout << "Enter marks for UXD: ";
    cin >> UXD;
    cout << "Enter marks for DBMS: ";
    cin >> DBMS;
    cout << "Enter marks for OOP: ";
    cin >> OOP;
    cout << "Enter marks for WA: ";
    cin >> WA;

    totalMarks = DCF + UXD + DBMS + OOP + WA;
    percentage = (totalMarks / 5.0); // Percentage calculation

    if (DCF < 50) failedSubjects++;
    if (UXD < 50) failedSubjects++;
    if (DBMS < 50) failedSubjects++;
    if (OOP < 50) failedSubjects++;
    if (WA < 50) failedSubjects++;

    cout << "Total Marks: " << totalMarks << endl;
    cout << "Percentage: " << percentage << "%" << endl;

    if (failedSubjects == 0) {
        cout << "Result: Pass" << endl;
        if (percentage >= 70) {
            cout << "Division: First Division" << endl;
        } else if (percentage >= 60) {
            cout << "Division: Second Division" << endl;
        } else if (percentage >= 50) {
            cout << "Division: Third Division" << endl;
        }
    } else if (failedSubjects == 1) {
        cout << "Result: Supplementary" << endl;
    } else {
        cout << "Result: Fail" << endl;
    }

    return 0;
}


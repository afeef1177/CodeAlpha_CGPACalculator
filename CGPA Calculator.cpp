#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Course {
    string name;
    double grade;
    double creditHours;
};

double calculateCGPA(const vector<Course>& courses) {
    double totalGradePoints = 0.0, totalCredits = 0.0;
    for (const auto& course : courses) {
        totalGradePoints += course.grade * course.creditHours;
        totalCredits += course.creditHours;
    }
    return (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);
    for (int i = 0; i < numCourses; i++) {
        cout << "\nEnter name of course " << i + 1 << ": ";
        cin.ignore();
        getline(cin, courses[i].name);

        cout << "Enter grade (0.0 - 10.0 scale): ";
        cin >> courses[i].grade;

        cout << "Enter credit hours: ";
        cin >> courses[i].creditHours;
    }

    cout << "\n------------------------------------\n";
    cout << left << setw(20) << "Course" << setw(10) << "Grade" << "Credits\n";
    cout << "------------------------------------\n";
    for (const auto& c : courses) {
        cout << left << setw(20) << c.name << setw(10) << c.grade << c.creditHours << "\n";
    }

    double cgpa = calculateCGPA(courses);
    cout << "------------------------------------\n";
    cout << "Final CGPA: " << fixed << setprecision(2) << cgpa << "\n";

    return 0;
}


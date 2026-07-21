#include <iostream>
using namespace std;

int main() {
    int numCourses;
    float totalCreditHours = 0.0;
    float totalGradePoints = 0.0;

    cout << "===== GPA / CGPA Calculator =====" << endl;
    cout << "Enter the number of courses taken: ";
    cin >> numCourses;

    
    float grades[numCourses];
    float credits[numCourses];

    for (int i = 0; i < numCourses; i++) {
        cout << "\n--- Course " << (i + 1) << " ---" << endl;

        cout << "Enter grade (e.g., 4.0, 3.3, 3.0...): ";
        cin >> grades[i];

        cout << "Enter credit hours: ";
        cin >> credits[i];

        float gradePoints = grades[i] * credits[i];

        totalGradePoints += gradePoints;
        totalCreditHours += credits[i];
}
    float GPA = totalGradePoints / totalCreditHours;


    float CGPA = GPA;

    cout << "\n===== Course Summary =====" << endl;
    for (int i = 0; i < numCourses; i++) {
        cout << "Course " << (i + 1)
             << " -> Grade: " << grades[i]
             << ", Credit Hours: " << credits[i]
             << ", Grade Points: " << (grades[i] * credits[i])
             << endl;
    }

    cout << "\nTotal Credit Hours: " << totalCreditHours << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;

    cout << "\nSemester GPA: " << GPA << endl;
    cout << "Overall CGPA: " << CGPA << endl;

    return 0;
}

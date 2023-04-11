#include <iostream>
#include <string>
using namespace std;

double get_gpa (string grade, int current_subject_gpa){
    if (grade == "A+") return 4.5 * current_subject_gpa;
    else if (grade == "A0") return 4.0 * current_subject_gpa;
    else if (grade == "B+") return 3.5 * current_subject_gpa;
    else if (grade == "B0") return 3.0 * current_subject_gpa;
    else if (grade == "C+") return 2.5 * current_subject_gpa;
    else if (grade == "C0") return 2.0 * current_subject_gpa;
    else if (grade == "D+") return 1.5 * current_subject_gpa;
    else if (grade == "D0") return 1.0 * current_subject_gpa;
    return 0;
}

int main(){
    string subject, subject_gpa, grade;
    int sum = 0;
    double gpa = 0;

    for (int i = 0; i < 20; i++){
        int current_subject_gpa = 0;

        cin >> subject >> subject_gpa >> grade;

        if (grade == "P") continue;
        current_subject_gpa = stoi(subject_gpa);
        sum += current_subject_gpa;

        if (grade == "F") continue;
        else gpa += get_gpa(grade, current_subject_gpa);
    }
    cout << gpa / sum << "\n";
    return 0;
}
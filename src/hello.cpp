#include <string>
#include "hello.hpp"
#include <iomanip>
using namespace std;
#include <sstream>
void Gradebook::add_student(string first_name, string last_name, string id) {
    first_names.push_back(first_name);
    last_names.push_back(last_name);
    ids.push_back(id);

    vector<int> new_row;
    for (int i = 0; i < assignments.size(); i++) {
        new_row.push_back(-1);
    }
    grades.push_back(new_row);
}

void Gradebook::add_assignment(string assignment, int assignment_points ) {
    assignments.push_back(assignment);
    assignments_points.push_back(assignment_points);

    for (int i = 0; i < grades.size(); i++) {
        grades[i].push_back(-1);
    }
}
void Gradebook::add_grade(string id, string assignment, int grade ) {
    int student_index = -1;
    int assignment_index = -1;
    for (int i = 0; i < ids.size(); i++) {
        if (ids[i] == id) {
            student_index = i;
        }
    }
    for (int i = 0; i < assignments.size(); i++) {
        if (assignments[i] == assignment) {
            assignment_index = i;
        }
    }
    if (student_index != -1 && assignment_index != -1) {
        if (grade >= 0) {
            grades[student_index][assignment_index] = grade;
        }
    }
}

string Gradebook::report() {
 ostringstream out;
    out << setprecision(3);
    out << "Last_Name,First_Name,Student_ID";
    for (int i = 0; i < assignments.size(); i++) {
        out <<"," <<assignments[i] ;
    }
    out <<",Average";
    out << "\n";
    for (int i = 0; i < ids.size(); i++) {
        out <<last_names[i] <<"," << first_names[i] << "," << ids[i];
        double points_earned = 0;
        double points_possible=0;
        for (int j = 0; j < grades[i].size(); j++) {
            if (grades[i][j] == -1) {
                out <<",N/A";
            }
            else{
                out << "," << grades[i][j];

                points_earned += grades[i][j];
                points_possible += assignments_points[j];
            }
        }
        if (points_possible==0) {
            out <<",N/A";
        }
        else {
            double avg = (points_earned / points_possible) *100.0;
            out <<"," <<avg;
        }

        out << "\n";
    }
    return out.str();
}

#include <iostream>

#include "src/hello.hpp"
using namespace std;

int main() {
    Gradebook gradebook;

    gradebook.add_student("Bob", "Bobberson", "ABC123");
    gradebook.add_student("Sam", "Sammerson", "DEF456");
    gradebook.add_student("Jess", "Jesserson", "HIJ789");

    gradebook.add_assignment("Quiz 1", 100);
    gradebook.add_assignment("Lab 1", 50);

    gradebook.add_grade("DEF456", "Quiz 1", 95);
    gradebook.add_grade("ABC123", "Quiz 1", 85);
    gradebook.add_grade("HIJ789", "Lab 1", 49);
    gradebook.add_grade("HIJ789", "Quiz 1", 93);
    gradebook.add_grade("ABC123", "Lab 1", 0);

    cout << gradebook.report();

}
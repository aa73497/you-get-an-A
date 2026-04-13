To use gradebook:

create a gradebook with "Gradebook _____"

(name of gradebook goes in blank, g, will be the example name)"

add students to gradebook by "g.add_student(first name, last name, ID)"

add assignments to gradebook by "g.add_assignment(*assignment name*, *integer of assignment_points* )"

assign grades to students by "g.add_grade(*students ID #, assignment name, int value grade* )"

to see a report "cout << g.report()"
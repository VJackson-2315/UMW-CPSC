#include <string.h>

#include "grades.h"

double grade_points(char grade[3]) {
    if (strcmp(grade, "A") == 0) {
        return 4.0;
    } else if (strcmp(grade, "A-") == 0) {
        return 3.7;
    } else if (strcmp(grade, "B+") == 0) {
        return 3.3;
    } else if (strcmp(grade, "B") == 0) {
        return 3.0;
    } else if (strcmp(grade, "B-") == 0) {
        return 2.7;
    } else if (strcmp(grade, "C+") == 0) {
        return 2.3;
    } else if (strcmp(grade, "C") == 0) {
        return 2.0;
    } else if (strcmp(grade, "C-") == 0) {
        return 1.7;
    } else if (strcmp(grade, "D+") == 0) {
        return 1.3;
    } else if (strcmp(grade, "D") == 0) {
        return 1.0;
    } else { // grade == F
        return 0.0;
    }
}

double calculate_gpa(Course* courses, int num) {
    double gpa = 0.0;
    int total_credits = 0;
    
    for (int i = 0; i < num; i++) {
        total_credits += courses[i].credits;
        gpa += grade_points(courses[i].grade) * courses[i].credits;
    }
    gpa /= total_credits;

    return gpa;
}

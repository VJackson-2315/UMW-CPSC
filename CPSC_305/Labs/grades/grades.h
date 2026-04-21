#ifndef GRADES_H
#define GRADES_H

typedef struct {
    char grade[3];
    unsigned int credits;
} Course;

double grade_points(char grade[3]);
double calculate_gpa(Course* courses, int num);

#endif

#include <stdio.h>

#include "grades.h"

int main() {
    Course transcript[] = {{"A", 3},
                           {"B+", 4},
                           {"A-", 3},
                           {"C", 1},
                           {"A", 3},
                           {"B-", 3},
                           {"A", 4},
                           {"B", 3},
                           {"A", 3},
                           {"A", 1}};

    double gpa = calculate_gpa(transcript, 10);
    printf("Overall GPA = %.2lf\n", gpa);
    return 0;
}


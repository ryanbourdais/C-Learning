#include "assignment.h"

#include <string.h>

void assignment_set_name(struct assignment *assignment, const char *name) {
    if (name == 0) {
        assignment->name[0] = '\0';
        return;
    }

    strncpy(assignment->name, name, sizeof(assignment->name) - 1);
    assignment->name[sizeof(assignment->name) - 1] = '\0';
}

void assignment_init(struct assignment *assignment, const char *name, int score) {
    assignment_set_name(assignment, name);
    assignment->score = score;
}

const char *assignment_get_name(const struct assignment *assignment) {
    return assignment->name;
}

void assignment_set_score(struct assignment *assignment, int score) {
    assignment->score = score;
}

int assignment_get_score(const struct assignment *assignment) {
    return assignment->score;
}

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

struct assignment {
    char name[50];
    int score;
};

void assignment_init(struct assignment *assignment, const char *name, int score);
void assignment_set_name(struct assignment *assignment, const char *name);
const char *assignment_get_name(const struct assignment *assignment);
void assignment_set_score(struct assignment *assignment, int score);
int assignment_get_score(const struct assignment *assignment);

#endif

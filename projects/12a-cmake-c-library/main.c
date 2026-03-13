#include <stdio.h>

#include "stats.h"

int main(void) {
    int quiz_scores[] = {88, 92, 76, 95, 84};
    size_t score_count = sizeof(quiz_scores) / sizeof(quiz_scores[0]);

    printf("Stats Toolkit Demo\n");
    print_stats_report(quiz_scores, score_count);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_FIELDS 10
#define MAX_LINE_LENGTH 1024

struct College {
    char name[100];
    char program[100];
    char quota[20];
    char seat_type[30];
    char gender[30];
    int opening_rank;
    int closing_rank;
    int year;
    int round;
};

int split_csv_line(char *line, char fields[MAX_FIELDS][200]) {
    int field_index = 0, char_index = 0;
    int in_quotes = 0;
    int i;
    for ( i = 0; line[i] && field_index < MAX_FIELDS; i++) {
        if (line[i] == '"') {
            in_quotes = !in_quotes;
        } else if (line[i] == ',' && !in_quotes) {
            fields[field_index][char_index] = '\0';
            field_index++;
            char_index = 0;
        } else {
            fields[field_index][char_index++] = line[i];
        }
    }
    fields[field_index][char_index] = '\0';
    return field_index + 1;
}

int load_colleges_from_csv(const char *filename, struct College *colleges, int max) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;
    fgets(line, sizeof(line), file); // skip header

    while (fgets(line, sizeof(line), file) && count < max) {
        char fields[MAX_FIELDS][200];
        int num_fields = split_csv_line(line, fields);
        if (num_fields < 9) continue;

        strncpy(colleges[count].name, fields[0], sizeof(colleges[count].name));
        strncpy(colleges[count].program, fields[1], sizeof(colleges[count].program));
        strncpy(colleges[count].quota, fields[2], sizeof(colleges[count].quota));
        strncpy(colleges[count].seat_type, fields[3], sizeof(colleges[count].seat_type));
        strncpy(colleges[count].gender, fields[4], sizeof(colleges[count].gender));
        colleges[count].opening_rank = atoi(fields[5]);
        colleges[count].closing_rank = atoi(fields[6]);
        colleges[count].year = atoi(fields[7]);
        colleges[count].round = atoi(fields[8]);

        count++;
    }

    fclose(file);
    return count;
}

int compare(const void *a, const void *b) {
    return ((struct College *)a)->closing_rank - ((struct College *)b)->closing_rank;
}

void print_college(const struct College *c, int index) {
    printf("\n%-3d. Institute: %s\n", index + 1, c->name);
    printf("     Program : %s\n", c->program);
    printf("     Quota   : %s\n", c->quota);
    printf("     Seat Type: %s\n", c->seat_type);
    printf("     Gender  : %s\n", c->gender);
    printf("     Opening Rank: %d\n", c->opening_rank);
    printf("     Closing Rank: %d\n", c->closing_rank);
    printf("     Year: %d | Round: %d\n", c->year, c->round);
}

int matches_seat_type(const char *seat_type, const char *filter) {
    return strcasecmp(seat_type, filter) == 0 ||
           (strcasecmp(filter, "OPEN") == 0 && strncasecmp(seat_type, "OPEN", 4) == 0) ||
           (strcasecmp(filter, "EWS") == 0 && strncasecmp(seat_type, "EWS", 3) == 0) ||
           (strcasecmp(filter, "OBC-NCL") == 0 && strncasecmp(seat_type, "OBC-NCL", 7) == 0) ||
           (strcasecmp(filter, "SC") == 0 && strncasecmp(seat_type, "SC", 2) == 0) ||
           (strcasecmp(filter, "ST") == 0 && strncasecmp(seat_type, "ST", 2) == 0);
}

int main() {
    struct College colleges[5000];
    int num_colleges = load_colleges_from_csv("2020-6.csv", colleges, 5000);
	int i;
    if (num_colleges == 0) {
        printf("No college data loaded. Please check the CSV file.\n");
        return 1;
    }

    int rank, seat_choice, gender_choice;
    char seat_filter[30], gender_filter[30];

    printf("==========================================================\n");
    printf("               College Predictor Based on Rank            \n");
    printf("==========================================================\n");

    printf("Enter your JEE Rank: ");
    scanf("%d", &rank);
    getchar();

    printf("\nChoose Seat Type:\n");
    printf("1. OPEN\n2. OPEN (PwD)\n3. EWS\n4. EWS (PwD)\n5. OBC-NCL\n");
    printf("6. OBC-NCL (PwD)\n7. SC\n8. SC (PwD)\n9. ST\n10. ST (PwD)\n");
    printf("Enter your choice (1-10) or 0 to skip: ");
    scanf("%d", &seat_choice);
    getchar();

    const char *seat_options[] = {
        "", "OPEN", "OPEN (PwD)", "EWS", "EWS (PwD)",
        "OBC-NCL", "OBC-NCL (PwD)", "SC", "SC (PwD)", "ST", "ST (PwD)"
    };

    if (seat_choice >= 1 && seat_choice <= 10)
        strcpy(seat_filter, seat_options[seat_choice]);
    else
        seat_filter[0] = '\0';

    printf("\nChoose Gender Preference:\n");
    printf("1. Gender-Neutral (Co-ed)\n2. Female-only\n3. Male-only\n");
    printf("Enter your choice (1-3) or 0 to skip: ");
    scanf("%d", &gender_choice);
    getchar();

    if (gender_choice == 1) strcpy(gender_filter, "Gender-Neutral");
    else if (gender_choice == 2) strcpy(gender_filter, "Female-only");
    else if (gender_choice == 3) strcpy(gender_filter, "Male-only");
    else gender_filter[0] = '\0';

    qsort(colleges, num_colleges, sizeof(struct College), compare);

    printf("\n========= Colleges You May Get (up to 50 listed) =========\n");
    int shown = 0;
    for ( i = 0; i < num_colleges && shown < 50; i++) {
        if (colleges[i].closing_rank >= rank &&
            (strlen(seat_filter) == 0 || matches_seat_type(colleges[i].seat_type, seat_filter)) &&
            (strlen(gender_filter) == 0 || strcasecmp(colleges[i].gender, gender_filter) == 0)) {
            print_college(&colleges[i], shown);
            shown++;
        }
    }

    if (shown == 0) {
        printf("\nNo colleges found for the entered rank and filters.\n");
    }

    printf("\n==========================================================\n");
    printf("      Note: Based on 2020 Round 6 JOSAA data.             \n");
    printf("==========================================================\n");

    return 0;
}


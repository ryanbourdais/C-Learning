#include <stdio.h>
#include <string.h>
#include <stdbool.h>


struct contact {
    char name[50];
    char phone[20];
    char email[100];
};

void add_contact(struct contact *contacts, int *count) {
    if (*count >= 100) {
        printf("Contact book is full.\n");
        return;
    }
    printf("Enter name: ");
    scanf("%s", contacts[*count].name);
    printf("Enter phone: ");
    scanf("%s", contacts[*count].phone);
    printf("Enter email: ");
    scanf("%s", contacts[*count].email);
    (*count)++;
}

void remove_contact(struct contact *contacts, int *count) {
    char name[50];
    printf("Enter name of contact to remove: ");
    scanf("%s", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact removed.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

struct contact *search_contact(struct contact *contacts, int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}

void list_contacts(struct contact *contacts, int count) {
    if (count == 0) {
        printf("No contacts found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void save_contacts(struct contact *contacts, int count) {
    FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        file = fopen("contacts.txt" ,"a");
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    fclose(file);
}

void load_contacts(struct contact contacts[], int *count ) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        *count = 0;
        return;
    }
    *count = 0;
    while (*count < 100 &&
            fscanf(file, "%49[^,],%19[^,],%99[^\n]\n",
                    contacts[*count].name,
                    contacts[*count].phone,
                    contacts[*count].email) == 3) {
            (*count)++;
        }

        fclose(file);
}

int main() {
    struct contact contacts[100];
    int count = 0;
    load_contacts(contacts, &count);
    int choice;
    do {
        printf("1. Add contact\n2. Remove contact\n3. Search contact\n4. List contacts\n5. Save and Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                remove_contact(contacts, &count);
                break;
            case 3:
                {
                    char name[50];
                    printf("Enter name to search: ");
                    scanf("%s", name);
                    struct contact *contact = search_contact(contacts, count, name);
                    if (contact != NULL) {
                        printf("Name: %s, Phone: %s, Email: %s\n", contact->name, contact->phone, contact->email);
                    } else {
                        printf("Contact not found.\n");
                    }
                }
                break;
            case 4:
                list_contacts(contacts, count);
                break;
            case 5:
                save_contacts(contacts, count);
                printf("Contacts saved. Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }

    } while (1);
}
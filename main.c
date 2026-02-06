#include "patient.h"

int main() {
    struct Patient* root = NULL;
    int choice, id, age;
    char name[50], disease[50];

    while (1) {
        printf("\n--- Patient Record System using BST ---\n");
        printf("1. Insert Patient Record\n");
        printf("2. Search Patient by ID\n");
        printf("3. Display All Records (Inorder)\n");
        printf("4. Update Patient Record\n");
        printf("5. Delete Patient Record\n");
        printf("6. Count Total Patients\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Disease: ");
                scanf("%s", disease);
                root = insert(root, id, name, age, disease);
                break;

            case 2: {
                printf("Enter Patient ID to search: ");
                scanf("%d", &id);
                struct Patient* patient = search(root, id);
                if (patient != NULL)
                    printf("ID: %d | Name: %s | Age: %d | Disease: %s\n",
                           patient->id, patient->name, patient->age, patient->disease);
                else
                    printf("Patient with ID %d not found!\n", id);
                break;
            }

            case 3:
                inorder(root);
                break;

            case 4:
                printf("Enter Patient ID to update: ");
                scanf("%d", &id);
                update(root, id);
                break;

            case 5:
                printf("Enter Patient ID to delete: ");
                scanf("%d", &id);
                root = deleteNode(root, id);
                printf("Record deleted successfully!\n");
                break;

            case 6:
                printf("Total Patients: %d\n", countPatients(root));
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

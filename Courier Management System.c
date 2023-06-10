#include<stdio.h>
#include<string.h>

#define MAX_PACKAGES 100  // Maximum number of packages that can be stored

// Structure to represent a courier package
struct Package {
    int id;
    char sender[100];
    char receiver[100];
    float weight;
};

struct Package packages[MAX_PACKAGES];  // Array to store packages
int numPackages = 0;  // Current number of packages stored

// Function to add a package
void addPackage() {
    if(numPackages>=MAX_PACKAGES){
        printf("Maximum number of packages reached!\n");
        return;
    }

    struct Package newPackage;

    printf("Enter Package ID: ");
    scanf("%d", &newPackage.id);
    printf("Enter Sender Name: ");
    scanf(" %[^\n]s", newPackage.sender);
    printf("Enter Receiver Name: ");
    scanf(" %[^\n]s", newPackage.receiver);
    printf("Enter Package Weight (in kg): ");
    scanf("%f", &newPackage.weight);

    packages[numPackages++] = newPackage;

    printf("Package added successfully!\n");
}

// Function to display all packages
void displayPackages(){
    if (numPackages == 0) {
        printf("No packages found!\n");
        return;
    }

    printf("ID\tSender\t\tReceiver\tWeight (kg)\n");
    int i=0;
    for (i=0;i<numPackages; i++) {
        printf("%d\t%s\t%s\t%.2f\n", packages[i].id, packages[i].sender, packages[i].receiver, packages[i].weight);
    }
}

// Function to search for a package by ID
void searchPackage() {
    if (numPackages == 0) {
        printf("No packages found!\n");
        return;
    }

    int searchId;
    printf("Enter Package ID to search: ");
    scanf("%d", &searchId);

    int found = 0;
    int i=0;
    for (i = 0; i < numPackages; i++) {
        if (packages[i].id == searchId) {
            printf("ID\tSender\t\tReceiver\tWeight (kg)\n");
            printf("%d\t%s\t%s\t%.2f\n", packages[i].id, packages[i].sender, packages[i].receiver, packages[i].weight);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Package not found!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nCourier Management System\n");
        printf("1. Add Package\n");
        printf("2. Display Packages\n");
        printf("3. Search Package\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPackage();
                break;
            case 2:
                displayPackages();
                break;
            case 3:
                searchPackage();
                break;
            case 4:
                printf("Thank you for using the Courier Management System!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


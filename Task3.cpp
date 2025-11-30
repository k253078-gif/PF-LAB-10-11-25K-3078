#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_FLIGHTS 5

struct Flight {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[20];
    int availableSeats;
};

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getPositiveInt(const char *prompt, int maxValue) {
    int num;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &num) != 1 || num <= 0 || num > maxValue) {
            printf(" Invalid input! Enter a positive number up to %d.\n", maxValue);
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return num;
        }
    }
}

int isValidDateFormat(const char *date) {
    if (strlen(date) != 10)
        return 0;
    return (isdigit(date[0]) && isdigit(date[1]) &&
            date[2] == '/' &&
            isdigit(date[3]) && isdigit(date[4]) &&
            date[5] == '/' &&
            isdigit(date[6]) && isdigit(date[7]) &&
            isdigit(date[8]) && isdigit(date[9]));
}

void getValidatedCity(const char *prompt, char *str, int size) {
    while (1) {
        printf("%s", prompt);
        if (fgets(str, size, stdin) == NULL) {
            printf(" Input error! Try again.\n");
            continue;
        }

        str[strcspn(str, "\n")] = '\0';

        if (strlen(str) == 0) {
            printf(" Invalid input! String cannot be empty.\n");
            continue;
        }

        int valid = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            if (!isalpha((unsigned char)str[i]) && str[i] != ' ') {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf(" Invalid input! Only letters and spaces allowed.\n");
            continue;
        }

        break;
    }
}

void getValidatedDate(const char *prompt, char *date, int size) {
    while (1) {
        printf("%s", prompt);
        if (fgets(date, size, stdin) == NULL) {
            printf(" Input error! Try again.\n");
            continue;
        }

        date[strcspn(date, "\n")] = '\0';

        if (!isValidDateFormat(date)) {
            printf(" Invalid date format! i.e: 01/01/2001.\n");
            continue;
        }

        break;
    }
}

// Display one flight
void displayFlight(struct Flight f) {
    printf("\n------------------------------\n");
    printf("Flight Number   : %d\n", f.flightNumber);
    printf("Departure City  : %s\n", f.departureCity);
    printf("Destination City: %s\n", f.destinationCity);
    printf("Date            : %s\n", f.date);
    printf("Available Seats : %d\n", f.availableSeats);
}

// Display all flights
void displayAllFlights(struct Flight flights[], int total) {
    printf("\n======= All Flights =======\n");
    for (int i = 0; i < total; i++) {
        displayFlight(flights[i]);
    }
}

// Find flight by number
int findFlight(struct Flight flights[], int total, int number) {
    for (int i = 0; i < total; i++) {
        if (flights[i].flightNumber == number)
            return i;
    }
    return -1;
}

// Book a seat
void bookSeat(struct Flight *f) {
    if (f->availableSeats > 0) {
        f->availableSeats--;
        printf("\n Seat booked successfully!\n");
        printf("Remaining Seats: %d\n", f->availableSeats);
    } else {
        printf("\n Sorry, no seats available on this flight.\n");
    }
}

// Add flight details (with duplicate check)
void addFlight(struct Flight flights[], int index, int total) {
    printf("\nEnter details for Flight %d:\n", index + 1);

    while (1) {
        int number = getPositiveInt("Enter flight number: ", 99999);
        if (findFlight(flights, total, number) != -1) {
            printf(" Flight number already exists! Enter a unique number.\n");
        } else {
            flights[index].flightNumber = number;
            break;
        }
    }

    getValidatedCity("Enter departure city: ", flights[index].departureCity, 50);
    getValidatedCity("Enter destination city: ", flights[index].destinationCity, 50);

    while (strcmp(flights[index].departureCity, flights[index].destinationCity) == 0) {
        printf(" Departure and destination cannot be the same!\n");
        getValidatedCity("Enter destination city again: ", flights[index].destinationCity, 50);
    }

    getValidatedDate("Enter date (DD/MM/YYYY): ", flights[index].date, 20);
    flights[index].availableSeats = getPositiveInt("Enter available seats: ", 1000);
}

int main() {
    struct Flight flights[MAX_FLIGHTS];
    int totalFlights = 0;
    int choice;

    totalFlights = getPositiveInt("Enter number of flights (1 to 5): ", MAX_FLIGHTS);

    for (int i = 0; i < totalFlights; i++) {
        addFlight(flights, i, i);  // pass i as total so far for duplicate checking
    }

    do {
        printf("\n\n========== Flight Menu ==========\n");
        printf("1. Display All Flights\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf(" Invalid input! Enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                displayAllFlights(flights, totalFlights);
                break;
            case 2: {
                int num = getPositiveInt("Enter flight number to book a seat: ", 99999);
                int index = findFlight(flights, totalFlights, num);
                if (index != -1)
                    bookSeat(&flights[index]);
                else
                    printf(" Flight not found!\n");
                break;
            }
            case 3:
                printf("\nExiting program... \n");
                break;
            default:
                printf(" Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}


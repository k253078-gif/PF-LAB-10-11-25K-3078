#include <stdio.h>
#include <string.h>
#define max_players 50
typedef struct {
    char name[50];
    int age;
    char position[50];
} Player;

typedef struct {
    char teamName[50];
    char sport[50];
    Player players[max_players];
    int totalPlayers;
} Team;

void addPlayer(Team *t) {
    getchar(); 

    printf("Enter player name: ");
    fgets(t->players[t->totalPlayers].name, sizeof(t->players[t->totalPlayers].name), stdin);
    t->players[t->totalPlayers].name[strcspn(t->players[t->totalPlayers].name, "\n")] = '\0';

    printf("Enter player age: ");
    scanf("%d", &t->players[t->totalPlayers].age);
    getchar();

    printf("Enter player position: ");
    fgets(t->players[t->totalPlayers].position, sizeof(t->players[t->totalPlayers].position), stdin);
    t->players[t->totalPlayers].position[strcspn(t->players[t->totalPlayers].position, "\n")] = '\0';

    t->totalPlayers++;

    printf("\nPlayer added successfully!\n");
}

void searchByPosition(Team t) {
    char searchPos[50];
    int found = 0;

    getchar();

    printf("Enter position to search: ");
    fgets(searchPos, sizeof(searchPos), stdin);
    searchPos[strcspn(searchPos, "\n")] = '\0';

    printf("\nPlayers with position '%s':\n", searchPos);

    for (int i = 0; i < t.totalPlayers; i++) {
        if (strcmpi(t.players[i].position, searchPos) == 0) {
            printf("\nName: %s\n", t.players[i].name);
            printf("Age: %d\n", t.players[i].age);
            printf("Position: %s\n", t.players[i].position);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo players found for this position.\n");
    }
}

void displayTeam(Team t) {
    printf("\n=== Team Details ===\n");
    printf("Team Name: %s\n", t.teamName);
    printf("Sport: %s\n", t.sport);
    printf("Total Players: %d\n", t.totalPlayers);

    if (t.totalPlayers == 0) {
        printf("\nNo players added yet.\n");
        return;
    }

    printf("\n--- Players ---\n");
    for (int i = 0; i < t.totalPlayers; i++) {
        printf("\nPlayer %d:\n", i + 1);
        printf("Name: %s\n", t.players[i].name);
        printf("Age: %d\n", t.players[i].age);
        printf("Position: %s\n", t.players[i].position);
    }
}

int main() {
    Team t;
    int choice;

    t.totalPlayers = 0;

    printf("Enter Team Name: ");
    fgets(t.teamName, sizeof(t.teamName), stdin);
    t.teamName[strcspn(t.teamName, "\n")] = '\0';

    printf("Enter Sport: ");
    fgets(t.sport, sizeof(t.sport), stdin);
    t.sport[strcspn(t.sport, "\n")] = '\0';

    while (1) {
        printf("\n=== Team Management Menu ===\n");
        printf("1. Add Player\n");
        printf("2. Search Player by Position\n");
        printf("3. Display Team Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPlayer(&t);
                break;

            case 2:
                searchByPosition(t);
                break;

            case 3:
                displayTeam(t);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

#include <stdio.h>
#include <string.h>
#define maxvalue 100
typedef struct 
{
    char title[100];
    char genre[50];
    char director[100];
    int releaseYear;
    float rating;
} Movie;
void addMovie(Movie movies[], int *count) 
{
    getchar(); 

    printf("Enter movie title: ");
    fgets(movies[*count].title, sizeof(movies[*count].title), stdin);
    movies[*count].title[strcspn(movies[*count].title, "\n")] = '\0';

    printf("Enter movie genre: ");
    fgets(movies[*count].genre, sizeof(movies[*count].genre), stdin);
    movies[*count].genre[strcspn(movies[*count].genre, "\n")] = '\0';

    printf("Enter director name: ");
    fgets(movies[*count].director, sizeof(movies[*count].director), stdin);
    movies[*count].director[strcspn(movies[*count].director, "\n")] = '\0';

    printf("Enter release year: ");
    scanf("%d", &movies[*count].releaseYear);

    printf("Enter movie rating (0 to 10): ");
    scanf("%f", &movies[*count].rating);

    (*count)++;
    printf("\nMovie added successfully!\n");
}

void searchByGenre(Movie movies[], int count) {
    char searchGenre[50];
    int found = 0;

    getchar(); 
    printf("Enter genre to search: ");
    fgets(searchGenre, sizeof(searchGenre), stdin);
    searchGenre[strcspn(searchGenre, "\n")] = '\0';

    printf("\nMovies with genre '%s':\n", searchGenre);

    for (int i = 0; i < count; i++) {
        if (strcmpi(movies[i].genre, searchGenre) == 0) {
            printf("\nTitle: %s\n", movies[i].title);
            printf("Genre: %s\n", movies[i].genre);
            printf("Director: %s\n", movies[i].director);
            printf("Release Year: %d\n", movies[i].releaseYear);
            printf("Rating: %.1f\n", movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo movies found for this genre.\n");
    }
}

void displayAllMovies(Movie movies[], int count) {
    if (count == 0) {
        printf("\nNo movies to display.\n");
        return;
    }

    printf("\n=== All Movies ===\n");

    for (int i = 0; i < count; i++) {
        printf("\nMovie %d:\n", i + 1);
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Release Year: %d\n", movies[i].releaseYear);
        printf("Rating: %.1f\n", movies[i].rating);
    }
}

int main() {
    Movie movies[maxvalue];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Movie Management System ===\n");
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;

            case 2:
                searchByGenre(movies, count);
                break;

            case 3:
                displayAllMovies(movies, count);
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

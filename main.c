#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a player
typedef struct {
    char full_name[50];
    int age;
    char player_role[50];
    int odi_match;
    int total_run;
    int highest_run;
} Player;

// Function prototypes
void read_players(const char *filename, Player players[], int *num_players);
void show_all_players(Player players[], int num_players);
void show_player_information(Player players[], int num_players, const char *player_name);
void show_most_experienced_player(Player players[], int num_players);
void show_the_new_commer_player(Player players[], int num_players);

// Define other functions for different options similarly

int main() {
    char filename[100];
    printf("Enter the input file name: ");
    scanf("%s", filename);

    // Array to store players
    Player players[50]; // Assuming a maximum of 50 players
    int num_players = 0; // Number of players read from the file

    // Read player data from the file
    read_players(filename, players, &num_players);

    // Show menu options in an infinite loop
    int choice;
    char playerName[100];
    while (1) {
        printf("\nMenu:\n");
        printf("1. Show All Players\n");
        printf("2. Show A Particular player information\n");
        printf("3. Show the MOST Experienced Player (MEP)\n");
        printf("4. Show the New Commer Player (NCP)\n");
        // Add other menu options similarly
        printf("9. Exit/Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                show_all_players(players, num_players);
                break;
            case 2:
                printf("\nEnter player name:");
                scanf(" %[^\n]s", playerName);
                show_player_information(players,num_players,playerName);
                break;
            case 3:
                show_most_experienced_player(players, num_players);
                break;
            // Add cases for other menu options similarly
            case 4:
                show_the_new_commer_player(players, num_players);
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

// Function to read player data from the file
void read_players(const char *filename, Player players[], int *num_players) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(file, "%d", num_players);
    getchar(); // Consume newline character

    for (int i = 0; i < *num_players; i++) {
        fscanf(file, " %[^\n] %d %[^\n] %d %d %d\n",
               players[i].full_name, &players[i].age, players[i].player_role,
               &players[i].odi_match, &players[i].total_run, &players[i].highest_run);
    }

    fclose(file);
}

// Function to show information of all players
void show_all_players(Player players[], int num_players) {
    printf("\nAll Players:\n");
    for (int i = 0; i < num_players; i++) {
        printf("\nName:%s\nAge:%d\nPlayer Role:%s\nOdi Match Played:%d\nTotal Run:%d\nHighest Run:%d\n", players[i].full_name, players[i].age,
               players[i].player_role, players[i].odi_match, players[i].total_run, players[i].highest_run);
    }
}

// Implement other functions similarly for different menu options
void show_player_information(Player players[], int num_players, const char *player_name) {
    // Search for the player with the given name
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].full_name, player_name) == 0) {
            printf("\nName:%s\nAge:%d\nPlayer Role:%s\nOdi Match Played:%d\nTotal Run:%d\nHighest Run:%d\n", players[i].full_name, players[i].age,
                   players[i].player_role, players[i].odi_match, players[i].total_run, players[i].highest_run);
            return; // Exit the function after printing player information
        }
    }
    // If player not found, print message
    printf("Player not found.\n");
}


void show_most_experienced_player(Player players[], int num_players){
        int mep_index =0;
        for(int i=0; i<num_players;i++){



            if((players[i].odi_match) >= (players[mep_index].odi_match)){
                mep_index = i;
            }
        }

        printf("\nThe most experienced player:%s\n\n",players[mep_index].full_name);


}

void show_the_new_commer_player(Player players[], int num_players){

        int newCom_index =0;
        for(int i=0; i<num_players;i++){



            if((players[i].age) <= (players[newCom_index].age)){
                newCom_index = i;
            }
        }

        printf("\nThe New Commer Player:%s\n",players[newCom_index].full_name);


}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

typedef struct {
    char full_name[50];
    int age;
    char player_role[50];
    int odi_match;
    int total_run;
    int highest_run;
} Player;

void read_players(const char *filename, Player players[], int *num_players); // Team work
void all_players(Player players[], int num_players); // Faiyaj
void player_information(Player players[], int num_players); // Faiyaj
void MEP(Player players[], int num_players); // Faiyaj
void NCP(Player players[], int num_players); // Irfad
void TSP(Player players[], int num_players); // Irfad
void HHP(Player players[], int num_players);//Arefin
void HRTP(Player players[], int num_players);//Arefin
void MVP(Player players[], int num_players); // Irfad
void the_allrounders(Player players[], int num_players);//Arefin

//Team Work
int main() {
    char file[100];
    printf("Enter the input file name(input.txt): ");
    scanf("%s", file);

    // Array to store players
    Player players[50]; // Assuming a maximum of 50 players
    int num_players = 0; // Number of players read from the file

    // Read player data from the file
    read_players(file, players, &num_players);

    // Show menu options in an infinite loop
    int choice;

    while (1) {
        Sleep(500);
        printf("\nMenu:\n");
        printf("1. Show All Players\n");
        printf("2. Show A Particular player information\n");
        printf("3. Show the MOST Experienced Player (MEP)\n");
        printf("4. Show the New Commer Player (NCP)\n");
        printf("5. Show the top scorer player(TSP)\n");
        printf("6. Show the hard hitter player(HHP):\n");
        printf("7. Show the Highest Run Taker Player (HRTP)\n");
        printf("8. Show the Most Valuable Player (MVP)\n");
        printf("9. Show the Allrounders\n");
        printf("10. Exit/Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            all_players(players, num_players);
        } else if (choice == 2) {
            player_information(players, num_players);
        } else if (choice == 3) {
            MEP(players, num_players);
        } else if (choice == 4) {
            NCP(players, num_players);
        } else if (choice == 5) {
            TSP(players, num_players);
        }else if (choice==6) {
            HHP(players, num_players);
        } else if (choice==7) {
            HRTP(players, num_players);
        } else if (choice == 8) {
            MVP(players, num_players);
        } else if (choice==9) {
            the_allrounders(players, num_players);
        } else if (choice == 10) {
            printf("Exiting program.\n");
            exit(0);
        } else {
            printf("Invalid choice. Please, enter a valid option.\n");
        }
    }

    return 0;
}

// Team Work
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

// Function to display information of all players
//Complete By Faiyaj
void all_players(Player players[], int num_players) {
    Sleep(1000);
    printf("\nAll Players:\n");
    for (int i = 0; i < num_players; i++) {
        Sleep(1000);
        printf("\nName:%s\nAge:%d\nPlayer Role:%s\nOdi Match Played:%d\nTotal Run:%d\nHighest Run:%d\n", players[i].full_name, players[i].age,
               players[i].player_role, players[i].odi_match, players[i].total_run, players[i].highest_run);
    }
}

// Function to display information of a specific player
//Complete By Faiyaj
void player_information(Player players[], int num_players) {
    char player_name[100];
    printf("\nEnter player name:");
    scanf(" %[^\n]s", player_name);
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].full_name, player_name) == 0) {
            Sleep(1000);
            printf("\nName:%s\nAge:%d\nPlayer Role:%s\nOdi Match Played:%d\nTotal Run:%d\nHighest Run:%d\n", players[i].full_name, players[i].age,
                   players[i].player_role, players[i].odi_match, players[i].total_run, players[i].highest_run);
            return; // Exit the function after printing player information
        }
    }
    // If player not found, print message
    printf("Player not found.\n");
}

// Function to display the most experienced player
//Complete By Faiyaj
void MEP(Player players[], int num_players) {
    int mep_index = 0;
    for (int i = 0; i < num_players; i++) {
        if (players[i].odi_match >= players[mep_index].odi_match) {
            mep_index = i;
        }
    }
    Sleep(1000);
    printf("\nThe most experienced player: %s\n\n\n", players[mep_index].full_name);
    Sleep(500);
}

// Function to display the new comer player
//Complete By Irfad
void NCP(Player players[], int num_players) {
    int min_age = players[0].age;
    int ncp_index = 0;

    for (int i = 1; i < num_players; i++) {
        if (players[i].age <= min_age) {
            min_age = players[i].age;
            ncp_index = i;
        }
    }
    Sleep(1000);
    printf("\nThe New Comer Player: %s\n\n\n", players[ncp_index].full_name);
    Sleep(500);
}

// Function to display the top scorer player
//Complete By Irfad
void TSP(Player players[], int num_players) {
    int max_runs = players[0].total_run;
    int tps_index = 0;

    for (int i = 1; i < num_players; i++) {
        if (players[i].total_run > max_runs) {
            max_runs = players[i].total_run;
            tps_index = i;
        }
    }
    Sleep(1000);
    printf("\nThe top scorer player: %s\n\n\n", players[tps_index].full_name);
    Sleep(500);
}
// Function to display the Hard Hitter Player
//Complete By Arefin
void HHP(Player players[], int num_players)
{
    float avg[num_players];
    for(int i=0; i<num_players;i++)
    {
        avg[i] = (float)players[i].total_run / players[i].odi_match;
    }

    float temp = avg[0];
    int j=0;
    for(int i=0; i<num_players;i++)
    {
        if(avg[i] > temp)
        {
            temp = avg[i];
            j = i;
        }
    }
    Sleep(1000);
    printf("\nThe hard hitter player is:%s\n\n\n",players[j].full_name);
    Sleep(500);
}
// Function to display the Highest Run Taker Player
//Complete By Arefin
void HRTP(Player players[], int num_players)
{
    int temp = players[0].highest_run;
    int j=0;
    for(int i=0; i<num_players;i++)
    {
        if(players[i].highest_run > temp)
        {
            temp = players[i].highest_run;
            j = i;
        }
    }
    Sleep(1000);
    printf("\nThe Highest Run Taker Player is:%s\n\n\n",players[j].full_name);
    Sleep(500);
}
// Function to display the  MOST Valuable Player
//Complete By Irfad
void MVP(Player players[], int num_players) {
    int mvp_index = 0;
    float max_value = 0;

    for (int i = 0; i < num_players; i++) {
        float value = players[i].age + players[i].odi_match + players[i].total_run + players[i].highest_run +
                      (players[i].total_run / players[i].odi_match) + (players[i].highest_run / players[i].age);
        if (strcmp(players[i].player_role, "Allrounder") == 0) {
            value += 50;
        }

        if (value >= max_value) {
            max_value = value;
            mvp_index = i;
        }
    }
    Sleep(1000);
    printf("\nThe Most Valuable Player: %s\n\n\n", players[mvp_index].full_name);
}
// Function to display the Allrounders
//Complete By Arefin
void the_allrounders(Player players[], int num_players)
{
    int flag=0;
    printf("\n");
    for(int i=0; i<num_players;i++)
    {
        if (strcmp(players[i].player_role, "Allrounder") == 0)
        {   Sleep(1000);
            printf("%s \n",players[i].full_name);
            flag++;
        }
    }
    if(flag==0)
    {   Sleep(500);
        printf("There are no allrounders");
    }
}

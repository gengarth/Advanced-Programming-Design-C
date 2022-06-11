/*
* COP 3515 – Fall Semester, 2020
*
* Homework #2: The Hospital Bed Problem
*
* Charles Denney
*
*/
#include <stdio.h>
#include <stdlib.h>

#define DATA_FILE "C:\\Users\\cbden\\OneDrive\\1School Stuff\\hwData2.txt"
void simpleTower(char sex[10][10], int release[10][10]);
void complexTower(char sex[10][10], int release[10][10]);

int main()
{
    FILE *fp;


    char patientSex[10][10];
    int daysOut[10][10];
    int userRequest;

    fp = fopen(DATA_FILE, "r");
    if (fp == NULL){
        printf("Can't open file.");
        return 1;
    }

    for(int row = 0; row < 10; row++){
        for(int column = 0; column < 10; column++){
            fscanf(fp, " %c", &patientSex[row][column]);
            fscanf(fp, " %d", &daysOut[row][column]);
        }
    }
    fclose(fp);

    printf("Enter '1' for simple version or '2' for complex version: ");
    scanf(" %d", &userRequest);

    if(userRequest == 1){
        simpleTower(patientSex, daysOut);
    }
    else if(userRequest == 2){
        complexTower(patientSex, daysOut);
    }
    else{
        printf("Incorrect selection.");
    }

}

//Function that produces the simple tower.
void simpleTower(char sex[10][10], int release[10][10]){
    int patientsReleased = 0;
    int totalPatients = 100;
    int emptyBeds = 0;

    for (int day = 0; day < 31; day++){
        int covidFloors = 10;
        int freeFloors = 0;
        int floorChecker = 0;

        //checks release date
        for(int row = 0; row < 10; row++){
            for(int column = 0; column < 10; column++){
               if(release[row][column] == day){
                    sex[row][column] = '.';
                    patientsReleased++;
               }
            }
        }

        //checks for free floors
        for(int row = 0; row < 10; row++){
            for(int column = 0; column < 10; column++){
               if((sex[row][column] == 'M') || (sex[row][column] == 'F')){
                    break;
               }
               floorChecker++;
               //adds a free floor every time there are ten '.' in a row
               if(floorChecker == 10){
                freeFloors++;
               }
            }
            floorChecker = 0;
        }

        //prints iteration if at least ten patients were released
        if(patientsReleased >= 10){
            for(int row = 0; row < 10; row++){
                for(int column = 0; column < 10; column++){
                    printf( " %c", sex[row][column]);
                }
                printf("\n");
            }
            printf("\n");

            //gets totals from change in patients and floors
            totalPatients -= patientsReleased;
            emptyBeds += patientsReleased;
            covidFloors -= freeFloors;

            //Prints session data
            printf("Number of patients:      %d\n", totalPatients);
            printf("Number of empty beds:    %d\n", emptyBeds);
            printf("Number of Covid floors:  %d\n", covidFloors);
            printf("Number of free floors:   %d\n\n", freeFloors);

            patientsReleased = 0;
        }
    }
}

//Function that produces the simple tower.
void complexTower(char sex[10][10], int release[10][10]){
    int patientsReleased = 0;
    int totalPatients = 100;
    int emptyBeds = 0;

    for (int day = 0; day < 31; day++){
        int covidFloors = 10;
        int freeFloors = 0;
        int floorChecker = 0;
        char sorter[10][10];

        strcpy(sorter, sex);
        //checks release date
        for(int row = 0; row < 10; row++){
            for(int column = 0; column < 10; column++){
               if(release[row][column] == day){
                    sex[row][column] = '.';
                    patientsReleased++;
               }
            }
        }

        //sorts every iteration
        for(int row = 0; row < 10; row++){
            for(int column = 0; column < 10; column++){
               if((sorter[row][column] == 'M') || (sorter[row][column] == 'F')){
                    for (int revRow = 10; revRow > 0; revRow--){
                        for(int revColumn = 10; revColumn > 0; revColumn--){
                            if(sorter[revRow][revColumn] == '.'){
                                sorter[revRow][revColumn] = sorter[row][column];
                                sorter[row][column] = '.';

                            }
                        }
                    }
               }
            }
        }

        //checks for free floors
        for(int row = 0; row < 10; row++){
            for(int column = 0; column < 10; column++){
               if((sorter[row][column] == 'M') || (sorter[row][column] == 'F')){
                    break;
               }
               floorChecker++;
               //adds a free floor every time there are ten '.' in a row
               if(floorChecker == 10){
                freeFloors++;
               }
            }
            floorChecker = 0;
        }

        //prints iteration if at least ten patients were released
        if(patientsReleased >= 10){
            for(int row = 0; row < 10; row++){
                for(int column = 0; column < 10; column++){
                    printf( " %c", sorter[row][column]);
                }
                printf("\n");
            }
            printf("\n");

            //gets totals from change in patients and floors
            totalPatients -= patientsReleased;
            emptyBeds += patientsReleased;
            covidFloors -= freeFloors;

            //Prints session data
            printf("Number of patients:      %d\n", totalPatients);
            printf("Number of empty beds:    %d\n", emptyBeds);
            printf("Number of Covid floors:  %d\n", covidFloors);
            printf("Number of free floors:   %d\n\n", freeFloors);

            patientsReleased = 0;
        }
    }
}

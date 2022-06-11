#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DATA_FILE "C:\\Users\\cbden\\OneDrive\\1School Stuff\\hw3Data.txt"

//Data structure for patients
struct Patient{
    char sex[100];
    char condition[100];
    int age[100];
    bool gettingBetter[100];
    int daysSinceChange[100]
};
//Global declaration so that functions can edit database
struct Patient patient;

//Function declarations
void printTower();
void conditionChanger();
void daysSinceSetter();

int main()
{
    FILE *fp;
    int day = 0;
    int numPatients = 100;

    //Opens the homework data file to read in
    fp = fopen(DATA_FILE, "r");
    if (fp == NULL){
        printf("Can't open file.");
        return 1;
    }

    //Initializes sex and condition arrays for the tower
    for(int i = 0; i < 100; i++){
        fscanf(fp, " %c", &patient.sex[i]);
        fscanf(fp, " %c", &patient.condition[i]);
        fscanf(fp, " %d", &patient.age[i]);
    }
    fclose(fp);

    //Calls function to print initial tower
    printTower();

    //Sets up initial values for admitted patients
    daysSinceSetter();

    while(numPatients > 0){
        conditionChanger();
        numPatients -= 10;
        printTower();
    }

    return 0;
}

//Function to print both versions of Tower A
void printTower(){
    printf("Tower A patient gender:\n");
    for(int i = 0; i < 100; i++){
        if(i % 10 == 0){
            printf("\n");
        }
        printf(" %c", patient.sex[i]);

    }
    printf("\n\n");

    printf("Tower A patient condition:\n");
    for(int i = 0; i < 100; i++){
        if(i % 10 == 0){
            printf("\n");
        }
        printf(" %c", patient.condition[i]);

    }
    printf("\n\n");

}

//Checks patient condition and changes it based on probability of getting worse or better
void conditionChanger(){
    int changeProbabilty = 0;

    for(int i = 0; i < 100; i++){

        //checks if a patient continues to get worse
        //if patient gets worse, won't be able to get better for 3 days
        if(!patient.gettingBetter[i]){
            changeProbabilty = (rand() % 100);
            if ((patient.condition[i] == 'G') && (changeProbabilty > 50)){
                    patient.condition[i] = 'Y';
                    patient.daysSinceChange[i] = (-1);
            }
            else if ((patient.condition[i] == 'Y') && (changeProbabilty > 60)){
                    patient.condition[i] = 'R';
                    patient.daysSinceChange[i] = (-1);
            }
            else if ((patient.condition[i] == 'R') && (changeProbabilty > 80)){
                    patient.condition[i] = 'P';
                    patient.daysSinceChange[i] = (-1);
            }
            else if(patient.daysSinceChange[i] >= 3){
                patient.gettingBetter[i] = true;
            }
        }

        if(patient.gettingBetter[i]){

        }

    }
}

//Sets initial daysSinceChange to keep 'P' patients from getting better for 3 days
void daysSinceSetter(){
    for(int i; i < 100; i++){
        if(patient.condition[i] != 'P'){
            patient.daysSinceChange[i] = 3;
        }
    }
}


/*
* COP 3515 – Fall, 2020
*
* Homework #4: Testing The Vaccine
*
* Charles Denney
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DATA_FILE "C:\\Users\\cbden\\OneDrive\\1School Stuff\\hw#4Data.txt"

struct Patient{
        char sex[200];
        int age[200];
        int tCell[100];
        int painSwelling[100];
        int fever[100];
        int chills[100];
        int fatigue[100];
        int headache[100];
        int aches[100];
        int immunity [200];
        int gotSick[500];
    };

void printVaccines(bool vaccines[4]);
void finalPrint(bool vaccines[4]);

int main()
{
    FILE *fp1, *fp2;
    char c;
    bool vaccines[4] = {true,true,true,true};

    //Opens the homework data file to read in
    fp1 = fopen(DATA_FILE, "r");
    if (fp1 == NULL){
        printf("Can't open file.");
        return 1;
    }

    //opens a file to write decryption
    fp2 = fopen("dataDecrypted.txt", "w");
    if (fp2 == NULL){
        printf("Can't open file.");
        return 1;
    }

    //loop to read data, decrypt it, then write to a new file
    while((c = fgetc(fp1)) != EOF){

        if(c != '\n'){
            fputc(c - 3, fp2);
        }
        else{
            fputc(c, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);

    //opens decrypted data for reading
    fp2 = fopen("dataDecrypted.txt", "r");
    if (fp2 == NULL){
        printf("Can't open file.");
        return 1;
    }

    struct Patient phase0;

    //scans in decrypted data for phase 0
    for(int i = 0; i < 60; i++){
        fscanf(fp2, " %c", &phase0.sex[i]);
        fscanf(fp2, " %d", &phase0.age[i]);
        fscanf(fp2, " %d", &phase0.tCell[i]);
    }

    printf("Phase 0:\n");

    //Loop to determine if tCell over
    //Math inside of expressions is necessary to hit the right array index
    int count = 0;
    int iteration = 1;
    while (count < 4){
        int tCellOverCount = 0;
        for(int i = (15 * count); i < (15 * iteration); i++){
            if(phase0.tCell[i] > 1200){
                tCellOverCount += 1;
            }
        }

        //Fails a vaccine if over too many tCell cases
        if(tCellOverCount > 10){
            vaccines[count] = false;
        }
        count++;
        iteration++;
    }


    printVaccines(vaccines);

    struct Patient phase1;

    //scans in decrypted data for phase 1
    for(int i = 0; i < 60; i++){
        fscanf(fp2, " %c", &phase1.sex[i]);
        fscanf(fp2, " %d", &phase1.age[i]);
        fscanf(fp2, " %d", &phase1.painSwelling[i]);
        fscanf(fp2, " %d", &phase1.fever[i]);
        fscanf(fp2, " %d", &phase1.chills[i]);
        fscanf(fp2, " %d", &phase1.fatigue[i]);
        fscanf(fp2, " %d", &phase1.headache[i]);
        fscanf(fp2, " %d", &phase1.aches[i]);
    }

    printf("Phase 1:\n");

    //Reintialize count and iteration for next while loop
    count = 0;
    iteration = 1;
    //Loop to find side effects in patients
    while(count < 3){
        int patientsWithSideEffects = 0;
        for(int i = (15 * count); i < (15 * iteration); i++){
            if((phase1.painSwelling[i] || phase1.fever[i] || phase1.chills[i] || phase1.fatigue[i] || phase1.headache[i] || phase1.aches[i]) > 0 ){
                patientsWithSideEffects +=1;
            }
        }
        if(patientsWithSideEffects > 4){
            vaccines[count] = false;

        }
        count++;
        iteration++;

    }

     printVaccines(vaccines);

     struct Patient phase2;

    //scans in data for phase 2
     for(int i = 0; i < 200; i++){
        fscanf(fp2, " %c", &phase2.sex[i]);
        fscanf(fp2, " %d", &phase2.age[i]);
        fscanf(fp2, " %d", &phase2.immunity[i]);
     }

     printf("Phase 2:\n");
    //Reintialize count and iteration for next while loop
    count = 0;
    iteration = 1;
    //loop to find days of immunity
    while(count < 2){
        int under60Days = 0;
        for(int i = (100 * count) ; i < (100 * iteration); i ++){
            if(phase2.immunity[i] < 60){
                under60Days ++;
            }
        }
        if((count == 0) && (under60Days > 50)){
            vaccines[0] = false;
        }
        if((count == 1) && (under60Days > 50)){
            vaccines[3] = false;
        }
        count++;
        iteration++;
    }

    printVaccines(vaccines);

    struct Patient phase3;

    //scans in data for phase 3
     for(int i = 0; i < 500; i++){
        fscanf(fp2, " %c", &phase3.sex[i]);
        fscanf(fp2, " %d", &phase3.age[i]);
        fscanf(fp2, " %d", &phase3.gotSick[i]);
     }

     printf("Phase 3:\n");

    //loop to find if more than 20% of patients got sick again
    while(count < 1){
        int sickCount = 0;
        for(int i = 0; i < 500; i++){

            if(phase3.gotSick[i]){
                sickCount++;
        }
        if(sickCount > 100){
            vaccines[3] = false;
        }
        }
    }

    printVaccines(vaccines);

    finalPrint(vaccines);

    fclose(fp2);

    return 0;

}

void printVaccines(bool vaccines[4]){
    if(vaccines[0] == true){
        printf("AstraZeneca : Pass\n");
    }
    else{
        printf("AstraZeneca : Fails\n");
    }

    if(vaccines[1] == true){
        printf("Johnson & Johnson : Pass\n");
    }
    else{
        printf("Johnson & Johnson : Fails\n");
    }
    if(vaccines[2] == true){
        printf("Moderna : Pass\n");
    }
    else{
        printf("Moderna : Fails\n");
    }
    if(vaccines[3] == true){
        printf("Novavax : Pass\n\n");
    }
    else{
        printf("Novavax : Fails\n\n");
    }

}

void finalPrint(bool vaccines[4]){
    if(vaccines[0] == true){
        printf("AstraZeneca passes the trials.\n");
    }
    else{
        printf("AstraZeneca fails the trials. \n");
    }

    if(vaccines[1] == true){
        printf("Johnson & Johnson passes the trials.\n");
    }
    else{
        printf("Johnson & Johnson fails the trials.\n");
    }
    if(vaccines[2] == true){
        printf("Moderna passes the trials.\n");
    }
    else{
        printf("Moderna fails the trials.\n");
    }
    if(vaccines[3] == true){
        printf("Novavax passes the trials.\n\n");
    }
    else{
        printf("Novavax fails the trials.\n\n");
    }
}

#include <stdio.h>
#include <stdlib.h>

#define DATA_FILE "C:\\Users\\cbden\\OneDrive\\1School Stuff\\hwData.txt"
/*
*COP 3515 - Fall Semester 200
*
*Homework #1: Helping the Governor Out
*
*Charles Denney
*/

int main()
{
    FILE* fp;

    char sizeCounter[5];
    int indexSize = 0;
    int index = 0;
    int totalMales = 0;
    int posMales = 0;
    int totalFemales = 0;
    int posFemales = 0;
    int posMaleTotalAge = 0;
    int posMaleAverageAge = 0;
    int posFemaleTotalAge = 0;
    int posFemaleAverageAge = 0;
    int ageHolder = 0;
    int negMaleAverageAge = 0;
    int negFemaleAverageAge = 0;
    int negMaleTotalAge = 0;
    int negFemaleTotalAge = 0;
    int posTotalWeightMale = 0;
    int posAverageWeightMale = 0;
    int posTotalWeightFemale = 0;
    int posAverageWeightFemale = 0;
    int posTotalHeightMales = 0;
    int posAverageHeightMales = 0;
    int posAverageHeightFemales = 0;
    int posTotalHeightFemales = 0;
    double posAverageBMIMales = 0;
    double posAverageBMIFemales = 0;
    double rateOfInfection = 0;
    int obeseMales = 0;
    int obeseFemales = 0;
    double BMIChecker = 0;
    int obeseOverSeventyNine = 0;
    double BMI = 0;
    double BMITotal = 0;
    int BMICounter = 0;
    double averageBMI = 0;

    //opens file to get index size
    fp = fopen(DATA_FILE, "r");
    if (fp == NULL){
        printf("Can't open file.");
        return 1;
    }

    //gets index size
    while (fscanf(fp, " %[^\n]s", &sizeCounter) != EOF){
        indexSize ++;
    }
    fclose(fp);

    //creates arrays to hold data
    char sexArray[indexSize];
    int ageArray[indexSize];
    int heightArray[indexSize];
    int weightArray[indexSize];
    char posNegArray[indexSize];
    int zipArray[indexSize];

    //opens file to populate array data
    fp = fopen(DATA_FILE, "r");
    if (fp == NULL){
        printf("Can't open file.");
        return 1;
    }

    //while condition also assigns the sex data
    while (fscanf(fp, " %c", &sexArray[index]) != EOF){
        fscanf(fp, " %d", &ageArray[index]);
        fscanf(fp, " %d", &heightArray[index]);
        fscanf(fp, " %d", &weightArray[index]);
        fscanf(fp, " %c", &posNegArray[index]);
        fscanf(fp, " %d", &zipArray[index]);

        index++;
    }
    fclose(fp);

    //reset index
    index = 0;

    //array checker for debugging
    /*
    while(index < (indexSize)){
        printf("%c ", sexArray[index]);
        printf("%d ", ageArray[index]);
        printf("%d ", heightArray[index]);
        printf("%d ", weightArray[index]);
        printf("%c ", posNegArray[index]);
        printf("%d\n", zipArray[index]);

        index++;
    }
    index = 0;
    */

    printf("1.How many males have been tested and how many of them tested positive?\n");

    //counts males
    while (index < indexSize){
        if (sexArray[index] == 'M'){
            totalMales++;
        }
        index++;
    }
    index = 0;

    //counts positive males
    while (index < indexSize){
        if ((sexArray[index] == 'M') && posNegArray[index] == '+'){
            posMales++;
            }
        index++;
    }
    index = 0;
    printf("\t%d have been tested and %d were positive.\n\n", totalMales, posMales);


    printf("2.How many females have been tested and how many of them tested positive? \n");

    //counts females
    totalFemales = indexSize - totalMales;

    //counts positive females
     while (index < indexSize){
        if ((sexArray[index] == 'F') && posNegArray[index] == '+'){
            posFemales++;
            }
        index++;
    }
    index = 0;
    printf("\t%d have been tested and %d were positive.\n\n", totalFemales, posFemales);


    printf("3.What is the average age of the males who tested positive? \n");

    //gets total age of positive males
    while(index < indexSize){
        if((sexArray[index] == 'M') && (posNegArray[index] == '+')){
            posMaleTotalAge += ageArray[index];
        }
        index++;
    }
    index = 0;

    //gets average age
    posMaleAverageAge = posMaleTotalAge / posMales;

    printf("\tThe average age of positive males was %d.\n\n", posMaleAverageAge);


    printf("4.What is the average age of the females who tested positive? \n");

    //gets total age of positive females
    while(index < indexSize){
        if((sexArray[index] == 'F') && (posNegArray[index] == '+')){
            posFemaleTotalAge += ageArray[index];
        }
        index++;
    }
    index = 0;

    //gets average age
    posFemaleAverageAge = posFemaleTotalAge / posFemales;

    printf("\tThe average age of positive females was %d.\n\n", posFemaleAverageAge);


    printf("5.What is the oldest age of a person who tested positive? \n");

    //gets oldest age
    while(index < indexSize){
        if (posNegArray[index] == '+'){
            if (ageArray[index] > ageHolder){
                ageHolder = ageArray[index];
            }
        }
        index++;
    }
    index = 0;

    printf("\tThe oldest positive person was %d.\n\n", ageHolder);


    printf("6.What is the youngest age of a person who tested positive? \n");

    //gets oldest age
    while(index < indexSize){
        if (posNegArray[index] == '+'){
            if (ageArray[index] < ageHolder){
                ageHolder = ageArray[index];
            }
        }
        index++;
    }
    index = 0;

    printf("\tThe youngest positive person was %d.\n\n", ageHolder);


    printf("7.Compare the average age of the males who tested positive to the average age of the males who did not test positive. \n");

    //gets average age of negatives
    while(index < indexSize){
        if((sexArray[index] == 'M') && (posNegArray[index] == '-')){
            negMaleTotalAge += ageArray[index];
        }
        index++;
    }
    index = 0;

    negMaleAverageAge = negMaleTotalAge / (totalMales - posMales);

    printf("\tThe ratio average age of positive to the average age of negative males was %d/%d\n\n", posMaleAverageAge, negMaleAverageAge);


    printf("8.Compare the average age of the females who tested positive to the average age of the females who did not test positive. \n");

    //gets average age of negatives
    while(index < indexSize){
        if((sexArray[index] == 'F') && (posNegArray[index] == '-')){
            negFemaleTotalAge += ageArray[index];
        }
        index++;
    }
    index = 0;

    negFemaleAverageAge = negFemaleTotalAge / (totalFemales - posFemales);

    printf("\tThe ratio average age of positive to the average age of negative females was %d/%d\n\n", posFemaleAverageAge, negFemaleAverageAge);


    printf("9.What's the average weight of the males who tested positive? \n");

    //gets average weight of pos males
    while(index < indexSize){
        if((sexArray[index] == 'M') && (posNegArray[index] == '+')){
            posTotalWeightMale += weightArray[index];
        }
        index++;
    }
    index = 0;

    posAverageWeightMale = posTotalWeightMale / posMales;

    printf("\tThe average weight of positive males was %d lbs\n\n", posAverageWeightMale);


    printf("10.What's the average weight of the females who tested positive? \n");

    //gets average weight of pos females
    while(index < indexSize){
        if((sexArray[index] == 'F') && (posNegArray[index] == '+')){
            posTotalWeightFemale += weightArray[index];
        }
        index++;
    }
    index = 0;

    posAverageWeightFemale = posTotalWeightFemale / posFemales;

    printf("\tThe average weight of positive females was %d lbs\n\n", posAverageWeightFemale);


    printf("11.The formula for BMI is weight in kilograms divided by height in meters squared.\nWhen using English measurements, pounds should be divided by inches squared.\nThis should then be multiplied by 703 to convert from lbs/inches2 to kg/m2.\nDetermine the average BMI for the males who tested positive. \n");

        //gets total pos male height
    while(index < indexSize){
        if((sexArray[index] == 'M') && (posNegArray[index] == '+')){
            posTotalHeightMales += heightArray[index];
        }
        index++;
    }
    index = 0;

    posAverageHeightMales = posTotalHeightMales / posMales;

    posAverageBMIMales = ((double)posAverageWeightMale / ((double)posAverageHeightMales * (double)posAverageHeightMales)) * 703;

    printf("\tThe average BMI of positive males is %.2f\n\n", posAverageBMIMales);


    printf("12.Determine the average BMI for the females who tested positive. \n");

    //gets total pos female height
    while(index < indexSize){
            if((sexArray[index] == 'F') && (posNegArray[index] == '+')){
            posTotalHeightFemales += heightArray[index];
        }
        index++;
    }
    index = 0;

    posAverageHeightFemales = posTotalHeightFemales / posFemales;

    posAverageBMIFemales = ((double)posAverageWeightFemale / ((double)posAverageHeightFemales * (double)posAverageHeightFemales)) * 709;

    printf("\tThe average BMI of positive females is %.2f\n\n", posAverageBMIFemales);

    printf("13.A BMI of 30 or higher means that the person is obese. There is a possibility that this is a greater chance that Covid-19 can be fatal if you are obese. Determine how many of the males who tested positive are obese. \n");

    //checks if person is over 30 bmi
    while(index < indexSize){
        if ((sexArray[index] == 'M') && (posNegArray[index] == '+')){
                BMIChecker = (((double)weightArray[index] / ((double)heightArray[index] * (double)heightArray[index])) * 709);
            }
        if (BMIChecker > 30){
            obeseMales++;
        }
        BMIChecker = 0;
        index++;
    }
    index = 0;

    printf("\t%d positive males are obese\n\n", obeseMales);


    printf("14.Determine how many of the females who tested positive are obese. \n");

     //checks if person is over 30 bmi
    while(index < indexSize){
        if ((sexArray[index] == 'F') && (posNegArray[index] == '+')){
                BMIChecker = (((double)weightArray[index] / ((double)heightArray[index] * (double)heightArray[index])) * 709);
            }
        if (BMIChecker > 30){
            obeseFemales++;
        }
        BMIChecker = 0;
        index++;
    }
    index = 0;

    printf("\t%d positive females are obese\n\n", obeseFemales);


    printf("15.Determine how many people who are 80 or older who tested positive are obese. \n");

    //checks if person is over 30 bmi
    while(index < indexSize){
        if ((ageArray[index] > 79) && (posNegArray[index] == '+')){
                BMIChecker = (((double)weightArray[index] / ((double)heightArray[index] * (double)heightArray[index])) * 709);
            }
        if (BMIChecker > 30){
            obeseOverSeventyNine++;
        }
        BMIChecker = 0;
        index++;
    }
    index = 0;

    printf("\tThe number of positive obese people who are 80 or older is %d\n\n", obeseOverSeventyNine);


    printf("16.Determine what the average BMI is for males who tested positive in the following three groups: under 30, between 30-60, and over 60. \n");

    //gets total bmi under 30
    while(index < indexSize){
        if((ageArray[index] < 30) && (sexArray[index] == 'M') && (posNegArray[index] == '+')){
            BMI = (((double)weightArray[index] / ((double)heightArray[index] * (double)heightArray[index])) *709);
            BMICounter++;
            BMITotal += BMI;
        }
        index++;
    }
    index = 0;

    averageBMI = BMITotal / (double)BMICounter;
    printf("\tAverage BMI for positive males under 30: %.2f\n", averageBMI);

    //resets calculator variables
    BMI = 0;
    BMICounter = 0;
    BMITotal = 0;
    averageBMI = 0;

    //gets total bmi between 30 and 60
    while(index < indexSize){
        if(((ageArray[index] > 29) && (ageArray[index] < 61)) && (sexArray[index] == 'M') && (posNegArray[index] == '+')){
            BMI = (((double)weightArray[index] / ((double)heightArray[index] * (double)heightArray[index])) *709);
            BMICounter++;
            BMITotal += BMI;
        }
        index++;
    }
    index = 0;

    averageBMI = BMITotal / (double)BMICounter;
    printf("\tAverage BMI for positive males between 30 and 60: %.2f\n", averageBMI);

     //resets calculator variables
    BMI = 0;
    BMICounter = 0;
    BMITotal = 0;
    averageBMI = 0;

     //gets total bmi over 60
    while(index < indexSize){
        if((ageArray[index] > 60) && (sexArray[index] == 'M') && (posNegArray[index] == '+')){
            BMI = (((double)weightArray[index] / ((double)heightArray[index] * (double)heightArray[index])) *709);
            BMICounter++;
            BMITotal += BMI;
        }
        index++;
    }
    index = 0;

    averageBMI = BMITotal / (double)BMICounter;
    printf("\tAverage BMI for positive males under over 60: %.2f\n\n", averageBMI);

    //resets calculator variables
    BMI = 0;
    BMICounter = 0;
    BMITotal = 0;
    averageBMI = 0;


    printf("17.Determine what the average BMI is for females who tested positive in the following three groups: under 30, between 30-60, and over 60. \n");

     //gets total bmi under 30
    while(index < indexSize){
        if((ageArray[index] < 30) && (sexArray[index] == 'F') && (posNegArray[index] == '+')){
            BMI = (((double)weightArray[index] / ((double)heightArray[index] * (double)heightArray[index])) *709);
            BMICounter++;
            BMITotal += BMI;
        }
        index++;
    }
    index = 0;

    averageBMI = BMITotal / (double)BMICounter;
    printf("\tAverage BMI for positive females under 30: %.2f\n", averageBMI);

    //resets calculator variables
    BMI = 0;
    BMICounter = 0;
    BMITotal = 0;
    averageBMI = 0;

    //gets total bmi between 30 and 60
    while(index < indexSize){
        if(((ageArray[index] > 29) && (ageArray[index] < 61)) && (sexArray[index] == 'F') && (posNegArray[index] == '+')){
            BMI = (((double)weightArray[index] / ((double)heightArray[index] * (double)heightArray[index])) *709);
            BMICounter++;
            BMITotal += BMI;
        }
        index++;
    }
    index = 0;

    averageBMI = BMITotal / (double)BMICounter;
    printf("\tAverage BMI for positive females between 30 and 60: %.2f\n", averageBMI);

     //resets calculator variables
    BMI = 0;
    BMICounter = 0;
    BMITotal = 0;
    averageBMI = 0;

    //gets total bmi over 60
    while(index < indexSize){
        if((ageArray[index] > 60) && (sexArray[index] == 'F') && (posNegArray[index] == '+')){
            BMI = (((double)weightArray[index] / ((double)heightArray[index] * (double)heightArray[index])) *709);
            BMICounter++;
            BMITotal += BMI;
        }
        index++;
    }
    index = 0;

    averageBMI = BMITotal / (double)BMICounter;
    printf("\tAverage BMI for positive females under over 60: %.2f\n\n", averageBMI);

    //resets calculator variables
    BMI = 0;
    BMICounter = 0;
    BMITotal = 0;
    averageBMI = 0;



    printf("18.What is the average rate of infection for all of the people who were tested? \n");

    rateOfInfection = (((double)posMales + (double)posFemales) / (double)indexSize) * 100;

    printf("\tThe rate of infection for those tested was %.2f%%", rateOfInfection);

    return 0;
}

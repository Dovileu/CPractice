#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int numberLenght(float input)
{
    int temp, digitCount = 0;

    temp = input;

    //digit count without the fractional part

    while(temp != 0)
    {
        temp /= 10;
        ++digitCount;
    }

    temp = 0;
    int fractionLenght = 0;
    float temp2 = input;

    while(temp2 != temp)
    {
        //if int is the same value as float, end of the fractional part has been reached
        temp = temp2;
        if(temp != temp2)
        {
            ++fractionLenght;
            ++digitCount;
            temp2 *= 10;
        }
    }

    //if the number is too long, function returns false
    if(fractionLenght > 3)
        return 0;

    else
        return digitCount;
}

int main()
{
    printf("This program calculates the lenght of a real number.\n");
    printf("The number must be between 10 and 1000.\n");
    printf("The decimal part of the number must be seperated with a comma.\n\n");

    //use comma instead of dot
    setlocale(LC_NUMERIC, "French_Canada.1252");

    float input = 0;
    FILE *fp;
    float minValue = 10, maxValue = 1000;
    int digitCount;
    int isCorrect = 1;

    char fileName[100] = "in.txt";

    //text file valition
    while(!(fp = fopen(fileName, "r")) || !(fscanf(fp, "%f", &input)) || input < minValue || input > maxValue)
    {
        fclose(fp);

        printf("Invalid input, please specify a new input file with correct input:\n");
        scanf("%[^\n]", &fileName);
        while(getchar() != '\n');
        printf("Opening file %s\n", fileName);
    }
    fclose(fp);

    digitCount = numberLenght(input);
    if(!digitCount)
    {
        isCorrect = 0;
    }

    while(isCorrect == 0)
    {
        printf("Invalid input, please specify a new input file with correct input 2:\n");
        scanf("%[^\n]", &fileName);
        while(getchar() != '\n');

        while(!(fp = fopen(fileName, "r")) || !(fscanf(fp, "%f", &input)) || input < minValue || input > maxValue)
        {
            printf("Invalid input.\n");
            printf("Please specify a new input file with correct input:\n");
            scanf("%[^\n]", &fileName);
            while(getchar() != '\n');
        }
        digitCount = numberLenght(input);
        if(!digitCount)
        {
            isCorrect = 0;
        }
        else
        {
            isCorrect = 1;
        }
        fclose(fp);
    }

    printf("Number length: %d\n", digitCount);

    return 0;
}

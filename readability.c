/*output what grade level is needed to understand text: index = 0.0588 * L - 0.296 * S - 15.8
L = average number of letters.
S = average number of sentences per 100 words in text.
1. Takes text to determine reading level
2. e.g. $ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
The text the user inputted has 65 letters, 4 sentences, and 14 words.
65 letters per 14 words is an average of about 464.29 letters per 100 words.
And 4 sentences per 14 words is an average of about 28.57 sentences per 100 words.
Plugged into the Coleman-Liau formula, and rounded to the nearest whole number,
we get an answer of 3: so this passage is at a third grade reading level.
*/

//Purpose: A program used to approximate grade level needed to comprehend some text according to the Coleman-Liau index.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


//Function declaration to calculate grade index.
float grade_index(float letters, float sentences, float words);

//Declare the maximum size of the string.
#define string_size 5000

int main(void)
{
    //Variable declarations.
    char string[string_size];

    int letters, l;
    int words, w;
    int sentences, s;
    letters = l = 0;
    words = w = 1;
    sentences = s = 0;

    //Inputs and stores the string value.
    printf("Text: ");
    fgets(string, sizeof string, stdin);

    //Calculates the number of letters in string.
    while (string[l] != '\0')
    {
        if ((string[l] >= 'a' && string[l] <= 'z') || (string[l] >= 'A' && string[l] <= 'Z'))
        {
            letters++;
        }

        l++;
    }

    //Calculates the number of words in a string.
    for (w = 0; string[w] != '\0'; w++)
    {
        if (string[w] == ' ' && string[w + 1] != ' ')
        {
            words++;
        }
    }

    //Calculates the number of sentences in a string.
    for (s = 0; string[s] != '\0'; s++)
    {
        if (string[s] == '.' || string[s] == '!' || string[s] == '?')
        {
            sentences++;
        }
    }

    //Calls function to calculate the grade index.
    float grade = grade_index(letters, sentences, words);
    
    //Prints the grade.
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.f\n", grade);
    }
}

//Function to calculate the grade index.
float grade_index(float letters, float sentences, float words)
{
    float l = ((float) letters / (float) words) * 100;
    float s = ((float) sentences / (float) words) * 100;
    float grade_index = round(0.0588 * l - 0.296 * s - 15.8);
    return grade_index;
}
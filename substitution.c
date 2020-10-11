// Purpose: A program that enables you to encrypt messages using a substitution cipher.

#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    int m;
    int j;

    //Prompts the user for a propper command line argument if not argument has been passed on launch.
    if (argc == 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

   //Variable decleration for a string of 26 charachters.
   char key[25];

   //String copy function that takes the first command line input and stores it as a variable.
   strcpy(key, argv[1]);

   //Variable decleration for charachter counter.
   int characters, c;
   characters = c = 0;

   //Calculates the number of charachters in command line argument.
   while (key[c] != '\0')
   {
       if ((key[c] >= 'a' && key[c] <= 'z') || (key[c] >= 'A' && key[c] <= 'Z'))
       {
           characters++;
       }

       c++;
   }

   if(characters != 26)
   {
       printf("Key must contain 26 characters.\n");
       return 1;
   }

   // Prompts the user for a proper command line argument.
   if (argc > 2 || argc < 1)
   {
       printf("Usage: ./substitution key\n");
       return 1;
   }

   // Checks for non-alphabetical characters.
   for (int i = 0, k = strlen(key); i < k; i++)
   {
       if (!isalpha(key[i]))
       {
           printf("Key must only contain alphabetic characters.\n");
           return 1;
       }
   }

   // Checks for repeated characters.
   for (m = 0; m < strlen(key); m++)
   {
       int count = 1;
       for (j = m + 1; j < strlen(key); j++)
       {
           if (key[m] == key[j] && key[m] != ' ')
           {
               count++;
               key[j] = '0';
           }
       }

       if(count > 1 && key[m] != '0')
       {
           printf("Key must not contain repeated characters.\n");
           return 1;
       }
   }

   //Ciphertext.
   char input[500];
   printf("plaintext: ");
   fgets(input, sizeof(input), stdin);

   for (int e = 0; e <strlen(input); e++)
   {
       if (islower(input[e]))
       {
           input[e] = tolower(argv[1][input[e] - 97]);
       }
       else if (isupper(input[e]))
       {
           input[e] = toupper(argv[1][input[e] - 65]);
       }
   }

   printf("ciphertext: %s", input);
   return 0;
}
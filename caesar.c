#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int digit_check = 0; //A counter for key digit checking


int main(int argc, string argv[])
{
    if(argc != 2 || argv[1] == '\0')   //Checks if the command is correct
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int key_length = strlen(argv[1]);
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)   //Iterate over every char in the key
    {
            
        if(isdigit(argv[1][i]))  //Check if the char is a digit
        {    
            digit_check++;
        }
        else                    //Return error if the key is not a number
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }
    }
    if(digit_check == key_length)    //Executes cipher if the key is valid
    {
        int key = atoi(argv[1]);
        string msg = get_string("plaintext: ");
        
        printf("ciphertext: ");
        for(int j = 0, m = strlen(msg); j < m; j++)   //Executes the cypher
        {
            if(msg[j] >= 'A' && msg[j] <= 'Z')
            {
                char c = (msg[j] + key) % 91;         //Deals with the rollover in capital letters
                if(c < 'A')
                    printf("%c", c + 'A');
                else
                {
                    printf("%c", c);
                }
            }
            else if(msg[j] >= 'a' && msg[j] <= 'z')
            {
                char c = (msg[j] + key) % 123;       //Deals with the rollover in small letters
                if(c < 'a')
                {
                    printf("%c", c + 'a');
                }
                else
                {
                    printf("%c", c);
                }
            }
            else
            {
                printf("%c", msg[j]);
            }
        }
        printf("\n");
        return 0;
    }
        
    
}
    


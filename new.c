// encryption for substitution cipher 

#include <stdio.h>

int main(void)
{
    char message[80];
    char emessage[80];
    char dmessage[80];
    
    int key;
    int temp;
    
    printf("Enter the text to encrypt:\n");
    scanf("%[^\n]s",message);
    printf("Enter the encryption key:\n");
    scanf("%d",&key);
    
    for (int i = 0; message[i]!='\0'; i++)
    {
        if(message[i]== ' ')
        {
            emessage[i] = ' ';
            printf("%c", emessage[i]);
        }
        
        else // upper case letters
        {
        temp = message[i];
        temp = (temp-65+key)%26;
        emessage[i] = temp + 65;
        printf("%c", emessage[i]);
        }
        
        else // lower case letters
        {
          temp = message[i];
        temp = (temp-97+key)%26;
        emessage[i] = temp + 97;
        printf("%c", emessage[i]);   
        }
    
    }        
    }
    printf("Encrpted message: \n");
    return 0;
}
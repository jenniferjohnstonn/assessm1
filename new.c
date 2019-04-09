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
    printf("%s\n",message);
    printf("Enter the encryption key:\n");
    scanf("%d",&key);
    
    for (int i = 0; message[i]!='\0'; i++)
    {
        if(message[i]== ' ')
        {
            emessage[i] = ' ';
            printf("%c", emessage[i]);
        }
        else
        {

        temp = message[i];
        temp = (temp-65+key)%26;
        emessage[i] = temp + 65;
        printf("%c", emessage[i]);
    }

        
    }
    printf("\n");
    return 0;
}
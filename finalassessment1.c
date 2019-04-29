/* ENGG1003 Assessment 1 */
/* Roatation cipher encryption */

#include <stdio.h>
#include <string.h>

// DISCLAIMER, it is understood that the use of fgets() and getchar aren't normally encouraged, but i found it to be much more efficient than other functions and personally I found it easier to understand and utilise within this assignment

int main()
{
	char message[100], ch;
	int i, key;
	
	printf("Enter a message to encrypt (roataion) : \n"); // prompt user to enter message to encrypt
	fgets(message, 100,stdin );	// reads a line from specified stream & stores it into string pointed to by str
	// fgets stops when either (n-1) characters are read, newline character is read, or end-of-file is reached
	printf("Enter key: \n"); // prompts user to enter a key number
	scanf("%d", &key); // reads the number in retation to the key
	getchar(); // getchar() used to get rid of previous values so they dont interfer with future lines 
	
	for(i = 0; message[i] != '\0'; ++i) // for loop used to provide appropiate values for encrypted code
	{
		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z') // if loop declaring lower case letters
		{
			ch = ch + key;
			
			if(ch > 'z')
			{
				ch = ch - 'z' + 'a' - 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z') // else if loop declaring upper case letters
		{
			ch = ch + key;
			
			if(ch > 'Z')
			{
				ch = ch - 'Z' + 'A' - 1;
			}			
			message[i] = ch;
		}
	}
	
	printf("Encrypted message: %s\n", message); // presents user with encrypted code
	
	/* Rotation cipher decryption */

    char mess_decrypt[100];
    int key_2;
	
	printf("Enter a message to decrypt (roatation): \n"); // prompt user to enter message to decrypt
	fgets(mess_decrypt, 100, stdin); // reads a line from specified stream & stores it into string pointed to by str
	// fgets stops when either (n-1) characters are read, newline character is read, or end-of-file is reached
	printf("Enter key: \n"); // prompts user to enter a key number
	scanf("%d", &key_2); // reads the number in retation to the key
	getchar(); // getchar() used to get rid of previous values so they dont interfer with future lines 
	
	for(i = 0; mess_decrypt[i] != '\0'; ++i) // for loop used to provide appropiate values for decrypted code
	{
		ch = mess_decrypt[i];
		
		if(ch >= 'a' && ch <= 'z') // if loop for lower case letters
		{
			ch = ch - key_2;
			
			if(ch < 'a')
			{
				ch = ch + 'z' - 'a' + 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z') // else if loop for upper case letters
		{
			ch = ch - key;
			
			if(ch < 'A')
			{
				ch = ch + 'Z' - 'A' + 1;
			}
			
			message[i] = ch;
		}
	}
	
	printf("Decrypted message: %s \n", message); // presents user with decrypted code
	
	/* Substitution cipher encryption */
	
	
	char smessage[80];
    char emessage[80];
    char dmessage[80];
    char skey[26];
    
    
    int temp;
    
    printf("Enter the text to encrypt (substitution):\n"); // prompt user to enter message to encrypt
    fgets(smessage, 80, stdin); // reads a line from specified stream & stores it into string pointed to by str
	// fgets stops when either (n-1) characters are read, newline character is read, or end-of-file is reached
    printf("Enter the encryption key:\n"); // prompts user to enter letter variation for key
    fgets(skey, 26, stdin); // similar use as line 102, but instead reads the key variation
    
    
    for(int i = 0; i < 26; i++) // for loop used to transfer all messages entered by user from lower case to upper case.
    // this has been utilised to make the code easier to read and to make the algorithms more efficient.
    // strupr would have been prefered but can only be used through windows
    {
        if(skey[i] >= 'a' && skey[i] <= 'z') 
        {
            skey[i] = skey[i] - 32; // -32 ensures conversion to upper case using ASCII values
        }
        
    }
    
    for (int i = 0; i < strlen(emessage)-1 ; i++) 
   {
        if(smessage[i]== ' ')
        {
            emessage[i] = ' ';
            printf("%c", emessage[i]);
        }
        
        else if(smessage[i] >= 'A' && smessage[i] <= 'Z') // upper case letters
        {
        temp = smessage[i];
        temp = temp-65;        
        emessage[i] = skey[temp];
        printf("%c", emessage[i]);
        }
        
        else if(smessage[i] >= 'a' && smessage[i] <= 'z') // lower case letters
        {
        temp = smessage[i];
        temp = temp-97;
        emessage[i] = skey[temp]+32; // due to the lower case letters being transfered into upper case in first for loop, +32 is added to ensure it returns to lowercase
        printf("%c", emessage[i]);   
        }
  
    }
    printf("Encrpted message:\n"); 
    printf("%s\n", emessage); // displays the encrypted message
	
	return 0;
}


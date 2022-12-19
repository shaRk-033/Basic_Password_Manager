#include <strings.h>
#include<time.h>

/*
  This file contains the main heart of the whole program,i.e the password encrypter/decrypter.
  How the whole encryption and decryption thing works is as follows...

  *As soon as a password is entered it is passed to the encrypter function.
  *The password is transformed into a cipher text thant no can understand(and it is not the original password).
  *The ciphered text is asscoiated with a randomly generated key.
  *Each and every password/ciphered text has its own unique key.
  *The purpose of the key is to regenerate the password from the ciphered text.
  *Basically one can think of ciphered text as a lock and a key is used to reveal the password.
  *The key generator uses a pre existing funtion rand() from stdlib.h file.
  *It randomly generates a string of length n.

*/
extern char *key_generator(int length)
{   
     static char key[50];
	srand((unsigned int)(time(NULL)));

	static char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for (int n = 0;n < length;n++)
	{
            int k = rand() % (int)(sizeof(alphabet) -1);
            key[n] = alphabet[k];
    }

            key[length] = '\0';

    return key;
}
char *xORCipher(char *in,char *key)
{
    static char out[50];
    int len = strlen(in);

   //XOR CIPHER IS IMPLEMENTED-----CHARACTER BY CHARACTER.
    for (int i = 0; i < len; i++)
    {
        out[i] = in[i] ^ key[i];

    }
		return out;
}

//                               PASSWORD MANAGER
//Source code of the password manager.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Heart.c"

/* 
  Using structure to store all the related information to the password.
*/ 
typedef struct
{
  char website[50];
  char email[50];
  char encrypted[50];
  char key[50];

}password_storage;


/*
  All the functions used in the main file are declared here
*/
void add_password();
void search_password();
void display_all();
void delete_all();


int main()
{ int choice;
  char main_pass[30]="cattopurr";char pass[30];
  puts("oooooooooo");
  puts(" 888    888 oooo   oooo");
  puts(" 888oooo88   888   888");
  puts(" 888    888  888 888");
  puts("o888ooo888     8888");
  puts("             o8o888");
  puts("oooooooooo             oooo   oooo            oooooooo8 oooo");
  puts(" 888    888  ooooooo    888  o88  ooooooooo8 888         888ooooo");
  puts(" 888oooo88   ooooo888   888888   888oooooo8   888oooooo  888   888");
  puts(" 888  88o  888    888   888  88o 888                 888 888   888");
  puts("o888o  88o8 88ooo88 8o o888o o888o 88oooo888 o88oooo888 o888o o888o");

  puts("------------------------------------------------------------------");
  puts("                                                                  ");
  puts("              *        ,MMM8&&&.                                  ");
  puts("                      MMMM88&&&&&                        *        ");
  puts("  *                  MMMM88&&&&&&&       .                        ");
  puts("                     MMM88&&&&&&&&                                ");
  puts("                     'MMM88&&&&&&'              *                 ");
  puts("                       'MMM8&&&'                                  ");
  puts("                                                                  ");
  puts("                                                                  ");
  puts("                      {}___{}                                     ");
  puts("                      )     (                                     ");
  puts("                    =\\     /=                                    ");
  puts("                       )===(                                      ");
  puts("                      /    \\                                     ");
  puts("                      )     (                                     ");
  puts("                     /      \\                                    ");
  puts("                     \\      /                                    ");
  puts("        _/|_/|_/|_/|_/|_____//|_/|_/|_/|_/|_/|                    ");
  puts("        |_______________ ))__________________|                    ");
  puts("        |_______________//___________________|                    ");
  puts("        |______________((____________________|                    ");
  puts("        |______________()____________________|                    ");
  puts("        |____________________________________|                    ");
  puts("                                                                  ");
  puts("                                                                  ");
  puts("                                                                  ");
  puts("------------------------------------------------------------------");
  puts(" CCC  AA  TTTTTT TTTTTT  OOO  PPPP   AA   SSS   SSS");  
  puts("C    A  A   TT     TT   O   O P   P A  A S     S");     
  puts("C    AAAA   TT     TT   O   O PPPP  AAAA  SSS   SSS");  
  puts("C    A  A   TT     TT   O   O P     A  A     S     S"); 
  puts(" CCC A  A   TT     TT    OOO  P     A  A SSSS  SSSS    ");
  puts("Please enter the password to access all of your passwords:");
  scanf(" %s",pass);
  if (strcmp(main_pass,pass)==0)
     {
      puts("You have succesfully entered the application.Long Live Catto.:)");
     }
  else
  {
    puts("Wrong password entered,sorry :/");
    exit(0);
  }
  puts("-----------------------  WELCOME  --------------------------------");
/*
   The main interface.Program displays the choices until the user doesn't want to perform any actions.
*/
  do
  {
    puts("ENTER YOUR CHOICE");

    puts("1.ADD A NEW PASSWORD");

    puts("2.SEARCH FOR A PASSWORD OF A SPECIFIC WEBSITE OR ACCOUNT");

    puts("3.DISPLAY ALL THE WEBSITES OR ACCOUNTS FOR WHICH THE PASSWORD WAS SAVED");

    puts("4.DELETE ALL PASSWORDS\n");
    
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:add_password();
             break;
      case 2:search_password();
             break;
      case 3:display_all();
             break;
      case 4:delete_all();
             break;
      default:printf("PLEASE ENTER A VALID CHOICE\n");
    }
  }
  while(choice!=5);

return 0;
}
void add_password ()
{
   password_storage p;char pass[30];char key[50];char encrypt[100];

   printf("Please enter the name of the website or application:");
   scanf(" %s",p.website);
   printf("\nPlease enter the email address you have used for this website:");
   scanf(" %s",p.email);
   puts("\nEnter the password(without spaces is strongly recommended:");
   scanf(" %s",pass);

   /*
     A random key is generated equal to length of the given password.
     And that key is passed to or copied to key using strcpy() function.
    */
   strcpy(p.key,key_generator(strlen(pass)));

   /*
    XOR Cipher function is invoked so as to encrypt the given password and is passed to encrypted variable in the structure.
    */
   strcpy(p.encrypted,xORCipher(pass,p.key));

   FILE *fp;
   fp=fopen("catto_bag.txt","ab");
   if (fp == NULL)
      {
          puts("File failed to open");
      }
    else
     {
        fwrite(&p,sizeof(p),1,fp);
        fputs("\n",fp);  
        puts("Password and associated email are successfully saved.:) ");
     }
    fclose(fp);
}
void search_password()
{
  password_storage ps;
  
  char ref[50];
  puts("Which website's password do you wanna check");
  scanf(" %s",ref);
  
  FILE *fp;
  fp=fopen("catto_bag.txt","rb");
  if (fp == NULL)
     {
         puts("File failed to open");
     }
  else
 {
     while (fread (&ps, sizeof(ps), 1, fp))
 
      {   
        if (strcmp(ps.website,ref)==0)
          break;
      }

  char decrypted[30];

  strcpy(decrypted,xORCipher(ps.encrypted,ps.key));

  puts("|  WEBSITE   |   EMAIL   |  PASSWORD  |");
  printf("|%s |%s |%s |\n", ps.website, ps.email, decrypted);

  }

  fclose(fp);
}
void display_all()
{
  password_storage p;
  FILE *fp;
  fp=fopen("catto_bag.txt","rb");
  if (fp == NULL)
     
     {
         puts("File failed to open");
     }

  else
    
    {
        while (fread (&p, sizeof(p), 1, fp))
         
         {   
           printf(" %s\n", p.website);
         }

    search_password();
    }
    
}
/*
  The user is given a choice to delete all the existing passwords.
*/
void delete_all()
{ 
	if (remove("catto_bag.txt") == 0)
    {
        printf("All passwords and associated website references and emails were deleted\n");
    }
    else
    {
    	printf("Unable to delete the vault\n");
    }  
}

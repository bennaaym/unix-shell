/**
 * @file prompt.c
 * @author Fatih Aytar
 * @brief Holds the implementation of the different functions related to the shell prompt
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../config/config.h"
#include "prompt.h"


int readInput(char* command)
{
    fgets(command,CONFIG.COMMAND_MAX_CHARS,stdin);
    command[strlen(command) - 1] = '\0';
 
    if (strlen(command) != 0) 
    {
        return 1;
    }

    return 0;
}

void prompt()
{
    printf("%s",CONFIG.PROMPT_USERNAME_COLOR);
    printUserName();
    printf("%s",CONFIG.PROMPT_CWD_COLOR);
    printf(":~");
    printWorkingDirectory();   
    printf("%s",CONFIG.PROMPT_LOGO_COLOR);
    printf(": %s > ",CONFIG.SHELL_NAME);
    printf("%s",CONFIG.PROMPT_TEXT_COLOR);
}

void initPrompt()
{
    const short MAX_LEN = 65;

    clear();

    printf("%s",CONFIG.PROMPT_LOGO_COLOR);                                                                                                                                     
    
    for(int i =0 ;i < MAX_LEN;i++)
        printf("*");
    
    printf("\n");  
    printf("     ####     #   #    #    ####  #    # ###### #      #\n");     
    printf("    #       #  #  #    #   #      #    # #      #      #\n");     
    printf("     ####  #    # #    #    ####  ###### #####  #      #\n");    
    printf("         # ###### #    #        # #    # #      #      #\n");   
    printf("    #    # #    # #    #   #    # #    # #      #      #\n");  
    printf("     ####  #    #  ####     ####  #    # ###### ###### ######\n");

    for(int i =0 ;i < MAX_LEN;i++)
        printf("*");

    printf("\n");
}


void printUserName()
{
    char* username = getenv("USER");
    printf("%s",username);
}

void printWorkingDirectory()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s", cwd);
}

void clear()
{
    printf("\033[H\033[J");
}

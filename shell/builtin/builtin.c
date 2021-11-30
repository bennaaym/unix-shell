/**
 * @file builtin.c
 * @author Aymen Bennabi
 * @brief Holds the implementation of the builtin commands
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void builtinExit()
{
    exit(0);
}

void cd(char* path)
{
    chdir(path);
}

void pwd()
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
}

void showpid(int* pids,int length)
{
    for(int i=0 ;i < length;i++)
    {
        printf("\t%d\n",pids[i]);
    }
}

void help()
{
    const int MAX_LEN = 30;
    for(int i = 0 ; i<MAX_LEN;i++)
    {
        printf("*");
    }

    printf("\nHelp\n");

    for(int i = 0; i< MAX_LEN;i++)
    {
        printf("*");
    }

    printf("\nbuiltin commands:");
    printf("\n- cd      : change the current working directory");
    printf("\n- pwd     : print the current working directory");
    printf("\n- showpid : shows the PID of the last process created by this shell process");
    printf("\n- help    : display a help menu");
    printf("\n- exit    : exit from shell");
    printf("\n");
}
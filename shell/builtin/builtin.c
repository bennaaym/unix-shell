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
#include "../util/util.h"

void builtinExit(){ exit(0); }

void cd(char* path)
{
    
    int found = chdir(path);

    if(found == 0)
    {
        return;
    }

    if((found < 0) && (path == NULL)) 
    {
        return;
    }

    if( (found < 0) && path[0] == '*')
    {
        printf("too many arguments\n");
        return;
    }    

    if(found < 0)
    {
        printf("No such directory\n");   
    }
}

void showpid(int* pids,int length)
{
    for(int i=0 ;i < length;i++)
    {
        printf("\t%d\n",pids[i]);
    }
}

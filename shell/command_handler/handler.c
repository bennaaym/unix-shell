/**
 * @file handler.c
 * @author Aymen Bennabi 
 * @brief Holds the implementation of the different functions related to built-in commands
 *        and command execution
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../util/util.h"
#include "../builtin/builtin.h"

static int childrenSize = 0;
static int childrenCounter = -1;
static int CHILDREN_PID[10];

void handleSystemCommand(char** parsed)
{
    // forks child
	pid_t pid = fork();
    int status;

	if (pid == -1) 
    {
		displayError("ForkError","failed to fork child process");
		return;
	} 

    if (pid == 0) 
    {
		if (execvp(parsed[0], parsed) < 0) 
        {
			displayError("ExecutionError","command cannot be executed");
		}

        exit(0);
	} 
    
    childrenCounter = (childrenCounter + 1) % 10;
    childrenSize = (childrenSize == 10)? 10 : childrenSize + 1;
    CHILDREN_PID[childrenCounter] = pid;

  
    // wait for child to terminate
    pid= waitpid(pid, &status, 0);
    if (pid == -1)
    {
        displayError("WaitError","error related to waitpid()");
    }
}



int handleBuiltinCommand(char** parsed)
{

    short commandNumber = -1;
	
    // checks if the parse command is a built-in command
	for (int i = 0; i < NUMBER_OF_BUILT_IN_COMMANDS; i++) 
    {
		if (strcmp(parsed[0], BUILT_IN_COMMANDS[i]) == 0) 
        {
			commandNumber = i ;
			break;
		}
	}
	// executes the buildin command
    switch (commandNumber) 
    {
        case 0:
            builtinExit();
            return 1;
        
        case 1:
            cd(parsed[1]);
            return 1;
        
        case 2:
            showpid(CHILDREN_PID,childrenSize);
            return 1;

        default:
            break;
	}

	return 0;
}



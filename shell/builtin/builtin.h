/**
 * @file builtin.h
 * @author Aymen Bennabi
 * @brief Holds the blueprints for the builtin commands
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#ifndef BUILT_IN_H
#define BUILT_IN_H



const unsigned short NUMBER_OF_BUILT_IN_COMMANDS = 3;
char* BUILT_IN_COMMANDS[] = 
{
    "exit",
    "cd",
    "showpid",
};


void builtinExit(); // exits from the shell
void cd(char*); // changes the current working directory
void showpid(int* pids,int lenght); // shows PID of the last 10 process  created by the shell process

#endif
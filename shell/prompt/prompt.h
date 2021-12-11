/**
 * @file prompt.h
 * @author Fatih Aytar 
 * @brief Holds the blueprint of the different functions related to the shell prompt
 * @version 0.1
 * @date 2021-11-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PROMPT_H
#define PROMPT_H

int  readInput(char*);
void initPrompt();
void prompt(); 
void printUserName();
void printWorkingDirectory(); 
void clear();

#endif
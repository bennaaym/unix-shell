/**
 * @file tests.c
 * @author Aymen Bennabi
 * @brief Holds the implementation of the different unittests
 * @version 0.1
 * @date 2021-12-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../config/config.h"
#include "../parser/parser.h"
#include "../command_handler/handler.h"


void test_parser_command_max_chars()
{   
    char const TEST_LENGTH = CONFIG.COMMAND_MAX_CHARS + 1;
    char command[TEST_LENGTH];
    char* parsed[CONFIG.COMMAND_MAX_WORDS];

    for(int i = 0; i < TEST_LENGTH; i++)
    {
        command[i] = 'a';
    }

    assert(processInput(command,parsed) == -1);
}

void test_parser_command_max_words()
{
    char const TEST_CHARS_LENGTH = (CONFIG.COMMAND_MAX_WORDS + 1) * 3;
    char command[TEST_CHARS_LENGTH];
    char* parsed[CONFIG.COMMAND_MAX_WORDS];

    for(int i = 0; i < TEST_CHARS_LENGTH; i += 3)
    {
        command[i] = 'a';
        command[i + 1] = 'a';
        command[i + 2] = ' ';
    }

    assert(processInput(command,parsed) == -1);
}

void test_parser_parse_command_with_args()
{
    char command[CONFIG.COMMAND_MAX_CHARS];
    char* parsed[CONFIG.COMMAND_MAX_WORDS];

    strcpy(command,"chmod 700 *");
    processInput(command,parsed);

    assert(strcmp(parsed[0],"chmod") == 0);
    assert(strcmp(parsed[1],"700") == 0);
    assert(strcmp(parsed[2],"*") == 0);
    assert(parsed[3] == NULL);
}

void test_parser_parse_command_with_multiple_arbitrary_spaces()
{
    char command[CONFIG.COMMAND_MAX_CHARS];
    char* parsed[CONFIG.COMMAND_MAX_WORDS];

    strcpy(command,"          chmod                 700                        *          ");
    processInput(command,parsed);
    
    assert(strcmp(parsed[0],"chmod") == 0);
    assert(strcmp(parsed[1],"700") == 0);
    assert(strcmp(parsed[2],"*") == 0);
    assert(parsed[3] == NULL);
}

void test_parser_identify_builtin_commands()
{
    char command[CONFIG.COMMAND_MAX_CHARS];
    char* parsed[CONFIG.COMMAND_MAX_WORDS];

    strcpy(command,"cd");
    assert(processInput(command,parsed) == 0);

    strcpy(command,"showpid");
    assert(processInput(command,parsed) == 0);

    strcpy(command,"ls");
    assert(processInput(command,parsed) != 0);
}

void run_tests()
{
    test_parser_command_max_chars();
    test_parser_command_max_words();
    test_parser_parse_command_with_args();
    test_parser_parse_command_with_multiple_arbitrary_spaces();
    test_parser_identify_builtin_commands();
}

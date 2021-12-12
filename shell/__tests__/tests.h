/**
 * @file tests.h
 * @author Aymen Bennabi
 * @brief  Holds the blueprints of the different unittests
 * @version 0.1
 * @date 2021-12-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TESTS_H
#define TESTS_H


void test_parser_command_max_chars();
void test_parser_command_max_words();
void test_parser_parse_command_with_args();
void test_parser_parse_command_with_multiple_arbitrary_spaces();
void test_parser_identify_builtin_commands();
void run_tests();
#endif

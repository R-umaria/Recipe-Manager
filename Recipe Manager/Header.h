// a Recipe Manager application
//
// PROG71985F23	-	Fall 23'	-	Group Assignment
//
// Group - 22 - Rishi - Henil - Elisha Enakhe


#pragma once

#include <stdio.h>
#include <string.h>

#define MAX_NAME_SIZE 30

void recipe_list();
void add_recipe(char recipename);
void delete_recipe(int recipe_numb);
void update_recipe(int recipe_numb);
void display_single_recipe(int recipe_numb);
void display_range_recipe();
void display_all_recipe();
void search_recipe();
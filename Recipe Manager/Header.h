// a Recipe Manager application
//
// PROG71985F23	-	Fall 23'	-	Group Assignment
//
// Group - 22 - Rishi - Henil - Elisha Enakhe


#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME_SIZE 30
#define MAX_RECIPE_LENGTH 1000
#define MAX_RECIPES 100

typedef struct {
    int recipe_number;
    int total_recipes;
    char recipe_name[MAX_NAME_SIZE];
} Recipe;

void recipe_list();
void add_recipe();
void delete_recipe();
void update_recipe(int recipe_numb);
void display_single_recipe(int recipe_numb);
void display_range_recipe();
void display_all_recipes();
void search_recipe();
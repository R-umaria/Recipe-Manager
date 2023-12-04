// a Recipe Manager application
//
// PROG71985F23	-	Fall 23'	-	Group Assignment
//
// Group - 22 - Rishi - Henil - Elisha Enakhe


#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

void recipe_list() {
    FILE* recipe_list_file = fopen("recipe list.txt", "r");
    if (recipe_list_file != NULL) {
        
    }
	return 0;
}


void add_recipe() {
    char recipe_name[MAX_NAME_SIZE];
    printf("Enter the name of the new recipe: ");
    scanf("%s", recipe_name);
    getchar(); // Consume the newline character

    char filename[MAX_NAME_SIZE];
    sprintf(filename, "%s.txt", recipe_name);

    FILE* newFile = fopen(filename, "r");

    if (newFile != NULL) {
        printf("\nFile Name already exists!\n");
        fclose(newFile);
    }
    else {
        
        newFile = fopen(filename, "w");

        if (newFile != NULL) {
            
            printf("Enter the recipe steps (enter an empty line to finish):\n");

            // Using a loop to read multiple lines of text
            bool finished = false;
            while (!finished) {
                char recipe_steps[MAX_RECIPE_LENGTH];
                fgets(recipe_steps, sizeof(recipe_steps), stdin);

                // to check if the line is empty (contains only newline character)
                if (recipe_steps[0] == '\n') {
                    finished = true;
                }
                else {
                    fprintf(newFile, "%s", recipe_steps);
                }
            }
            
            printf("\nRecipe added successfully!\n");
            fclose(newFile);
        }
        else {
            printf("\nError creating the recipe file!\n");
        }
    }
}


void delete_recipe(int recipe_numb) {
	return 0;
}
void update_recipe(int recipe_numb) {
	return 0;
}
void display_single_recipe(int recipe_numb) {
	return 0;
}
void display_range_recipe() {
	return 0;
}
void display_all_recipe() {
	return 0;
}
void search_recipe() {
	return 0;
}
// a Recipe Manager application
//
// PROG71985F23	-	Fall 23'	-	Group Assignment
//
// Group - 22 - Rishi - Henil - Elisha Enakhe


#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

Recipe recipe[MAX_RECIPES];

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

            fclose(newFile);

            // Update recipe_list.txt with the new recipe
            FILE* recipe_list_file = fopen("recipe_list.txt", "r+");
            if (recipe_list_file != NULL) {
                int total_recipes = 0;  // Initialize to zero

                // Read the total count of recipes
                fscanf(recipe_list_file, "%d", &total_recipes);

                // Increment the total count of recipes
                total_recipes++;

                // Move the file pointer to the beginning of the file
                fseek(recipe_list_file, 0, SEEK_SET);

                // Write the updated total count of recipes
                fprintf(recipe_list_file, "%d\n", total_recipes);

                fclose(recipe_list_file);

                recipe_list_file = fopen("recipe_list.txt", "a");
                if (recipe_list_file != NULL) {
                    fprintf(recipe_list_file, "%d %s\n", total_recipes, recipe_name);
                    fclose(recipe_list_file);
                }
                else {
                    printf("\nError updating recipe_list.txt!\n");
                }

                printf("\nRecipe added successfully!\n");
            }
            else {
                printf("\nError updating recipe_list.txt!\n");
            }
        }
        else {
            printf("\nError creating the recipe file!\n");
        }
    }
}




void delete_recipe() {
    // Display the recipe list
    display_all_recipes();

    // Get the recipe number to delete
    int recipe_number;
    printf("Enter the recipe number to delete: ");
    scanf("%d", &recipe_number);

    // Open the recipe_list.txt file in read mode
    FILE* recipe_list_file = fopen("recipe_list.txt", "r");

    if (recipe_list_file != NULL) {
        // Open a temporary file to write updated content
        FILE* temp_file = fopen("temp_recipe_list.txt", "w");

        if (temp_file != NULL) {
            int current_recipe_number;
            char recipe_name[MAX_NAME_SIZE];

            // Read each line from the recipe_list.txt file
            while (fscanf(recipe_list_file, "%d %[^\n]", &current_recipe_number, recipe_name) == 2) {
                // Check if the current line has the recipe to delete
                if (current_recipe_number == recipe_number) {
                    // Delete the recipe file
                    char filename[MAX_NAME_SIZE];
                    sprintf(filename, "%s.txt", recipe_name);
                    remove(filename);
                }
                else if (current_recipe_number > recipe_number) {
                    // Decrement the recipe number for recipes after the deleted one
                    fprintf(temp_file, "%d %s\n", current_recipe_number - 1, recipe_name);
                }
                else {
                    // Write the line as is for recipes before the deleted one
                    fprintf(temp_file, "%d %s\n", current_recipe_number, recipe_name);
                }
            }

            fclose(temp_file);
            fclose(recipe_list_file);

            // Replace the original file with the temporary file
            remove("recipe_list.txt");
            rename("temp_recipe_list.txt", "recipe_list.txt");

            printf("\nRecipe deleted successfully!\n");
        }
        else {
            printf("\nError creating temporary file!\n");
            fclose(recipe_list_file);
        }
    }
    else {
        printf("\nError reading recipe_list.txt!\n");
    }
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
void display_all_recipes() {
    FILE* recipe_list_file = fopen("recipe_list.txt", "r");

    if (recipe_list_file != NULL) {
        printf("\n::----------  Recipe List  ----------::\n\n");
        printf("Recipe Number\tRecipe Name\n");
        printf("--------------------------------------\n");

        int total_recipes;  // Variable to store the total count of recipes
        int recipe_number;
        char recipe_name[MAX_NAME_SIZE];

        // Read the total count of recipes
        fscanf(recipe_list_file, "%d", &total_recipes);

        // Read and print each line in the file
        while (fscanf(recipe_list_file, "%d %[^\n]", &recipe_number, recipe_name) == 2) {
            printf("%d\t\t%s\n", recipe_number, recipe_name);
        }

        fclose(recipe_list_file);
        printf("\n::-----------------------------------::\n");
    }
    else {
        printf("\nError reading recipe_list.txt!\n");
    }
}



void search_recipe() {
    return 0;
}
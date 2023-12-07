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
    char recipe_name[MAX_NAME_SIZE];
    FILE* recipe_list_file = fopen("recipe_list.txt", "r");

    if (recipe_list_file != NULL) {
        int current_recipe_number;
        int total_recipes;
        fscanf(recipe_list_file, "%d", &total_recipes);

        // Check if the entered recipe number is valid
        if (recipe_numb < 1 || recipe_numb > total_recipes) {
            printf("\nInvalid recipe number. Please enter a valid recipe number.\n");
            fclose(recipe_list_file);
            return;
        }

        // Find the recipe name corresponding to the entered recipe number
        while (fscanf(recipe_list_file, "%d %[^\n]", &current_recipe_number, recipe_name) == 2) {
            if (current_recipe_number == recipe_numb) {
                break;
            }
        }

        fclose(recipe_list_file);

        char filename[MAX_NAME_SIZE];
        sprintf(filename, "%s.txt", recipe_name);

        FILE* recipe_file = fopen(filename, "r");

        if (recipe_file != NULL) {
            printf("\n::----------  Current Recipe Details for %s  ----------::\n\n", recipe_name);

            char recipe_steps[MAX_RECIPE_LENGTH];

            // Read and print each line in the file
            while (fgets(recipe_steps, sizeof(recipe_steps), recipe_file) != NULL) {
                printf("%s", recipe_steps);
            }

            printf("\n::------------------------------------------------------::\n");
            fclose(recipe_file);

            // Prompt for new recipe steps
            printf("\nEnter the updated recipe steps (enter an empty line to finish):\n");

            // Open the recipe file in write mode to overwrite the existing content
            recipe_file = fopen(filename, "w");

            if (recipe_file != NULL) {
                // Using a loop to read multiple lines of text
                bool finished = false;
                while (!finished) {
                    fgets(recipe_steps, sizeof(recipe_steps), stdin);

                    // to check if the line is empty (contains only newline character)
                    if (recipe_steps[0] == '\n') {
                        finished = true;
                    }
                    else {
                        fprintf(recipe_file, "%s", recipe_steps);
                    }
                }

                fclose(recipe_file);

                printf("\nRecipe updated successfully!\n");
            }
            else {
                printf("\nError updating the recipe file!\n");
            }
        }
        else {
            printf("\nError reading the current recipe file!\n");
        }
    }
    else {
        printf("\nError reading recipe_list.txt!\n");
    }
}


void display_single_recipe(int recipe_numb) {
    char recipe_name[MAX_NAME_SIZE];
    FILE* recipe_list_file = fopen("recipe_list.txt", "r");

    if (recipe_list_file != NULL) {
        int current_recipe_number;
        int total_recipes;
        fscanf(recipe_list_file, "%d", &total_recipes);

        // Check if the entered recipe number is valid
        if (recipe_numb < 1 || recipe_numb > total_recipes) {
            printf("\nInvalid recipe number. Please enter a valid recipe number.\n");
            fclose(recipe_list_file);
            return;
        }

        // Find the recipe name corresponding to the entered recipe number
        while (fscanf(recipe_list_file, "%d %[^\n]", &current_recipe_number, recipe_name) == 2) {
            if (current_recipe_number == recipe_numb) {
                break;
            }
        }

        fclose(recipe_list_file);

        char filename[MAX_NAME_SIZE];
        sprintf(filename, "%s.txt", recipe_name);

        FILE* recipe_file = fopen(filename, "r");

        if (recipe_file != NULL) {
            printf("\n::----------  Recipe Details for %s  ----------::\n\n", recipe_name);

            char recipe_steps[MAX_RECIPE_LENGTH];

            // Read and print each line in the file
            while (fgets(recipe_steps, sizeof(recipe_steps), recipe_file) != NULL) {
                printf("%s", recipe_steps);
            }

            printf("\n::----------------------------------------------::\n");
            fclose(recipe_file);
        }
        else {
            printf("\nError reading the recipe file!\n");
        }
    }
    else {
        printf("\nError reading recipe_list.txt!\n");
    }
}

void display_range_recipe() {
    int start_recipe, end_recipe;

    // Get the range of recipe numbers
    printf("Enter the start recipe number: ");
    scanf_s("%d", &start_recipe);
    printf("Enter the end recipe number: ");
    scanf_s("%d", &end_recipe);

    // Display recipes within the specified range
    for (int recipe_numb = start_recipe; recipe_numb <= end_recipe; ++recipe_numb) {
        display_single_recipe(recipe_numb);
    }
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
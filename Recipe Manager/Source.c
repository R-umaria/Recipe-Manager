// a Recipe Manager application
//
// PROG71985F23	-	Fall 23'	-	Group Assignment
//
// Group - 22 - Rishi - Henil - Elisha Enakhe


#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

int main() {

	int choice;
	do {
		printf("\n::----------  Recipe Manager  ----------::\n\n");
		printf("\t\tMain Menu\n");
		printf("  \t1. add a new recipe\n");
		printf("  \t2. delete an existing recipe\n");
		printf("  \t3. update an existing recipe\n");
		printf("  \t4. display single recipe\n");
		printf("  \t5. display range recipe\n");
		printf("  \t6. display all recipe\n");
		printf("  \t7. search for recipe\n");
		printf("  \t0. Exit\n");
		printf("------------------------------------------\n");
		printf("Enter your Choice: ");
		scanf_s("%d", &choice);

        char recipe_name[MAX_NAME_SIZE];
        int recipe_numb;

        switch (choice) {
        case 1:         
            add_recipe();
            break;

        case 2:
            recipe_list();
            printf("Enter the recipe number to delete: ");
            scanf_s("%d", &recipe_numb);

            delete_recipe(recipe_numb);
            break;

        case 3:
            recipe_list();
            printf("Enter the recipe number to update: ");
            scanf_s("%d", &recipe_numb);
            update_recipe(recipe_numb);
            break;

        case 4:
            recipe_list();
            printf("Enter the recipe number to Display: ");
            scanf_s("%d", &recipe_numb);
            display_single_recipe(recipe_numb);
            break;

        case 5:
            display_range_recipe(); //don't know what exactly it will do
            break;

        case 6:
            display_all_recipe();
            break;

        case 7:
            search_recipe();
            break;

        case 0:
            printf("\nExiting the program...\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
	} while (choice != 0);
	return 0;
}
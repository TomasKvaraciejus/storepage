#include <stdio.h>
#include <stdlib.h>

#define MENU_ITEM_AMOUNT 9

#define NEWLINE printf("\n");

// ---- Menu and User Input ----
// User input will be read through options menu accessed by index "menuIndex"
// 0 - Item Name*
// 1 - Image Source
//		(If image is not found or format is incorrect user will be notified but not prompted to enter new source; In case of no available source image will be replaced with "No image provided")
// 2 - Item Price*
// 3 - Shipping Cost (+ Seller's Location (?))
// 4 - Description
// 5 - More Information (Link)
// 6 - Details
// 7 - Seller's Contacts* (?)
// 8 - Compile Website Function
//
// * - mandatory (User will be prompted to enter details when attempting to compile website without sufficient data)
//		(User will be notified on currently empty mandatory fields with "*" character appended to name of field)
//
// Details will expand into separate menu accessed by index "menuIndex"
// 0 - Back (Return to Main Menu)
// 1 - Add New List Item to Top
// 2 - Add New List Item to Bottom
// 3 - Insert New List Item to Custom Index
//		(User will be provided with current Details list and prompted to enter index)
// 4 - Remove List Item
//		(User will be provided with current Details list and prompted to enter index of list item to remove)
//
// Seller's Contacts will expand into separate menu accessed by index "menuIndex"
//		(At least one field must contain contact information)
// 0 - Back (Return to Main Menu)
// 1 - Add or Replace Phone Number
// 2 - Add or Replace Email Address
// 3 - Add or Replace Custom Contact Link
//
// ---- Website Compilation ---- 
// Website will be compiled with highest index (8)
// On successful compilation program will exit

// TODO:
// Validate String Input (MAXCHAR)
// Save User Input
// Details Menu
// Seller's Contacts Menu
//
// Compile Website Function 

int validateIndexInput();

int main()
{
	int menuIndex;
	char* mainMenuOptions[MENU_ITEM_AMOUNT] = {"Item Name", "Image Source", "Item Price", "Shipping Cost", "Description", "More Information (Link)", "Details", "Seller's Contacts", "Compile Website and Exit"};
	char mainMenuFields[MENU_ITEM_AMOUNT] = { 1, 0, 1, 0, 0, 0, 0, 1, 0}; // 0 - Empty, non-mandatory; 1 - Empty, mandatory; 2 - Non-empty

	char end = 0;
	while (!end)
	{
		printf("---- Main Menu ----\n\n");
		for (int i = 0; i < MENU_ITEM_AMOUNT; i++)
		{
			printf("%d - %s%c\n", i, mainMenuOptions[i], ((mainMenuFields[i] == 1) ?'*' : ' '));
		}
		NEWLINE

		menuIndex = validateIndexInput();

		++end;
	}
}

int validateIndexInput()
{
	int input;
	printf("Enter index: ");
	while (!scanf("%d", &input) || !((input >= 0) && (input <= MENU_ITEM_AMOUNT - 1)))
	{
		char peekChar = getc(stdin);
		while (peekChar != '\n' && peekChar != ' ')
		{
			peekChar = getc(stdin);
		}
		putc(peekChar, stdin);
		printf("err: incorrect input\nEnter index: ");
	}

	NEWLINE

	return input;
}
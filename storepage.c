#include <stdio.h>
#include <stdlib.h>

#define MAIN_MENU_ITEM_AMOUNT 9
#define USERCONTACTS_MENU_ITEM_AMOUNT 4
#define MAX_STRING_LENGTH 128
#define MAX_STRING_DESCRIPTION_LENGTH 256
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
// ----------------
//
// Details will expand into separate menu accessed by index "menuIndex"
// 0 - Back (Return to Main Menu)
// 1 - Add New List Item to Top
// 2 - Insert New List Item to Custom Index
//		(User will be provided with current Details list and prompted to enter index)
// 3 - Modify List Item 
// 4 - Remove List Item
//		(User will be provided with current Details list and prompted to enter index of list item to remove)
//
// ----------------
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
//

// ---- TODO: ----
// Validate String Input (MAXCHAR)
// Save User Input
// Details Menu
// Seller's Contacts Menu
//
// Compile Website Function 

struct linkedList
{
	int maxStringLength;
	int index;
	char* s;
	struct linkedList* nextListItem;
};
typedef struct linkedList linkedList;

int validateIndexInput();

int getStringLength(char* s);

linkedList* initializeLinkedList();

char* validateStringInput(int maxLength);

int addLinkedListItem(linkedList* l, char* s);

int removeLinkedListItem(linkedList* l, int index);

int insertLinkedListItem(linkedList* l, char* s, int index);

int main()
{
	int menuIndex;
	char* mainMenuOptions[MAIN_MENU_ITEM_AMOUNT] = { "Item Name", "Image Source", "Item Price", "Shipping Cost", "Description", "More Information (Link)", "Details", "Seller's Contacts", "Compile Website and Exit" };
	char mainMenuFields[MAIN_MENU_ITEM_AMOUNT] = { 1, 0, 1, 0, 0, 0, 0, 1, 0 }; // 0 - Empty, non-mandatory; 1 - Empty, mandatory; 2 - Non-empty

	char* userContactsMenuOptions[USERCONTACTS_MENU_ITEM_AMOUNT] = {"Back", "Phone Number", "Email Address", "Custom Contact Link"};

	linkedList *mainMenuValues[MAIN_MENU_ITEM_AMOUNT];
	linkedList *userContactsMenuValues[USERCONTACTS_MENU_ITEM_AMOUNT];

	for (int i = 0; i < MAIN_MENU_ITEM_AMOUNT; i++)
	{
		mainMenuValues[i] = initializeLinkedList();
	}

	for (int i = 0; i < USERCONTACTS_MENU_ITEM_AMOUNT; i++)
	{
		userContactsMenuValues[i] = initializeLinkedList();
	}

	char end = 0;
	while (!end)
	{
		printf("---- Main Menu ----\n\n");
		for (int i = 0; i < MAIN_MENU_ITEM_AMOUNT; i++)
		{
			printf("%d - %-24s - %c%s\n", i, mainMenuOptions[i], ((mainMenuFields[i] == 1) ? '*' : ' '), (((i == 6 || i == 7)) ? "Expand Menu" : mainMenuValues[i]->s));
		}
		NEWLINE

		menuIndex = validateIndexInput(MAIN_MENU_ITEM_AMOUNT - 1);

		if (menuIndex == 8)
		{
			++end;
		}
		else if (menuIndex == 6)
		{

		}
		else if (menuIndex == 7)
		{
			char endMenu = 0;

			while (!endMenu)
			{
				for (int i = 0; i < USERCONTACTS_MENU_ITEM_AMOUNT; i++)
				{
					printf("%d - %-24s - %s\n", i, userContactsMenuOptions[i], userContactsMenuValues[i]->s);
				}
				NEWLINE

				menuIndex = validateIndexInput(12);

				if (menuIndex == 0)
				{
					++endMenu;
				}
				else
				{
					userContactsMenuValues[menuIndex]->s = validateStringInput(MAX_STRING_LENGTH);
					NEWLINE
				}
			}
		}
		else
		{
			printf("Enter New %s: ", mainMenuOptions[menuIndex]);
			free(mainMenuValues[menuIndex]->s);
			mainMenuValues[menuIndex]->s = validateStringInput(MAX_STRING_LENGTH);
		}
	}
}

linkedList* initializeLinkedList()
{
	linkedList* l = malloc(sizeof(linkedList));
	l->index = 0;
	l->s = NULL;
	l->nextListItem = NULL;
	l->maxStringLength = MAX_STRING_LENGTH;
	return l;
}

int addLinkedListItem(linkedList* l, char* s)
{
	int addValue = 0;

	while (l->nextListItem != NULL)
	{
		l = l->nextListItem;
	}

	linkedList* newListItem = malloc(sizeof(linkedList));
	if (newListItem != NULL)
	{
		newListItem->s = s;
		newListItem->nextListItem = NULL;
		newListItem->maxStringLength = l->maxStringLength;
		newListItem->index = l->index + 1;
		l->nextListItem = newListItem;
	}
	else
	{
		++addValue;
	}

	return addValue;
}

int removeLinkedListItem(linkedList* l, int index)
{
	int removeValue = 0;

	linkedList* prevListItem = l, *_l, *_originalListItem = l;

	if (l->index >= index)
	{
		++removeValue;
	}
	else
	{
		while (l->index != index && l != NULL)
		{
				prevListItem = l;
				l = l->nextListItem;
		}

		if (l->index == index)
		{
			prevListItem->nextListItem = l->nextListItem;
			_l = l->nextListItem;
			while (_l != NULL)
			{
				--(_l->index);
				_l = _l->nextListItem;
			}

			if (index == 0)
			{
				_l = l->nextListItem;
				free(l);
				l = _l;
				printf("buh\n");
			}
			else
			{
				free(l);
			}
		}
		else
		{
			++removeValue;
		}
	}

	return removeValue;
}

int insertLinkedListItem(linkedList* l, char* s, int index)
{
	int insertValue = 0;

	if (l->index > index)
	{
		++insertValue;
	}
	else
	{
		while (l->index != index && l != NULL)
		{
			l = l->nextListItem;
		}

		if (l->index == index)
		{
			linkedList* newListItem = malloc(sizeof(linkedList));
			newListItem->index = l->index + 1;
			newListItem->maxStringLength = l->maxStringLength;
			newListItem->s = s;
			newListItem->nextListItem = l->nextListItem;
			l->nextListItem = newListItem;

			linkedList* _l = newListItem->nextListItem;
			while (_l != NULL)
			{
				++(_l->index);
				_l = _l->nextListItem;
			}
		}
		else
		{
			++insertValue;
		}
	}

	return insertValue;
}

int validateIndexInput(int maxIndex)
{
	int input;
	printf("Enter index: ");
	while (!scanf("%d", &input) || !((input >= 0) && (input <= maxIndex)))
	{
		char peekChar = getc(stdin);
		while (peekChar != '\n' && peekChar != ' ')
		{
			peekChar = getc(stdin);
		}
		printf("err: incorrect input\nEnter index: ");
	}
	NEWLINE

		return input;
}

int getStringLength(char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		++i;
	}

	return i;
}

char* validateStringInput(int maxLength)
{
	char* input = (char*)malloc(maxLength);
	printf("Input string (character limit: %d): ", maxLength);
	scanf("%s", input);
	if (getStringLength(input) < maxLength)
	{
		input[getStringLength(input) - 1] = '\0';
	}
	else
	{
		if (getchar() != '\n')
		{
			printf("war: input exceeds character limit. Your input will be shortened in order to fit.\n");
			while (getchar() != '\n')
			{

			}
		}
	}
	return input;
}

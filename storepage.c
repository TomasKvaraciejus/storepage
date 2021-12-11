#include <stdio.h>
#include <stdlib.h>

#define MAIN_MENU_ITEM_AMOUNT 9
#define USERCONTACTS_MENU_ITEM_AMOUNT 4
#define MAX_STRING_LENGTH 128
#define MAX_STRING_DESCRIPTION_LENGTH 256
#define NEWLINE printf("\n");

#define TD fprintf(outputFile, "<td>\n");
#define TD_END fprintf(outputFile, "</td>\n");
#define TR fprintf(outputFile, "<tr>\n");
#define TR_END fprintf(outputFile, "</tr>\n");
#define BR fprintf(outputFile, "<br>\n");

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

int editLinkedListItem(linkedList* l, char* s, int index);

int printLinkedList(linkedList* list);

int addLinkedListItemToTop(linkedList** l, char* s);

void compileWebsite(linkedList** mainMenuValues, linkedList** userContactsMenuValues);

int main()
{
	int menuIndex;
	char* mainMenuOptions[MAIN_MENU_ITEM_AMOUNT] = { "Item Name", "Image Source", "Item Price", "Shipping Cost", "Description", "More Information (Link)", "Details", "Seller's Contacts", "Compile Website and Exit" };
	char mainMenuFields[MAIN_MENU_ITEM_AMOUNT] = { 1, 0, 1, 0, 0, 0, 0, 1, 0 }; // 0 - Empty, non-mandatory; 1 - Empty, mandatory; 2 - Non-empty

	char* userContactsMenuOptions[USERCONTACTS_MENU_ITEM_AMOUNT] = { "Back", "Phone Number", "Email Address", "Custom Contact Link" };

	linkedList* mainMenuValues[MAIN_MENU_ITEM_AMOUNT];
	linkedList* userContactsMenuValues[USERCONTACTS_MENU_ITEM_AMOUNT];

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
			int index = 0;
            		for(int index = 0; index < MAIN_MENU_ITEM_AMOUNT; ++index)
            		{
                		if(mainMenuFields[index] == 1)
                		{
                    			printf("You have not filled in all the necessary fields. Thus, you are unable to compile the file.\n");
                    			NEWLINE
                    			break;
                		}
            		}
            		if(index == MAIN_MENU_ITEM_AMOUNT - 1)
            		{
                		compileWebsite(mainMenuValues, userContactsMenuValues);
                		++end;
            		}
		}
		else if (menuIndex == 6)
		{
			char a = 1;
			int availableOptions = 5;
			int index = 0;
			int userInput;
			char* detailMenuOptions[5] = { "Return to Main Menu", "Add New List Item to Top", "Insert New List Item to Custom Index", "Modify List Item", "Remove List Item" };
			while (a)
			{
				printf("---- Current details ---- \n");
				NEWLINE
					if (mainMenuValues[menuIndex]->nextListItem == NULL)
					{
						printf("No current details.\n");
					}
					else
					{
						index = printLinkedList(mainMenuValues[menuIndex]);
					}
				NEWLINE
					printf("---- End of details ---- \n");
				NEWLINE
					linkedList* first = mainMenuValues[menuIndex];
				printf("---- Options menu ---- \n");
				if (!index)
				{
					availableOptions = 2;
				}
				else
				{
					availableOptions = 5;
				}
				for (int i = 0; i < availableOptions; ++i)
				{
					printf("%d - %s\n", i, detailMenuOptions[i]);
				}
				printf("What do you want to do?\n");
				userInput = validateIndexInput(availableOptions);
				switch (userInput)
				{
				case 0:
				{
					a = 0;
					break;
				}
				case 1:
				{
					addLinkedListItemToTop(&mainMenuValues[menuIndex], validateStringInput(MAX_STRING_LENGTH));
					index++;
					break;
				}
				case 2:
				{
					insertLinkedListItem(mainMenuValues[menuIndex], validateStringInput(MAX_STRING_LENGTH), validateIndexInput(index));
					index++;
					break;
				}
				case 3:
				{
					editLinkedListItem(mainMenuValues[menuIndex], validateStringInput(MAX_STRING_LENGTH), validateIndexInput(index));
					break;
				}
				case 4:
				{
					removeLinkedListItem(mainMenuValues[menuIndex], validateIndexInput(index));
					index--;
					break;
				}
				}
			}
		}
		else if (menuIndex == 7)
		{
			char endMenu = 0;

			while (!endMenu)
			{
				printf("---- User Contacts Menu ----\n");
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
					mainMenuFields[7] = 2;
					NEWLINE
				}
			}
		}
		else
		{
			printf("Enter New %s: ", mainMenuOptions[menuIndex]);
			free(mainMenuValues[menuIndex]->s);
			mainMenuValues[menuIndex]->s = validateStringInput(MAX_STRING_LENGTH);
			mainMenuFields[menuIndex] = 2;
		}
	}
}

void compileWebsite(linkedList** mainMenuValues, linkedList** userContactsMenuValues)
{
	FILE* outputFile = fopen("website.html", "w");
	if (outputFile != NULL)
	{
		fprintf(outputFile, "<!DOCTYPE html>\n");
		fprintf(outputFile, "<html>\n");
		fprintf(outputFile, "<head>\n");
		fprintf(outputFile, "<link href=\"style.css\" rel=\"stylesheet\" />\n");
		fprintf(outputFile, "<title>IrmaList</title>\n");
		fprintf(outputFile, "</head>\n");
		fprintf(outputFile, "<body>\n");

		fprintf(outputFile, "<h1> World's Best Store - <span class=\"demo rainbow\">IrmaList</span> </h1>\n");
		fprintf(outputFile, "<article>\n");
		fprintf(outputFile, "<h2>%s</h2>\n", mainMenuValues[0]->s); // Item Name
		fprintf(outputFile, "<table>\n");
		TR
			fprintf(outputFile, "<td rowspan=\"4\">\n");
		fprintf(outputFile, "<img src = \" %s \" width = \"250\"/>\n", mainMenuValues[1]->s); // Image Source
		TD_END
			TD
			fprintf(outputFile, "<strong>Price:</strong> %s\n", mainMenuValues[2]->s);
		TD_END
			TR_END
			TR
			TD
			fprintf(outputFile, "<strong>Shiping cost:</strong> %s\n", mainMenuValues[3]->s); // Shipping Cost
		TD_END
			TR_END
			TD
			TR_END
			TR
			TD
			fprintf(outputFile, "<p>\n");
		fprintf(outputFile, "<strong>Description:</strong>\n");
		BR
		fprintf(outputFile, "%s\n", mainMenuValues[4]->s); // Description
		fprintf(outputFile, "<a href=\"%s\">More information &rarr;</a>\n", mainMenuValues[5]->s); // More Information (Link)
		BR
		fprintf(outputFile, "</p>\n");
		TD_END
			TR_END
			TR
			TD
			fprintf(outputFile, "<strong>Product details:</strong>\n");
		fprintf(outputFile, "<ul>\n");
		do
		{
			fprintf(outputFile, "<li> %s\n", mainMenuValues[6]->s); // Product Details
			if (mainMenuValues[6]->nextListItem)
			{
				mainMenuValues[6] = mainMenuValues[6]->nextListItem;
			}
		} while (mainMenuValues[6]->nextListItem);
		fprintf(outputFile, "</ul>\n");
		fprintf(outputFile, "<button>Add to cart</button>\n");
		fprintf(outputFile, "</td>\n");
		fprintf(outputFile, "</tr>\n");
		fprintf(outputFile, "</article>\n");
		fprintf(outputFile, "</table>\n");

		for (int i = 0; i < 5; ++i)
		{
			BR
		}

		fprintf(outputFile, "<img class=\"stonks\"\n");
		fprintf(outputFile, "src=\"stonks.png\"\n");
		fprintf(outputFile, "/>");
		for (int i = 0; i < 5; ++i)
		{
			BR
		}


		fprintf(outputFile, "<p id=\"copyright\">&copy; 2021 Adomas, Tomas, Matas, Domas</p>\n");
		fprintf(outputFile, "</body>\n");
		fprintf(outputFile, "</html>\n");
	}
	else
	{
		printf("err: unable to create or open file\n");
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

	linkedList* prevListItem = l, * _l, * _originalListItem = l;

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
	getchar();
	fgets(input, maxLength + 1, stdin);
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
int editLinkedListItem(linkedList* l, char* s, int index)
{
	while (l->index != index)
	{
		l = l->nextListItem;
	}
	l->s = s;
	return 0;
}
int printLinkedList(linkedList* list)
{
	int index = 0;
	do
	{
		printf("%d - %s\n", list->index, list->s);
		if (list->nextListItem != NULL)
		{
			list = list->nextListItem;
		}
		index++;
	} while (list->nextListItem != NULL);
	return index;
}
int addLinkedListItemToTop(linkedList** l, char* s)
{
	linkedList* newElement = (linkedList*)malloc(sizeof(linkedList));
	newElement->s = s;
	newElement->index = 0;
	newElement->maxStringLength = (*l)->maxStringLength;
	newElement->nextListItem = *l;
	*l = newElement;
	while (newElement->nextListItem != NULL)
	{
		if (newElement->nextListItem != NULL);
		{
			newElement = newElement->nextListItem;
		}
		newElement->index++;
	}
	free(newElement);
	return 0;
}

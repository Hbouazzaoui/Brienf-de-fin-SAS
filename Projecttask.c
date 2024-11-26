#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int day;
	int month;
	int year;
} due_date;
typedef struct
{
	char title[30];
	char description[30];
	char priority[30];
	due_date date;
} task;
task ts[100];
int size = 0;
int added = 0;
void add()
{
	printf("Enter the title: ");
	scanf("%s", ts[size].title);

	printf("Enter the description: ");
	scanf("%s", ts[size].description);
	int choice;
	do
	{
		printf("Enter priority (1- High, 2- Low): ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			strcpy(ts[size].priority, "High");
			break;
		case 2:
			strcpy(ts[size].priority, "Low");
			break;
		default:
			printf("Invalid choice .\n");
		}
	} while (choice != 1 && choice != 2);
    do
    {
		printf("Enter the day: ");
		scanf("%d", &ts[size].date.day);
		if (ts[size].date.day >= 1 && ts[size].date.day <= 31)
		{
		}
		else
		{
			printf("No day available \n");
		}

	} while (ts[size].date.day < 1 || ts[size].date.day > 31);
    do
	{
		printf("Enter the month: \n");
	    scanf("%d", &ts[size].date.month);
		if (ts[size].date.month >= 1 && ts[size].date.month <= 12)
		{
		}
		else
		{
			printf("No month available\n");
		}

	} while (ts[size].date.month < 1 || ts[size].date.month > 12);
    do
	{
			printf("Enter the year :");
	        scanf("%d", &ts[size].date.year);
		if (ts[size].date.year >= 2024)
		{
		}
		else
		{
			printf("No year available\n");
		}

	} while (ts[size].date.year < 2024);
	size++;
	added = 1;
	printf("Task added successfully!\n");
}
void display()
{
	if (size == 0)
	{
		printf("No tasks available.\n");
		return;
	}
	int i = 0;
	while (i < size)
	{
		printf("\nTask %d:\n", i + 1);
		printf("Title: %s\n", ts[i].title);
		printf("Description: %s\n", ts[i].description);
		printf("Priority: %s\n", ts[i].priority);
		printf("Date: %02d/%02d/%04d\n", ts[i].date.day, ts[i].date.month, ts[i].date.year);
		i++;
	}
}
void modify()
{
	int index;
	printf("Enter the task index to modify (1 to %d): ", size);
	scanf("%d", &index);
	index--;

	if (index < 0 || index >= size)
	{
		printf("Invalid index!\n");
		return;
	}

	printf("Enter the new title :");
	scanf("%s", ts[index].title);
	printf("Enter the new description : ");
	scanf("%s", ts[index].description);

	int choice;
	do
	{
		printf("Enter priority (1- High, 2- Low): ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			strcpy(ts[index].priority, "High");
			break;
		case 2:
			strcpy(ts[index].priority, "Low");
			break;
		default:
			printf("Invalid choice! Try again.\n");
		}
	} while (choice != 1 && choice != 2);

	printf("Enter the new day : ");
	scanf("%d", &ts[index].date.day);
	printf("Enter the new month : ");
	scanf("%d", &ts[index].date.month);
	printf("Enter the new year : ");
	scanf("%d", &ts[index].date.year);

	printf("Task modified successfully!\n");
}

void delete()
{
	int index;
	printf("Enter the task index to delete ");
	scanf("%d", &index);
	index--;

	if (index < 0 || index >= size)
	{
		printf("Invalid index!\n");
		return;
	}
	int i = index;
	while (i < size - 1)
	{
		ts[i] = ts[i + 1];
		i++;
	}
	size--;
	printf("Task deleted successfully!\n");
}
void filter()
{
	if (size == 0)
	{
		printf("No tasks available.\n");
		return;
	}

	char filter[10];
	printf("Enter the priority to filter by (High/Low): ");
	scanf("%s", filter);
	int found = 0;
	printf("\n Tasks with priority '%s':\n", filter);
	int i = 0;
	while (i < size )
	{
		if (strcmp(ts[i].priority, filter) == 0)
		{
			printf("\nTask %d:\n", i + 1);
			printf("Title: %s\n", ts[i].title);
			printf("Description: %s\n", ts[i].description);
			printf("Date: %02d/%02d/%04d\n", ts[i].date.day, ts[i].date.month, ts[i].date.year);
		}
		i++;
	}
	if (!found)
	{
		printf("No tasks found with priority '%s'.\n", filter);
	}
}

int main() {
    int choice;

    do {
		printf("\n\n ---------- Task management application ----------\n \n"); 
        printf("\n---- Menu ----\n\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Modify \n");
        printf("4. Delete \n");
        printf("5. Filter Tasks by Priority\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
		{
            add();
        } 
		else if (added == 1) {
            switch (choice) {
                case 2:
                    display();
                    break;
                case 3:
                    modify();
                    break;
                case 4:
                    delete();
                    break;
                case 5:
                    filter();
                    break;
                case 6:
                    printf("Goodbye !\n");
                    break;
                default:
                    printf("Invalid choice!.\n");
            }
        } else {
            printf("You must add a task first before using other options.\n");
        }
    } while (choice != 6);
    return 0;
}

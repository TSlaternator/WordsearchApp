#include <windows.h>
printWordSearch(char wordSearch[25][25], int category, char name[256], int time, int wordsLeft, 
                char categories[7][25])
{
	int height, width;
	//colour changing:
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//prints the wordsearch with a border, aswell as remaining time and unfound words
	printf("OK %s, There are 10 %s hidden in this grid.", name, categories[category]);
	printf("\nCan you find them all in 5 minutes? Type in any you see.");
	printf("\nNote: multiple guesses per second will count down a second\n");
	printf("----------------------------------------------------");
	for (height = 0; height < 25; height++)
	{
		printf("\n|");
		for (width = 0; width < 25; width++)
		{
			SetConsoleTextAttribute(hConsole, 15);
			if (wordSearch[height][width] >= 97 && wordSearch[height][width] < 122)
			{
				SetConsoleTextAttribute(hConsole, 9);
				printf("%c ", (wordSearch[height][width] - 32));
			}
			else 
				printf("%c ", wordSearch[height][width]);
		}
		printf("|");
	}
	printf("\n----------------------------------------------------\n");
	printf("%d word(s) still to find...", wordsLeft);
	printf("time left: %d:%d...\n", (time / 60), (time % 60));
}


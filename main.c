#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(int argc, char *argv[]) 
{
	//setting seed for the random function
	srand((unsigned) time(NULL));
	
	// 3D array to hold all the categories
	char wordsList[7][10][12] = {
							        {"APPLES", "BANANAS", "ORANGES", "WATERMELON", "GRAPES", 
                         		    "PINEAPPLE", "LEMON", "AVOCADO", "STRAWBERRY", "CITRUS"},
                         		   
								    {"BRITAIN", "MEXICO", "CANADA", "GERMANY", "ARGENTINA", 
                         		    "BULGARIA", "NORWAY", "JAPAN", "ICELAND", "GREENLAND"},
                         		   
								    {"FOOTBALL", "RUGBY", "HOCKEY", "BADMINTON", "BASKETBALL", 
                         		    "HANDBALL", "NETBALL", "CRICKET", "BASEBALL", "ROUNDERS"},
                         		    
                         		    {"TEACHER", "ATHELETE", "ENGINEER", "SCIENTIST", "CHEF", 
                         		    "ACTOR", "PRIEST", "LIFEGUARD", "FARMER", "BARBER"},
                         		    
                         		    {"AUDI", "VAUXHALL", "BENTLEY", "JAGUAR", "PEUGEOT", 
                         		    "PORSCHE", "SUBARU", "TOYOTA", "HONDA", "MAZDA"},
                         		    
                         		    {"FIFA", "DOTA", "THECULLING", "DARKSOULS", "SUPERMARIO", 
                         		    "POKEMON", "SMASHBROS", "SMITE", "CALLOFDUTY", "MOTORSTORM"},
                         		    
                         		    {"THEMATRIX", "ELYSIUM", "INCEPTION", "CONAIR", "INTIME", 
                         		    "DODGEBALL", "GODFATHER", "FIGHTCLUB", "TERMINATOR", "GLADIATOR"}
								};
    char categories[7][25] = {"fruit", "countries", "sports", "professions", "car manufacturers",
							  "video Games", "films"};
   
    int storage [10][3]; /* array to store location and direction of all words, will be used to 
	colour them in later on in the program, [][0] will hold directional value (0 - vertical,
	1 -horizontal 2 - diagonally up, 3 diagonally down) [][1] will hold start height, [][2] will 
	hold start width */
    
	//declaring varibles
    char wordSearch[25][25];
    int height, width, wordLength, direction, category, time, seconds;
    int currentWord = 0, gameWon = 0;
    int wordsLeft = 10;
    char name[256];
    char guess[256];
    
    //presets wordsearch to .'s so i can check for duplicates
    preset(&wordSearch);
    
    //welcomes the user to the program and asks which category to use
    welcome();
    printf("\nWhat is your name?:>");
    scanf("%s", &name);
    category = (getCategory(name)) - 1;
    
    while(currentWord < 10)
    {
    	wordLength = strlen(wordsList[category][currentWord]);
    	
    	/*randomly selecting direction, will be hoorizontal on 0 - 3 (40% of time), vertical on
    	4 - 7 (40% of time) diagonally up on 8 (10%) and diagonally down on 9 (10%) */
    	direction = rand () % 9;
    	if (direction < 4)
            currentWord = insertHorizontally(&wordsList, &wordSearch, &storage, currentWord, wordLength, category);
        else if (direction > 3 && direction < 8)
            currentWord = insertVertically(&wordsList, &wordSearch, &storage, currentWord, wordLength, category);
        else if (direction == 8)
            currentWord = insertDiagonallyUp(&wordsList, &wordSearch, &storage, currentWord, wordLength, category);
        else if (direction == 9)
            currentWord = insertDiagonallyDown(&wordsList, &wordSearch, &storage, currentWord, wordLength, category);
    } 
    	
    //fills rest of wordsearch with random letters
    fillWordSearch(&wordSearch);
    
    //running the actual game and starting the timer
    for (time = 300; time > 0;)
    {
    	clock_t start = clock();
    	system("cls");
    	//prints out wordsearch with a border
    	printWordSearch(&wordSearch, category, name, time, wordsLeft, categories);
    	printf("Guess:> ");
    	scanf("%s[^ ]", &guess);
    	clock_t end = clock();
    	//making minimum time between guess 1 sec, to avoid spam cheesing the game
    	if(((end - start) / CLOCKS_PER_SEC) == 0)
    		end += (1 * CLOCKS_PER_SEC);
    	seconds = (end - start) / CLOCKS_PER_SEC;
    	time -= seconds;
    	wordsLeft = checkGuess(&wordSearch, &wordsList, category, guess, storage, wordsLeft);
    	if (wordsLeft == 0)
    	{
    		gameWon = 1;
    		break;
		}
    }	
    
    //exit message
	if (gameWon == 1)
		printf("\n\nCongratulations %s! You found all the words in %d seconds!", name, (300 - time));
	else
		printf("\n\nYou only found %d words before time ran out... you're a failure.", (10 - wordsLeft));
		
		
	return 0;
}

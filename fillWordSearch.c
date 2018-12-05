fillWordSearch(char wordSearch[25][25])
{
	int width, height;
	//random function will be used to select a random letter from alphabet
	char alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	
	for (height = 0; height < 25; height++)
	{
		for (width = 0; width < 25; width++)
			if (wordSearch[height][width] == '.')
			    wordSearch[height][width] = alphabet[rand() % 26];
    }
}

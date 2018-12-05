insertHorizontally(char wordsList[7][10][12], char wordSearch[25][25], int storage[10][3], int currentWord, 
                   int wordLength, int category)
{
	int x, width, height, overlap = 0;
	int pass = 0;
	
	while (pass == 0)
	{
		overlap = 0;
		//setting random width and height while ensuring word fits in the grid
		height = rand() % 25;
		width = rand() % (25 - wordLength);

		//checking for overlap
		for (x = 0; x < wordLength; x++)
		{
			if (wordSearch[height][(width + x)] != '.')
				overlap++;
		} 
	
		//if no overlap, inserts word into the wordsearch
		if (overlap == 0)
		{
			storage[currentWord][0] = 1;
			storage[currentWord][1] = height;
			storage[currentWord][2] = width;
			
			for (x = 0; x < wordLength; x++)
				wordSearch[height][(width + x)] = wordsList[category][currentWord][x];
		    currentWord++;
		    pass++;
		}
    }
	return currentWord;
}

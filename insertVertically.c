insertVertically(char wordsList[7][10][12], char wordSearch[25][25], int storage[10][3], int currentWord, 
                 int wordLength, int category)
{
	int x, width, height, overlap = 0;
	int pass = 0;
	
	while (pass == 0)
	{
		overlap = 0;
		//setting random width and height while ensuring word fits in the grid
		height = rand() % (25 - wordLength);
		width = rand() % 25;
	
		//checking for overlap
		for (x = 0; x < wordLength; x++)
		{
			if (wordSearch[(height + x)][width] != '.')
				overlap++;
		} 
		
		//if no overlap, inserts word into the wordsearch and breaks loop
		if (overlap == 0)
		{
			storage[currentWord][0] = 0;
			storage[currentWord][1] = height;
			storage[currentWord][2] = width;
			
			for (x = 0; x < wordLength; x++)
				wordSearch[(height + x)][width] = wordsList[category][currentWord][x];
			currentWord++;
			pass++;
		}
    }
	return currentWord;
}

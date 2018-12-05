checkGuess(char wordSearch[25][25], char wordsList[7][10][12], int category, char guess[256], int storage[10][3], 
           int wordsLeft)
{
	int currentLetter, currentWord, wordLength;
	for (currentWord = 0; currentWord < 10; currentWord++)
	{	
		//checking guess against words in the category
		if (strcmp(guess, wordsList[category][currentWord]) == 0)
		{
			wordsLeft--;
			wordLength = strlen(wordsList[category][currentWord]);
			//sets found word to lowercase so it can be highlighted in the array
			for (currentLetter = 0; currentLetter < wordLength; currentLetter++)
		    	wordsList[category][currentWord][currentLetter] += 32;
	        
	        //loops to change the words to lowercase
			if (storage[currentWord][0] == 0) //Vertically
			{
				for (currentLetter = 0; currentLetter < wordLength; currentLetter++)
					wordSearch[(storage[currentWord][1] + currentLetter)][storage[currentWord][2]] = wordsList[category][currentWord][currentLetter];
		    }		
			
			if (storage[currentWord][0] == 1) //Horizontally
			{
				for (currentLetter = 0; currentLetter < wordLength; currentLetter++)
					wordSearch[storage[currentWord][1]][(storage[currentWord][2] + currentLetter)] = wordsList[category][currentWord][currentLetter];
		    }
			
			if (storage[currentWord][0] == 2) //DiagonallyUp
			{
				for (currentLetter = 0; currentLetter < wordLength; currentLetter++)
					wordSearch[(storage[currentWord][1] - currentLetter)][(storage[currentWord][2] + currentLetter)] = wordsList[category][currentWord][currentLetter];
		    }
			
			if (storage[currentWord][0] == 3) //DiagonallyDown
			{
				for (currentLetter = 0; currentLetter < wordLength; currentLetter++)
					wordSearch[(storage[currentWord][1] + currentLetter)][(storage[currentWord][2] + currentLetter)] = wordsList[category][currentWord][currentLetter];
		    }	
		}
	}
	return wordsLeft;
}

preset(char wordSearch[25][25])
{
	int width, height;
	//fills the array with .'s so i can detect where letters have been placed
	for (height = 0; height < 25; height++)
	{
		for (width = 0; width < 25; width++)
			wordSearch[height][width] = '.';
	}
}

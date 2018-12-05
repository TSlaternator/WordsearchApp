getCategory(char name[256])
{
	int output;
	int pass = 0;
	
	//selecting which category
	printf("Hi %s! Select a category by typing in it's number", name);
	printf("\n--------------------------------");
	printf("\n1. Fruits");
	printf("\n2. Countries");
	printf("\n3. Sports");
	printf("\n4. Professions");
	printf("\n5. Car Manufacturers");
	printf("\n6. Videogames");
	printf("\n7. Films");
	printf("\n--------------------------------\n:>");
	
	//making sure input is valid
	scanf("%d", &output);
	if (output > 0 && output < 8)
		pass++;
	
	while (pass == 0)
	{
		printf("\nERROR! PlEASE INPUT CORRECT VALUE!");
		scanf("%d", &output);
		getchar();
		if (output > 0 && output < 8)
			pass++;
    }
	return output;
}

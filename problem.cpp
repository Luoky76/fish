Problem *Problem::getInstance(int level)
{
	Problem *Pro = nullptr;
	if (level == 1)
	{
		Pro = new Level1;
	}
	else if (level == 2)
	{
		Pro = new Level2;
	}
	else if (level == 3)
	{
		Pro = new Level3;
	}
	return Pro;
}
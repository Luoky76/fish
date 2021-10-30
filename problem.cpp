Problem *Problem::getInstance(int level)
{
	if (level == 1)
	{
		Problem Pro = new Level1;
	}
	else if (level == 2)
	{
		Problem Pro = new Level2;
	}
	else if (level == 3)
	{
		Problem Pro = new Level3;
	}
	return Pro;
}
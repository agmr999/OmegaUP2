#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, color, cost1, cost2;
	char cartas[100];
	scanf("%d", &n); 
	scanf("%s", cartas);
	cost1 = 0;
	for(int i = 0, color = 0; i < n; i++, color++)
	{
		if(color % 2 == 0)
		{
			if(cartas[i] == 'B')
				cost1++;
		}
		else
		{
			if(cartas[i] == 'W')
				cost1++;
		}
	}
	cost2 = 0;
	for(int i = 0, color = 1; i < n; i++, color++)
	{
		if(color % 2 == 0)
		{
			if(cartas[i] == 'B')
				cost2++;
		}
		else
		{
			if(cartas[i] == 'W')
				cost2++;
		}
	}
	if(cost1<cost2)
		printf("%i",cost1);
	else
		printf("%i",cost2);		
	return 0;
}

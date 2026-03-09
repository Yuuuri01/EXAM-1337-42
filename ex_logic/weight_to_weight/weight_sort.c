# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>



//check space
int blank(char c)
{
	if(c == 32 || c == 9)
		return 1;
	return 0;
}
//swap by order
void swap(char **a, char **b)
{
	char *tmp = *a;
	*a = *b;
	*b = tmp;
}
//calcule sum of number n100 == 1n
int convert_sum(char *str)
{
	int i = 0;
	int sum = 0;
	while(str[i])
	{
		sum += str[i] - 48;
		i++;
	}
	return sum;
}
//cump the two values
int cmp_sum(char *s1, char *s2)
{
	int w1 = convert_sum(s1);
	int w2 = convert_sum(s2);
	if(w1 > w2)
		return 1;
	if(w1 <= w2)
		return -1;
}
//count words
int count_word(const char *str)
{
	int index = 0;
	int i = 0;
	int val;
	while(str[i])
	{
		val = blank(str[i]);
		if(!val)
		{
			if(i == 0 || blank(str[i - 1]))
				index++;
		}
		i++;
	}
	return index;
}
//count length of every string
int length_string(const char *tab)
{
	int i = 0;
	while(tab[i] && !blank(tab[i]))
		i++;
	return i;
}
//copy string to another string 2D
char *copy(const char *tab, int length)
{
	char *str = malloc((length + 1) * sizeof(char));
	if(!str)
		return NULL;
	int i = 0;
	while(i < length)
	{
		str[i] = tab[i];
		i++;
	}
	str[i] = '\0';
	return str;
}
//function 1er
char *orderWeight(const char *string)
{
	 int len = 0;
         while(string[len])
                 len++;
	int size = count_word(string);
	char **tab = malloc((size + 1) * sizeof(char *));
	if(!tab)
		return NULL;
	int index = 0;
	int length;
	int i = 0;
	while(string[i])
	{
		if(!blank(string[i]))
		{
			length = length_string(&string[i]);
			tab[index++] = copy(&string[i], length);
			i += length;
		}
		else
			i++;
	}
	tab[index] = NULL;
	i = 0;
	int j;
	while(tab[i])
	{

		j = i + 1;
		while(tab[j])
		{
			if(cmp_sum(tab[i], tab[j]) > 0)
				swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	char *str = calloc((len + 1), sizeof(char));
	if(!str)
		return NULL;
	i = 0;
	index = 0;
	while(tab[i])
	{
		j = 0;
		while(tab[i][j])
			str[index++] = tab[i][j++];
		i++;
		if(tab[i] != NULL)
			str[index++] = ' ';
	}
	str[index] = '\0';
	i = 0;
	while(tab[i])
		free(tab[i++]);
	free(tab);
	return str;
}
/*
int main()
{
	const char *str = "100 20 97 99 56";
	char *src = orderWeight(str);
	int i = 0;
	while(src[i])
		printf("%c", src[i++]);
	printf("\n");

	free(src);
}
*/

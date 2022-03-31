/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:02:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/03/31 17:26:27 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define FALSE 0
# define TRUE 1

int	give_next_character_not_in_quote(char *str, int start, char c)
{
	while(str[start])
	{
		if (str[start] == c)
			return (start);
		start++;
	}
	return (start);
}

int	give_next_character(char *str, int start, char c)
{
	while(str[start])
	{
		if (str[start] == c)
			return (start);
		start++;
	}
	return (start);
}

int quote_checker(char *commande)
{
	int i;
	DEBUG || printf()
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			give_next_character(commande, i + 1, '\'');
			if (str[i])
				i++;
			else
				return ((int)'\'');
		}
		if (str[i] == '\"')
		{
			give_next_character(commande, i + 1, '\"');
			if (str[i])
				i++;
			else
				return ((int)'\"');
		}
		i++;
	}
	return (0)
}

int	primary_checker(char *commande)
{
	int i;
	int	check;

	i = 0;
	check = quote_checker(commande) != 0;
	if (check != 0)
		printf("syntax error: missing %c\n", check);
	
	i++;
}

int main()
{
	char *commande;

	commande = "";
	if(primary_checker() == TRUE)
		printf("The checker say 'commande is good'");
	else
		printf("The checker say 'commande is bad'");
}
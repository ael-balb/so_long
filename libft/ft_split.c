/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-balb <ael-balb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 17:53:00 by ael-balb          #+#    #+#             */
/*   Updated: 2023/08/14 18:01:27 by ael-balb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calcul_w(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			k++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (k);
}

int	ft_calcul_len(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		if (s[i] != c)
			k++;
		i++;
	}
	return (k);
}

char	*ft_alloc_w(const char *s, char c)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = ft_calcul_len(s, c);
	str = malloc(sizeof(char) * k + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	str = malloc (sizeof (char *) * (ft_calcul_w(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			str[k] = ft_alloc_w(&s[i], c);
			i = i + ft_calcul_len(&s[i], c);
			k++;
		}
	}
	str[k] = 0;
	return (str);
}

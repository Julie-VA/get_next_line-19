/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:14:24 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/04/18 18:35:05 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_modstrlen(const char *s, int mod)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (mod == 1)
		while (s[i] && s[i] != '\n')
			i++;
	else
		while (s[i])
			i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*(char *)s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		l;

	i = 0;
	l = ft_modstrlen(s, 0);
	dest = (char *)malloc(sizeof(char) * (l + 1));
	if (!dest)
		return (NULL);
	while (i < l)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	char	*destcpy;
	char	*srccpy;

	if (!src && !dest)
		return (NULL);
	destcpy = (char *)dest;
	srccpy = (char *)src;
	if (destcpy > srccpy)
	{
		while (n-- > 0)
			destcpy[n] = srccpy[n];
	}
	else
		while (n-- > 0)
			*destcpy++ = *srccpy++;
	return (destcpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		lens1;
	int		lens2;

	if (!s1 && !s2)
		return (ft_strdup(""));
	lens1 = ft_modstrlen(s1, 0);
	lens2 = ft_modstrlen(s2, 0);
	str = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	ft_memmove(str, s1, lens1);
	ft_memmove(str + lens1, s2, lens2);
	str[lens1 + lens2] = '\0';
	free((char *)s1);
	return (str);
}

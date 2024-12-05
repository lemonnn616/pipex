/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iriadyns <iriadyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:21:36 by iriadyns          #+#    #+#             */
/*   Updated: 2024/11/10 16:27:59 by iriadyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_get_next_line(char *s1, char *s2)
{
	char	*result;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result = ft_join_get_next_line(result, s1, s2);
	if (s1)
		free(s1);
	return (result);
}

char	*ft_join_get_next_line(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	x = 0;
	while (s2 && s2[x])
	{
		dest[i] = s2[x];
		i++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}

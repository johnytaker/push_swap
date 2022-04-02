/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iugolin <iugolin@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:37:12 by iugolin           #+#    #+#             */
/*   Updated: 2022/03/31 14:59:17 by iugolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*rtn;
	size_t	size;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((const char *)s1);
	s2_len = ft_strlen((const char *)s2);
	size = s1_len + s2_len + 1;
	rtn = (char *)malloc(sizeof(char) * size);
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, s1, s1_len + 1);
	ft_strlcpy(rtn + s1_len, s2, s2_len + 1);
	free(s1);
	return (rtn);
}

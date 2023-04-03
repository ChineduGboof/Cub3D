/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:08:53 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/03 15:09:57 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup_and_trim(char *src)
{
	char	*new;
	size_t	index;
	size_t	new_index;

	if (src == NULL)
		return (NULL);
	new = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (new == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	index = 0;
	new_index = 0;
	while (src[index] != '\0')
	{
		if (src[index] != ' ' && src[index] != '\t')
		{
			new[new_index] = src[index];
			new_index++;
		}
		index++;
	}
	new[new_index] = '\0';
	return (new);
}

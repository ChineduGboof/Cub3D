/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:52:13 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/31 22:16:06 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*	Gets the number of elements in a 2D array */
size_t	ft_arrlen(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}

/*	checks if a string contains a valid integer */
int	ft_isvalidint(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*	counts how many tabs are in the string */
static	int	count_tabs(char *src)
{
	int		num_tabs;
	size_t	i;

	num_tabs = 0;
	if (src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '\t')
			num_tabs++;
		i++;
	}
	return (num_tabs);
}

/*	duplicates a string, replacing also all tabs with 4 spaces */
char	*ft_strdup_replace_tabs_with_space(char *src)
{
	size_t	len;
	size_t	i;
	size_t	j;
	int		k;
	char	*new;

	len = ft_strlen(src);
	new = malloc((len + count_tabs(src) * 3 + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (src[++i] != '\0')
	{
		if (src[i] == '\t')
		{
			k = -1;
			while (++k < 4)
				new[j++] = ' ';
		}
		else
			new[j++] = src[i];
	}
	new[j] = '\0';
	return (new);
}

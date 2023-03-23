/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 20:04:12 by oaydemir          #+#    #+#             */
/*   Updated: 2021/10/09 19:11:44 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*traversing_ptr;
	t_list	*first_element;
	t_list	**head;

	if (lst == NULL || f == NULL)
		return (NULL);
	del++;
	first_element = ft_lstnew(f(lst->content));
	lst = lst->next;
	head = &(first_element);
	traversing_ptr = first_element->next;
	while (lst != NULL)
	{
		traversing_ptr = ft_lstnew(f(lst->content));
		if (traversing_ptr == NULL)
		{
			ft_lstclear(head, del);
			return (NULL);
		}
		ft_lstadd_back(head, traversing_ptr);
		lst = lst->next;
	}
	return (*(head));
}

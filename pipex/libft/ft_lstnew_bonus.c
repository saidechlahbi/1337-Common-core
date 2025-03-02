/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:13:59 by sechlahb          #+#    #+#             */
/*   Updated: 2024/10/31 13:13:59 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*now;

	now = (t_list *)malloc(sizeof(t_list));
	if (!now)
		return (NULL);
	now->content = content;
	now->next = NULL;
	return (now);
}

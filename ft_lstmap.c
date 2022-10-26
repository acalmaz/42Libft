/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalmaz <acalmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 02:13:47 by acalmaz           #+#    #+#             */
/*   Updated: 2022/10/26 02:18:07 by acalmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list    *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list    *new;
    t_list    *begin;

    if (lst == NULL || f == NULL)
        return (NULL);
    begin = 0;
    while (lst)
    {
        new = ft_lstnew((*f)(lst->content));
        if (!new)
        {
            ft_lstclear(&begin, del);
            return (NULL);
        }
        ft_lstadd_back(&begin, new);
        lst = lst->next;
    }
    return (begin);
}
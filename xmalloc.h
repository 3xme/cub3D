/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:35:54 by abiari            #+#    #+#             */
/*   Updated: 2020/02/14 17:41:12 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XMALLOC_H
# define XMALLOC_H

# define MALLOC1 xmalloc
# define FREE xfree
# define FLUSH xflush
# define EXIT xexit

typedef struct		s_link
{
	size_t			addr;
	struct s_link	*next;
}					t_link;
void				xflush(void);
void				*xmalloc(size_t bytes);
void				xfree(void *adr);
#endif

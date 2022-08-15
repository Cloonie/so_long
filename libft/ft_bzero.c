/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:10:58 by mliew             #+#    #+#             */
/*   Updated: 2022/05/24 09:54:30 by mliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

// int	main () 
// {
// 	char str[] = "This is string.h library function";
// 	printf("%s\n", str);
// 	ft_bzero(str, 4);
// 	printf("%s\n", str);
// 	ft_bzero(str, 16);
// 	printf("%s\n", str);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:25:00 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/06 12:27:57 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

char	*mult(char *num_x, char *num_y)
{
	int i_x;
	int i_y;
	int i_r;
	int len_x;
	int len_y;
	char *x;
	char *y;
	char *r;
	int carry;

	i_x = i_y = i_r = 0;
	len_x = ft_strlen(num_x);
	len_y = ft_strlen(num_y);
	r = (char *)ft_memalloc(sizeof(char) * (len_x + len_y + 1));
	x = ft_strdup(num_x);
	y = ft_strdup(num_y);
	//ft_strcpy(x, num_x);
	while (i_x < len_x)
	{
		x[i_x] -= '0';
		i_x++;
	}
	//ft_strcpy(y, num_y);
	while (i_y < len_y)
	{
		y[i_y] -= '0';
		i_y++;
	}
	i_x = len_x - 1;
	i_y = len_y - 1;
	i_r = i_x + i_y + 1;
	carry = 0;
	while (i_x >= 0)
	{
		carry = 0;
		while (i_y >= 0)
		{
			int n = x[i_x] * y[i_y] + r[i_r] + carry;
			r[i_r] = (n % 10);
			carry = n / 10;
			i_y--;
			i_r--;
		}
		r[i_r] += carry;
		i_x--;
	}
	i_r = 0;
	while (i_r < len_x + len_y)
	{
		r[i_r] += '0';
		++i_r;
	}
	while (r[0] == '0')
		ft_memmove(r, &r[1], len_x + len_y);
	free(x);
	free(y);
	return (r);
}

int main()
{
	printf("%s\n", mult("1115", "3"));
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:25:00 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/07 17:02:12 by ysibous          ###   ########.fr       */
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
	int sign;
	char *output;

	sign = 1;
	if (num_x[0] == '-')
	{
		num_x++;
		sign *= -1;
	}
	if (num_y[0] == '-')
	{
		num_y++;
		sign *= -1;
	}
	int z = 0;
	int count_x = 0;
	int is_flt = 0;
	int count_y = 0;
	/*while (num_x[z])
	{
		if (is_flt)
			count_x++;
		if (num_x[z] == '.')
			is_flt = 1;
		z++;
	}
	z = 0;
	is_flt = 0;
	while (num_y[z])
	{
		if (is_flt)
			count_y++;
		if (num_y[z] == '.')
			is_flt = 1;
		z++;
	}*/
	printf("%d\n", count_x);
	printf("%d\n", count_y);
	if (ft_atoi(num_x) >= ft_atoi(num_y))
		ft_swapstr(&num_x, &num_y);
	i_x = i_y = i_r = 0;
	len_x = ft_strlen(num_x);
	len_y = ft_strlen(num_y);
	r = (char *)ft_memalloc(sizeof(char) * (len_x + len_y + 1));
	/*if (count_y > count_x && count_x == 0)
	{
		x = ft_strnew(len_x + count_y + 1);
		ft_strcpy(x, num_x);
		x[len_x] = '.';

		printf("%s\n", x);
	}
	else if (count_y > count_x && count_x != 0)
	{
		x = ft_strnew(len_x + (count_y - count_x));
		ft_strcpy(x, num_x);
	}
	else*/
	//{
		x = ft_strnew(len_x);
		ft_strcpy(x, num_x);
//	}
	while (i_x < len_x)
	{
		x[i_x] -= '0';
		++i_x;
	}
/*	if (count_x > count_y && count_y == 0)
	{
		y = ft_strnew(len_y + count_x + 1);
		ft_strcpy(y, num_y);
		y[len_y] = '.';
		printf("%s\n", y);
	}
	else if (count_x > count_y && count_y != 0)
	{
		y = ft_strnew(len_x + (count_x - count_y));
		ft_strcpy(y, num_y);
	}
	else*/
//	{
		y = ft_strnew(len_y);
		ft_strcpy(y, num_y);
//	}
	while (i_y < len_y)
	{
		y[i_y] -= '0';
		++i_y;
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
		i_r++;
	}
	free(x);
	free(y);
	if (sign == -1)
	{
		output = ft_strnew((ft_strlen(r) + 1));
		output[0] = '-';
		ft_strcpy((output + 1), r);
		return (output);
	}
	return (r);
}

int main()
{
	printf("%s\n", mult("500", "5000"));
}


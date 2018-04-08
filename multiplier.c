/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:54:57 by ysibous           #+#    #+#             */
/*   Updated: 2018/04/07 18:55:22 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>


char  *mult(char *num_x, char *num_y)
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
  if (ft_atoi(num_x) >= ft_atoi(num_y))
    ft_swapstr(&num_x, &num_y);
  i_x = i_y = i_r = 0;
  len_x = ft_strlen(num_x);
  len_y = ft_strlen(num_y);
  r = (char *)ft_memalloc(sizeof(char) * (len_x + len_y + 1));
  x = ft_strnew(len_x);
  ft_strcpy(x, num_x);
  while (i_x < len_x)
  {
    x[i_x] -= '0';
	++i_x;
  }
  y = ft_strnew(len_y);
  ft_strcpy(y, num_y);
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
  printf("%s\n", mult("4", "50"));
}

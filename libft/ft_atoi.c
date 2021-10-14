/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:08:43 by eperaita          #+#    #+#             */
/*   Updated: 2021/10/14 18:10:49 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

static void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

int	ft_atoi(const char *str)
{
	unsigned int		i;
	int					neg;
	unsigned long int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' && i != 0)
		ft_error();
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	if ((nb > 2147483648 && neg == -1) || (nb > 2147483647 && neg == 1)
		|| str[i] != '\0')
		ft_error();
	return (nb * neg);
}

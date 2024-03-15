/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:38:02 by tjehaes           #+#    #+#             */
/*   Updated: 2024/03/15 14:07:06 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char const *str);
int		ft_printdecimal(int nb);
int		ft_print_hexa(unsigned long nb, char type);
int		ft_printptr(unsigned long long ptr);
int		ft_printint(int nb);
int		ft_printunsigned(unsigned int nb);
int		count_digit(int nb);

#endif

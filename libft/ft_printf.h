/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravenel <mravenel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 11:50:34 by mravenel          #+#    #+#             */
/*   Updated: 2014/02/01 17:16:58 by mravenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_attribute
{
	int			sp;
	int			pl;
	int			sh;
	int			dot;
	int			dot_value;
	int			digits;
	int			star;
	int			percent;
}				t_att;

char	*ft_utoa(unsigned long n);
char	*ft_itox(long int n);
char	*ft_itoh(long unsigned int n);
char	*ft_itoc(long int n);
char	*ft_strrev(char *str);
void	deal_percent(t_att *attr, int *i, const char **s);
size_t	put_percent(char c);
int		ft_printf(const char *format, ...);
int		x_case(unsigned long int nb, t_att attr);
int		p_case(unsigned long nb, t_att attr);
int		cx_case(unsigned long int nb, t_att attr);
int		o_case(unsigned long int nb, t_att attr);
int		d_case(long int nb, t_att attr);
int		ft_print_str(char c);
int		attr_cases(long int nb, t_att attr);
int		s_case(char *str, t_att attr);
int		c_case(unsigned char c, t_att attr);
int		u_case(unsigned long int nb, t_att attr);
size_t	digits_put(t_att attr, int size, char t);
int		dot_case(t_att attr, int size);
void	star_case(t_att *attr, int *i, const char **s);
void	deal_digits(const char **s, int *i, t_att *attr);
void	deal_dot(t_att *attr, int *i, const char **s);

#endif /* !FT_PRINTF_H */

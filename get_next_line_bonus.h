/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvan-aud <rvan-aud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 17:15:14 by rvan-aud          #+#    #+#             */
/*   Updated: 2021/04/15 17:15:14 by rvan-aud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# define FD_MAX 10240

int		get_next_line(int fd, char **line);
int		ft_strchr(const char *s, int c);
int		ft_modstrlen(const char *s, int mod);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

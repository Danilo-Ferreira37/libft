/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosorio- <dosorio-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:13:46 by dosorio-          #+#    #+#             */
/*   Updated: 2025/11/27 12:50:38 by dosorio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Lê uma linha do descritor de arquivo fd.
 *        Preserva conteúdo entre chamadas usando buffer estático.
 *
 * @param fd Descritor de arquivo.
 * @return Linha lida (inclui '\n' se presente), ou NULL em erro/fim.
 */
char	*get_next_line(int fd)
{
	static char	buffer[(BUFFER_SIZE > 0) * BUFFER_SIZE];
	char		*str;
	ssize_t		n_bytes;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!has_newline(str))
	{
		if (buffer[0] == '\0')
		{
			n_bytes = read(fd, buffer, BUFFER_SIZE);
			if (n_bytes == -1)
				return (free(str), NULL);
			if (n_bytes == 0)
				break ;
		}
		str = gnl_strjoin(str, buffer);
		if (!str)
			return (NULL);
		clean_buffer(buffer);
	}
	return (str);
}

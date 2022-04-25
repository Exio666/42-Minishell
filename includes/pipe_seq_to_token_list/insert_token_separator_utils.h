/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_token_separator_utils.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:45:09 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/21 13:46:38 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERT_TOKEN_SEPARATOR_UTILS_H
# define INSERT_TOKEN_SEPARATOR_UTILS_H

char	*insert_token_heredoc(void);
char	*insert_token_redirect_in(void);
char	*insert_token_redirect_out_append(void);
char	*insert_token_redirect_out(void);
char	*insert_token_pipe(void);

#endif

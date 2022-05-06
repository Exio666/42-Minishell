/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_path.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 16:45:57 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/03 16:43:51 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ALL_PATH_H
# define GET_ALL_PATH_H

char	**parse_arg(char *arg);
char	*get_path_env_variable_from_array(char **envp);
char	**split_path_env_variable_and_add_slash(char *path_env_variable);
char	*get_name_command(char **exe_argv);
int		execute(char **exe_argv, t_lst_env **env_list);

#endif
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 09:36:39 by dsaada            #+#    #+#              #
#    Updated: 2023/01/03 15:16:46 by dsaada           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all :
	@./run_tests.sh test_containers
	
vector :
	@./run_tests.sh test_container vector

stack :
	@./run_tests.sh test_container stack
	
map :
	@./run_tests.sh test_container map

set :
	@./run_tests.sh test_container set

clean :
	@rm -rf logs
	@rm -rf diffs

fclean : clean

re : fclean all

.PHONY: all vector stack set map clean fclean re
/*
** main.c for  in /home/han_d/rendu/PSU_2014_philo
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Thu Feb 26 18:47:15 2015 Daniel Han
** Last update Sun Mar  1 17:32:36 2015 Daniel Han
*/

#include <pthread.h>
#include <stdlib.h>
#include "philo.h"

int		main()
{
  t_philo	philosophes[NB_PHILO];
  int		i;

  i = 0;
  init_mutex_stick();
  init_philo(philosophes);
  init_thread(philosophes);
  while (i < NB_PHILO)
    {
      if (pthread_join(philosophes[i].th_philo, NULL) != 0)
	return (EXIT_FAILURE);
      ++i;
    }
  return (0);
}

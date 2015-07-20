/*
** init.c for  in /home/han_d/rendu/PSU_2014_philo
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Thu Feb 26 18:46:52 2015 Daniel Han
** Last update Sun Mar  1 17:33:07 2015 Daniel Han
*/

#include <pthread.h>
#include <stdlib.h>
#include "philo.h"

void		init_mutex_stick()
{
  int		i;

  i = 0;
  while (i != NB_CHOPSTICK)
    {
      if (pthread_mutex_init(&g_chopstick[i], NULL) != 0)
	exit(EXIT_FAILURE);
      ++i;
    }
}

void		init_philo(t_philo philosophes[NB_PHILO])
{
  int		i;

  i = 0;
  while (i < NB_PHILO)
    {
      philosophes[i].nb = i + 1;
      philosophes[i].status = NONE;
      philosophes[i].right_chopstick = &g_chopstick[i];
      if (i - 1 < 0)
	{
	  philosophes[i].left_chopstick = &g_chopstick[NB_CHOPSTICK - 1];
	  philosophes[i].left_philo = &philosophes[NB_PHILO - 1];
	}
      else
	{
	  philosophes[i].left_chopstick = &g_chopstick[i - 1];
	  philosophes[i].left_philo = &philosophes[NB_PHILO - 1];
	}
      if (i + 1 > NB_PHILO - 1)
	philosophes[i].right_philo = &philosophes[0];
      else
	philosophes[i].right_philo = &philosophes[i + 1];
      ++i;
    }
}

void		init_thread(t_philo philosophes[NB_PHILO])
{
  int		i;

  i = 0;
  while (i < NB_PHILO)
    {
      if (pthread_create(&philosophes[i].th_philo, NULL,
			 search_action, &philosophes[i]) != 0)
	exit(EXIT_FAILURE);
      ++i;
    }
}

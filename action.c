/*
** action.c for  in /home/quach_a/rendu/PSU_2014_philo
** 
** Made by Jonathan Quach
** Login  <jonathan.quach@epitech.eu>
** 
** Started on  Wed Feb 25 19:30:30 2015 Jonathan Quach
** Last update Sun Mar  1 20:34:41 2015 Daniel Han
*/

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"

void		eat(t_philo *philo)
{
  philo->status = EAT;
  printf("The philosopher %d is eating for %d seconds\n",
	 philo->nb, EAT_DURATION);
  sleep(EAT_DURATION);
  if (pthread_mutex_unlock(philo->left_chopstick) != 0 ||
      pthread_mutex_unlock(philo->right_chopstick) != 0)
    exit(EXIT_FAILURE);
}

void		think(t_philo *philo)
{
  philo->status = THINK;
  printf("The philosopher %d is thinking for %d seconds\n",
	 philo->nb, THINK_DURATION);
  sleep(THINK_DURATION);
}

void		rest(t_philo *philo)
{
  philo->status = REST;
  printf("The philosopher %d is sleeping for %d seconds\n",
	 philo->nb, REST_DURATION);
  sleep(REST_DURATION);
}

void		*search_action(void *arg)
{
  t_philo	*philo;

  philo = (t_philo *)arg;
  while (1)
    {
      if (philo->status == NONE || philo->status == EAT)
	rest(philo);
      else if (philo->status == REST && philo->left_philo->status == REST &&
      	       philo->right_philo->status == REST)
      	{
      	  if (pthread_mutex_trylock(philo->left_chopstick) == 0)
      	    think(philo);
      	  else
      	    sleep(WAIT_DURATION);
      	}
      else if (philo->status == THINK)
	{
	  if (pthread_mutex_lock(philo->right_chopstick) != 0)
	    exit(EXIT_FAILURE);
	  eat(philo);
	}
      else
      	sleep(WAIT_DURATION);
    }
  return (arg);
}

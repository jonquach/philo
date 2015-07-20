/*
** philo.h for  in /home/han_d/rendu/PSU_2014_philo
** 
** Made by Daniel Han
** Login   <han_d@epitech.net>
** 
** Started on  Sun Mar  1 20:34:12 2015 Daniel Han
** Last update Sun Mar  1 22:42:29 2015 Jonathan Quach
*/

#ifndef PHILO_H_
# define PHILO_H_

/*
** NB_QUANTITY
*/
# define NB_PHILO 7
# define NB_CHOPSTICK NB_PHILO

/*
** ACTION_DURATION
*/
# define EAT_DURATION 2
# define THINK_DURATION 2
# define REST_DURATION 2
# define WAIT_DURATION 1

/*
** e_status
*/
typedef enum
  {
    NONE,
    EAT,
    REST,
    THINK,
  }			e_status;

/*
** list
*/
typedef struct		s_philo
{
  int			nb;
  e_status		status;
  pthread_t		th_philo;
  pthread_mutex_t	*left_chopstick;
  pthread_mutex_t	*right_chopstick;
  struct s_philo	*left_philo;
  struct s_philo	*right_philo;
}			t_philo;

/*
** global
*/
pthread_mutex_t		g_chopstick[NB_CHOPSTICK];

/*
** action.c
*/
void		        eat(t_philo *);
void			think(t_philo *);
void			rest(t_philo *);
void			*search_action(void *);

/*
** init.c
*/
void			init_mutex_stick();
void			init_philo(t_philo []);
void			init_thread(t_philo []);

#endif /* !PHILO_H_ */

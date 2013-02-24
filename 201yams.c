/*
** main.c for main in /home/sauvag_m//201yams
** 
** Made by maxime sauvage
** Login   <sauvag_m@epitech.net>
** 
** Started on  Mon Feb 11 14:30:48 2013 maxime sauvage
** Last update Mon Feb 11 16:20:43 2013 maxime sauvage
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<math.h>

char            **myTotab(char *str, char c)
{
  char          **tabl;
  int           a;
  int           b;
  int           i;

  i = 0;
  a = 0;
  tabl = malloc((strlen(str) + 1) * sizeof(char *));
  while (str && str[i] != '\0')
    {
      if (str[i] == ' ')
        i++;
      else
        {
          b = 0;
          tabl[a] = malloc(strlen(str) + 1 * sizeof(char));
          while (str[i] && (str[i] != c))
            {
              tabl[a][b] = str[i];
              b++;
              i++;
            }
          if (str[i] != '\0')
            i++;
          tabl[a][b] = '\0';
          a++;
        }
    }
  tabl[a] = NULL;
  return (tabl);
}


void	paire(char **nb, char **op)
{
  printf("paire\n");
}

void	brelan(char **nb, char **op)
{
  printf("brelan\n");
}

void	carre(char **nb, char **op)
{
  printf("carre\n");
}

void	full(char **nb, char **op)
{
  printf("full\n");
}

void	suite(char **nb, char **op)
{
  printf("suite\n");
}

void	yams(char **nb, char **op)
{
  printf("yams\n");
}

void	sendToFunc(char **nb, char **op)
{
  if (strcmp("paire", op[0]) == 0)
    paire(nb, op);
  else if (strcmp("brelan", op[0]) == 0)
    brelan(nb, op);
  else if (strcmp("carre", op[0]) == 0)
    carre(nb, op);
  else if (strcmp("full", op[0]) == 0)
    full(nb, op);
  else if (strcmp("suite", op[0]) == 0)
    suite(nb, op);
  else if (strcmp("yams", op[0]) == 0)
    yams(nb, op);
}

char	**getNumb(char **av)
{
  char		**new;

  new = malloc(6 * sizeof(char *));
  new[0] = strdup(av[1]);
  new[1] = strdup(av[2]);
  new[2] = strdup(av[3]);
  new[3] = strdup(av[4]);
  new[4] = strdup(av[5]);
  new[5] = NULL;
  return (new);
}

int	check_error(int ac, char **av)
{
  int	i = 1;

  if (ac != 7)
    {
      printf("Le nombre d'arguments doit etre egal a 6\n");
      return (1);
    }
  while (i <= 4)
    {
      if (atoi(av[i]) == 0)
	{
	  printf("Certains des n'ont pas ete lances\n");
	  return (1);
	}
      else if (atoi(av[i]) < 0 || atoi(av[i]) > 9)
	{
	  printf("Le nombre numero %d n'est pas un nombre entier\n", i);
	  return (1);
	}
      i++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  char	**a;
  char	**b;

  if (check_error(ac, av) == 1)
    return (1);
  a = myTotab(av[6], '_');
  b = getNumb(av);
  sendToFunc(b, a);
  return (0);
}

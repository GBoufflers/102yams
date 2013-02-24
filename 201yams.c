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

int	checkHowManyTime(char **nbs, char *val)
{
  int	times;
  int	i;

  i = times = 0;
  while (nbs[i] != NULL)
    {
      if (strcmp(nbs[i], val) == 0)
	times++;
      i++;
    }
  return (times);
}

int	fact(int nb)
{
  if (nb > 1)
    return (nb * fact(nb - 1));
}

void	paire(char **nb, char **op)
{
  int		times;
  int		tmp;
  int		x;
  int		y;
  double	a;
  double	res;

  times = checkHowManyTime(nb, op[1]);
  tmp = times;
  if (times == 2)
    printf("la probabilite de faire un carre est de 100%");
  else
    {
      a = 1.0 / 6.0;
      tmp++;
      while(tmp < 2)
	{
	  a = a *  1.0 / 6.0;
	  tmp++;
	}
      x = 2 - times;
      y = 5 - times;
      res = (fact(y)) / (fact(x) * fact(y - x));
      res *= a;
      res = res - ((2 - 1) / (powf(6, 2)));
      res *= 100;
      printf("la probabilite de faire une paire de %s est de %.2f%\n", op[1], res);
    }
}

void	brelan(char **nb, char **op)
{
  int		times;
  int		tmp;
  int		x;
  int		y;
  double	a;
  double	res;

  times = checkHowManyTime(nb, op[1]);
  tmp = times;
  if (times == 3)
    printf("la probabilite de faire un carre est de 100%");
  else
    {
      a = 1.0 / 6.0;
      tmp++;
      while(tmp < 3)
	{
	  a = a *  1.0 / 6.0;
	  tmp++;
	}
      x = 3 - times;
      y = 5 - times;
      res = (fact(y)) / (fact(x) * fact(y - x));
      res *= a;
      res = res - ((3 - 1) / (powf(6, 3)));
      res *= 100;
      printf("la probabilite de faire un brelan de %s est de %.2f%\n", op[1], res);
    }
}

void	carre(char **nb, char **op)
{
  int		times;
  int		tmp;
  int		x;
  int		y;
  double	a;
  double	res;

  times = checkHowManyTime(nb, op[1]);
  tmp = times;
  if (times == 4)
    printf("la probabilite de faire un carre est de 100%");
  else
    {
      a = 1.0 / 6.0;
      tmp++;
      while(tmp < 4)
	{
	  a = a *  1.0 / 6.0;
	  tmp++;
	}
      x = 4 - times;
      y = 5 - times;
      res = (fact(y)) / (fact(x) * fact(y - x));
      res *= a;
      res = res - ((4 - 1) / (powf(6, 4)));
      res *= 100;
      printf("la probabilite de faire un carre de %s est de %.2f%\n", op[1], res);
    }
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
  int		times;
  int		tmp;
  double	a;
  double	res;

  times = checkHowManyTime(nb, op[1]);
  tmp = times;
  if (times == 5)
    printf("la probabilite de faire un carre est de 100%");
  else
    {
      a = 1.0 / 6.0;
      tmp++;
      while(tmp < 5)
	{
	  a = a *  1.0 / 6.0;
	  tmp++;
	}
      res = a * 100;
      printf("la probabilite de faire un carre de %s est de %.2f%\n", op[1], res);
    }
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
  int	nb_zero;
  int	i = 1;

  nb_zero = 0;
  if (ac != 7)
    {
      printf("Le nombre d'arguments doit etre egal a 6\n");
      return (1);
    }
  while (i <= 5)
    {
      if (atoi(av[i]) == 0)
	nb_zero++;
      else if (atoi(av[i]) < 0 || atoi(av[i]) > 9)
	{
	  printf("Le nombre numero %d n'est pas un nombre entier\n", i);
	  return (1);
	}
      i++;
    }
  if (nb_zero != 5)
    {
      printf("certains des n'ont pas ete lances\n");
      return (1);
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

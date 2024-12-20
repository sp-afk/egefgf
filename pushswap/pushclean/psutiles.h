#ifndef PSUTILES_H
#define PSUTILES_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_dlist
{
	int				data;
	struct s_dlist  *next;
	struct s_dlist  *prev;
} t_dlist;



/*dilleme*/

void rn(t_dlist **lista, t_dlist **listb, int n, int nuy);
void rrr(t_dlist **stacka, t_dlist **stackb);
void rr(t_dlist **stacka, t_dlist **stackb);
void ss(t_dlist **stacka, t_dlist **stackb);
void pb(t_dlist **stacka, t_dlist **stackb);
void pa(t_dlist **stackb, t_dlist **stacka);
void sb(t_dlist **stackb, int z);
void sa(t_dlist **stacka, int z);
void rb(t_dlist **stackb, int z);
void ra(t_dlist **stacka, int z);
void rrb(t_dlist **stackb, int z);
void rra(t_dlist **stacka, int z);




/*listutile*/
void del_head(t_dlist **list);
t_dlist *dlist_new(int data);
t_dlist *get_head(t_dlist *list);
void lst_clear(t_dlist **list);
void printlist(t_dlist *list);
void put_head(t_dlist **list, int data);
void put_tail(t_dlist **list, int data);
int	lstsize(t_dlist *lst);
void make_circular(t_dlist **list);
void dead_circular(t_dlist **list);
int cmpt_big(t_dlist *list);
int small(t_dlist *list);
int big(t_dlist *list);
int cmpt_small(t_dlist *list);


/*utile*/
int str_cmp(char *s1, char *s2);
int	ft_atoi(const char *str);
void	ft_swap(int *a, int *b);
long ft_atoi_long(const char *str);


/*algo*/
void	algoturk(t_dlist **a, t_dlist **b);
void algotr(t_dlist **a);
void algo(t_dlist **list1, t_dlist **list2);
void altugo(t_dlist **list);



/*turk*/
void end_game(t_dlist **a);
void treistheloneliestnb(t_dlist **a, t_dlist **b);
void	perfect_clock(t_dlist **a, t_dlist **b, int chp, int lv);








/*turk*/
void	make_tic_tac(int sla, int slb, int pca, int pcb, t_dlist **a, t_dlist **b);
void	make_tac(int rra, int rrb, t_dlist **a, t_dlist **b);
void	make_tic(int ra, int rb, t_dlist **a, t_dlist **b);
int	find_crush(int pca, t_dlist *list, int smb, int bgb);
int	count_tic_tac(int sla, int slb, int pca, int pcb);
int	evil_find_crush(int pca, t_dlist *list, int bgb);



#endif

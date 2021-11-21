/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguidado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 03:27:34 by iguidado          #+#    #+#             */
/*   Updated: 2021/11/19 15:03:53 by iguidado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "common.h"

/*
** Instruction cleaning : for error management purpose,
** function doing nothing stock ** a "\0" instruction
** to not trigger program exit. these function clean them
*/
void		ft_print_inst(void *inst);
void		ft_print_insts(t_list *inst);
t_list		*ft_trim_inst(t_list *inst);
t_list		*ft_adapt_inst(t_list *inst);

/*
** ft_inst_utils : for norme purpose, instjoin is a lstadd_back
** version with error management included
*/
int			ft_instjoin(t_list **inst, t_list *inst_added);

/*
** Stack information gathering
*/
t_stack		*ft_stack_last_node(t_stack *a);
t_stack		*ft_stack_min(t_stack *a);
t_stack		*ft_stack_highest(t_stack *stack);
t_stack		*ft_stack_next(t_stack *head, t_stack *node);
t_stack		*ft_stack_prev(t_stack *head, t_stack *node);

/*
** Stack indexation
*/
t_stack		*ft_stack_index(t_stack *stk, int index);
t_stack		*ft_stack_index_mod(t_stack *stk, int index);

/*
** ft_stack_checker : checking if stack / part / node is ordered
*/
int			ft_stack_ordered(t_stack *a);
int			ft_node_ordered(t_stack *a, t_stack *node);
int			ft_stkprt_ordered(t_stack *head, t_stack *begin, t_stack *end);

/*
** Node detection
*/
int			ft_node_instack(t_stack *stk, t_stack *node);
int			ft_node_detect(t_stack *hd, t_stack *beg, t_stack *end,
				t_stack *node);

/*
** Stack Comparison
*/
int			ft_stack_lt(t_stack *node_a, t_stack *node_b);

/*
** Stack manipulation advanced function
*/
t_list		*ft_crawl_stack(t_stack **head, t_stack *target, char stack_id);
t_list		*ft_crawl_dist(t_stack **stack, int distance, char stack_id);
t_list		*ft_rotate_dist(t_stack **stack, int distance, char stack_id);
t_list		*ft_rrotate_dist(t_stack **stack, int distance, char stack_id);

t_list		*ft_stack_push_all_b(t_stack **a, t_stack **b, t_list *inst);

/*
** Selection sort and helper
*/
int			ft_stack_rtt_to_min(t_stack **a, t_list **inst);
t_list		*ft_stack_srt_slct_min(t_stack **a, t_stack **b, t_list *inst);
t_list		*ft_stack_sort_slct(t_stack **a);

/*
** ft_bubble_swap : bubblesort helper
*/
t_stack		*ft_find_next_swap(t_stack *a);
t_list		*ft_swap_next_unordered(t_stack **stk, int s_id);

/*
** Bubblesort
*/
t_list		*ft_stack_sort_bubble_max_a(t_stack **a);

/*
** Insertion sort and helper
*/
t_stack		*ft_stack_lower(int nbr, t_stack *b);
t_list		*ft_stack_srt_insrt(t_stack **a);
t_list		*ft_srt_insrt_nbr(t_stack **a, t_stack **b, t_list *inst,
				t_stack *lwr);
t_list		*ft_stack_srt_insrt_reorganize(t_stack **a, t_stack **b,
				t_list *inst);

/*
** ------------------ Quicksort Part -----------------
*/

/*
** Part function are error prone when begin is not head node of stack
*/

/*
** ft_part_gather_info : find some useful information about part
*/
t_stack		*ft_stkpart_min(t_stack *head, t_stack *beg, t_stack *end);
t_stack		*ft_stkpart_max(t_stack *head, t_stack *begin, t_stack *end);
t_stack		*ft_stkpart_pick_pivot(t_stack *a, t_stack *beg);
t_stack		*ft_stkpart_choose_pivot(t_stack *begin, t_stack *end);

/*
** ft_part_checker
*/
int			ft_part_check_h(t_stack *head, t_stack *pivot, t_stack *end);

int			ft_part_check(t_stack **a, t_stack *beg, t_stack *end,
				t_stack *piv);

int			ft_check_pivot_parted(t_stack *head, t_stack *pivot,
				t_stack *end);

/*
** ft_quickprep : use all function above to check which quicksort operation
** is needed 
*/
int			ft_mng_excep(t_stack **head, t_stack *beg, t_stack *end,
				t_list **inst);
int			ft_quickprep(t_stack **head, t_stack *beg, t_stack *end,
				t_list **inst);

/*
** Choose pivot is done by quicksorting the part in tab and
** Selecting middle value
*/
int			*ft_stack_to_tab(t_stack *stack, int tab_len);
int			ft_quickpivot(int **tab, int begin, int end, int pivot);
int			*ft_quicksort(int *tab, int begin, int end);
int			*ft_stack_tab_sort(t_stack *stack);

/*
** Initialising Partition info struct
*/
typedef struct s_stkpart
{
	t_stack	*pivot;
	t_stack	*min;
	t_stack	*max;
	t_stack	**debut;
	t_stack	**end;
	t_stack	*next_debut;
	t_stack	*next_end;
}				t_stkpart;

t_stkpart	*ft_stkpart_info(t_stack *a, t_stack **debut, t_stack **end);
void		ft_print_stkpart_info(t_stack *a, t_stack *b, t_stkpart *info);

/*
** ft_stack_quickrecurse : apply recursion to ft_stack_quicksort
*/
t_list		*ft_quickrec_l(t_stack **head, t_stack *beg, t_stack *end,
				t_stack *piv);
t_list		*ft_quickrec_h(t_stack **head, t_stack *beg, t_stack *end,
				t_stack *piv);
t_list		*ft_quickrec(t_stack **head, t_stack *beg, t_stack *end,
				t_stack *piv);

/*
** ft_stack_quickpart : decide what you should do with each node and keep part
** integrity
*/
int			ft_quickpiv(t_stack **a, t_stack **b,
				t_stkpart *info, t_list **inst);

int			ft_quickpivot_l(t_stack **a, t_stack **b,
				t_stkpart *info, t_list **inst);

int			ft_quickpivot_h(t_stack **a, t_stack **b,
				t_stkpart *nfo, t_list **inst);

int			ft_quickpart(t_stack **a, t_stkpart *part_nfo, t_list **inst);

/*
** Quicksort
*/
int			ft_quickpart_rec(t_stack **head, t_stkpart *nfo, t_list **inst);
t_list		*ft_stack_quicksort(t_stack **head, t_stack *begin, t_stack *end);
t_stack		*ft_stack_choose_pivot(t_stack *begin, t_stack *end);
t_list		*ft_launch_quicksort(t_stack **a);

/*
** ----------------------------------------------------------------
**
** Part sorting : used to sort small part partitionned by quicksort
**
** Not used actually since sort algorithm need optimization and
** a function choosing algorithm
*/
typedef struct s_stack_part
{
	t_stack		**head;
	t_stack		*begin;
	t_stack		*end;
}				t_stkprt;

/*
** ft_choose_part_sort : WIP
*/
t_stkprt	ft_copy_part(t_stack *a, t_stack *begin, t_stack *end);
int			ft_try_part_sort(t_stkprt *part_copy, t_list **inst,
				t_list *(*ft_partsort)(t_stack **, t_stack *, t_stack *));
int			ft_choose_part_sort(t_stack **a, t_stack **beg, t_stack **end,
				t_list **inst);

/*
** ft_part_bubblesort : sorting small sublist
*/
t_list		*ft_bubble_sort_max_part(t_stack **a, t_stack *beg, t_stack *end);
t_stack		*ft_part_find_next_swap(t_stack *a, t_stack *beg, t_stack *end);
t_list		*ft_part_swap_unordered(t_stack **head, t_stack **beg,
				t_stack **end);

/*
** ft_part_srt_insrt : sorting small list, supposed to be more stable than
** bubblesort, still need optimization
*/
t_list		*ft_part_srt_insrt(t_stack **a, t_stack *end);

/*
** ft_part_sort_slct : same as part_srt_insrt
** perform well where part_srt_insrt suck
**
**
** can be optimized by pushing until part is sorted then you push
** everything back on top of part
*/
t_list		*ft_qkslct_min(t_stack **a, t_stack **b,
				t_stack **beg, t_stack **end);
t_list		*ft_part_srt_slct(t_stack **a, t_stack *beg, t_stack *end);

#endif

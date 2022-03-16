
typedef struct s_info t_info

struct t_info {
	stack *a;
	stack *b;
	int min_cost;
	int ra;
	int rb;
	int rra;
	int rrb;
	int rr;
	int rrr;
}


void find_costs_manager(t_info *info)
{
	while (info->b->next)
	{
		find_costs(info, info->b)
		info->b = info->b->next;
	}
}

void find_costs(t_info *info, t_list *node)
{
	int ra = find_ra(info);
	int rb = find_ra(info);
	int rra = find_ra(info);
	int rrb = find_ra(info);

	int min_cost;
	int min_r;
	int rr;

	if (ra > rb)  // ra = 5 rb = 3
	{
		min_r = ra - rb; // 2
		rr = ra - min_r; // sum = 3
		min_r += rr;
	}
	if (rb < ra)
		...
	int min_rr;
	if (rra > rrb)  // ra = 7 rb = 4
	{
		min_rr = rra - rrb; // 3
		min_rr += rra - min_rr; // sum = 7
	}

	min_cost = ...
	if (min_cost > info->min_cost)
		return;


	if (min_r < min_rr)
	{
		reset_counts(info)
		min_cost = min_r;
		info->min_cost = min_cost;
		into->ra = ra;
		into->rb = rb;
		into->rr = rr;
		info->pop_ind....;
	}
	if (min_rr < min_r)
	{
		reset_counts(info)
		min_cost = min_rr;
		info->min_cost = min_cost;
		into->rra = rra;
		into->rrb = rrb;
		into->rrr = rrr;
		info->pop_ind....;
	}

}

void do_operation(char *op_name, t_info *info)
{
	if (op_name == 'ra')
		do_ra();
	...
}

void do_operations(t_info *info)
{
	if (info->ra || info->rb || info->rr)
		while
			do_operation("ra", info);

}

void insertion(_info *info)
{
	while (...)
	{
		find_costs_manager(info);
		do_operations(info);
		reset(info);
	}
}
#include <ft_tpool.h>

typedef struct s_my_data_struct {
	int ret;
	char info_to_pass;
} t_my_data_struct;

void my_job_to_exec(void *param)
{
	t_my_data_struct *my;
	my=(t_my_data_struct *)param;
	if ()// I do something wih my->ret work)
		my->ret=SUCCESS;
	else
		my->ret=FAILURE;
}
int main(int ac, char **av)
{
	t_tp_thread *my_tp;
	t_my_data_struct *data;
	my_tp=tp_create(8);
	tp_add_task(my_tp, my_job_to_exec, (void *)data); //we can add several jobs
	tp_wait_for_queue(my_tp);
	if (data->ret == SUCCESS)
		//that was a success
	else
		//that was a failure
}

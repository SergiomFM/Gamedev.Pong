#include "Pong.h"
#include <sys/time.h>

long long int	get_time_mil()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_usec / 1000 + time.tv_sec * 1000);
}

long long int delta_time(void)
{
	static long long int time;

	long long int ret;

	ret = get_time_mil() - time;
	time = get_time_mil();
	return(ret);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalshaer <kalshaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:02:32 by kalshaer          #+#    #+#             */
/*   Updated: 2023/04/17 00:35:56 by kalshaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



unsigned long long get_time_ms() {
   struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void print_timestamped_message(char* message, t_philo *philosopher) {
    unsigned long long timestamp_ms = get_time_ms();
    pthread_mutex_lock(&philosopher->info->print_mutex);
    printf("%llu %d %s\n", timestamp_ms - philosopher->info->start_time, philosopher->id, message);
    pthread_mutex_unlock(&philosopher->info->print_mutex);
}

void* philosopher_thread(void* arg) {
    t_philo	*philosopher = (t_philo	*) arg;

    while (1) {
        // think
        print_timestamped_message("is thinking", philosopher);
        usleep(rand() % 1000); // sleep for random time between 0 and 999 microseconds

        // get forks
        unsigned long long start_time = get_time_ms();
        while (pthread_mutex_lock(&philosopher->left_fork) != 0) {
            // failed to acquire left fork
            if (get_time_ms() - start_time >= (unsigned long long)philosopher->info->time_to_die) {
                // timed out waiting for left fork
                print_timestamped_message("died", philosopher);
                return NULL;
            }
            usleep(rand() % 1000); // sleep for random time between 0 and 999 microseconds
        }

        start_time = get_time_ms();
        while (pthread_mutex_lock(&philosopher->right_fork) != 0) {
            // failed to acquire right fork, release left fork
            pthread_mutex_unlock(&philosopher->left_fork);
            if (get_time_ms() - start_time >= (unsigned long long)philosopher->info->time_to_die) {
                // timed out waiting for right fork
                print_timestamped_message("died", philosopher);
                return NULL;
            }
            usleep(rand() % 1000); // sleep for random time between 0 and 999 microseconds
        }

        // eat
        print_timestamped_message("has taken a fork", philosopher);
        print_timestamped_message("has taken a fork", philosopher);
        philosopher->times_eaten++;
        philosopher->last_meal_time = get_time_ms();
        print_timestamped_message("is eating", philosopher);
        usleep(rand() % 1000); // sleep for random time between 0 and 999 microseconds

        // release forks
        pthread_mutex_unlock(&philosopher->left_fork);
        pthread_mutex_unlock(&philosopher->right_fork);
        print_timestamped_message("is sleeping", philosopher);
        usleep(rand() % 1000); // sleep for random time between 0 and 999 microseconds

        // check if finished eating enough times
        if (philosopher->info->num_times_each_must_eat > 0 && philosopher->times_eaten >= philosopher->info->num_times_each_must_eat) {
            break;
        }

         // check if starved
        if (get_time_ms() - philosopher->last_meal_time >= (unsigned long long)philosopher->info->time_to_die) {
            print_timestamped_message("died", philosopher);
            return NULL;
        }
    }

    return NULL;
}


int main(int argc, char** argv) {
    // parse command line arguments
    if (argc < 4 || argc > 5) 
	{
        printf("Usage: %s num_philosophers time_to_die time_to_eat time_to_sleep [num_times_each_must_eat]\n", argv[0]);
        return 1;
    }
	
	t_info info[1];
	t_philo philosophers[MAX_PHILOSOPHERS];
    info[0].num_philosophers = atoi(argv[1]);
	info[0].start_time = get_time_ms();
    info[0].time_to_die = atoi(argv[2]);
    info[0].time_to_eat = atoi(argv[3]);
    info[0].time_to_sleep = atoi(argv[4]);
    if (argc == 6) {
        info->num_times_each_must_eat = atoi(argv[5]);
    }
    // initialize philosopher threads and mutexes
    int i;
    for (i = 0; i < info[0].num_philosophers; i++) {
        philosophers[i].id = i;
        philosophers[i].times_eaten = 0;
        philosophers[i].last_meal_time = 0;
		philosophers[i].info = info;
        pthread_mutex_init(&philosophers[i].left_fork, NULL);
        pthread_mutex_init(&philosophers[i].right_fork, NULL);
		pthread_mutex_init(&info[0].print_mutex, NULL);
        pthread_create(&philosophers->threads[i], NULL, philosopher_thread, &philosophers[i]);
    }
    // wait for philosopher threads to finish
    for (i = 0; i < info[0].num_philosophers; i++)
	{
        pthread_join(philosophers->threads[i], NULL);
    }
    // destroy mutexes
    for (i = 0; i < info[0].num_philosophers; i++) {
        pthread_mutex_destroy(&philosophers[i].left_fork);
        pthread_mutex_destroy(&philosophers[i].right_fork);
		pthread_mutex_destroy(&info[0].print_mutex);
    }

    return 0;
}

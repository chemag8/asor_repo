#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(int argc, char *argv[]) {

	if (argc != 2) {
        printf("ERROR: Introduce PID\n");
        return -1;
    }

    int pid = atoi(argv[1]);

    int scheduler = sched_getscheduler(pid);

    switch (scheduler) {

        case SCHED_OTHER:
            printf("SCHEDULER: OTHER\n");
        break;

        case SCHED_FIFO:
            printf("SCHEDULER: FIFO\n");
        break;

        case SCHED_RR:
            printf("SCHEDULER: RR\n");
        break;

        default:
            printf("SCHEDULER: ERROR\n");
        break;
    }

    struct sched_param p;

    sched_getparam(pid, &p);

    int prio = p.sched_priority;

    int max = sched_get_priority_max(scheduler);

    int min = sched_get_priority_min(scheduler);

    printf("Prioridad: %i MAX: %i MIN: %i \n", prio, max, min);

    return 0;
}

#include "Scheduler.h"
#include "Led.h"

static void ExecuteTask (Taskp t)
{
  /* insert code */
  t->Taskf(t->ExecutionTime); // execute task
  /* insert code */
}

void Scheduler_P_EDF (Task Tasks[])
{
  unsigned int PrioList[NUMTASKS];
  Taskp ClosestTask;

  for (int i = 0; i < NUMTASKS; i++)
  {
    Taskp t = &Tasks[i];
    if ((i == 0) || (t->NextRelease < ClosestTask->NextRelease))
    {
      ClosestTask = t; 
    }
    
    
  }
   
  /* insert code */
  /* Use ExecuteTask function to execute a task */
  /* insert code */
}

#include "Scheduler.h"
#include "Led.h"
#include <stdbool.h>
// #include "TimeTracking.c"

static void ExecuteTask (Taskp t)
{
  /* insert code */
  t->Flags |= ACTIVE;
  t->Taskf(t->ExecutionTime); // execute task
  t->Flags = 0;
  
  /* insert code */
}

void Scheduler_P_EDF (Task Tasks[])
{
  // unsigned int PrioList[NUMTASKS];
  StartTracking(1);
  bool taskSet = false;
  Taskp closestTask;
  
  uint8_t i;
  for (i = 0; i < NUMTASKS; i++)
  {
    Taskp t = &Tasks[i];
    if ((!taskSet || t->NextRelease < closestTask->NextRelease) && t->Flags != 0)
    {
      closestTask = t; 
      taskSet = true;
    }   
  }

  if(taskSet && !(closestTask->Flags & ACTIVE))
  {
    _EINT(); 
    StopTracking(1);
    AddJobExecution();
    PrintResults();

    ExecuteTask(closestTask);

    StartTracking(1);
    _DINT(); 
    StopTracking(1);
    PrintResults();
    Scheduler_P_EDF(Tasks);
  }
  /* insert code */
  /* Use ExecuteTask function to execute a task */
  /* insert code */
}

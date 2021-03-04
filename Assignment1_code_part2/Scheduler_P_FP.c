#include "Scheduler.h"
#include "Led.h"
#include <stdbool.h>

static void ExecuteTask (Taskp t)
{
  /* ----------------------- INSERT CODE HERE ----------------------- */

  t->Flags |= ACTIVE;
  t->Taskf(t->ExecutionTime); // execute task
  t->Flags = 0;
  // Check scheduler after done? Done automatically?

  /* ---------------------------------------------------------------- */

}

void Scheduler_P_FP (Task Tasks[])
{ 
  /* ----------------------- INSERT CODE HERE ----------------------- */

  StartTracking(1);
  bool taskSet = false;
  Taskp closestTask;
  
  uint8_t i;
  for (i = 0; i < NUMTASKS; i++)
  {
    Taskp t = &Tasks[i];
    if ((!taskSet || t->Period < closestTask->Period) && t->Flags != 0)
    {
      closestTask = t; 
      taskSet = true;
    }   
  }

  if(taskSet && !(closestTask->Flags & ACTIVE))
  {
    taskSet = false;
    _EINT(); 
    StopTracking(1);
    AddJobExecution();
    PrintResults();

    ExecuteTask(closestTask);
    

    StartTracking(1);
    _DINT(); 
    StopTracking(1);
    PrintResults();
    Scheduler_P_FP(Tasks);
  }

  /* ---------------------------------------------------------------- */
}

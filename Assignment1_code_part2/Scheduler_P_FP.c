#include "Scheduler.h"
#include "Led.h"

static void ExecuteTask (Taskp t)
{
  /* ----------------------- INSERT CODE HERE ----------------------- */

  t->Invoked++;
  t->Taskf(t->ExecutionTime); // execute task
  // t->Flags = 0;

  //Own code:
  
  // Check scheduler after done? Done automatically?

  /* ---------------------------------------------------------------- */

}

void Scheduler_P_FP (Task Tasks[])
{ 
  /* ----------------------- INSERT CODE HERE ----------------------- */

  /* Super simple, single task example */
  // Taskp t = &Tasks[0];
  // if (t->Activated != t->Invoked)
  // {
  //   ExecuteTask(t);
  // }
  /* End of example*/
 

  // First, find task t in Tasks[] that 
  //  a) is triggered
  //  b) has shortest period

  // Second, ExecuteTask(t) 

  // Third: call Scheduler_P_FP() with Tasks[]. 


  uint8_t i;
  // for(i = NUMTASKS-1; i >= 0; i--)
  for(i = 0; i < NUMTASKS; i++)
  {
    Taskp t = &Tasks[NUMTASKS - 1 - i];

    if (t->Activated != t->Invoked)
    {
      _EINT(); 
      ExecuteTask(t);
      _DINT(); 
      // break; //Is it blocking untill done? Do we break? No clue yet. We need to schedule highest priority task.
    }
  }

  /* ---------------------------------------------------------------- */
}

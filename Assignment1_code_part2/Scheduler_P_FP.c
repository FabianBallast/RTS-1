#include "Scheduler.h"
#include "Led.h"

static void ExecuteTask (Taskp t)
{
  /* ----------------------- INSERT CODE HERE ----------------------- */

  t->Invoked++;
  t->Taskf(t->ExecutionTime); // execute task
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
  uint8_t i;
  for(i = 0; i < NUMTASKS; i++)
  {
    Taskp t = &Tasks[i];

    if (t->Activated != t->Invoked)
    {
      ExecuteTask(t);
      // break; Is it blocking untill done? Do we break? No clue yet. We need to schedule highest priority task.
    }
  }

  /* ---------------------------------------------------------------- */
}

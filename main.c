
#include "object-model.h"
#include <stdio.h>

int main()
{
  program myProg = program_new("TESTBED TEST #1");
  program_add_signal_ins(myProg, NOOP, NULL_SIG, NO_DEVICE);
  program_add_signal_ins(myProg, SET, ON, TESTLED);

  program_execute(myProg);

  program_free(myProg);

  return 0;
}


#include "object-model.h"
#include <stdio.h>

int main()
{
  program myProg = program_new("TESTBED TEST #2 (LED BLINK)");

  program_add_signal_ins(myProg, WAIT, 1000_MS, TESTLED);
  program_add_signal_ins(myProg, SET, ON, TESTLED);

  program_add_signal_ins(myProg, WAIT, 1000_MS, TESTLED);
  program_add_signal_ins(myProg, SET, OFF, TESTLED);

  program_add_signal_ins(myProg, WAIT, 1000_MS, TESTLED);
  program_add_signal_ins(myProg, SET, ON, TESTLED);

  program_execute(myProg);

  program_free(myProg);

  return 0;
}

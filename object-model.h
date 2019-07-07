
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "device-ins.h"

typedef struct prg {
  char* uid;
  instruction* instructions;
  int instruction_count;
  int instruction_index;
} * program;

program program_new(char* uid) {
  program p = malloc(sizeof(struct prg));
  p->instruction_count = 0;
  p->instruction_index = 0;
  p->instructions = NULL;
  p->uid = uid;
  return p;
}

void program_free(program p) {
  /* free all instructions
  */
  for (int i=0; i < p->instruction_count; i++)
  {
    free(p->instructions[i]);
  }

  free(p);
}

void program_add_signal_ins(program p, mode mde, sig s, device d)
{
  assert(mde==NOOP || mde==SET || mde==WAIT || mde==ENSURE || mde==LOGSENSOR || mde==TERMINATE); /* If this fails, mode is not signal! */
  p->instructions = realloc(p->instructions, p->instruction_count+1);
  p->instructions[p->instruction_count] = malloc(sizeof(struct ins));
  p->instructions[p->instruction_count]->ins_mode = mde;
  p->instructions[p->instruction_count]->signal = s;
  p->instructions[p->instruction_count]->dev_id = d;
  p->instruction_count++;
}

void program_add_message_ins(program p, mode mde, char* msg, device d)
{
  assert(mde==PROMPT || mde==LOGMSG); /* If this fails, mode is not message! */
  p->instructions = realloc(p->instructions, p->instruction_count+1);
  p->instructions[p->instruction_count] = malloc(sizeof(struct ins));
  p->instructions[p->instruction_count]->ins_mode = mde;
  p->instructions[p->instruction_count]->message = msg;
  p->instructions[p->instruction_count]->dev_id = d;
  p->instruction_count++;
}

feedback program_step(program p)
{
  feedback f = devices_send_ins(p->instructions[p->instruction_index]);
  p->instruction_index++;
  return f;
}

feedback program_execute(program p)
{
  /* TRACE_ONLY is the only EXE_MODE ; so this is not actually
   * a programmable mode yet. */
  printf("Executing program %s. [EXE_MODE=TRACE_ONLY]\n", p->uid);
  assert(p->instruction_index == 0); /* ensure program is reset first */
  while (p->instruction_index < p->instruction_count)
  {
    if (program_step(p) == FAIL)
    {
      printf("Terminated with errors. Please see logs.\n");
      return FAIL;
    }
  }
  printf("Terminated with no errors. :)\n");
  return SUCCESS;
}

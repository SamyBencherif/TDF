
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "device-ins.h"

/*
 * This structure is the memory representation of a TDF program. It
 * sports a linear array of instructions to be executed in order. It is
 * important to note that this is the memory representation of a
 * compiled TDF program, AST is not appropriate here. AST may or may
 * not be used to generate a hardcoded instance of this structure in
 * the TDF compiled binary.
 * @author S. A. Bencherif
 * @field uid a human readable identifier displayed in reports and user
 *            interfaces
 * @field instructions a pointer used to reference the array of
 *                     instructions
 * @field instruction_count the size of the array 'instructions'
 * @field instruction_index the index of the next instruction to
 *                          execute
 */
typedef struct prg {
  char* uid;
  instruction* instructions;
  int instruction_count;
  int instruction_index;
} * program;

/*
 * Creates a null program. NOOP must be added to create a compliant
 * empty program.
 * @author S. A. Bencherif
 * @param uid the program's designated uid
 * @return the program
 */
program program_new(char* uid) {
  program p = malloc(sizeof(struct prg));
  p->instruction_count = 0;
  p->instruction_index = 0;
  p->instructions = NULL;
  p->uid = uid;
  return p;
}

/*
 * Frees all memory used by a 'program' object.
 * @author S. A. Bencherif
 *
 */
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
  fprintf(stderr, "Executing program %s. [EXE_MODE=ICODE]\n", p->uid);
  assert(p->instruction_index == 0); /* ensure program is reset first */
  while (p->instruction_index < p->instruction_count)
  {
    if (program_step(p) == FAIL)
    {
      printf("\n");
      return FAIL;
    }
  }
  printf("\n");
  return SUCCESS;
}

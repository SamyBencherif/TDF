
#include <stdio.h>
#include "device-config.h"

feedback devices_send_ins(instruction i)
{
  switch (i->ins_mode)
  {
    case NOOP:
      printf("TRACE: NOOP INS\n");
      return SUCCESS;

    case SET:
      printf("TRACE: SET INS <devid: %d> <signal: %d>\n", i->dev_id,
          i->signal);

      /*
       * Trade study:
       * Should there be an implicit ENSURE after every SET?
       *
       * */

      return SUCCESS;

    default:
      fprintf(stderr, "ERROR: INS VALUE %d UNIMPLEMENTED.\n", i->ins_mode);
      return FAIL;
  }

  /* Unreachable */
  return FAIL;
}

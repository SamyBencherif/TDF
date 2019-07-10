
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

      assert(i->signal == ON || i->signal == OFF);
      /* TODO set hardware.
       *
       * i->dev_id is the device identifier
       * i->signal is the signal to be set (ON or OFF)
       */

      /*
       * Trade study:
       * Should there be an implicit ENSURE after every SET?
       */

      return SUCCESS;

    case WAIT:
      /* TODO wait */
      return SUCCESS;

    case ENSURE:
      assert(0);

      return FAIL;

    default:
      fprintf(stderr, "ERROR: INS VALUE %d UNIMPLEMENTED.\n", i->ins_mode);
      return FAIL;
  }

  /* Unreachable */
  return FAIL;
}


#include <stdio.h>
#include "device-config.h"

feedback devices_send_ins(instruction i)
{

  printf("%02x%02x%02x", i->ins_mode, i->signal, i->dev_id);

  return SUCCESS;
}

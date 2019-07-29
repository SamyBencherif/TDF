
#include <stdio.h>
#include "device-config.h"

/*
 * This function contains the implementations of state transitioning
 * signals and in turn physical pin configurations of the devices.
 * @author S. A. Bencherif
 * @param i an instruction from the TDF compiled program that requires
 *          immediate execution
 * @return a feedback status to be interpreted by the main program
 */
feedback devices_send_ins(instruction i)
{

  /*
   * In lieu of implementations the program writes to STDOUT. This
   * function is useful for runtime profiling tools. In future versions
   * that have implementations, a compile flag will be available that
   * will restrict the program to only generating output like this.
   */
  printf("%02x%02x%02x", i->ins_mode, i->contents.signal, i->dev_id);
  return SUCCESS;

}

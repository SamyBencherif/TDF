
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
feedback devices_send_ins(instruction i);

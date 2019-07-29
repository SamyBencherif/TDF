/*
 * This enum statement contains identifiers for all physical devices.
 * Using a C enum for this is essential as it only allows certain
 * literal values for the device type. A variable of type device
 * signifies a physical device, the pins to interact with this device
 * are decided in a configuration header file. Obviously, the
 * configuration must be checked against the wiring regularly.
 * @author S. A. Bencherif
 * @val NO_DEVICE an inconsequential device useful for testing or NOOP
 *                operations
 * @val FILESYSTEM a local database used to store logs
 * @val TESTLED used during development stages to analyze and test
 *              binary output evices
 */
typedef enum {NO_DEVICE = 0, FILESYSTEM = 1, TESTLED = 2} device;

/*
 * mode represents all instructions in the TDF specification. This is
 * the same set as the set of keywords.
 * @author S. A. Bencherif
 * @val NOOP no operation, a safeguard against special cases in cross
 *           compilation pipeline.
 * @val SET assignment of a state signal to a device, formulated as
 *          SET <device> <signal>
 * @val WAIT a thread-block of specified duration
 * @val ENSURE a TDF control structure that contains operations and
 *             required conditions, able to defer to a specified abort
 *             sequence
 * @val PROMPT a thread-block that requires operator input to continue
 * @val LOGMSG storage of a hardcoded string to a log database
 * @val LOGSENSOR storage of a sensor value to a log database
 * @val TERMINATE a flag that must be present on all codepaths
 */
typedef enum {NOOP, SET, WAIT, ENSURE, PROMPT, LOGMSG, LOGSENSOR,
  TERMINATE} mode;

/*
 * A signal represents a high level state transition to enact upon a
 * device. How state transitions are actually implemented is contained
 * in source configuration files and usually irrelevant to other parts
 * of the TDF lanuage or programs.
 * @author S. A. Bencherif
 * @val NULL_SIG the one signal that must be implemented a certain way,
 *               defined as having no effect on any device,
 *               a logical counterpart to NOOP and NO_DEVICE
 * @val ON a signal keyword that turns devices on, to be used when
 *         confusion about normally closed vs normally open circuitry
 *         is not a possibility
 * @val OFF a signal keyword that turns devices off, to be used when
 *         confusion about normally closed vs normally open circuitry
 *         is not a possibility
 * @val OPEN a special signal keyword for valves, the method to allow
 *           contents to flow
 * @val CLOSED a special signal keyword for valves, the method to
 *             disallow contents to flow
 */
typedef enum {NULL_SIG, ON, OFF, OPEN, CLOSED} sig;

/*
 * A unit is associated with a value. A value is an integer that
 * represents a physical quantity. For example a value can specify
 * temperature, pressure, or duration. For each of those quantities,
 * respectively some examples of units are Kelvin, Pascals, and
 * MilliSeconds. Abbreviations are not allowed here. Units are in full-
 * upper case. Exercise extreme caution in selecting the correct unit.
 * @author S. A. Bencherif
 * @val MILLISECONDS one one-thousandth of a second
 */
typedef enum {
  MILLISECONDS
} unit;

/*
 * Quick feedback to be sent to the operator. Unlike a prompt it does
 * not require input, and it always occurs after a test is complete.
 * Unlike a log, the information is extremely brief and must be
 * prominently displayed to the operator after each test.
 * @author S. A. Bencherif
 * @val SUCCESS an indication the experiment has completed without any
 *              violations
 * @val FAILURE an indication that at least one violation has occured,
 *              always followed by risk mitigation protocol
 * @val CHECKLOG under consideration, a flag that is not as severe as
 *               failure but indicates unusual activity
 */
typedef enum {SUCCESS, FAIL, CHECKLOG} feedback;

/*
 * An instruction typically corresponds to a single line of TDF code.
 * This structure is more likely to change than other components
 * because of how closely it relates to the language standard.
 * @author S. A. Bencherif
 * @field ins_mode the type of instruction
 * @field signal the signal if any to send to the device
 * @field message a string to be sent to the device (non-hardware)
 * @field dev_id DEPRECATED, the device to send the signal to
 */
typedef struct ins {
  mode ins_mode;
  union Contents {sig signal; char* message;} contents;
  device dev_id;

  /*
   * An abort_sequence field will likely need to be added
   */

} * instruction;


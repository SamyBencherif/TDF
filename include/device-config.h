
typedef enum {NO_DEVICE = 0, FILESYSTEM = 1, TESTLED = 2} device;
typedef enum {NOOP, SET, WAIT, ENSURE, PROMPT, LOGMSG, LOGSENSOR, TERMINATE} mode;
typedef enum {NULL_SIG, ON, OFF, OPEN, CLOSED} sig;
typedef enum {SUCCESS, FAIL, CHECKLOG} feedback;

typedef struct ins {
  mode ins_mode;
  union {sig signal; char* message;};
  device dev_id;
} * instruction;

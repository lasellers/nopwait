NOPWAIT is a test program used to test if spawned processes are be called correctly.
It outputs it's thread id and the current RDTSC (The processor cycle counter).
Unlike it's sibling NOP, NOPWAIT blocks completion by waiting for a character input from the keyboard (or stdin). This is useful for testing what happens waiting for long calls to process or how termination of subprocesses is handled.
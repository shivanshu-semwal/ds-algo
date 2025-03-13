# Debugging

## Debugging using printing

- Use this template to debug,

```cpp
{{ include_file('debug.cpp') }}
```

## Debugging using a debugger

Debugger is a program that helps to debug a program.
As simple as this definition may seems, debugger is a quite powerful tool
if utilized properly. What debugger does is it compiles a program but add
additional information to the program and while running you can check
which line of code is causing error.

Here is basic functionalities of a debugger

- Start - starts the execution of the program
- Stop - stops the execution of the program
- Restart - restart the code execution
- Continue - continue running code till next breakpoint
- Next - continue execution till next line of code
- Previous - rollback execution to previous line of code
- Step in - step inside the function call if present
- Step out - continue execution till getting outside of the function

While debugging you are also provided with a debug console where
you can perform operations on the current variables in scope.

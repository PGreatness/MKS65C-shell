# MKS65C-shell
## Roster: Jabir Chowdhury, Ahnaf Hasan

## Features implemented:
- Displays user and current directory
- Changing directories
- Exiting process
- Multiple commands separated with semicolons(";"), there can be whitespace
  before and after the semicolon but not in-between command arguments
- Piping (only single pipes)
- Redirecting (< , > , >>)

## Features tried but were unsucessful in implementation
- Parsing for white spaces in-between command arguments

## Bugs that we are aware of
- exit does not work sometimes, have to call it 2 to 3 times for it to work
- sometimes, redirecting stdout appends instead of overwriting
## Function headers

### forkin.c

`char ** parse_args( char * line );`

`char *** parse_lines (char* line);`

`int lenarray(char*** arr);`

`int sizeofarray(char ** arr);`

`char * trimwhitespace(char *str);`

`int deal_with_command(char ** command);`

`int deal_with_multiple_commands(char * command);`

### shell.c

`int main();`

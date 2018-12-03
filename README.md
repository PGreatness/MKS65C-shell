# MKS65C-shell 
## Roster: Jabir Chowdhury, Ahnaf Hasan

## Features implemented:
- Changing directories
- Exiting process
- Multiple commands seperated with semicolons(";")

## Features tried but were unsucessful in implementation
- Piping
- Redirecting

## Bugs that we are aware of
- (FIXED) echoing into the terminal causes only up to around 28 characters to be returned instead of the whole string
- multi commands starting with a space are not parsed correctly yet
## Function headers

`int lenarray(char*** arr);`

`int ** parse_args( char * line );`

`char *** parse_lines (char* line);`

`int deal_with_command(char ** command);`

`int deal_with_multiple_commands(char * command);`

`int sizeofarray(char ** arr);`

`int deal_with_command(char ** command);`

`int deal_with_multiple_commands(char * command);`
`

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <time.h>
#include <sys/sysinfo.h>
 
 //global variables
static const char *historyofCommands[500];
int num = 0;
 //colors
void white(){
    printf("\033[1;37m");
}
 
void purple(){
    printf("\033[1;35m");
}
 
void cyan(){
    printf("\033[1;36m");
}
 
void green(){
    printf("\033[1;32m");
}
 
void yellow(){
    printf("\033[1;33m");
}
 
void blue(){
    printf("\033[1;34m");
}
 
void red(){
    printf("\033[1;31m");
}
//free command
 
void printFree(char** command){
const double gigabyte = 1024 * 1024 * 1024;
const double megabyte = 1024 * 1024;
const double kilobyte = 1024;
const double byte = 1;
struct sysinfo si;
sysinfo (&si);
green();
 //-b option
if(command[1] == NULL || strcmp(command[1],"-b") == 0){ 
printf("Total RAM:  %5.1f B\n", si.totalram / byte);
printf("Free RAM: %5.1f B\n", si.freeram / byte);
printf("Used RAM: %5.1f B\n", (si.totalram- si.freeram) / byte);
printf("Shared RAM: %5.1f B\n", si.sharedram / byte);
printf("Buffered RAM: %5.1f B\n", si.bufferram / byte);
printf("Total swap space size : %5.1f B\n", si.totalswap / byte);
printf("Total available swap space : %5.1f B\n", si.freeswap / byte);
printf("Total used swap space : %5.1f B\n", (si.totalswap - si.freeswap) / byte);
} //-k option
else if(strcmp(command[1], "-k") == 0){
printf("Total RAM:  %5.1f KB\n", si.totalram / kilobyte);
printf("Free RAM: %5.1f KB\n", si.freeram / kilobyte);
printf("Used RAM: %5.1f KB\n", (si.totalram- si.freeram) / kilobyte);
printf("Shared RAM: %5.1f KB\n", si.sharedram / kilobyte);
printf("Buffered RAM: %5.1f KB\n", si.bufferram / kilobyte);
printf("Total swap space size : %5.1f KB\n", si.totalswap / kilobyte);
printf("Total available swap space : %5.1f KB\n", si.freeswap / kilobyte);
printf("Total used swap space : %5.1f KB\n", (si.totalswap - si.freeswap) / kilobyte);
} //-m option
else if(strcmp(command[1], "-m") == 0){
printf("Total RAM:  %5.1f MB\n", si.totalram / megabyte);
printf("Free RAM: %5.1f MB\n", si.freeram / megabyte);
printf("Used RAM: %5.1f MB\n", (si.totalram- si.freeram) / megabyte);
printf("Shared RAM: %5.1f MB\n", si.sharedram / megabyte);
printf("Buffered RAM: %5.1f MB\n", si.bufferram / megabyte);
printf("Total swap space size : %5.1f MB\n", si.totalswap / megabyte);
printf("Total available swap space : %5.1f MB\n", si.freeswap / megabyte);
printf("Total used swap space : %5.1f MB\n", (si.totalswap - si.freeswap) / megabyte);
} //-g option
else if(strcmp(command[1], "-g") == 0){
printf("Total RAM:  %5.1f GB\n", si.totalram / gigabyte);
printf("Free RAM: %5.1f GB\n", si.freeram / gigabyte);
printf("Used RAM: %5.1f GB\n", (si.totalram- si.freeram) / gigabyte);
printf("Shared RAM: %5.1f GB\n", si.sharedram / gigabyte);
printf("Buffered RAM: %5.1f GB\n", si.bufferram / gigabyte);
printf("Total swap space size : %5.1f GB\n", si.totalswap / gigabyte);
printf("Total available swap space : %5.1f GB\n", si.freeswap / gigabyte);
printf("Total used swap space : %5.1f GB\n", (si.totalswap - si.freeswap) / gigabyte);
}
//handles invalid commands
else{
printf("\n Invalid option!");
}
 
white();
return;
}
 
//fortune command 
 
void printFortune(char** command){
    blue();
    srand(time(NULL));
    int arrayLen = 14;
    char fortuneArray[arrayLen][100];
 
    strcpy(fortuneArray[0], "The ability to speak does not make you intelligent.");
    strcpy(fortuneArray[1], "You can't stop change more then you can stop the suns from setting."); 
    strcpy(fortuneArray[2], "Never tell me the odds.");
    strcpy(fortuneArray[3], "Your focus determines your reality.");
    strcpy(fortuneArray[4], "Train yourself to let go of everything you fear to lose.");
    strcpy(fortuneArray[5], "There is always a bigger fish.");
    strcpy(fortuneArray[6], "May the force be with you.");
    strcpy(fortuneArray[7], "Do or do not. There is no try.");
    strcpy(fortuneArray[8], "A single chance is a galaxy of hope.");
    strcpy(fortuneArray[9], "Uuuuuuuuur Aaaaahhhrrrr Uhhhhrrrr");
    strcpy(fortuneArray[10], "Named must be your fear before banish it you can.");
    strcpy(fortuneArray[11], "Fear is the path to the dark side. Fear leads to anger. Anger leads to hate. Hate leads to suffering.");
    strcpy(fortuneArray[12], "The greatest teacher, failure is.");
    strcpy(fortuneArray[13], "Pass on what you have learned.");
 
//prints one random quote from fortune array
if(command[1] == NULL){
    int random = rand() % 13;
    for(int i = 0; i < arrayLen; i++){
	if(i + 1 == random){
	    printf("%s\n", fortuneArray[i]);
	    }
        }
    } //custom -all option that prints the whole fortune array
else if(strcmp(command[1], "-all") == 0){
    for(int j = 0; j < arrayLen; j++){
        printf("%s\n", fortuneArray[j]);
        }
    }
//handles invalid commands
else{
    printf("Invalid option!\n");
    }
    white();
    return;
}
 
//history command
void historyCommand(char** command)
{
    if (command[1] == NULL){
	for(int i = 0; i < num; i++){
	    printf("%s\n", historyofCommands[i]);
        }
    }
//-r option
    else if(strcmp(command[1], "-r") == 0){
	for (int j=num-1; j >=0; j--) {
	    printf("%s\n",historyofCommands[j]);
	}
    }
//handles invalid command
    else{
	printf("\n Invalid option!");
    }
}
 
//prints intro when the shell starts
void printIntro(){
printf("\033[H\033[J"); //command to clear screen
cyan();
printf("                        8888888888  888    88888                               \n");
printf("	               88     88   88 88   88  88                              \n");
printf("	                8888  88  88   88  88888                               \n");
printf("                           88 88 888888888 88   88                             \n");
printf("                    88888888  88 88     88 88    888888                        \n");
printf("                                                                               \n");
printf("                    88  88  88   888    88888    888888                        \n");
printf("                    88  88  88  88 88   88  88  88                             \n");
printf("                    88 8888 88 88   88  88888    8888                          \n");
printf("                     888  888 888888888 88   88     88                         \n");
printf("                      88  88  88     88 88    8888888                          \n");
printf("                                                                               \n");
printf("*******************************************************************************\n");
printf("                                Created by:                                    \n");
printf("                        Emina Sirbubalo & Mak Alijevic                        \n");
printf("                                                                               \n");
white();
}
 
//cp command 
void cpCommand(char** command)
{
   FILE *src, *dest;
   src = fopen(command[1], "r");
   dest = fopen(command[2], "w");
   char contents = fgetc(src);
   while (contents != EOF){
      fputc(contents, dest);
      contents = fgetc(src);
   }
   fclose(src);
   fclose(dest);
}
 
//function to print goodbye
void printGoodbye(){
char* user = getenv("USER");
yellow();
printf("                             /~\\                      \n");
printf("                            |OO )     GOODBYE,                 \n");
printf("                            _\\=/_        MASTER %s           \n", user);
printf("                           /   _ \\                    \n");
printf("                          //|/.\\|\\\\                   \n");
printf("                         ||  \\_/  ||                  \n");
printf("                         || |\\ /| ||                  \n");
printf("                          # \\_ _/  #                  \n");
printf("                            | | |                     \n");
printf("                            | | |                     \n");
printf("                            []|[]                     \n");
printf("                            | | |                     \n");
printf("___________________________/_]_[_\\____________________________________________\n");
white();
return;
}
 
//implementation of forkbomb as a command
void forkBomb(){
    while(1)
        fork();
    return;
}
 
//help command
 
void help()
{
    red();
    printf("***ONLY ONES THAT SEEK HELP, SHALL GET IT***                           !!!    \n\n");
    printf("        MAY THE FORCE BE WITH YOU...                                   ___  \n");
    printf("Weapons at disposal:                                                  /() \\ \n");
    printf(">cd                                                                 _|_____|_ \n");
    printf(">ls                                                                | | === | | \n");
    printf(">exit                                                              |_|  0  |_| \n");
    printf(">cp                                                                 ||  0  || \n");
    printf(">history(-r {reverse history})                                      ||__*__|| \n");
    printf(">fortune(-all {prints all quotes})                                 |~ \\___/ ~| \n");
    printf(">free(-b {byte}, -k {kilobyte}, -m {megybyte}, -g {gigabyte})      /=\\ /=\\ /=\\ \n");
    printf(">all other general commands available in UNIX shell              __[_]_[_]_[_]_\n");
    printf(">forkbomb(use at your own risk)");
    white();
    return;
}
 
//execute system commands using forks
void executeCommand(char** command)
{
    pid_t child_pid = fork();
 
    if (child_pid == -1) {
        printf("\nFailed executing child fork...");
        return;
    } else if (child_pid == 0) {
	execvp(command[0], command);
        if (execvp(command[0], command) < 0) {
            printf("\nInvalid command...");
        }
        exit(0);
    } else {
        wait(NULL);
        return;
    }
}
 
//execute pipe commands using forks
void executePipeCommand(char** command, char** pipeCommand)
{
    int pipefd[2]; 
    pid_t proc1, proc2;
 
    if (pipe(pipefd) < 0) {
        printf("\npipe cannot be initialized");
        return;
    }
    proc1 = fork();
    if (proc1 < 0) {
        printf("Fork failed\n");
        return;
    }
 
    if (proc1 == 0) {
        // Child 1
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO); //The dup2() duplicates file descr
        close(pipefd[1]);
 
        if (execvp(command[0], command) < 0) {
            printf("\nInvalid command...");
        exit(0);
      }
 
      }
	else {
        // Parent
        proc2 = fork();
 
        if (proc2 < 0) {
            printf("\nFork failed");
            return;
        }
 
        // Child 2
        if (proc2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);// dup2() dupilcates
            close(pipefd[0]);
            if (execvp(pipeCommand[0], pipeCommand) < 0) {
                printf("\nCould not execute second command");
                exit(0);
            }
 
        } else {
            // parent
            wait(NULL);
            wait(NULL);
        }
 
    }
}
 
//function to handle built-in commands 
int executeBuiltInCommands(char** command)
{
    char* BuiltInCommands[9];
    int commandNumber;
 
    BuiltInCommands[0] = "cd";
    BuiltInCommands[1] = "exit";
    BuiltInCommands[2] = "help"; 
    BuiltInCommands[3] = "cp";
    BuiltInCommands[4] = "history";
    BuiltInCommands[5] = "fortune";
    BuiltInCommands[6] = "free";
    BuiltInCommands[7] = "forkbomb";
 
 
    for (int i = 0; i < 9; i++) {
        if (strcmp(command[0], BuiltInCommands[i]) == 0) {
            commandNumber=i+1;
            break;
        }
    }
 
    switch (commandNumber) {
    case 1:
        chdir(command[1]);
        return 1;
    case 2:
        printGoodbye();
        exit(0);
    case 3:
        help();
        return 1;
    case 4:
        cpCommand(command);
        return 1;
    case 5:
        historyCommand(command);
        return 1;
    case 6:
        printFortune(command);
        return 1;
    case 7:
	printFree(command);
	return 1;
    case 8:
        forkBomb();
        return 1;
    default:
        break;
    }
 
    return 0;
}
 
//read username and machinename and handle input of commands
int commandInput(char* str)
{
    char* stringInput;
    char* user = getenv("USER");
    char machineName[1024];
    gethostname(machineName,1024);
    purple();
    printf("%s",machineName);
    white();
    printf("@");
    cyan();
    printf("%s",user);
    white();
    stringInput = readline("~");
    if (strlen(stringInput) != 0) {
        historyofCommands[num]=stringInput;
        num++;
        strcpy(str, stringInput);
        return 0;
    } else {
        return 1;
    }
}
//process and parse pipe
int processPipe(char* str, char** strpiped)
{
    int i;
    for (i = 0; i < 2; i++) {
        strpiped[i] = strsep(&str, "|");
        if (strpiped[i] == NULL) {
            break;
          }
    }
    if (strpiped[1] == NULL) {
        return 0; // returns zero if no pipe is found.
     }
    else {
        return 1;
    }
}
 
//parse command and check if pipe or not in order to correctly execute
int  processString(char* str, char** command,char** pipeCommand)
{
char* pipestr[2];
int pipe = 0;
 
pipe = processPipe(str, pipestr);
 
//handle command that includes piping
if(pipe){
for(int i = 0; i<100; i++){
        command[i] = strsep(&pipestr[0], "  " );
 
        if(command[i] == NULL){
            break;
        }
        if(strlen(command[i]) == 0){
            i--;
        }
    }
for(int i = 0; i<100; i++){
        pipeCommand[i] = strsep(&pipestr[1], "  " );
 
        if(pipeCommand[i] == NULL){
            break;
        }
        if(strlen(pipeCommand[i]) == 0){
            i--;
        }
    }
//handle command that does not include piping
}else{
    for(int i = 0; i<100; i++){
	command[i] = strsep(&str, "  " );
 
	if(command[i] == NULL){
	    break;
	}
	if(strlen(command[i]) == 0){
	    i--;
	}
    }
}//return flags
    if(executeBuiltInCommands(command)){
	return 0;
    } else {
	return 1+pipe;
    }
}
 
//main function
int main()
{
    char input[1000];
    char *parsedCommand[100];
    char *parsedPipeCommand[100];
    int commandType;
    printIntro();
    while(1)
    {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("\n %s ", cwd);
 
        if(commandInput(input)){
	    continue;
        }
        commandType = processString(input, parsedCommand,parsedPipeCommand);
 
        //handle flags for system and piping commands
        if(commandType == 1){
	     executeCommand(parsedCommand);
	}
        if(commandType == 2){
            executePipeCommand(parsedCommand,parsedPipeCommand);
 
        }
    }
    return 0;
}

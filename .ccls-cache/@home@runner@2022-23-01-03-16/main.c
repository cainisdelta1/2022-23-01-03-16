// print all on one line. move for loops to outside of the if statements
  //convert strings into 2d arrays 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Block_Letter
{
  char ** block;
  char letter;
} blockletter;

blockletter a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,one,two,three,four,five,six,seven,eight,nine,zero;

char chars[36] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S', 'T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0'};

blockletter * alphabetNormVoid[36] = {&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p,&q,&r,&s, &t,&u,&v,&w,&x,&y,&z,&one,&two,&three,&four,&five,&six,&seven,&eight,&nine,&zero};

char * load_data(char fileName[]);

char * upper();

int get_cols(char *s){
  int len = strlen(s);
  if(len%25 == 0)return 5;
  if(len%20 == 0)return 4;
  if(len%15 == 0)return 3;
  return -1;
}

char * strOfLetterLine(int NumOfLine, int letterWidth);

int main(void) {
  char * data = load_data("data.txt"); //use strtok
  if (data) {
    char * token;
    char * letter[36];
    int line = 0;
    int newlines = 0;
    for (int i = 0; i < strlen(data); i++) if (data[i] == '\n') newlines++; // 36 characters
    token = strtok(data, "\n");
    while( token != NULL ) {
      //printf( "\t%s\n", token ); // prints all data
      letter[line++] = token;
      token = strtok(NULL, "\n"); 
      }
    char * input = upper(); 
    for(int letterInInput = 0; letterInInput < strlen(input); letterInInput++){
      for (int lettersInAlph = 0; lettersInAlph < strlen(chars); lettersInAlph++){
        if (input[letterInInput] == chars[lettersInAlph]){
          if(chars[lettersInAlph] == 'I' || chars[lettersInAlph] == 'T' || chars[lettersInAlph] == '1'){
            for (int sizeOfLetter = 0; sizeOfLetter < strlen(letter[lettersInAlph]); sizeOfLetter++){
              if(sizeOfLetter%3 == 0) printf("\n");  // /n statement must be in front. 0 divided by any num also == 0
              printf("%c",letter[lettersInAlph][sizeOfLetter]);
              }
            }
            else if(chars[lettersInAlph] == 'M' || chars[lettersInAlph] == 'W' || chars[lettersInAlph] == 'Y')
          {
          for (int sizeOfLetter = 0; sizeOfLetter < strlen(letter[lettersInAlph]); sizeOfLetter++){
            if(sizeOfLetter%5 == 0) printf("\n");
            printf("%c",letter[lettersInAlph][sizeOfLetter]);
          }
        }
        else
        {
          for (int sizeOfLetter = 0; sizeOfLetter < strlen(letter[lettersInAlph]); sizeOfLetter++){
            if((sizeOfLetter%4 == 0)) printf("\n"); // correct width of letter nums
            printf("%c",letter[lettersInAlph][sizeOfLetter]);
          }
        }
      }
    }
    printf("\n");
  }
  printf("\n");    
  printf("newlines = %d\n", newlines);
  if(token) free(token);
  free(data);
  }  
    
  return 0;
}

/*
char * strOfLetterLine(int NumOfLine, int letterWidth) // not using right now. used in onld version
{
  char * data = load_data("data.txt");
  if(data){
    int lineCount = 0; // put txt file opening char on own line. skips that line then treats 2 as first line
    int pastData = 0;
    int sizeLineChange = 0;
    int lineSizeFinal;
    char * OutputLine = malloc(sizeof(char) * ((4 * letterWidth)+1));
    printf("TEST %zu\n", strlen(data));
    for (int i = 0; i < strlen(data); i++){
      if(data[i] == '\n' && lineCount == NumOfLine)
      {
        lineSizeFinal = sizeLineChange;
        printf("\nPastData: %i",pastData);
        printf("\nsize of line: %i",lineSizeFinal);
      }
      if (lineCount == NumOfLine)
      {
        OutputLine[pastData+sizeLineChange] = data[i]; 
        printf("%c",OutputLine[i]); // only reason the correct letter is being printed.
        if (sizeLineChange%(letterWidth-1) == 0)
        {
          printf("\n"); // printf("    "); if(input == null) printf("\n"); // for to print on one line
        }
      }
      if (data[i] == '\n')
      {
        lineCount++;
        pastData+=sizeLineChange;
        sizeLineChange=0;
      }
      sizeLineChange++;
    }
    return OutputLine; // not returning the string for some reason
    free(data);
    free(OutputLine);
  }
  else {
    printf("Error! could not read file data\n");
    return "err";
  }
}
*/

char * upper() // makes text inpt caps
{
  char * input;
  scanf("%m[^\n]", &input);
  for(int i = 0; i < strlen(input); i++)
  {
    input[i] = toupper(input[i]);
  }
  printf("input = %s\n", input);
  return input;
}

char * load_data(char fileName[]) // contains the data in data.txt file and returns the text of it
{
  FILE *dataFile = fopen(fileName, "r");
  if(dataFile) // ptr isnt null
  {
    fseek(dataFile, 0, SEEK_END); // move file ptr to end of file
    int len = ftell(dataFile); // get num of char in file

    //move the file ptr back to the beginning of the file
    //so we can start reading each char from the file
    fseek(dataFile, 0, SEEK_SET);

    //dynamically allocate space for char array
    // include null terminator '\0'

    char * data = malloc(sizeof(char) * (len+1));
    char c;
    int i = 0;
    while((c=fgetc(dataFile)) != EOF) { // keep reading from file until end of file 
      data[i] = c;
      i++;
    } 
    fclose(dataFile); // release ptr

      // return char array containing contents of file
      return data;
  }
  else{
    printf("couldn't read file\n");
    return NULL;
  }
}

/* // int main
  char * input = upper();
  for (int i = 0; i < strlen(input); i++){ // going to have to move this stuff into strOfLetterLine so that it all prints on one line. 
    for (int x = 0; x <=strlen(chars);x++){
      if(input[i] == chars[x])
      {
        if (input[i] == 'I' || input[i] == 'T' || input[i] == '1')
        {
          strOfLetterLine((x+1), 4);
        }
        else if(input[i] == 'M' || input[i] == 'W' || input[i] == 'Y')
        {
          strOfLetterLine((x+1), 6);
        }
        else
        {
          strOfLetterLine((x+1), 5);     // inconsistent return of block letter. first letter in input always returns 0
        }
        // if any letter follows b or c program crashes // something to do with malloc // only b and c from what i can see
      }
    }
  }
  */
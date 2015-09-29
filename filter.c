#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int lineno = 0;
  int charno = 0;
  int c = 0;
  int i = 0;
  double sum = 0.0;
  double mean = 0.0;
  int cutoff = 40;

  char line[100], header[100], sequence[100], description[100];

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      /* add the null terminator to the string */
      line[charno] = '\0';

      switch(lineno % 4) {
      case 0:
        strcpy(header, line);
        break;
      case 1:
        strcpy(sequence, line);
        break;
      case 2:
        strcpy(description, line);
        break;
      case 3:
        for (i = 0; i < charno; i++) {
          sum += line[i] - 33;
          // printf("%d ", line[i] - 33);
        }
        mean = sum / i;

        if (mean >= cutoff) {
          printf("mean: %.2f\n", mean);
          printf("%s\n%s\n%s\n%s\n",
                 header,
                 sequence,
                 description,
                 line);
        }
        break;
      default:
        fputs("Something went wrong!", stderr);
        return 1;
      }

      lineno += 1;
      charno = 0;
    } else {
      line[charno] = c;
      charno += 1;
    }
  }

  line[charno] = '\0';
  /* handle the last line */
  switch(lineno % 4) {
  case 0:
    strcpy(header, line);
    break;
  case 1:
    strcpy(sequence, line);
    break;
  case 2:
    strcpy(description, line);
    break;
  case 3:
    for (i = 0; i < charno; i++) {
      sum += line[i] - 33;
      // printf("%d ", line[i] - 33);
    }
    mean = sum / i;

    if (mean >= cutoff) {
      printf("mean: %.2f\n", mean);
      printf("%s\n%s\n%s\n%s\n",
             header,
             sequence,
             description,
             line);
    }
    break;
  default:
    fputs("Something went wrong!", stderr);
    return 1;
  }

  return 0;
}

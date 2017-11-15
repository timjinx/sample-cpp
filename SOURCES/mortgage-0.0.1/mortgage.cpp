#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <math.h> 
using namespace std;

int
main(int argc, char *argv[])
{
    int amount, duration, opt, param_count;
    double interest_rate, rm, dm;
    double top_line, bottom_line, mp, ap;

    param_count = 0; /* Prime Counter */
    while ((opt = getopt(argc, argv, "a:i:d:?")) != -1) {
        switch (opt) {
        case 'a':
            amount = atoi(optarg);
            param_count+=7;
            break;
        case 'i':
            interest_rate = atof(optarg);
            param_count+=11;
            break;
        case 'd':
            duration = atoi(optarg);
            param_count+=13;
            break;
        default: /* '?' */
            fprintf(stderr, "Usage: %s -a <amount> -i <interest> -d <duration>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
   }
   if (optind > argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
   }
   if (param_count != 31) {
       /* Using primes, the only way param_count can equal 31 is if 
          each parameter is entered one time only. */
       fprintf(stderr, "Usage: %s -a <amount> -i <interest> -d <duration>\n", argv[0]);
       exit(EXIT_FAILURE);
   }
   printf("Amount=£%d\nInterest=%5.2f%%\nDuration=%d years\n", amount, interest_rate, duration);

   rm = interest_rate / 12;
   dm = duration * 12;

   top_line = ( amount * rm * pow(( 1 + ( rm / 100 )),dm) );
   bottom_line = 100 * ( pow((1 + ( rm / 100 )),dm) -1);
   
   mp = top_line / bottom_line;
   ap = mp * 12;
   printf("Annual replayments will be £%8.2f\n", ap);
   printf("Monthly replayments will be £%7.2f\n", mp);
   printf("Total cost of loan is £%8.2f\n", (ap * duration));
    

   exit(EXIT_SUCCESS);
}

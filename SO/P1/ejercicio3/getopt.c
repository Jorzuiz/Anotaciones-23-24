#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h>
#include "defs.h"

char *progname;

/**
 * @brief  Print usage of the tool
 **/
void usage() {
    printf("Usage: %s [ options ] title \n", progname);
    printf("\n\toptions:\n");
    printf("\t\t-h: display this help message\n");
    printf("\t\t-e: print even numbers instead of odd  (default)\n");
    printf("\t\t-l lenght: lenght of the sequence to be printed\n");
    printf("\t\ttitle: name of the sequence to be printed\n");
}

/**
 * @brief  Prints a sequence of odd or even numbers in stdout
 *
 * @param lenght
 * @param type
 * @param title
 **/
void display_numbers(int length, parity_t type, char *title) {

    int i, n;
    int first = (type == ODD) ? 1 : 2;

    printf("Title: %s\n", title);
    for (i = 0, n = first; i < length; i++, n += 2) {
        printf("%d ", n);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int opt;
    struct options options;

    progname = argv[0];

    /* Initialize default values for options */
    options.par_mode = ODD;
    options.length = 10;
    options.title = NULL;

    /* Parse command-line options */
    while ((opt = getopt(argc, argv, "hel:")) != -1) {
        switch (opt) {
            case 'h':
                usage();
                exit(0);
            case 'e':
                options.par_mode = EVEN;
                break;
            case 'l':
                char *endptr; // Guarda el puntero del final
                options.length = strtol(optarg, endptr, 10);
                if (endptr == optarg || *endptr != '\0') {
                    fprintf(stderr, "%s: -l requiere de un número, pero se ha introducido %s\n",
                            argv[0], optarg);
                    return 1;
                //options.length = atoi(optarg);
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }

    /* There should be one extra argument (the title of the sequence) */
    if (optind >= argc) {
        fprintf(stderr, "Invalid title\n");
        usage();
        exit(EXIT_FAILURE);
    }

    /* Fill options.title with the corresponding element of argv */
    options.title = argv[optind];

    /* Call display_numbers */
    display_numbers(options.length, options.par_mode, options.title);
    return 0;
}
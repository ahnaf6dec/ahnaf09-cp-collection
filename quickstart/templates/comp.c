================================================================================
          C UTILITY FOR COMPARING OUTPUTS AND LOGGING FAILING INPUTS
================================================================================

This updated 'comp.c' script reads 'sample-out.txt' and 'out.txt' to spot a 
mismatch. Simultaneously, it parses 'in.txt' to track exactly where each "Case #X" 
begins. If a mismatch is detected, it prints the raw input associated with that 
specific failing test case.

--------------------------------------------------------------------------------
SOURCE CODE: comp.c
--------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 4096
#define MAX_INPUT_LINES 50000

// Stores line offsets of in.txt to reprint the failing test case block
long input_line_offsets[MAX_INPUT_LINES];

const char* skip_case_prefix(const char* str) {
    if (strncmp(str, "Case #", 6) == 0) {
        const char* p = str + 6;
        while (*p >= '0' && *p <= '9') p++;
        if (*p == ':') {
            p++;
            while (*p == ' ' || *p == '\t') p++;
            return p;
        }
    }
    return str;
}

void trim_trailing(char* str) {
    int len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r' || str[len - 1] == ' ' || str[len - 1] == '\t')) {
        str[len - 1] = '\0';
        len--;
    }
}

int main() {
    FILE *f_sample = fopen("sample-out.txt", "r");
    FILE *f_out = fopen("out.txt", "r");
    FILE *f_in = fopen("sample-in.txt", "r");
    // FILE *f_in = fopen("in.txt", "r");
    
    if (!f_sample || !f_out || !f_in) {
        printf("Error: Missing file(s). Ensure sample-out.txt, out.txt, and in.txt exist.\n");
        if (f_sample) fclose(f_sample);
        if (f_out) fclose(f_out);
        if (f_in) fclose(f_in);
        return 1;
    }

    // Index the input file line positions
    int total_input_lines = 0;
    long current_offset = ftell(f_in);
    char dummy[MAX_LINE_LEN];
    while (fgets(dummy, MAX_LINE_LEN, f_in)) {
        if (total_input_lines < MAX_INPUT_LINES) {
            input_line_offsets[total_input_lines++] = current_offset;
        }
        current_offset = ftell(f_in);
    }

    char line_s[MAX_LINE_LEN];
    char line_o[MAX_LINE_LEN];
    int case_num = 0;
    int mismatch_found = 0;

    // Assuming Google-style formatting where each output line corresponds to one case
    while (1) {
        char *r_s = fgets(line_s, MAX_LINE_LEN, f_sample);
        char *r_o = fgets(line_o, MAX_LINE_LEN, f_out);

        if (!r_s && !r_o) break;

        case_num++;

        if ((r_s && !r_o) || (!r_s && r_o)) {
            printf("Mismatch at Case #%d: File size mismatch.\n", case_num);
            mismatch_found = 1;
            break;
        }

        trim_trailing(line_s);
        trim_trailing(line_o);

        const char* clean_s = skip_case_prefix(line_s);
        const char* clean_o = skip_case_prefix(line_o);

        if (strcmp(clean_s, clean_o) != 0) {
            printf("\n========================================\n");
            printf("  MISMATCH DETECTED AT CASE #%d\n", case_num);
            printf("========================================\n");
            printf("Expected (sample-out): \"%s\"\n", line_s);
            printf("Received (your output): \"%s\"\n\n", line_o);

            // Print the corresponding failing input block if mapped correctly
            // (Assumes a 1-to-1 map or logs the indexed lines around the case context)
            if (case_num <= total_input_lines) {
                printf("--- Corresponding Input Line (%d) ---\n", case_num);
                fseek(f_in, input_line_offsets[case_num - 1], SEEK_SET);
                if (fgets(dummy, MAX_LINE_LEN, f_in)) {
                    printf("%s", dummy);
                }
            } else {
                printf("[Notice: Case number exceeds total processed lines in in.txt]\n");
            }
            mismatch_found = 1;
            break;
        }
    }

    fclose(f_sample);
    fclose(f_out);
    fclose(f_in);

    if (!mismatch_found) {
        printf("Success: All test cases match sample-out perfectly!\n");
    }

    return mismatch_found;
}


--------------------------------------------------------------------------------
HOW TO EXECUTE
--------------------------------------------------------------------------------
1. Compile:
   gcc -O2 comp.c -o comp.out

2. Run:
   ./comp.out
================================================================================
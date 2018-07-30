#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

static inline 
int get_type(char b)
{
    if (b == '(' || b == ')') {
        return 0;
    } else if (b == '{' || b == '}'){
        return 1;
    } else if (b == '[' || b == ']') {
        return 2;
    }
    return -1;
}

static
int is_close(char b)
{
    if (b == '(' || b == '{' || b == '[') {
        return 0;
    } else if (b == ')' || b == '}' || b == ']'){
        return 1;
    }

    return -1;
}


char* isBalanced(char* s)
{
    char* yes = "YES";
    char* no = "NO";
    int count_arr[1024] = {0};

    int cur_pos = -1;
    int cur_type = -1;
    int last_type = -1;
    int len = strlen(s);
    int i =0;

    if (len == 0) {
        return yes;
    }

    for (i = 0; i < len; i++) {
        cur_type = get_type(s[i]);

        //printf("\n %d %d ", last_type, cur_type);

        if (is_close(s[i])) {
            if (cur_type != last_type) {
                return no;
            }

            cur_pos--;
            last_type = cur_pos < 0 ? -1 : count_arr[cur_pos];
            continue;
       }

       cur_pos++;
       count_arr[cur_pos] = cur_type;
       last_type = cur_type;
   }


   if (cur_pos > 0) {
       return no;
   }

    return yes;
}


// Complete the isBalanced function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//

int
main(int argc, char* argv[])
{
    char* in_str = strdup(argv[1]);

    printf("\n bracket = %s , result = %s", in_str, isBalanced(in_str));
    return 0;
}







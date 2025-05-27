#include "balloc.h"
static char allocbuf[ALLOCSIZE]; /*creation of the buffer*/
static char *allocp = allocbuf; /*pointer that keeps track of next FREE POSITION in the heap we have created*/

/*basic allocator*/
char *balloc(int n){
    if(allocbuf + ALLOCSIZE - allocp >= n){ /*check if there is enough size in the buffer to be allocated*/
        allocp += n; /*move pointer forward n bytes to reserve space*/
        return allocp -n; /*return a pointer that is n bytes big*/
        }else
            return 0;
    }

/*basic free, does not have checks*/
/*preferable to call afree from the MOST RECENT POINTER RETURNED FROM BALLOC*/
void bafree(char *p){
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE) /* w*/
        allocp = p;
}

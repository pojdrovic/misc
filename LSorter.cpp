#include "LSorter.h"
#include <iostream>
using namespace std;


/*
I'd like to start off by saying that the requirements for O(1) space and
O(nlogn) time were rather difficult to implement. All of the nlogn
algorithms require additiona space as a result of recursions, and all
of the constant space algorthms, such as bubble sort are incredibly slow.

That being said, I believe I was able to implement both constant space and
nlogn time. All of the additional space requirements are for variables which I use
to store pointers and locations within the linked list. However, this is at most
a few integers, so the space requirement needed to store those is absolutely
negligible.

Not being able to modify the LSorter.h file was a large issue. I wanted to write
a few additional functions (non of them recursive) to achive greater code simplcity
and readbility. Unfortunably, I was unable to do this, so I had to pack the
functionality of these methods into the sorList method.

Another issue which I noticed was the fact that the main function and the
provided files were written on mac. As a result, some parts would not work
on the lab computers without modification. The usage of nullptr in the main function
is incompatible with the compilers on the lab machine is 307. For the testing
of my code I changed nulptr to NULL which sloved the issue. Also, the declaration
of the header files was hpp instead of h, which threw some warnings when compiled
on the lab machines.


A few resources came in very handy when doing this assignemnet.
The Algorithms book
http://www.geeksforgeeks.org/merge-sort-for-linked-list/
https://www.youtube.com/watch?v=jOyYaBHyN28
https://www.youtube.com/watch?v=o5wJkJJpKtM
http://faculty.salina.k-state.edu/tim/CMST302/study_guide/topic7/bubble.html

I worked with Alexander Chowdhury on this assignment.



*/




LNode* LSorter::sortList(LNode* head){


        LNode* point1;
        LNode* point2;
        LNode* point3;
        LNode* tail;
        LNode* oldhead;

        int size_int;
        int num_merges;
        int point_size1;
        int point_size2;
        int i;

        if (!head)
        {
          return NULL;
        }

        size_int = 1;

        while (1) {
            point1 = head;
            head = NULL;
            tail = NULL;

            num_merges = 0;

            while (point1) {
                num_merges++;
                point2 = point1;
                point_size1 = 0;
                for (i = 0; i < size_int; i++) {
                    point_size1++;

            point2 = point2->next;
                    if (!point2) break;
                }

                point_size2 = size_int;

                while (point_size1 > 0 || (point_size2 > 0 && point2)) {
                    if (point_size1 == 0) {
            point3 = point2; point2 = point2->next; point_size2--;
        } else if (point_size2 == 0 || !point2) {
            point3 = point1; point1 = point1->next; point_size1--;
        } else if ((point1->val - point2->val) <= 0){
            point3 = point1; point1 = point1->next; point_size1--;
        } else {
            point3 = point2; point2 = point2->next; point_size2--;
        }

        if (tail) {
            tail->next = point3;
        } else {
            head = point3;
        }

        tail = point3;
                }
                point1 = point2;
            }

          tail->next = NULL;

            if (num_merges <= 1)
                return head;
            size_int *= 2;
        }
}

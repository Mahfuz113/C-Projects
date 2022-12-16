#include <stdio.h>
int main()
{
    int incoming_Stream[] = {4, 1, 2, 4, 5,3,0,4,2,0};
    int page_Faults = 0;
    int frames = 3;
    int m, n, s, pages;

    pages = sizeof(incoming_Stream)/sizeof(incoming_Stream[0]);

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3");
    int temp[frames];
    for(m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for(m = 0; m < pages; m++)
    {
        s = 0;

        for(n = 0; n < frames; n++)
        {
            if(incoming_Stream[m] == temp[n])
            {
                s++;
                page_Faults--;
            }
        }
        page_Faults++;
        
        if((page_Faults <= frames) && (s == 0))
        {
            temp[m] = incoming_Stream[m];
        }
        else if(s == 0)
        {
            temp[(page_Faults - 1) % frames] = incoming_Stream[m];
        }
      
        printf("\n");
        printf("%d\t\t\t",incoming_Stream[m]);
        for(n = 0; n < frames; n++)
        {
            if(temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", page_Faults);
    return 0;
}

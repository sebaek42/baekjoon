#include <stdio.h>



int main()

{

	    int num[10001] = {0,};
	   	int i;
	   	int temp;
		int n;
		int old_i;
		
	 	i = 1;
	    while (i < 10001)
	    {
	        n = i;
			old_i = i;
	        temp = 0;
	        while (i / 10)
	        {
	            temp += i % 10;
	            i = i / 10;
	        }
	        n = n + i + temp;
			if (n <= 10000)
				num[n] = -1;
	        i = old_i;
			i++;
	    }
	    i = 1;
	    while (i < 10001)
	    {
	        if (num[i] != -1)
	            printf("%d\n", i);
	        i++;
	    }
	   	return (0);
}

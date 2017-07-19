# include <stdio.h>
# include <malloc.h>

void fab(int n, int *array )
{
	int first = 0, second = 1, next, c;
	for ( c = 0 ; c < n ; c++ )
   {
      if ( c <= 1 )
         next = c;
      else
      {
         next = first + second;
         first = second;
         second = next;
      }
      array[c] = next;
   }
}

int is_prime (int n)
{
    int i,j=0;
    for(i=2 ;i<n/2;++i)
    {
        if ((n %i) == 0){
            j=0;
            break;
        }
        else
            j = 1;
    }
    if (n == 2)
        return 1;
    else
    /*printf("prime = %d", j); */
    return j;
}

int main()
{
	int n,i;
	int *array;
	array = (int*) malloc(n * sizeof(int));
	printf ("Number for Fab series \n");
	scanf("%d",&n);
	fab(n,array);
	printf("%d \t ", array[0]);
	for (i = 1 ; i< n ; i++)
	{
	    int x = is_prime(array[i]);
	    int m = array[i];
	    if ((m% 5) == 0)
        {
           if ((m% 15) == 0)
             printf("FIZZBuzz \t");
           else
             printf("Fizz \t");
        }
         else if ((m% 3) == 0)
        {
           if ((m% 15) == 0)
             printf("FizzBuzz \t");
           else
             printf("Buzz \t");
        }
        else if ( x== 1)
            printf("BuzzFizz \t");
        else
		printf ("%d \t", m);
	}

	free(array);
}

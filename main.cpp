/**<
Patrick Roche
Exercise 14
File processing */

/**< Preprocessor Directives */
#include <iostream>
#include <math.h>
/**< for file i/o's */
#include <fstream>
/**< for the error function */
#include <cstdlib>

using namespace std;

int main()
{
     /**< Variable Declerations.*/
    double maximum = 0,minimum = 0,avg,sum = 0,top,topoverbottom,stddev,value;

    /**< ascdes is a variable which checks whether the user wants ascending or descending order */
    int n=0,i,j,k,ascdes;

    /**< values is an array that will store all values in the input txt file (1000 is a random number) */
    int values[1000];
    /**< Order is an array that stores the values in ascending order */
    int order[1000];
    /**< equals is a variable that counts the number of equal values in the input file.
    gthan is a variable that counts how many values a specific choosen value is greater than */
    int equals,gthan;


    /**< creates a file output object called sorted, which creates a text file (sortedValues.txt)
    and outputs to it (ios::out)*/
    ofstream sorted( "sortedValues.txt", ios::out );

    /**< creates a file input object called raw, which reads from a text file (rawValues.txt)*/
    ifstream raw( "rawValues.txt", ios::in );

    /**< determine whether the open operation succeeded */
	if (!sorted)
	{
		cerr << "File could not be opened!" << endl;
		exit( 1 );
	}

	/**< determine whether the open operation succeeded */
	if (!raw)
	{
		cerr << "File could not be opened!" << endl;
		exit( 1 );
	}

    /**< while there is still readable data in the txt file */
	while  (raw >> value)
    {

        /**< stores the value in the values array */
        values[n] = value;

        /**< find max and min */
        if (n==0)
        {
            maximum = value;
        }
        else if (value > maximum)
        {
            maximum = value;
        }

        if (n==0)
        {
            minimum = value;
        }
        else if (value < minimum)
        {
            minimum = value;
        }

        /**< counts amount of values in the input file */
        n = n + 1;
        cout << value << endl;

        /**< Adds all the values in the input file */
        sum = sum + value;

        /**< the sum divided by amount of numbers in the input file to get the average */
        avg = sum/n;
    }

    /**< presenting the standard deviation */
    cout << "max is: " << maximum << endl;
    cout << "min is: " << minimum << endl;
    cout << "average is: " << avg << endl;

    top = 0;

    for(i=0;i<n;i++)
    {
        /**< the whole topline of the equation */
        top = top + pow(values[i]-avg,2);
    }

    /**< topline divided by the amount of numbers in the file-1 */
    topoverbottom = top/(n-1);

    /**< sqrt of everything for the stand dev */
    stddev = sqrt(topoverbottom);

    cout << "stddev is: " << stddev << endl;

    /**< For loop orders the values in ascending order.  */
    for(i = 0; i < n; i++)
    {
        gthan = 0;
        equals = 0;

        /**< This for loop counts how many values a specifc value in the array is equal toor greater than. */
        for(j = 0; j < n; j++)
        {
            if (values[i] > values[j])
            {
                gthan += 1;
            }
            /**< If the element of the array is equal to an element other than itself then enter this if statment. */
            if (values[i] == values[j] && i != j)
            {
                equals += 1;
            }
            /**< If we are at the end of the second for loop,ie. we have checked this element vs all other elements */
            if (j==n-1)
            {
                /**< This for loop assigns a position to the value based on how many other values it is greater than or equal too. */
                for (k = gthan; k<=gthan+equals; k++)
                {
                    order[k] = values[i];
                }
            }
        }
    }

    cout << "For ascending order, enter '1'. For descending order, enter '2'" << endl;
    cin >> ascdes;


    if(ascdes == 1)
    {
        /**< Output to the 'sorted txt file' in ascending order */
        for(i=0;i<n;i++)
        {
            sorted << order[i] << endl;
        }
    }
    else if(ascdes == 2)
    {
        /**< Output to the 'sorted txt file' in descending order */
        for(i=n-1;i>=0;i--)
        {
            sorted << order[i] << endl;
        }
    }

    return 0;
}

#include <cstdio>
#include <string>
#include <cmath>
#define N 1000000
int main ()
{
    char input [210];
    int cases = 0;

    while ( scanf ("%s", input) && strcmp (input, "END") )
    {
        char *token;
        token = strtok (input, ",.");

        double x = 10e-6;
        double y = 10e-6;

        while ( token != NULL )
        {
            int number = atoi (token);
            double temp;

            if ( strstr (token, "NE" ) != NULL )
            {
                temp = number * sqrt (2);
                x += temp / 2;
                y += temp / 2;
            }
            else if ( strstr (token, "SE" ) != NULL )
            {
                temp = number * sqrt (2);
                x += temp / 2;
                y -= temp / 2;
            }
            else if ( strstr (token, "SW" ) != NULL )
            {
                temp = number * sqrt (2);
                x -= temp / 2;
                y -= temp / 2;
            }
            else if ( strstr (token, "NW" ) != NULL )
            {
                temp = number * sqrt (2);
                x -= temp / 2;
                y += temp / 2;
            }
            else if ( strstr (token, "N" ) != NULL )
            {
                y += number;
            }
            else if ( strstr (token, "E" ) != NULL )
            {
                x += number;
            }
            else if ( strstr (token, "S" ) != NULL )
            {
                y -= number;
            }
            else {
                x -= number;
            }

            token = strtok (NULL, ",.");
        }

        printf ("Map #%d\n", ++cases);
        printf ("The treasure is located at (%.3lf,%.3lf).\n", x, y);
        printf ("The distance to the treasure is %.3lf.\n\n", sqrt(x * x + y * y));
    }
}


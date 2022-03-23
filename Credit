#include <cs50.h>
#include <stdio.h>

int get_validity(long num);
string return_brand(long input);

int main(void)
{
    // Input
    long input = get_long("Please enter a CC number: ");
    // Verify Brand
    if (get_validity(input) == 1)
    {
        printf("%s\n", return_brand(input));
    }
    // Otherwise invalid
    else
    {
        printf("INVALID\n");
    }
}

// Determine the validity of a credit card based on Luhn's algorithm
int get_validity(long num)
{
    // Variables
    int count = 1;
    int current_num = 0;
    int placeholder = 0;
    int odd_total = 0;
    int total = 0;
    while (num > 0)
    {
        // Get current digit
        current_num = num % 10;
        // Check if count is odd or even
        // Even
        if (count % 2 == 0)
        {
            //Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
            placeholder = (current_num * 2);
            if (placeholder < 10)
            {
                total += placeholder;
            }
            else
            {
                current_num = placeholder % 10;
                total += current_num;
                placeholder /= 10;
                total += placeholder;
            }
        }
        // Odd
        else
        {
            odd_total += current_num;
        }
        // Increment
        count++;
        // Restart
        num /= 10;
    }

    // Add it all together
    total += odd_total;

    //Add the sum to the sum of the digits that weren’t multiplied by 2.
    //If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if (total % 10 == 0)
    {
        return 1;
    }
    return 0;
}

string return_brand(long input)
{
    // Chop off congruent excess
    input /= 100000000000;
    if (input > 9999)
    {
        input /= 1000;
    }
    else if (input > 999)
    {
        input /= 100;
    }
    if (input == 34 || input == 37)
    {
        return "AMEX";
    }
    else if (input > 50 && input < 56)
    {
        return "MASTERCARD";
    }
    else if (input / 10 == 4)
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

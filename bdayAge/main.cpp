// B-Day Program: Displays the Users Age in Years, Months, and Days
#include <iostream>
using namespace std;

// Declare Variables
int current_Year = 0;
int current_Month = 0;
int current_Day = 0;
int user_BDay = 0;
int user_BMonth = 0;
int user_BYear = 0;
int years_Old = 0;
int months_Old = 0;
int days_Old = 0;

int main()
{
    // Get the User's Current Date
    cout << "What year is it?" << endl;
    cin >> current_Year;
    cout << "What month is it?" << endl;
    cin >> current_Month;
    cout << "What day is it?" << endl;
    cin >> current_Day;

    // Get the User's Birth Date
    cout << "What year were you born in?" << endl;
    cin >> user_BYear;
    cout << "What month were you born in?" << endl;
    cin >> user_BMonth;
    cout << "What day were you born on?" << endl;
    cin >> user_BDay;

    // Calculate the age in years, months, and days
    years_Old = current_Year - user_BYear;

    // Check if birthdate hasn't occurred yet this year
    if ((user_BMonth > current_Month) || (user_BMonth == current_Month && user_BDay > current_Day)) {
        years_Old--; // If the birthday hasn't passed this year, subtract one year
    }

    // Calculate months old
    if (user_BMonth <= current_Month) {
        if (user_BDay <= current_Day) {
            months_Old = current_Month - user_BMonth;
        } else {
            months_Old = current_Month - user_BMonth - 1;
        }
    } else {
        months_Old = 12 - (user_BMonth - current_Month);
        if (user_BDay > current_Day) {
            months_Old--;
        }
    }

    // Calculate days old
    if (user_BDay <= current_Day) {
        days_Old = current_Day - user_BDay;
    } else {
        int days_in_previous_month;
        // Determine the number of days in the previous month
        if (current_Month == 3) {
            // Check for leap year in February
            if ((current_Year % 4 == 0 && current_Year % 100 != 0) || (current_Year % 400 == 0)) {
                days_in_previous_month = 29;
            } else {
                days_in_previous_month = 28;
            }
        } else if (current_Month == 1 || current_Month == 2 || current_Month == 4 || current_Month == 6 ||
                   current_Month == 8 || current_Month == 9 || current_Month == 11) {
            days_in_previous_month = 31;
        } else {
            days_in_previous_month = 30;
        }

        days_Old = days_in_previous_month - user_BDay + current_Day;
    }

    // Output the user's age
    cout << "You are " << years_Old << " years, " << months_Old << " months, and " << days_Old << " days old.\n";

    return 0;
}

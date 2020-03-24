#include <bits/stdc++.h>


using namespace std;



const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


int daysBetweenDates(string date1, string date2) {
    stringstream ss(date1);
    int year, month, day;
    char ch;
    ss>>year>>ch>>month>>ch>>day;
    struct tm starttm = {0, 0, 0, day, month - 1, year - 1900};
    time_t start = mktime(&starttm);

    stringstream ss1(date2);
    ss1>>year>>ch>>month>>ch>>day;
    starttm = {0, 0, 0, day, month - 1, year - 1900};
    time_t end = mktime(&starttm);

    return abs(end - start) / 86400;

        
}

int main(){
    string date1, date2;
    cin>>date1>>date2;
    cout<<daysBetweenDates(date1, date2);
    return 0;
}
/****************************
 * Струк Степан Андреевич   *
 * 28.11.2023               *
 * Календарь                *
 * onlinegdb.com/G-OPP8upCL *
 ****************************/

#include <iostream>
#include <string>

using namespace std;

/*
       Январь               Февраль     
пн вт ср чт пт сб вс  пн вт ср чт пт сб вс
 1  2  3  4  5  6  7            1  2  3  4
 8  9 10 11 12 13 14   5  6  7  8  9 10 11
15 16 17 18 19 20 21  12 13 14 15 16 17 18
22 23 24 25 26 27 28  19 20 21 22 23 24 25
29 30 31              26 27 28
*/

const string monthes[12] = {"       Январь       ",
                            "       Февраль      ",
                            "        Март        ",
                            "       Апрель       ",
                            "         Май        ",
                            "        Июнь        ",
                            "        Июль        ",
                            "       Авгусь       ",
                            "      Сентабль      ",
                            "       Октябрь      ",
                            "       Ноябрь       ",
                            "       Декабрь      "
};


int getFebruaryDaysCount(int y){
  return y % 400 == 0 || (y % 4 == 0 && y % 100) ? 29 : 28;
}

int getFirstWeekDay(int targetYear, int currentYear = 1, int daysSum = 0){
  if (currentYear >= targetYear){
    return daysSum % 7;
  }
  return getFirstWeekDay(targetYear, currentYear + 1, daysSum + getFebruaryDaysCount(currentYear) + 337);
}

int main(){
  int year;

  cout << "enter year: ";
  cin >> year;
  
  int februaryDaysCount = getFebruaryDaysCount(year);
  
  int monthesDaysCount[12] = {31, februaryDaysCount, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  int firstWeekDay = getFirstWeekDay(year);
  
  string calendar[12][7][6];
  
  //for (int spaces = 0; spaces < firstWeekDay; ++spaces){
  //  calendar[0][spaces][0] = "  ";
  //}
  
  int currentWeekDay = firstWeekDay;
  
  for (int monthIndex = 0; monthIndex < 12; ++monthIndex){
    int currentMonthMaxDay = monthesDaysCount[monthIndex];
    int currentMonthDaysCount = 0;
    int currentRow = 0;
    
    for (int spaces = 0; spaces < currentWeekDay; ++spaces){
      calendar[monthIndex][spaces][0] = "  ";
    }
    
    while (currentMonthDaysCount < currentMonthMaxDay){
      ++currentMonthDaysCount;

      if (currentMonthDaysCount < 10){
        calendar[monthIndex][currentWeekDay][currentRow] = " " + to_string(currentMonthDaysCount);
      } else {
        calendar[monthIndex][currentWeekDay][currentRow] = to_string(currentMonthDaysCount);
      }
      
      ++currentWeekDay;
      
      if (currentWeekDay >= 7){
        currentWeekDay = 0;
        ++currentRow;
      }
      
    }
    
  }
  
  for (int monthIndex = 0; monthIndex < 12; ++monthIndex){
    cout << monthes[monthIndex] << endl
         << "пн вт ср чт пт сб вс" << endl;

    for (int row = 0; row < 6; ++row){

      for (int weekDay = 0; weekDay < 7; ++weekDay){
        cout << calendar[monthIndex][weekDay][row] << " ";
      }

      cout << endl;
    }

  }
  
  return 0;
}


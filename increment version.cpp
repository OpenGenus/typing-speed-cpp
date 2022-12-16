


#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
string s;
void space() { cout << "\n\n\n"; }
string startscreen()
{
    char ch = 1;
    string name;
    space();
    cout << "\t\t\t\t\t     TYPING SPEED TEST IN C++   \n";
    space();
    cout << "\t\t\t***************************************************************************\n";
    cout << "\t\t\t|   CHECK YOUR TYPING SPEED AND EVALUATE YOUR PERFORMANCE " << ch << "               | \n";
    cout << "\t\t\t|   ENTER YOUR NAME AND START TYPING =>                                   |\n";
    cout << "\t\t\t***************************************************************************\n\t\t\t\t\t\t";
    cin >> name;
    system("cls");
    return name;
}
void homescreen(string name)
{
	cout<<"**********************************************************************************************************************************************************" ;
  
	cout << "\n\n\n\t\t\t\t\t\t\t\t    WELCOME " << name << "     \n";
    space();
    cout << "\t\t\t\t\t\t \t\t   TYPING SPEED TEST IN C++ \n\n\n";
    	cout<<"************************************************************************************************************************************************************" ;
    space();
        
		s="This is console based c++ program for the typing test .this is an example paragraph .A cryptocurrency is a virtual or digital currency that is highly secured by cryptography or encryption techniques which makes it nearly impossibleto counterfeit such cryptocurrency Cryptocurrency is an alternative means of exchange and the transactionsof crypto are highly secured using cryptography. Crypto is electronicmoney or we can say that it is a type of virtual money. The power ofgoverning or controlling the distribution of Cryptocurrency does not liein the hands of the government or any single authority.\n";
	cout<<s;
	space();
}


int user_interface(char &curr_word, string userName)
{
  homescreen(userName);
  cout << "To start the Test, press enter \'R-key\' \n";
  curr_word = getch();
  curr_word = tolower(curr_word);
  while (curr_word != 'R')
    {
      cout << "Please press the valid key : \n";
      curr_word = getch();
    }
     cout << "\t\t\t YOUR TEST STARTS, start typing \n\n\n";
    return time(0);
}

void userStatus(int totalWords, int total_letters, int seconds, string name)
{
      system("cls");
     homescreen(name);
     cout << "\n\t\t\t\t\t\t\t\t   " << name << "'S TYPING STATS  "
         << "\n\n";
      cout << "\t\t\t\t\t\t\t\tTOTAL WORDS   : " << totalWords << "\n";
      cout << "\t\t\t\t\t\t\t\tTOTAL LETTERS : " << total_letters << "\n";
      cout << "\t\t\t\t\t\t\t\tTOTAL TIME    : " << seconds / 60 << ":" << seconds % 60 << "\n";
    cout << "\t\t\t\t\t\t\t\tWords/minute  : " << (totalWords / (seconds / 60)) << "\n\n\n";
}

int time_span(int &starting_time)
{
  int currentTime = time(0);
  int sec = currentTime - starting_time;
  static int min;
  if (sec > 59)
    {
     min++;
     starting_time = time(0);
    }
    cout << "Time passed  : " << min << " : " << sec << "\n";
    return (min * 60) + sec;
}

void calculation(char *&str, const char curr_word, int &total_letters, int &totalWords)
{
    if (curr_word != 8)
    {
       char *temp = new char[total_letters + 1];
       for (int i = 0; str[i] != '\0'; i++)
        {
            temp[i] = str[i];
        }
          temp[total_letters - 1] = curr_word;
          temp[total_letters] = '\0';
          delete[] str;
          str = temp;
          total_letters++;
    }
    if (curr_word == 8 && total_letters != 0)
    {
     char *temp = new char[total_letters - 1];
     for (int i = 0; i < total_letters - 1; i++)
     {
         temp[i] = str[i];
     }
     temp[total_letters - 2] = '\0';
     delete[] str;
     str = temp;
     total_letters--;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i - 1] != 32 && str[i] == 32)
        {
          totalWords++;
        }
    }
}

void display(char &curr_word, char *&str, int &total_letters, int &starting_time, string userName)
{
	int i=0;
    do
    {
        int totalWords = 0;
        curr_word = getch();
        
        if(s[i++]==curr_word){
		
        if ((curr_word >= 32 && curr_word <= 126) || curr_word == 13 || curr_word == 8)
        {
          calculation(str, curr_word, total_letters, totalWords);
          system("cls");
          int currentTime = time(0);
          homescreen(userName);
          cout << "\n\nTotal Letters = " << total_letters - 1 << "\n";
          cout << "\n\nTotal Words = " << totalWords << "\n";
            time_span(starting_time);
            space();
            for (int i = 0; str[i] != '\0'; i++)
            {
                cout << str[i];
            }
                space();
                space();
            cout << "To END THE PROGRAM : PRESS ENTER-KEY\n";
        }
        else
        {curr_word = getch();
        }
        if (curr_word == 13)
        {
            userStatus(totalWords, total_letters, time_span(starting_time), userName);
        }
    } 
    else if (curr_word == 13)
        {
            userStatus(totalWords, total_letters, time_span(starting_time), userName);
        }
	
	else i--;
	
	}while (curr_word != 13);
}

int main()
{
  int total_letters = 1;
  char *str = new char[total_letters]{'\0'};
  char curr_word;
 string userName = startscreen();
   int starting_time = user_interface(curr_word, userName);
    display(curr_word, str, total_letters, starting_time, userName);
    delete[] str;
    str = NULL;
    return 0;
}








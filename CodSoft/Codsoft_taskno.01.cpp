#include <iostream>
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()
using namespace std;
void guess(int target);
int main()
{
	int random;
	srand(time(0));
	random=1+rand()%20;
	cout<<"----------------------Number Guess---------------------";
	cout<<"\n______________________________________________________";
	cout<<"\n______________________________________________________";
	cout<<"\n\nThe Game Rules are:\n";
	cout<<"You have to guess a random number from 1 to 20\n";
	cout<<"In the end, you'll get to know how many attempts it took to guess correct number";
	sleep(3);
	guess(random);
	return 0;
}
void guess(int target)
{
	int attempts=0;
	char quit;
	while(!((quit=='E')||(quit=='e')))
	{
		system("cls");
		int answer;
		cout<<"\n\nEnter the number you think it is:";
		cin>>answer;
		if(target==answer)
		{
			cout<<"\nCongrats, you've found the number";
		}
		
		
		else if((target>10)&&(answer>15)&&(answer<20))
		{
			cout<<"\nYou're guess is above the number";
		}
		else if((target<10)&&(answer>15))
		{
			cout<<"\nYou're guess is way above the number";
		}
		else if ((target>10)&&(answer>=10)&&(answer<=15))
		{
			cout<<"\nYou are close to the guess";
		}
		else if((target<10)&&(answer>=10)&&(answer<=15))
		{
			cout<<"\nYou have gotten close but you would have to go low a bit more";
		}
		else if((target<10)&&(answer>=5)&&(answer<=10))
		{
			cout<<"\nyou are indeed close to it";
		}
		else if((target<5)&&(answer>=5)&&(answer<=10))
		{
			cout<<"\nyou are indeed close to it but would need to go low more";
		}
		else if((target<5)&&(answer>=1)&&(answer<=5))
		{
			cout<<"\nyou are indeed close to it but try it close to your guess again";
		}
	
		cout<<"\n\n\nIf you want to quit then Press \"E\"";
		cin>>quit;
		++attempts;
    }
		
		
		cout<<"\n\n\nTotal Attempts: "<<attempts;
		cout<<"\nNumber:"<<target;
		
		
		
	
}

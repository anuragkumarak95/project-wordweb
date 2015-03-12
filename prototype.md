#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h> // to get system time through time_t
int num,i;
void srand()
{unsigned int sval;
time_t t; // t is time type variable
sval=(unsigned)time(&t); srand(sval);
	for(i=0;i<5;++i)
	{num=rand()%100;
	//cout<<num<<' ';
	}
}
void main(){
clrscr();
srand();
cout<<endl<<"\\              / ____  ___  __   \\                /  ____  ____ "
    <<endl<<" \\            / |    ||   ||  \\   \\      /\\      /  |     |    \\ "
    <<endl<<"  \\    /\\    /  |    ||___||   |   \\    /  \\    /   |__   |____/"
    <<endl<<"   \\  /  \\  /   |    || \\  |   |    \\  /    \\  /    |     |    \\ "
    <<endl<<"    \\/    \\/    |____||  \\ |__/      \\/      \\/     |____ |____/"
    <<endl<<"Designed by - Anurag Kumar:: enjoy!!"<<endl;

char words[3][5]={{'a','3','4','1','2'},{'b','1','2','5','6'},{'c','5','6','7','8'}};
// ^ database done::
int colindex,strtcol,strtrow,finalcol,finalrow,rowindex,counter=0;
// ^ declared all the indexes..here..!!:

	for(int i=0;i<num;i++){
	strtcol=random(3);strtrow=random(5);
	do{finalcol=random(3);finalrow=random(5);
       //cout<<strtcol<<"\t"<<strtrow<<endl<<finalcol<<"\t"<<finalrow<<endl<<endl;
	}while(finalcol==strtcol||finalrow==strtrow);
			     }
	// ^ generated random number::
char item=words[strtcol][strtrow],won=words[finalcol][finalrow];
/*cout<<strtcol<<"\t"<<strtrow<<"\t"<<item<<endl
      <<finalcol<<"\t"<<finalrow<<"\t"<<won<<endl<<endl;*/
	// ^ positioned the start and end point::
cout<<endl<<"you final word you have to reach is : "<<won<<endl
    <<"Let the game begin::"<<endl;
//cout<<sizeof(words[0]);//to find the number of row in a column..
do{cout<<endl;//<<"entered the loop!!";
	if(strtrow==0){for(i=1;i<5;i++){cout<<words[strtcol][i]<<"\t";}
		      }
	// ^ where start point is a category.
else
{	for(colindex=0;colindex<3;colindex++)
	{
		for(rowindex=0;rowindex<5;rowindex++)
		{
			if(words[colindex][rowindex]==item)
			{cout<<words[colindex][0]<<"\t";}

		}
	}
}
		// ^ where start point is a context.
		// ^ end of displaying options....
cout<<"\nSelect the next step from the above choices: ";
cin>>item;//taking the next start point..
counter++;
if(item==won){cout<<"CONGRATULATIONS....you have reahced the final word.\n"
		  <<"\t\tNumber of steps you took is: "<<counter;}
	// ^ checked for if the player have reached the final word and won the game!!::
	for(colindex=0;colindex<3;colindex++)
	{	for(rowindex=0;rowindex<5;rowindex++)
		{   if(words[colindex][rowindex]==item)
		    {strtcol=colindex;strtrow=rowindex;
		   //cout<<"\nindexing done..";
		   continue;}

		}
	}
//cout<<"\nexiting the loop..";
}while(item!=won);
//cout<<item<<won;
char ch=' ';
cout<<"\nWanna try again??[y/n]";
cin>>ch;
if(ch=='y'||ch=='Y'){main();}
//repeating the game if the user wants to play agian.::
else if(ch=='n'||ch=='N'){exit(1);}
getch();
}

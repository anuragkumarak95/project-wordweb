/*This code operates on the file doc_file.txt that is also provided in the prohect files, please to copy it also in the same link as the project code..*/

#include<iostream.h>
#include<time.h>
#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<String.h>
int num;
void srand()
{unsigned int sval;
time_t t; // t is time type variable
sval=(unsigned)time(&t); srand(sval);
	for(int m=0;m<5;++m)
	{ num=rand()%100;
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

int strtcol,finalcol,counter=0;
// ^ declared all the indexes..here..!!:
	for(int i=0;i<num;i++){
	do{strtcol=random(60);}while(strtcol<10);
	do{do{finalcol=random(60);}while(finalcol<10);
       //cout<<strtcol<<"\t"<<strtrow<<endl<<finalcol<<"\t"<<finalrow<<endl<<endl;
	}while(finalcol==strtcol);
			     }
	// ^ generated random number::
	char word[50],line[50],won[50];
	ifstream file_a("doc_file.txt",ios::nocreate);
	for(int strt=0;strt<strtcol;strt++){file_a.getline(word,50);}file_a.seekg(0);
	for(int final=0;final<finalcol;final++){file_a.getline(won,50);}file_a.seekg(0);
	//Initiated the start and win points.
	file_a.close();
cout<<endl<<"Your final win word of the game is:: "<<won
    <<endl<<"Lets Begin:";

do{
ifstream file("doc_file.txt",ios::nocreate);
counter++;
int ind_list[9],tell[6]={0,0,0,0,0,0};

while(file.eof()==0)
{ file.getline(line,50);
  tell[5]=tell[4];tell[4]=tell[3];
  tell[3]=tell[2];tell[2]=tell[1];
  tell[1]=tell[0];tell[0]=file.tellg();
  if(strcmp(line,word)==0)//to check if the word entered and any line in the doc is equal to each other in refrence to string::
  { //cout<<"yess ";
    if(file.tellg()>=700){cout<<"cant use this:\n\npress enter to choose again::";getch();main();}
    file.seekg(tell[5]);
    for(int i=0;i<9;i++)
    { int toog=0;

      file.getline(line,50);
      for(int k=0;k<i;k++)//to check for unique entry in the list::
       { if(file.tellg()>=800){file.seekg(tell[5]);continue;}
	 //cout<<"\t"<<file.tellg();
	 if(ind_list[k]==file.tellg())
		{toog=1;}
       }
       if(i==0||toog==0)
		{ //srand();
		  int ran=random(20);
		  //cout<<ran<<"\t";
	 if(ran<=10)
	   {ind_list[i]=file.tellg();}
	 else{i--;}}//entering the unique location of the words nieghbouring the given word.
       else{i--;}
       // cout<<i<<"\t";
    }

  }//cout<<file.tellg()<<"\t";

}
file.close();//to complex to use agian for seeking::


// opening the doc again to use it in fresh file..
ifstream file_1("doc_file.txt",ios::nocreate);
//cout<<endl<<endl<<file_1.tellg();

//providing the relative options from previous select..
cout<<endl<<"The relative options from our previous word are:\n";
char line_b[50];
for(int j=0;j<9;j++)
{ file_1.seekg(ind_list[j]);
  // cout<<endl<<file_1.tellg();
  file_1.getline(line_b,50);
  cout<<"\t"<<line_b;
}
file_1.close();

//Next choice ::
cout<<endl<<"Now choose from the above word for next links:";
cin>>word;

//The win scenario..
if(strcmp(word,won)==0)
{cout<<endl<<"CONGRATULATIONS::\nYou have just finished the game by entering the winning word"
     <<endl<<"You took "<<counter<<" steps to finish.";}
}while(strcmp(word,won)!=0);


//The repeat the code page::
char ch=' ';
cout<<"\n\n\nWanna try again??: [y/n]::";
cin>>ch;
if(ch=='y'||ch=='Y'){main();}
else if(ch=='n'||ch=='N'){exit(1);}
getch();
}

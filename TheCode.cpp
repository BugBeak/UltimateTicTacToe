#include<iostream>
#include<string>
#include<stdio.h>
#include<cstdlib> // for system()
using namespace std;

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void display(char s[][10])
{//1
 cout<<"                       row- horizontal; column- vertical     "<<endl;
 cout<<"                  -------------------------------------------"<<endl;
 cout<<"                   || 1   2   3 || 4   5   6 || 7   8   9 ||"<<endl;
 cout<<"                  -------------------------------------------"<<endl;
 for(int i=0; i<9; i+=3)
 {//2
  cout<<"               --- ||---|---|---||---|---|---||---|---|---||"<<endl;
  cout<<"                "<<i+1<<" ";
  for(int j=0; j<9; j+=3)
  cout<<" || "<<s[i][j]<<" | "<<s[i][j+1]<<" | "<<s[i][j+2];
  cout<<" ||"<<endl;
  cout<<"                -  || - | - | - || - | - | - || - | - | - ||"<<endl;
  cout<<"                "<<i+2<<" ";
  for(int j=0; j<9; j+=3)
   cout<<" || "<<s[i+1][j]<<" | "<<s[i+1][j+1]<<" | "<<s[i+1][j+2];
  cout<<" ||"<<endl;
  cout<<"                -  || - | - | - || - | - | - || - | - | - ||"<<endl;
  cout<<"                "<<i+3<<" ";
  for(int j=0; j<9; j+=3)
   cout<<" || "<<s[i+2][j]<<" | "<<s[i+2][j+1]<<" | "<<s[i+2][j+2];
  cout<<" ||"<<endl;
 }   //2
 cout<<"               --- ||---|---|---||---|---|---||---|---|---||"<<endl;
 cout<<"                  -------------------------------------------"<<endl;
}             //1

int main(void)
{//1
 clear_screen();
 char board[9][10];
 for(int i=0;i<9;i++)
     for(int j=0;j<9;j++)
         board[i][j] = ' ';
 cout<<"                              ULTIMATE TIC TAC TOE"<<endl;
 cout<<endl<<"The rules are: \n 1. Each turn, you mark one of the small squares"<<endl;
 cout<<" 2. When you get three in a row on a small board, you've won that board "<<endl;
 cout<<" 3. to win the game, you need to win three small boards in a row"<<endl;
 cout<<" 4. THE MOST IMPORTANT RULE: you don't get to pick which of the nine small  "<<endl;
 cout<<"\tboards to play in.That's determined by your opponent's previous "<<endl;
 cout<<"\tmove. The small board  in which you have to play is at the same position "<<endl;
 cout<<"\ton the big board as the square your opponent chose(in his/her last "<<endl;
 cout<<"\tmove) is in the corresponding  small board."<<endl;
 cout<<"\tFor example, if your opponent chose the top right square in a small ,"<<endl;
 cout<<"\tboard then you get to play your move in the top right small board, and"<<endl;
 cout<<"\tso on."<<endl;
 cout<<" 5. In case the previous player's move points to an already won"<<endl;
 cout<<"\tsmall board, the present player can play in ANY small"<<endl; cout<<"\tboard."<<endl; 
 cout<<" 6. In case a small board is tied, it can be used as both cross and zero"<<endl<<endl;
 char done;
 cout<<"Shall we start the game?";
 cin>>done;
 int row=0, col=0, row1=0, col1=0;
 int available[3][3]={{1,1,1},{1,1,1},{1,1,1}};
 char winner[3][4]={"   ","   ","   "};
 int exc=0, r, c;
 int gameover=0;
 display(board);
 do{
  cout<<"player 1 enter row   ";
  cin>>row;
  cout<<"               column   ";
  cin>>col;
 }while((row>9)||(col>9));
 board[row-1][col-1]='x';
 display(board);
 char something;
 do{
  cout<<"ready for next turn?";
  cin>>something;
 }while(something!='y'&&something!='Y');
 int player=2;

 // .................................................................

 do
 {//3
  if (player%2==0)       //player 2
  {//4
   exc=0;               //means pointed s.board is available                
   r=(row-1)%3;
   c=(col-1)%3;
   if (available[r][c]==0)
    exc=1;        //means pointed s.board is unavailable
   do{
    if (row%3==0)      //row entry of player 2
     do
     {//5
      cout<<"player 2 enter row   ";
      cin>>row1;
      //5
     }while((exc==0)&&(row1!=7)&&(row1!=8)&&(row1!=9));
    else if((row+1)%3==0)
     do
     {//5
      cout<<"player 2 enter row   ";
      cin>>row1;
      //5
     }while((exc==0)&&(row1!=4)&&(row1!=5)&&(row1!=6));
    else do
    {//5
     cout<<"player 2 enter row   ";
     cin>>row1;
     //5
    }while((exc==0)&&(row1!=1)&&(row1!=2)&&(row1!=3));
    if (col%3==0)                  //column entry of player 2
     do
     {//5
      cout<<"player 2 enter column   ";
      cin>>col1;
      //5
     }while((exc==0)&&(col1!=7)&&(col1!=8)&&(col1!=9));
    else if((col+1)%3==0)
     do
     {//5
      cout<<"player 2 enter column   ";
      cin>>col1;
      //5
     }while((exc==0)&&(col1!=4)&&(col1!=5)&&(col1!=6));
    else 
     do
     {//5
      cout<<"player 2 enter column   ";
      cin>>col1;
      //5
     }while((exc==0)&&(col1!=1)&&(col1!=2)&&(col1!=3));
    int blrow=(row1-1)/3;
    int blcol=(col1-1)/3;
    if ((available[blrow][blcol]==1)&&(board[row1-1][col1-1]==' '))
     board[row1-1][col1-1]='o';
   }while(board[row1-1][col1-1]==' ');
   clear_screen();
   display(board);
   //4
  }
  else                      //player%=1;
  {//4
   exc=0;
   r=(row1-1)%3;
   c=(col1-1)%3;
   if (available[r][c]==0)
    exc=1;
   do{
    if (row1%3==0)                            //row entry of player 1
     do
     {cout<<"player 1 enter row   ";
      cin>>row;
     }while((exc==0)&&(row!=7)&&(row!=8)&&(row!=9));
    else if((row1+1)%3==0)
     do
      {cout<<"player 1 enter row   ";
       cin>>row;
      }while((exc==0)&&(row!=4)&&(row!=5)&&(row!=6));
    else 
     do
     {cout<<"player 1 enter row   ";
      cin>>row;
     }while((exc==0)&&(row!=1)&&(row!=2)&&(row!=3));
    if (col1%3==0)                    //column entry of player 1
     do
     {cout<<"player 1 enter column   ";
      cin>>col;
     }while((exc==0)&&(col!=7)&&(col!=8)&&(col!=9));
    else if((col1+1)%3==0)
     do
     {cout<<"player 1 enter column   ";
      cin>>col;
     }while((exc==0)&&(col!=4)&&(col!=5)&&(col!=6));
    else
     do
     {cout<<"player 1 enter column   ";
      cin>>col;
     }while((exc==0)&&(col!=1)&&(col!=2)&&(col!=3));
    int blrow=(row-1)/3;
    int blcol=(col-1)/3;
    if ((available[blrow][blcol]==1)&&(board[row-1][col-1]==' '))
     board[row-1][col-1]='x';
   }while(board[row-1][col-1]==' ');
   clear_screen();
   display(board);
   //4
  }
  int i, j;
  for(i=0;i<9;i++)             //for 3 in a horizontal row
   for(j=0;j<9;j+=3)
    if ((board[i][j]=='x')&&(board[i][j+1]=='x')&&(board[i][j+2]=='x'))
    {int temp=(i/3);
     int ii=temp*3;
     board[ii][j]='x' ;
     board[ii][j+1]='x';
     board[ii][j+2]='x';
     board[ii+1][j]='x';
     board[ii+1][j+1]='x';
     board[ii+1][j+2]='x';
     board[ii+2][j]='x';
     board[ii+2][j+1]='x';
     board[ii+2][j+2]='x';
     available[ii/3][j/3]=0;
     winner[ii/3][j/3]='c';
    }
    else  if ((board[i][j]=='o')&&(board[i][j+1]=='o')&&(board[i][j+2]=='o'))
    {int temp=(i/3);
     int ii=temp*3;
     board[ii][j]='o' ;
     board[ii][j+1]='o';
     board[ii][j+2]='o';
     board[ii+1][j]='o';
     board[ii+1][j+1]='o';
     board[ii+1][j+2]='o';
     board[ii+2][j]='o';
     board[ii+2][j+1]='o';
     board[ii+2][j+2]='o';
     available[ii/3][j/3]=0;
     winner[ii/3][j/3]='z';
    }
  for(j=0;j<9;j++)          //for 3 in a vertical row
   for(i=0;i<9;i+=3)
    if ((board[i][j]=='x')&&(board[i+1][j]=='x')&&(board[i+2][j]=='x'))
    {
     int temp=(j/3);
     int jj=temp*3;
     board[i][jj]='x' ;
     board[i][jj+1]='x';
     board[i][jj+2]='x';
     board[i+1][jj]='x';
     board[i+1][jj+1]='x';
     board[i+1][jj+2]='x';
     board[i+2][jj]='x';
     board[i+2][jj+1]='x';
     board[i+2][jj+2]='x';
     available[i/3][jj/3]=0;
     winner[i/3][jj/3]='c';
    }
    else  if ((board[i][j]=='o')&&(board[i+1][j]=='o')&&(board[i+2][j]=='o'))
    {
     int temp=(j/3);
     int jj=temp*3;
     board[i][jj]='o' ;
     board[i][jj+1]='o';
     board[i][jj+2]='o';
     board[i+1][jj]='o';
     board[i+1][jj+1]='o';
     board[i+1][jj+2]='o';
     board[i+2][jj]='o';
     board[i+2][jj+1]='o';
     board[i+2][jj+2]='o';
     available[i/3][jj/3]=0;
     winner[i/3][jj/3]='z';
    }
  for(i=0;i<9;i+=3)             //for 3 in a right diagonal(\)
   for(j=0;j<9;j+=3)
    if ((board[i][j]=='x')&&(board[i+1][j+1]=='x')&&(board[i+2][j+2]=='x'))
    {
     board[i][j]='x' ;
     board[i][j+1]='x';
     board[i][j+2]='x';
     board[i+1][j]='x';
     board[i+1][j+1]='x';
     board[i+1][j+2]='x';
     board[i+2][j]='x';
     board[i+2][j+1]='x';
     board[i+2][j+2]='x';
     available[i][j]=0;
     winner[i][j]='c';
    }
    else  if ((board[i][j]=='o')&&(board[i+1][j+1]=='o')&&(board[i+2][j+2]=='o'))
    {
     board[i][j]='o' ;
     board[i][j+1]='o';
     board[i][j+2]='o';
     board[i+1][j]='o';
     board[i+1][j+1]='o';
     board[i+1][j+2]='o';
     board[i+2][j]='o';
     board[i+2][j+1]='o';
     board[i+2][j+2]='o';
     available[i][j]=0;
     winner[i][j]='z';
    }        
  for(i=0;i<9;i+=3)             //for 3 in a left diagonal(/)
   for(j=0;j<9;j+=3)
    if ((board[i][j+2]=='x')&&(board[i+1][j+1]=='x')&&(board[i+2][j]=='x'))
    {
     board[i][j]='x' ;
     board[i][j+1]='x';
     board[i][j+2]='x';
     board[i+1][j]='x';
     board[i+1][j+1]='x';
     board[i+1][j+2]='x';
     board[i+2][j]='x';
     board[i+2][j+1]='x';
     board[i+2][j+2]='x';
     available[i][j]=0;
     winner[i][j]='c';
    }
    else  if ((board[i][j+2]=='o')&&(board[i+1][j+1]=='o')&&(board[i+2][j]=='o'))
    {
     board[i][j]='o' ;
     board[i][j+1]='o';
     board[i][j+2]='o';
     board[i+1][j]='o';
     board[i+1][j+1]='o';
     board[i+1][j+2]='o';
     board[i+2][j]='o';
     board[i+2][j+1]='o';
     board[i+2][j+2]='o';
     available[i][j]=0;
     winner[i][j]='z';
    }
  for(i=0; i<9; i+=3)
   for(j=0; j<9; j+=3)
    if((available[i][j]==1)&&(board[i][j+1]!=' ')&&(board[i][j+2]!=' ')&&(board[i+1][j]!=' ')&&(board[i+1][j+1]!=' ')&&(board[i+1][j+2]!=' ')&&(board[i+2][j]!=' ')&&(board[i+2][j+1]!=' ')&&(board[i+2][j+2]!=' '))
    {
     available[i][j]=0;
     winner[i][j]='t';
     board[i][j]='t' ;
     board[i][j+1]='t';
     board[i][j+2]='t';
     board[i+1][j]='t';
     board[i+1][j+1]='t';
     board[i+1][j+2]='t';
     board[i+2][j]='t';
     board[i+2][j+1]='t';
     board[i+2][j+2]='t';
    }
  //big board horizontal row
  for(i=0; i<3; i++)
   if( ((winner[i][0]=='c')||(winner[i][0]=='t'))&&((winner[i][1]=='c')||(winner[i][1]=='t'))&&((winner[i][2]=='c')||(winner[i][2]=='t')) )
    gameover=1;
   else if( ((winner[i][0]=='z')||(winner[i][0]=='t'))&&((winner[i][1]=='z')||(winner[i][1]=='t'))&&((winner[i][2]=='z')||(winner[i][2]=='t')) )
    gameover=2;
  //big board vertical row
  for(j=0; j<3; j++)
   if( ((winner[0][j]=='c')||(winner[0][j]=='t'))&&((winner[1][j]=='c')||(winner[1][j]=='t'))&&((winner[2][j]=='c')||(winner[2][j]=='t')) )
    gameover=1;
   else if( ((winner[0][j]=='z')||(winner[0][j]=='t'))&&((winner[1][j]=='z')||(winner[1][j]=='t'))&&((winner[2][j]=='z')||(winner[2][j]=='t')) )
    gameover=2;
  //big board right diagonal
  if( ((winner[0][0]=='c')||(winner[0][0]=='t'))&&((winner[1][1]=='c')||(winner[1][1]=='t'))&&((winner[2][2]=='c')||(winner[2][2]=='t')) )
   gameover=1;
  else if( ((winner[0][0]=='z')||(winner[0][0]=='t'))&&((winner[1][1]=='z')||(winner[1][1]=='t'))&&((winner[2][2]=='z')||(winner[2][2]=='t')) )
   gameover=2;
  //big board left diagonal
  if( ((winner[0][2]=='c')||(winner[0][2]=='t'))&&((winner[1][1]=='c')||(winner[1][1]=='t'))&&((winner[2][0]=='c')||(winner[2][0]=='t')) )
   gameover=1;
  else if( ((winner[0][2]=='z')||(winner[0][2]=='t'))&&((winner[1][1]=='z')||(winner[1][1]=='t'))&&((winner[2][0]=='z')||(winner[2][0]=='t')) )             gameover=2;
   ++player;
  if(gameover==0)
  do
  {
   cout<<"ready for next turn?";
   cin>>something;
  }while(something!='y'&&something!='Y');
 }while(gameover==0);
 cout<<endl<<endl;
 if (gameover==1)
  cout<<"player 1 (cross) wins!!!"<<endl<<endl;
 else cout<<"player 2 (zero) wins!!!"<<endl<<endl;
  cout<<" game ends. type a character. \t";
 char what;
 cin>>what;
 cin.get();
 cin.get();
}

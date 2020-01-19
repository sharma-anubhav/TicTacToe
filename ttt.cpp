#include<iostream>
using namespace std;
class game{
	public:
		int state[3][3]={0};
		int x,y;
		int flag;
		void print_state();
		void human_turn();
		void comp_turn();
		void Vhuman_winCheck();
	 	void comp_winCheck();
};
void game::print_state(){
cout << "**********************************\n\n";
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
		cout << "     "<<state[i][j]<<"      ";
	}
	cout << "\n\n";
}
cout << "**********************************\n";
}
void game::human_turn(){
	cout << "Your Turn";
	cin >> x >> y;
	int p,q;
	if(state[x-1][y-1]!=0){
		cout << "invalid move";
	}else{
		state[x-1][y-1]=1;
	}
	for(p=0,q=0;p<3,q<3;p++,q++){
		if(state[p][0]+state[p][1]+state[p][2]==3||state[0][q]+state[1][q]+state[2][q]==3){
			cout<<"human wins";
			exit(0);
		}
	}
	if(state[0][0]+state[1][1]+state[2][2]==3||state[2][0]+state[1][1]+state[0][2]==3){
			cout<<"human wins";
			exit(0);
	}
}
void game::comp_winCheck(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(state[i][j]==0){
				
				if(state[i][0]+state[i][1]+state[i][2]==-2||state[0][j]+state[1][j]+state[2][j]==-2){
					state[i][j]=-1;
					print_state();
					cout<<"comp winn";
					exit(0);
				}
			
				if(i==j==1){
					if(state[0][0]+state[1][1]+state[2][2]==-2||state[2][0]+state[1][1]+state[0][2]==-2){
						state[i][j]=-1;
						print_state();
						cout<<"comp winn";
						exit(0);
					}
				}
				if(i==j){
					if(state[0][0]+state[1][1]+state[2][2]==-2){
						state[i][j]=-1;						
						print_state();
						cout<<"comp winn";
						exit(0);
					}
				}
				if((i==0&&j==2)||(i==2&&j==0)){
					if(state[2][0]+state[1][1]+state[0][2]==-2){
						state[i][j]=-1;
						print_state();
						cout<<"comp winn";
						exit(0);
					}
				}
				
			}
		}
	}
}
void game::Vhuman_winCheck(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(state[i][j]==0){
				
				if(state[i][0]+state[i][1]+state[i][2]==2||state[0][j]+state[1][j]+state[2][j]==2){
					state[i][j]=-1;
					flag=1;
				}
			
				if(i==j==1){
					if(state[0][0]+state[1][1]+state[2][2]==2||state[2][0]+state[1][1]+state[0][2]==2){
						state[i][j]=-1;
						flag=1;
					}
				}
				if(i==j){
					if(state[0][0]+state[1][1]+state[2][2]==2){
						state[i][j]=-1;
						flag=1;
					}
				}
				if((i==0&&j==2)||(i==2&&j==0)){
					if(state[2][0]+state[1][1]+state[0][2]==2){
						state[i][j]=-1;
						flag=1;
					}
				}
				
			}
		}
	}
}
void game::comp_turn(){
	comp_winCheck();
	flag=0;
	Vhuman_winCheck();
	if(game::flag==0){	
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(state[i][j]==0){
					state[i][j]=-1;
					return;
				}
			}
		}
	}
}

int main(){
	game g1;
		for(int i=0;i<4;i++){
		g1.print_state();
		g1.human_turn();
		g1.print_state();
		g1.comp_turn();
	}
	g1.human_turn();
}
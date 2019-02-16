#include<stdio.h>
#include<stdlib.h>

int board[64][64]={0};
int cnt=0,size=1;
int tilerec(int,int,int,int,int);

int main() {
	int i,j,k,hr,hc;
    printf("enter the size(k)");
    scanf("%d",&k);
    printf("enter the defective block");
    scanf("%d%d",&hr,&hc);


	for(i=0;i<k;i++){
		size = 2*size;
	}
    board[hr][hc]=-1;
    tilerec(size,0,0,hr,hc);
    for(i=0;i<size;i++){
	for(j=0;j<size;j++) {
		printf("%2d ",board[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int tilerec(int n,int x,int y,int hr,int hc) {
	int i,j,colour;
    colour=++cnt;
	if(n == 2){
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++){
				if(board[x+i][y+j]==0)
					board[x+i][y+j]=colour;
			}
		}
		return 0;
	}
	//If missing Tile is in 1st quadrant
	if(hr< x + n/2 &&hc < y+ n/2)
		tilerec(n/2,x,y,hr,hc);
    else
    {
        board[x+n/2-1][y+n/2-1]=colour;
        tilerec(n/2,x,y,x+n/2-1,y+n/2-1);
    }
	//If missing Tile is in 2st quadrant
	if(hr>=x+ n/2 && hc < y + n/2)
        tilerec(n/2,x+n/2,y,hr,hc);
    else
    {
        board[x+n/2][y+n/2-1]=colour;
        tilerec(n/2,x+n/2,y,x+n/2,y+n/2-1);
    }
	//If missing Tile is in 3st quadrant
	if(hr < x + n/2 && hc >= y + n/2)
		tilerec(n/2,x,y+n/2,hr,hc);
    else
    {
        board[x+n/2-1][y+n/2]=colour;
        tilerec(n/2,x,y+n/2,x+n/2-1,x+n/2);
    }
	//If missing Tile is in 4st quadrant
	if(hr >= x + n/2 && hc >= y + n/2)
        tilerec(n/2,x+n/2,y+n/2,hr,hc);
    else
    {
        board[x+n/2][y+n/2]=colour;
        tilerec(n/2,x+n/2,y+n/2,x+n/2,y+n/2);
    }

	return 0;

}


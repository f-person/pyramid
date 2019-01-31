#include <iostream>
#define n 4

using namespace std;

int main(){
	int row, col, left, right, top, bottom, num, fixright, arr[n][2*n-1];
	left=0;
	right=2*n-2;
	top=0;
	bottom=n-1;
	num=1;
	for(row=0; row<n; row++){
    	for(col=0; col<=2*n-2; col++){
	        arr[row][col]=0;
    	}
	}
	do{
		fixright=right;
		for(col=left; col<=right; col++){
			arr[bottom][col]=num;
			num++;
		}
    
		for(row=bottom-1; row>=top; row--){
		    right--;
			arr[row][right]=num;
			num++;
		}
    
		for(row=top+1; row<=bottom-1; row++){
			right--;
			arr[row][right]=num;
			num++;
		}
    
		top++; bottom--; left+=2; right=fixright-2; 
	} while(bottom>=top); 
    
	for(row=0; row<n; row++){
		for(col=0; col<=2*n-2; col++){
			if (arr[row][col]!=0)
				cout<<arr[row][col]<<"\t";
            else
                cout<<"\t";
		}
		cout<<endl;
	}

	return 0;
}

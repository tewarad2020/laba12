#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool im[][M]){
    for(int i=0;i<32;i++) {
        if (i != 0 && i != 31) cout << "|"; 
        for(int j=0;j<72;j++) {
            if (i == 0) cout << "-";
            if(i != 0 && i != 31 && j != 0 && j != 71) {
            	if(im[i-1][j-1] == 1) cout << "*";
            	else cout << " ";
			}
            if (i == 31) cout << "-";
        }
		if (i != 0 && i != 31) cout << "|" << endl;
		else cout << endl; 
    }
}

void updateImage(bool im[][M],int s,int x,int y) {
    for(int i=0;i<30;i++) {
        for(int j=0;j<70;j++) {
            if (sqrt(pow(i-double(x),2)+pow(j-double(y),2)) <= s-1) im[i][j] = '*';
        }
    }
}
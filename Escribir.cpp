#include <iostream>
#include <cstdlib>
#include <cmath>

#define MX 2000000000

using namespace std;

int main(){
	int n=8000;
	for(int i=0;i<n;i++){
		cout<<n<<" ";
		for(int j=0;j<n;j++){
			cout<<rand()%MX<<" ";
		}
		cout<<endl;
		
	}

	return 0;
}

//tiempo de generacion N
//tiempo de generacion <=3N/2

/*
ID: asdfasdfasdf
PROG: combo
LANG: C++
*/


#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int N;

class Locker{
	public:
		int n1, n2, n3;
		Locker(int, int, int);
	bool operator <(const Locker & r) const{
		return (n1*100+n2*10+n3 < r.n1*100+r.n2*10+r.n3);
	}
};

Locker::Locker(int x, int y, int z){ 
	n1=x; n2=y; n3=z;
}

Locker check(int x,int y,int z){
	while (x<1){x+=N;} while(y<1){y+=N;} while(z<1){z+=N;}
        while (x>N){x-=N;} while(y>N){y-=N;} while(z>N){z-=N;}
	return Locker(x,y,z);
}
	
int main(){

	ifstream fin("combo.in");
	ofstream fou("combo.out");	
	fin>>N;
	set<Locker> mylocker;
	int n1,n2,n3;
	fin>>n1>>n2>>n3;
	for (int i=-2;i<3;++i)
		for(int j=-2;j<3;++j)
			for(int k=-2;k<3;++k)
				mylocker.insert(check(n1+i,n2+j,n3+k));
				
	fin>>n1>>n2>>n3;
	for (int i=-2;i<3;++i)
                for(int j=-2;j<3;++j)
                        for(int k=-2;k<3;++k)
                                mylocker.insert(check(n1+i,n2+j,n3+k));

	for (set<Locker> :: iterator it=mylocker.begin(); it!=mylocker.end(); ++
it){
		const Locker & i=*it; 
		cout << i.n1 << i.n2 << i.n3 << " ";
	}
	cout<< endl;
		
	fou<<mylocker.size()<<endl;
return 0;
}
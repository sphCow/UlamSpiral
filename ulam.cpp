#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

	unsigned long n=4096; //only ODD
	
	vector<unsigned long> lookup;
	vector<unsigned long> spiral;
	vector<bool> isprime_vec;

	
	//create lookup table
	lookup.resize(n*n+1);
	spiral.resize(n*n+1);
	isprime_vec.resize(n*n+1);
	
	unsigned long nr=1;
	unsigned long elem=1;
	unsigned long cx = int(n/2); 
	unsigned long cy = int(n/2);
	//a[cx][cy] = 1;
	
	while(elem<n*n) {
		for(unsigned long j=0; j<2*nr; j++) {			
			if(nr%2==0) {    // nr = EVEN
				if(j<nr) cy--; //L
				else cx++;     //D
			} 
			
			else {		       // nr = ODD
				if(j<nr) cy++; //R
				else cx--;     //U
			}
			
			//a[cx][cy] = elem+1;
			
			lookup[elem] = cy+n*cx;
			spiral[cy+n*cx] = elem;
			
			elem++;
			
			if(elem==(n*n)) break;
		}
		
		nr++;
	}
	
	//prunsigned long_vec(a);
	//cout << endl << endl;
		
	// Sieve now
	for(unsigned long i=0; i<n*n;i++) {
		isprime_vec[i] = true; 
	}
		
	for(unsigned long i=2; i<n;i++) {
		if(isprime_vec[i]) {
			for(unsigned long j=0; j<n*n+1; j++) {
				unsigned long k = i*i + j*i;
				if(k<n*n+1) isprime_vec[lookup[k]] = false;
			}
		}
	}
	
	for(unsigned long i=0; i<n*n; i++) {
		//cout << setw(10) << spiral[i] << "(" << isprime_vec[i] << ")";
		cout << setw(10) << isprime_vec[i] << " ";
		if((i+1)%(n)==0) cout << endl;
	}
				
	cout << endl << endl;
	
	for(unsigned long i=0; i<n*n; i++) {
		//cout << setw(10) << spiral[i] << "(" << isprime_vec[i] << ")";
		cout << setw(10) << spiral[i] << " ";
		if((i+1)%(n)==0) cout << endl;
	}
	
	return 0;
}

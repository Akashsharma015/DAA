#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
char freq[26];
void countSortMaxFreq(char arr[],int n){
	for(int i=0;i<26;i++)
		freq[i]=0;
	for(int i=0;i<n;i++){
		++freq[(int)(arr[i])-97];
	}

}
int main(){
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int t,n;
	in >> t;
	while(t--){
		in >> n;
		char arr[n];
		for(int i=0;i<n;i++)
			in >> arr[i];

		countSortMaxFreq(arr,n);
		int max= *max_element(freq,freq+26);
		int index = max_element(freq,freq+26)-freq;
	//cout << "Index = " << index << endl;
		char alph = 'a' + (char)(index);
		if(max>1)
			out << alph << "-" << max << endl;
		else
			out << "No Duplicate Present" << endl;
	}
}

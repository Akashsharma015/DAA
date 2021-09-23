#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream in;
	in.open("input.txt");
	ofstream out;
	out.open("output.txt");
	int n,k,t;
	int temp;
	int arr[100];
	in >> t;
	while(t){
		in >> n;
		for(int i=0;i<n;i++){
			in >> arr[i];
		}
		in >> k;
		int left = 0;
		int right = n-1;
		temp=0;
		int index;
		while(left<=right){
			int mid = left + ((right-left)/2);
			if(arr[mid]==k){
				index=mid;
				temp=1;
				break;
			}else if(arr[mid]>k){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		if(temp==0){
			out << "Key not Present";
		}
		else{
			int count=1;
			int left_side = index-1;
			while(left_side>=0 && arr[left_side]==k){
				count++;
				left_side--;
			}
			int right_side=index+1;
			while(right_side<n && arr[right_side]==k){
				count++;
				right_side++;
			}
			out << k << " - " << count << endl;
		}
	t--;
	}
}

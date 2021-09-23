#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream in;
    in.open("input.txt");
    ofstream out;
    out.open("output.txt");
    int n,t;
    int arr[100];
    int flag;
    in >> t;
    int ifinal,jfinal,kfinal;
    while(t){
        in >> n;
        for(int i=0;i<n;i++){
            in >> arr[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n-i-1;j++){
                int sum=0;
                sum += arr[i] + arr[j];
                for(int k=0;k<n;k++){
                    if(sum==arr[k]){
                        ifinal=i+1;
                        jfinal=j+1;
                        kfinal=k+1;
                        flag=1;
                    }
                }
            }
        }
    t--;
    if(flag==1){

            out << ifinal << "," << jfinal << "," << kfinal << endl;
        }
    else{
    out << "No Sequence Found"<<endl;
    }
    }
}

#include<bits/stdc++.h>
using namespace std;

class Result{
    public:
        int min;
        int max;
};

Result getMinMax(int array[], int left, int right){
        Result r;
        if (left >= right){
            r.min = r.max = array[left];
        }else if(left+1==right){
            if(array[left]<array[right]){
                r.min = array[left];
                r.max = array[right];
            }else{
                r.min = array[right];
                r.max = array[left];
            }
        }else{
            int mid=(left+right)/2;

            Result task1 = getMinMax(array, left, mid);
            Result task2 = getMinMax(array, mid + 1, right);

            if(task1.max>task2.max){
                r.max = task1.max;
            }else{
                r.max = task2.max;
            }


            if(task1.min<task2.min){
                r.min = task1.min;
            }else{
                r.min = task2.min;
            }
        }

        return r;
}


int main(){
        int n;
        cin >> n;

        int array[n];
        for (int i = 0; i < n;i++){
            cin >> array[i];
        }

        Result r = getMinMax(array, 0, n - 1);

        cout << "Max: " << r.max<<endl;
        cout << "Min: " << r.min<<endl;
}
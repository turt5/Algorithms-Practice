#include<bits/stdc++.h>
using namespace std;

class Item{
    
    public:

    int weight;
    int profit;

    Item(int weight, int profit) : weight(weight), profit(profit) {}
};

bool comparator(Item a, Item b){
    return (double) a.profit / a.weight > (double) b.profit / b.weight;
}

double fractional_knapsack(vector<Item>items_list,int knapsack_size){
    int totalItems = items_list.size();

    sort(items_list.begin(), items_list.end(), comparator);
    
    int current_weight = 0; // current available weight in knapsack
    
    double finalProfit=0.0;

    for (int i = 0; i < totalItems;i++)
    {
        if(current_weight<=knapsack_size && current_weight+items_list.at(i).weight<=knapsack_size){
            current_weight += items_list.at(i).weight;
            cout << "Added profit: " << items_list.at(i).profit << endl;
            finalProfit += items_list.at(i).profit;
        }else{
            int remaining = knapsack_size - current_weight;
            // cout << remaining<<endl;
            double ppw =(double) items_list.at(i).profit / (double) items_list.at(i).weight;
            cout << "Added profit: " << remaining * ppw << endl;
            finalProfit += remaining * ppw;
            cout << "Knapsack is full now!" << endl;
            break;
        }
    }

    return finalProfit;
}



int main(){
    int n;
    cout << "How many items?" << endl;
    cin >> n;

    int size;
    cout << "Knapsack size?" << endl;
    cin >> size;

    vector<Item> items;
    // items.resize(n);

    cout << "Enter the values and the weights of the items: " << endl;
    for (int i = 0; i < n;i++){
        int weight;
        int value;
        cin >> value >> weight;

        items.push_back(Item(weight, value));
    }

    cout << "Maximum Profits can be earned: "<<fractional_knapsack(items,size) << endl;
}
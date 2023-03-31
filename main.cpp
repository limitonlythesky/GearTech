#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include "TestGenerator.h"

using namespace std;

int arr[100005], temp[100005];
vector <int> answer, a[1000], median;
vector <thread> threads;

void merge(int ind, int l, int mid, int r){
    int pos1 = l, pos2 = mid + 1;
    int pos3 = 0;
    while(pos1 <= mid && pos2 <= r){
        if (a[ind][pos1] <= a[ind][pos2]){
            temp[pos3++] = a[ind][pos1++];
        }
        else {
            temp[pos3++] = a[ind][pos2++];
        }
    }
    while (pos1 <= mid){
        temp[pos3++] = a[ind][pos1++];
    }
    while (pos2 <= r){
        temp[pos3++] = a[ind][pos2++];
    }
    for (int i = 0; i < pos3; ++i){
        a[ind][l + i] = temp[i];
    }
}

void msort(int i, int l, int r){
    int mid = (l + r) / 2;
    if (l < r){
        msort(i, l, mid);
        msort(i, mid + 1, r);
        merge(i, l, mid, r);
    }
}

int smaller_than(int ind, int target, int r){
    if(r <= 0) return -1;
    if (target > a[ind][r - 1]) return r - 1;
    int l = 0, ans = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[ind][mid] >= target){
            r = mid - 1;
        }else{
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}

int greater_than(int ind, int target, int r){
    int l = 0;
    int ans = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[ind][mid] <= target){
            l = mid + 1;
        }else{
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

void calculate(int i, int n){
    //cout << ind << endl;
    //cout << "R: " << a[i].size() - 1 << "\n";
    if(i == 0){
        int ind = smaller_than(i, median[i + 1], a[i].size() - 1);
        for(int j = 0; j <= ind; ++j){
            answer.push_back(a[i][j]);
        }
    }else if (i > 0 && i < n - 1){
        int ind = smaller_than(i, median[i + 1], a[i].size() - 1);
        for(int j = a[i].size() / 2; j <= ind; ++j){
            answer.push_back(a[i][j]);
        }
    }else{
        int ind = greater_than(n - 1, median[n - 2], a[n - 1].size() - 1);
        for(int j = ind; j < a[n - 1].size(); ++j){
            answer.push_back(a[n - 1][j]);
        }
    }
}


int main(){
    int n, m, tmp = 0, tmpsum = 0, cnt = 0;
    TestGenerator test;
    test.generateSize();
    test.generateN();
    test.generateArray();
    test.scanToFile();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    while(cin >> arr[tmp]){
        ++tmp;
        ++tmpsum;
    }
    int el_row = (tmpsum + n - 1) / n;
    m = n;
    for(int i = 0, j = 0; i < tmp; ++i){
        a[j].push_back(arr[i]);
        cnt++;
        if(cnt % el_row == 0){
            j++;
            cnt = 0;
            tmpsum -= el_row;
            m--;
            if(m != 0)
                el_row = (tmpsum + m - 1) / m;
        }
    }
    for(int i = 0; i < n; ++i){
        msort(i, 0, a[i].size() - 1);
        for(int j = 0; j < a[i].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    /*for(int i = 0; i < n; ++i){
        msort(i, 0, a[i].size() - 1);
    }*/
    for(int i = 0; i < n; ++i){
        if(a[i].size() % 2 == 0){
            median.push_back((a[i][a[i].size() / 2] + a[i][a[i].size() / 2 - 1]) / 2);
        }else{
            median.push_back(a[i][a[i].size() / 2]);
        }
    }
    cout << "Medians: \n";
    for(int i = 0; i < median.size(); ++i){
        cout << median[i] << "\n";
    }
    for(int i = 0; i < n; i++){
        thread t(calculate, i, n);
        threads.push_back(move(t));
    }
    for(auto &t: threads){
        t.join();
    }
    cout << "Answer: \n";
    for(int i = 0; i < answer.size(); ++i){
        cout << answer[i] << "\n";
    }
    return 0;
}


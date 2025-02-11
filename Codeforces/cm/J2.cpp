//    VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define vi vector<int>
#define fl(i,x,y) for(int i=x; i<y; i++)

int sum = 0, bottles = 0, temp_sum = 0, temp_soda = 0, Time = 999999;
bool allSame = true;

bool cmp(const pair<int,int> & a, const pair<int,int> & b){
    if(a.S > b.S) return 1;
    else if(a.S == b.S) return a.F > b.F;
    else return 0;
}

int min(int a, int b){
    if(a<b) return a;
    return b;
}
int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    vector< pair<int,int> > ab(n);
    vi arr(n,0);
    fl(i,0,n) {
        cin >> ab[i].F;
        sum += ab[i].F;
    }
    fl(i,0,n){
        cin >> ab[i].S;
        if(i>0){
            if(ab[i].S!=ab[i-1].S)
                allSame = false;
        }
    }
    sort(ab.begin(),ab.end(), cmp);
    while(temp_sum<sum){
        temp_sum += ab[bottles].S;
        bottles++;
    }
    fl(i,0,bottles){
        arr[i] = 1;
        temp_soda += ab[i].F;
    }
    Time = sum - temp_soda;
    int l,temp_vol;
    temp_vol = temp_sum;
    l = bottles-1;
    if(allSame){
        cout<<bottles<<" "<<Time<<endl;
        return 0;
    }
    while(1){
        fl(i,l+1,n){
            temp_vol += ab[i].S - ab[i-1].S;
            if(temp_vol<sum){
                l = i-1;
                temp_vol = temp_vol - ab[i].S + ab[i-1].S;
                break;
            }
            arr[i-1] = 0;
            arr[i] = 1;
            temp_soda += ab[i].F - ab[i-1].F;
            Time = min(Time,sum - temp_soda);
            if(i==n-1)  l = n-1;
        }
        int count = 0;
        while(arr[l]==1){
            count++;
            temp_soda -= ab[l].F;
            temp_vol -= ab[l].S;
            arr[l] = 0;
            l--;
        }
        if(count==bottles){
            if(temp_vol>=sum)
                Time = min(Time, sum - temp_soda);
            break;
        }
        for(int i=l; i>=0; i--){
            if(arr[i]==1){
                l = i;
                break;
            }
        }
        arr[l] = 0;
        arr[l+1] = 1;
        temp_soda += ab[l+1].F - ab[l].F;
        temp_vol += ab[l+1].S - ab[l].S;
        l++;
        if(temp_vol>=sum)
            Time = min(Time, sum - temp_soda);
        fl(i,0,count){
            l++;
            arr[l] = 1;
            temp_soda += ab[l].F;
            temp_vol += ab[l].S;
        }
        if(temp_vol>=sum)
            Time = min(Time, sum - temp_soda);
        // int breaker_count = 0;
        // for(int i=l; i>=0; i--){
        //     if(arr[i])  breaker_count++;
        //     else break;
        // }
        // if(breaker_count==bottles)
        //     break;
    }
    // int s=0;
    // fl(i,0,n)   {cout<<ab[i].F<<" ";s+=ab[i].F;}
    // cout<<endl;
    // fl(i,0,n)   cout<<ab[i].S<<" ";
    // cout<<endl;
    // cout<<s<<endl;
    cout<<bottles<<" "<<Time<<endl;

    return 0;
}

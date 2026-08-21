class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n=coins.size();
        long long left=1;
        long long right=(long long)k*(*min_element(coins.begin(),coins.end()));
        long long ans=right;
        while(left<=right){
            long long mid=left+(right-left)/2;
            long long count=0;
            for (int mask=1;mask<(1<<n);++mask){
                long long current_lcm=1;
                int bits=0;
                for (int i=0;i<n;++i){
                    if (mask&(1<<i)){
                        bits++;
                        current_lcm=std::lcm(current_lcm,coins[i]);
                        if (current_lcm>mid) break; 
                    }
                }
                if (current_lcm<=mid){
                    if (bits%2==1){
                        count+=mid/current_lcm;
                    }else{
                        count-=mid/current_lcm;
                    }
                }
            }
            if(count>=k){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
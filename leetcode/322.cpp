class Solution {
public:
    vector<int>memo;
    int coinChange(vector<int>& coins, int amount) {
        memo=vector<int>(amount+1,INT_MIN);
        memo[0]=0;
        for(int coin : coins){
            if(coin<amount){
                memo[coin]=1;
            }
        }
        
        return dp(amount,coins);
    }
    int dp(int amount,vector<int>& coins){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return -1;
        }
        if(memo[amount]!=INT_MIN){
            return memo[amount];
        }
        int ans=INT_MAX;
        for(int coin : coins){
            int sub=dp(amount-coin,coins);
            
            if(sub==-1){
                continue;
            }
            ans=min(ans,sub+1);
        }
        memo[amount] =(ans==INT_MAX?-1:ans);
        return memo[amount];
    }
};

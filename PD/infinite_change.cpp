/******O(MAX * coins.size())******/
int dp[MAX];

int change(int amount, vector<int>& coins) {
	memset(dp, 0, sizeof(dp));

	dp[0] = 1;
	for(int i = 0; i < coins.size(); i++) {
	    for(int j = coins[i]; j <= amount; j++) {
		dp[j] += dp[j - coins[i]];;
	    }
	}

	return dp[amount];
}

//amount = value of change;
//coins = coin values;

//change(amount, coins);

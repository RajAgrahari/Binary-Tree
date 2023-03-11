//https://practice.geeksforgeeks.org/problems/bbt-counter4914/1
long long int countBT(int h) { 
         int mod= 1e9+7;
       vector<long long int> bbt(h+1);
       bbt[0]=1;
       bbt[1]=1;
       for(int i=2;i<=h;i++){
           // difference can be 1 to height of left subtree and right subtree
           // can be i-1, i-1/ i-1, i-2/ i-2,i-1
           // multiplying all the counts from both side
           // adding all the cases
           bbt[i]= ((bbt[i-1]*bbt[i-1])%mod + (2*(bbt[i-1]*bbt[i-2]))%mod)%mod;
       }
       return bbt[h];
    }

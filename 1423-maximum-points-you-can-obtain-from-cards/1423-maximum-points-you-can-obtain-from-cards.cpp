class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int sum = 0;
        int n = points.size();
        k=n-k;

        for(int i=0;i<k;i++){
            sum+=points[i];
        }

        int l=0, r=k-1;
        int maxi=sum;

        while(r<n-1){
            r++;
            sum+=points[r];
            sum-=points[l];
            l++;
            maxi=min(sum,maxi);
        }

        sum=0;
        for(int i=0;i<n;i++){
            sum+=points[i];
        }

        return sum-maxi;
    }
};
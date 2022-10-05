class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
       priority_queue<pi> q;
        for(int i=0;i<arr.size();i++){
            if(q.size()<k){
                q.push({abs(arr[i]-x),arr[i]});
            }else if(q.size()>=k && q.top().first>abs(arr[i]-x)){
               q.pop();
                q.push({abs(arr[i]-x),arr[i]});
            }
        }
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

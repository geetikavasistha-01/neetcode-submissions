class Solution
{
    public:
    vector<int> topKFrequent(vector<int>&nums,int k )
    {
        int n= nums.size();
        unordered_map<int,int> mp;
        for(int num:nums)
        {
            mp[num]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto &it : mp)
        {
            int element =it.first;
            int freq=it.second;
            bucket[freq].push_back(element);
        }

        vector<int> result;
        for(int i = n; i>=0;--i)
        {
            if(bucket[i].size()==0)
            continue;
            while(bucket[i].size()>0 && k>0)
            {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};


































/*class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        //1. Map for storing frequency
        unordered_map<int,int> mp;
        for(int num : nums)
        {
            mp[num]++;
        }
        //2.Define min heap
        priority_queue< P,vector<P> , greater<P>> pq;

        //3. Push elements in min-heap 
        //maintains size of k only
        for(auto &it: mp)
        {
            int value=it.first;
            int freq=it.second;
            pq.push({freq,value});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<int> result;
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
    return result;
}
};*/

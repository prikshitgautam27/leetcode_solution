class Solution {
public:

    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();

        vector<int>first(26,n), last(26,-1);

        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            first[c]= min(first[c],i);
            last[c]= max(last[c],i);
        }

        vector<pair<int,int>>intervals;

        for(int c=0;c<26;c++){
            if(last[c]==-1) continue;
            int l=first[c], r=last[c];
            bool valid=true;

            for(int i=l;i<=r;i++){

                int d=s[i]-'a';
                if(first[d]<l) {
                    valid=false;
                    break;
                }
                r=max(r,last[d]);

            }
            if(valid){
                intervals.push_back({l,r});
            }
        }
// step 3 sorting for end intervals 
auto cmp = [&](pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
};
sort(intervals.begin(), intervals.end(),cmp);
// step 4 getting relevant interval excludign the overlaping one
vector<string>res;
int prev_end=-1;
for(auto it:intervals){
    if(it.first>prev_end){
        res.push_back(s.substr(it.first,it.second-it.first +1));
        prev_end=it.second;
    }
}

return res;
    }
};
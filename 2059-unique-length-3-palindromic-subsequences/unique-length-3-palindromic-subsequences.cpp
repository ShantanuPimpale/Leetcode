class Solution {
public:
   
    int countPalindromicSubsequence(string s) {
        set<string>st;
      map<char,vector<int>>mp;
      for(int i=0;i<s.size();i++){
        mp[s[i]].push_back(i);
      }  

      for(auto i:mp){
        int minIndex=*min_element(i.second.begin(),i.second.end());
        int maxIndex=*max_element(i.second.begin(),i.second.end());

        string temp="";
        for(int j=minIndex+1;j<maxIndex;j++){
            temp+=s[minIndex];
            temp+=s[j];
            temp+=s[maxIndex];
            st.insert(temp);
            temp="";
        }
      }
      return st.size();
}

};
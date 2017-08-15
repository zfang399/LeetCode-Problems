class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        if(!wordList.size()) return ans;
        int thresh=INT_MAX;
        queue<vector<string>> q;
        vector<string> nowWord;
        int l=beginWord.length(),pos=-1;
        queue<int> t;
        unordered_map<string,bool> visited;
        unordered_map<string,bool> tvisited;
        map<vector<string>,bool> kkk;
        map<string,vector<string>> go;
        for(int i=0;i<wordList.size();i++){
            int countd=0;
            for(int j=0;j<l;j++){
                if(wordList[i][j]!=beginWord[j]){
                    countd++;
                    if(countd>1) break;
                }
            }
            if(countd==1) go[beginWord].push_back(wordList[i]);

            int cound=0;
            for(int j=0;j<l;j++){
                if(wordList[i][j]!=endWord[j]){
                    countd++;
                    if(countd>1) break;
                }
            }
            if(countd==1) go[wordList[i]].push_back(endWord);
        }
        for(int i=0;i<wordList.size()-1;i++){
            for(int j=i+1;j<wordList.size();j++){
                int countd=0;
                for(int k=0;k<l;k++){
                    if(wordList[i][k]!=wordList[j][k]){
                        countd++;
                        if(countd>1) break;
                    }
                }
                if(countd==1){
                    go[wordList[i]].push_back(wordList[j]);
                    go[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        vector<string> x;
        x.push_back(beginWord);
        q.push(x);
        t.push(1);
        int nowNum=0;
        visited[beginWord]=true;
        for(int i=0;i<wordList.size();i++){
            if(endWord.compare(wordList[i])==0){
                pos=i;
                break;
            }
        }
        if(pos==-1) return ans;
        while(q.size()){
            if(t.front()>nowNum){
                for(auto e:tvisited){
                    visited[e.first]=true;
                }
                tvisited.erase(tvisited.begin(),tvisited.end());
            }
            nowWord=q.front();
            q.pop();
            nowNum=t.front();
            t.pop();
            if(nowNum>thresh) break;
            if(nowNum>wordList.size()) return ans;
            string xxx=nowWord.back();
            for(int i=0;i<go[xxx].size();i++){
                if(visited[go[xxx][i]]) continue;
                if(go[xxx][i]==wordList[pos]){
                    thresh=nowNum;
                    nowWord.push_back(go[xxx][i]);
                    if(!kkk[nowWord]){
                        ans.push_back(nowWord);
                        kkk[nowWord]=true;
                    }
                    break;
                }else{
                    nowWord.push_back(go[xxx][i]);
                    q.push(nowWord);
                    t.push(nowNum+1);
                    tvisited[go[xxx][i]]=true;
                    nowWord.pop_back();
                }
            }
            nowWord.erase(nowWord.begin(),nowWord.end());
        }
        return ans;
    }
};

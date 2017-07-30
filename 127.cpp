class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(!wordList.size()) return 0;
        queue<string> q;
        queue<int> t;
        unordered_map<string,bool> visited;
        q.push(beginWord);
        t.push(1);
        visited[beginWord]=true;
        int l=beginWord.length(),pos=-1;
        for(int i=0;i<wordList.size();i++){
            if(endWord.compare(wordList[i])==0){
                pos=i;
                break;
            }
        }
        if(pos==-1) return 0;
        while(q.size()){
            string nowWord=q.front();
            q.pop();
            int nowNum=t.front();
            t.pop();
            if(nowNum>wordList.size()) return 0;
            for(int i=0;i<wordList.size();i++){
                int countd=0;
                for(int j=0;j<l;j++){
                    if(wordList[i][j]!=nowWord[j]){
                        countd++;
                        if(countd>1) break;
                    }
                }
                if(countd==1){
                    if(i==pos) return nowNum+1;
                    if(!visited[wordList[i]]){
                        q.push(wordList[i]);
                        t.push(nowNum+1);
                        visited[wordList[i]]=true;
                    }
                }
            }
        }
        return 0;
    }
};

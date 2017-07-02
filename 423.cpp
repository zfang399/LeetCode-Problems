class Solution {
public:
    string originalDigits(string s) {
        unordered_map <char,int> count;
        int num[10]={0};
        string ans;
        for(int i=0;i<s.length();i++){
            count[s[i]]++;
        }
        if(count['z']){
            num[0]=count['z'];
            count['e']-=count['z'];
            count['r']-=count['z'];
            count['o']-=count['z'];
            count['z']=0;
        }
        if(count['w']){
            num[2]=count['w'];
            count['t']-=count['w'];
            count['o']-=count['w'];
            count['w']=0;
        }
        if(count['x']){
            num[6]=count['x'];
            count['s']-=count['x'];
            count['i']-=count['x'];
            count['x']=0;
        }
        if(count['u']){
            num[4]=count['u'];
            count['f']-=count['u'];
            count['o']-=count['u'];
            count['r']-=count['u'];
            count['u']=0;
        }
        if(count['f']){
            num[5]=count['f'];
            count['i']-=count['f'];
            count['v']-=count['f'];
            count['e']-=count['f'];
            count['f']=0;
        }
        if(count['v']){
            num[7]=count['v'];
            count['s']-=count['v'];
            count['e']-=2*count['v'];
            count['n']-=count['v'];
            count['v']=0;
        }
        if(count['g']){
            num[8]=count['g'];
            count['e']-=count['g'];
            count['i']-=count['g'];
            count['h']-=count['g'];
            count['t']-=count['g'];
            count['g']=0;
        }
        if(count['t']){
            num[3]=count['t'];
            count['h']-=count['t'];
            count['r']-=count['t'];
            count['e']-=2*count['t'];
        }
        if(count['o']){
            num[1]=count['o'];
            count['n']-=count['o'];
            count['e']-=count['o'];
        }
        if(count['i']){
            num[9]=count['i'];
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<num[i];j++){
                ans+=to_string(i);
            }
        }
        return ans;
    }
};

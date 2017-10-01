class Solution {
public:
    struct t{
        int hours;
        int mins;
        int diff;
    };
    static bool cmp(t a, t b){
        return a.diff<b.diff;
    }
    string nextClosestTime(string time) {
        vector<int> dig;
        vector<t> tt;
        int h=0,m=0,now=0;
        int count=0;
        bool f=false;
        for(int i=0;i<time.length();i++){
            if(!(time[i]==':')){
                count++;
                dig.push_back(time[i]-'0');
                now=now*10+(time[i]-'0');
                if(count==2 && !f){
                    f=true;
                    h=now;
                    now=0;
                    count=0;
                }
            }
        }
        m=now;
        cout<<h<<" "<<m<<endl;
        int tim=h*60+m;
        cout<<tim<<endl;
        for(int i=0;i<dig.size();i++){
            if(dig[i]>2) continue;
            for(int j=0;j<dig.size();j++){
                if(dig[i]==2 && dig[j]>3) continue;
                int hours=dig[i]*10+dig[j];
                for(int k=0;k<dig.size();k++){
                    if(dig[k]>5) continue;
                    for(int l=0;l<dig.size();l++){
                        if(dig[k]==6 && dig[l]!=0) continue;
                        int mins=dig[k]*10+dig[l];
                        t tmp;
                        tmp.hours=hours;
                        tmp.mins=mins;
                        int x=hours*60+mins;
                        if(x-tim>0){
                            tmp.diff=x-tim;
                        }else{
                            tmp.diff=x+1440-tim;
                        }
                        tt.push_back(tmp);
                        //cout<<hours<<" "<<mins<<" "<<tmp.diff<<endl;
                    }
                }
            }
        }
        sort(tt.begin(),tt.end(),cmp);
        string ho=to_string(tt[0].hours);
        if(ho.length()==1) ho="0"+ho;
        string mi=to_string(tt[0].mins);
        if(mi.length()==1) mi="0"+mi;
        return ho+":"+mi;
    }
};

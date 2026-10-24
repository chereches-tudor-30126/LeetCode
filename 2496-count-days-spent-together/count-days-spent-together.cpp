class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int p[12]={0,31,59,90,120,151,181,212,243,273,304,334};
        
        int a1=p[(arriveAlice[0]-'0')*10+(arriveAlice[1]-'0')-1]+(arriveAlice[3]-'0')*10+(arriveAlice[4]-'0');
        int l1=p[(leaveAlice[0]-'0')*10+(leaveAlice[1]-'0')-1]+(leaveAlice[3]-'0')*10+(leaveAlice[4]-'0');
        
        int a2=p[(arriveBob[0]-'0')*10+(arriveBob[1]-'0')-1]+(arriveBob[3]-'0')*10+(arriveBob[4]-'0');
        int l2=p[(leaveBob[0]-'0')*10+(leaveBob[1]-'0')-1]+(leaveBob[3]-'0')*10+(leaveBob[4]-'0');
        
        int st=max(a1,a2);
        int en=min(l1,l2);
        
        if(st<=en)return en-st+1;
        return 0;
    }
};
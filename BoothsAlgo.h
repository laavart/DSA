//
// Created by Oballium on 16-10-2021.
//

#ifndef DSA_BOOTHSALGO_H
#define DSA_BOOTHSALGO_H

class Booth{
    static string toBinaryString(int n){
        string b = "";
        while(n>0){
            b = to_string(n%2) + b;
            n/=2;
        }
        return b;
    }

    static int toValue(string s){
        int l = s.length()-1;
        int v=0;
        for(int i=1; l>=0; i*=2){
            v+=((s[l--]-48)*i);
        }
        return v;
    }

    static string find2sCompliment(string s){
        int l = s.length();
        for(int i=0; i<l; i++){
            if(s[i] == '0'){
                s[i] = '1';
            }
            else{
                s[i] = '0';
            }
        }
        return addBinaryString(s,"1");
    }

    static string addBinaryString(string s1, string s2){
        int l1 = s1.length();
        int l2 = s2.length();
        string s = "";

        if(l1>l2){
            for(int i=0; i<l1-l2; i++){
                s2 = "0" + s2;
            }
        }
        else{
            for(int i=0; i<l2-l1; i++){
                s1 = "0" + s1;
            }
        }

        string c = "0";
        for(int i = max(l1,l2)-1; i>=0; i--){
            if(c=="0"){
                if(s1[i]=='0' && s2[i]=='0'){
                    s = "0" + s;
                    c = "0";
                }
                else if(s1[i]=='1' && s2[i]=='1'){
                    s = "0" + s;
                    c = "1";
                }
                else{
                    s = "1" + s;
                    c = "0";
                }
            }
            else{
                if(s1[i]=='0' && s2[i]=='0'){
                    s = "1" + s;
                    c = "0";
                }
                else if(s1[i]=='1' && s2[i]=='1'){
                    s = "1" + s;
                    c = "1";
                }
                else{
                    s = "0" + s;
                    c = "1";
                }
            }
        }
        return s;
    }

    static int Algo(int A, int B){
        int nC;
        if(A>0 && B>0){
            nC = 0;
        }
        else if(A<0 && B<0){
            nC = 2;
        }
        else{
            nC = 1;
        }

        A = abs(A);
        B = abs(B);

        if(B > A){
            A = A ^ B;
            B = A ^ B;
            A = A ^ B;
        }

        string m = "0" + toBinaryString(A); int ml = m.length();

        string q = toBinaryString(B); int ql = q.length();
        for(int i=0; i<ml-ql; i++){
            q = "0" + q;
        }

        string a = "";
        for(int i=0; i<ml; i++){
            a = "0"+a;
        }

        string h = "0";
        for(int i=0; i<ml; i++){
            string t = q.substr(ml-1)+h;
            if(t == "01"){
                a = addBinaryString(a, m);
            }
            else if(t == "10"){
                a = addBinaryString(a, find2sCompliment(m));
            }
            h = q.substr(ml-1);
            q = a.substr(ml-1) + q.substr(0,ml-1);
            a = h + a.substr(a.length()-ml);
            a = a.substr(0,ml);
        }

        if(nC%2 == 0){
            return toValue(a+q);
        }
        else{
            return -1* toValue(a+q);
        }
    }
public:
    static void Test(){
        cout<<Algo(1234, -12345)<<endl;
    }
};

#endif //DSA_BOOTHSALGO_H

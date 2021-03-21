#include<bits/stdc++.h>
using namespace std;
string int_to_hex(int n)
{
    string result = "";
    if(n<0){
        n=n*(-1);
    }
    while (n > 0)
    {
        int rem = n % 16;
        n = n / 16;
        if (rem >= 0 && rem <= 9)
        {
            char x = (char)(rem + 48);
            result = x + result;
        }
        else
        {
            char x = 'A' + (rem - 10);
            result = x + result;
        }
    }
    return result;
}

int hex_to_int(string hexVal){
    int len = hexVal.length();  
    int base = 1; 
    int dec_val = 0; 
    for (int i=len-1; i>=0; i--) 
    {    
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            dec_val += (hexVal[i] - 48)*base; 
            base = base * 16; 
        } 
        else if (hexVal[i]>='A' && hexVal[i]<='F') 
        { 
            dec_val += (hexVal[i] - 55)*base;  
            base = base*16; 
        } 
    }  
    return dec_val;
}
string exact(string s,int k){
    if(k==4){
        int i=0;
        while(s[i]=='0'){
            i++;
        }
        return s.substr(i,s.length()-1);
    }
    if(k==6){
        int i=0;
        while(s[i]!=' '){
            i++;
        }
        return s.substr(0,i);
    }
    return " ";
}
int main(){
    string sect_adrr="4000";string sect_len="";
    map<string,string>estab;

    // Pass 1

    ifstream inputfile("input_loader.txt");
    string s;
    getline(inputfile,s);
    while(s!="END"){
        if(s[0]=='H'){
            sect_len=s.substr(s.length()-6,6);
            //cout<<sect_len<<"\n";
            string sect=s.substr(1,6);
            sect=exact(sect,6);
            if(estab.find(sect)==estab.end()){
                estab[sect]=sect_adrr;
            }
            while(s[0]!='E'){
                getline(inputfile,s);
                if(s[0]=='D'){
                    int k=s.length();
                    k=k-1;
                    
                    
                    for(int i=1;i<k;i+=12){
                        string str_name=s.substr(i,6);
                        //cout<<str_name<<"\n";
                        str_name=exact(str_name,6);
                        if(estab.find(str_name)==estab.end()){
                            string str_val=s.substr(i+6,6);
                            //cout<<str_val<<"\n";
                            str_val=int_to_hex(hex_to_int(str_val)+hex_to_int(sect_adrr));
                            //cout<<str_val<<"\n";
                            
                            estab[str_name]=str_val;
                        }
                    }   
                }
            }
            //cout<<sect_adrr<<"\n";
            sect_adrr=int_to_hex(hex_to_int(sect_adrr)+hex_to_int(sect_len));
            
            
            getline(inputfile,s);
            getline(inputfile,s);
        }

    }
    inputfile.close();
    ifstream input_file("input_loader.txt");
    getline(input_file,s);

    // Pass 2

    map<string,string>act_obj;
    map<string,string>rem;
    map<string,string>neg;
    sect_adrr="4000";
    while(s!="END"){
        if(s[0]=='H'){
            sect_len=s.substr(s.length()-6,6);
            while(s[0]!='E'){
                getline(input_file,s);
                if(s[0]=='T'){
                    int i=9;
                    string s_a=int_to_hex(hex_to_int(sect_adrr)+hex_to_int(s.substr(1,6)));
                    while(i<s.length()){
                        act_obj[s_a]=s.substr(i,2);
                        i+=2;
                        s_a=int_to_hex(hex_to_int(s_a)+1);
                    }
                }
                if(s[0]=='M'){
                    string s_a=int_to_hex(hex_to_int(sect_adrr)+hex_to_int(s.substr(1,6)));
                    if(s[9]=='+'){
                        string temp=act_obj[s_a]+act_obj[int_to_hex(hex_to_int(s_a)+1)]+act_obj[int_to_hex(hex_to_int(s_a)+2)];
                        if(rem[s_a]=="1000000"){
                            temp="1"+temp;
                        }
                        //cout<<temp<<"\n";
                        int k=hex_to_int(temp)+hex_to_int(estab[s.substr(10,s.length()-10)]);
                        if(neg[s_a]=="1"){
                            k=(hex_to_int(temp))*(-1)+hex_to_int(estab[s.substr(10,s.length()-10)]);
                            
                        }
                        if(k>0){
                            neg[s_a]="0";
                        }
                        else{
                            neg[s_a]="1";
                        }
                        temp=int_to_hex(k);

                        if(temp.length()==7){
                            rem[s_a]="1000000";
                            temp=temp.substr(1,6);
                        }
                        else{
                            rem[s_a]="0";
                        }
                        while(temp.length()<6){
                            temp="0"+temp;
                        }
                        
                        act_obj[s_a]=temp.substr(0,2);
                        act_obj[int_to_hex(hex_to_int(s_a)+1)]=temp.substr(2,2);
                        act_obj[int_to_hex(hex_to_int(s_a)+2)]=temp.substr(4,2);

                        
                    }
                    if(s[9]=='-'){
                        string temp=act_obj[s_a]+act_obj[int_to_hex(hex_to_int(s_a)+1)]+act_obj[int_to_hex(hex_to_int(s_a)+2)];
                        if(rem[s_a]=="1000000"){
                            temp="1"+temp;
                        }
                        //cout<<temp<<"\n";
                        int k=hex_to_int(temp)-hex_to_int(estab[s.substr(10,s.length()-10)]);
                        if(neg[s_a]=="1"){
                            k=(hex_to_int(temp))*(-1)-hex_to_int(estab[s.substr(10,s.length()-10)]);
                            
                        }
                        if(k>0){
                            neg[s_a]="0";
                        }
                        else{
                            neg[s_a]="1";
                        }
                        temp=int_to_hex(k);
                        if(temp.length()==7){
                            rem[s_a]="1000000";
                            temp=temp.substr(1,6);
                        }
                        else{
                            rem[s_a]="0";
                        }
                        while(temp.length()<6){
                            temp="0"+temp;
                        }
                    
                        act_obj[s_a]=temp.substr(0,2);
                        act_obj[int_to_hex(hex_to_int(s_a)+1)]=temp.substr(2,2);
                        act_obj[int_to_hex(hex_to_int(s_a)+2)]=temp.substr(4,2);
                        
                        
                    }

                }
            }
            sect_adrr=int_to_hex(hex_to_int(sect_adrr)+hex_to_int(sect_len));
            getline(input_file,s);
            getline(input_file,s);

        }   
    }
    
    ofstream outputfile("output_loader.txt");
    outputfile<<"\nMemory adress"<<"\t\t\t\t\t\t"<<"Contents"<<"\n\n";
    outputfile<<"\t0000"<<"\t\t\t\txxxxxxxx  xxxxxxxx  xxxxxxxx xxxxxxxx"<<"\n";
    outputfile<<"\t .  "<<"\t\t\t\t    .         .         .         ."<<"\n";
    outputfile<<"\t .  "<<"\t\t\t\t    .         .         .         ."<<"\n";
    outputfile<<"\t .  "<<"\t\t\t\t    .         .         .         ."<<"\n";
    outputfile<<"\t3FF0"<<"\t\t\t\txxxxxxxx  xxxxxxxx  xxxxxxxx xxxxxxxx"<<"\n";
    string add="4000";
    for(int i=0;i<22;i++){
        outputfile<<"\t"<<add<<"\t\t\t\t";
        for(int j=0;j<16;j++){
            if(hex_to_int(add)>hex_to_int("4132")){
                outputfile<<"xx";
            }
            else if(act_obj.find(add)==act_obj.end()){
                outputfile<<"..";   
            }
            else{
                outputfile<<act_obj[add];
            }
            if(j%4==3){
                outputfile<<"  ";
            }
            add=int_to_hex(hex_to_int(add)+1);
        }
        outputfile<<"\n";
    }



}
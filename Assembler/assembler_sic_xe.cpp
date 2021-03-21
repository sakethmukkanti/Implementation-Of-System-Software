#include<bits/stdc++.h>
using namespace std;
void fill(unordered_map<string,pair<string,int>>&op_tab){
    op_tab["LDA"]={"00",3};op_tab["STCH"]={"54",3};  op_tab["J"]={"3C",3};   op_tab["TD"]={"E0",3};
    op_tab["LDX"]={"04",3};op_tab["ADD"]={"18",3};   op_tab["JLT"]={"38",3}; op_tab["RD"]={"D8",3};
    op_tab["LDB"]={"68",3};op_tab["SUB"]={"1C",3};   op_tab["JEQ"]={"30",3}; op_tab["WD"]={"DC",3};
    op_tab["LDT"]={"74",3};op_tab["MUL"]={"20",3};   op_tab["JGT"]={"34",3}; op_tab["LDL"]={"08",3};
    op_tab["STA"]={"0C",3};op_tab["DIV"]={"24",3};   op_tab["JSUB"]={"48",3};
    op_tab["STX"]={"10",3};op_tab["COMP"]={"28",3};  op_tab["RSUB"]={"4C",3};
    op_tab["STL"]={"14",3};op_tab["COMPR"]={"A0",2}; op_tab["TIX"]={"2C",3}; 
    op_tab["LDCH"]={"50",3};op_tab["CLEAR"]={"B4",2};op_tab["TIXR"]={"B8",2};
    
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
string int_to_hex(int n)
{
    string result = "";
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
string HexToBin(string hexdec)
{
	long int i = 0;
    string res="";

	while (hexdec[i]) {

		switch (hexdec[i]) {
		case '0':
			res+="0000";
			break;
		case '1':
			res+="0001";
			break;
		case '2':
			res+="0010";
			break;
		case '3':
			res+="0011";
			break;
		case '4':
			res+="0100";
			break;
		case '5':
			res+="0101";
			break;
		case '6':
			res+="0110";
			break;
		case '7':
			res+="0111";
			break;
		case '8':
			res+="1000";
			break;
		case '9':
			res+="1001";
			break;
		case 'A':
		case 'a':
			res+="1010";
			break;
		case 'B':
		case 'b':
			res+="1011";
			break;
		case 'C':
		case 'c':
			res+="1100";
			break;
		case 'D':
		case 'd':
			res+="1101";
			break;
		case 'E':
		case 'e':
			res+="1110";
			break;
		case 'F':
		case 'f':
			res+="1111";
			break;
			
		}
		i++;
	}
    return res;
}
string bToHexaDecimal(string s)
{
	int len = s.length(), check = 0;
	int num = 0, sum = 0, mul = 1;
	vector<char> ans;
    string res="";

	// Iterating through
	// the bits backwards
	for (int i = len - 1; i >= 0; i--) {
		sum += (s[i] - '0') * mul;
		mul *= 2;
		check++;

		// Computing the HexaDecimal
		// Number formed so far
		// and storing it in a vector.
		if (check == 4 || i == 0) {
			if (sum <= 9)
				ans.push_back(sum + '0');
			else
				ans.push_back(sum + 55);

			// Reinitializing all
			// variables for next group.
			check = 0;
			sum = 0;
			mul = 1;
		}
	}

	len = ans.size();

	// Printing the Hexadecimal
	// number formed so far.
	for (int i = len - 1; i >= 0; i--){
		string s(1,ans[i]);
        res+=s;
    }
    return res;
}

void split(vector<string>&t,string l){
    istringstream sss(l);
    string sub;
    t.clear();
    while(sss>>sub){
        t.push_back(sub);
    }
    int k=t.size();
    string a="";string b="";string c="";
    if(k==2){
        if(t[1]=="CSECT"){
            t.push_back("");
            return;
        }
        b=t[0];c=t[1];
        t[0]=a;t[1]=b;
        t.push_back(c);
    }
    if(k==1){
        b=t[0];
        t[0]=a;t[1]=b;t[2]=c;
    }
    
}
void split2(vector<string>&t,string l){
    istringstream sss(l);
    string sub;
    t.clear();
    while(sss>>sub){
        t.push_back(sub);
    }
    int k=t.size();
    string a="";string b="";string c="";string d="";
    if(k==3){
        if(t[2]=="CSECT"){
            t.push_back("");
            return;
        }
        c=t[1];d=t[2];
        t[1]=b;t[2]=c;
        t.push_back(d);
    }
    if(k==2){
        if(t[0]=="END" || t[0]=="EXTDEF" || t[0]=="EXTREF"){
            c=t[0];d=t[1];
            t[0]=a;
            t[1]=b;t.push_back(c);t.push_back(d);
            return;
        }
        c=t[1];
        t[1]=b;t.push_back(c);t.push_back(d);
    }
    if(k==1){
        c=t[0];
        t[0]=a;t.push_back(b);t.push_back(c);t.push_back(d);
    }
    

}
string find_obj_code(unordered_map<string,pair<string,int>>&op_tab,unordered_map<string,string>&sym_tab,vector<string>&temp,set<string>&ref_var,int pc,unordered_map<string,pair<string,int>>&lit_tab,vector<string>&mod_rec){
    string a=temp[2];string oper=temp[3];
    string n,i,x,b,p,e;
    string res="";
    //cout<<temp[3]<<"\n";
    n="1";i="1";x="0";b="0";p="0";e="0";
    if(a=="CLEAR" || a=="TIXR"){
        res+=op_tab[a].first;
        res+=sym_tab[oper];
        res+="0";
        //cout<<res<<"\n";
        return res;
    }
    if(a=="COMPR"){
        string c,d;
        int i;
        for(i=0;i<oper.size();i++){
            if(oper[i]==','){
                break;
            }
        }
        res+=op_tab[a].first;
        res+=sym_tab[oper.substr(0,i)];
        res+=sym_tab[oper.substr(i+1,oper.length()-i-1)];
        return res;
    }
    
    if(temp[2].length()>0 && temp[2][0]=='+'){
        //cout<<"5";
        e="1";
        a=a.substr(1,a.length()-1);
        a=op_tab[a].first;
    }
    if(temp[3].length()>2 && temp[3][temp[3].length()-2]==','){
        x="1";
        oper=oper.substr(0,oper.length()-2);
    }
    if(temp[3].length()>0 && temp[3][0]=='='){
        
        p="1";
        a=op_tab[a].first;
        oper=int_to_hex(hex_to_int(lit_tab[temp[3]].first)-pc);
        while(oper.length()<3){
            oper="0"+oper;
        }
        a= HexToBin(a);
        a=a.substr(0,6);
        res=a+n+i+x+b+p+e;
        res+=HexToBin(oper);
        res=bToHexaDecimal(res);
        //cout<<res<<"\n";
        return res;

    }
    if(temp[3].length()>0 && temp[3][0]=='@'){
        i="0";
        a=op_tab[a].first;
        oper=oper.substr(1,oper.length()-1);
    }
    if(temp[3].length()>0 && temp[3][0]=='#'){
        a=op_tab[a].first;
        n="0";
    }
    if(n=="1" && i=="1" && e!="1"){
        a=op_tab[a].first;   
    }
    if(ref_var.find(oper)!=ref_var.end()){
        string k="";
        k=int_to_hex(hex_to_int(temp[0])+1);
        while(k.size()<6){
            k="0"+k;
        }
        k+="05";
        k+="+";
        k+=oper;
        k="M"+k;
        mod_rec.push_back(k);
        if(e=="1"){
            oper="00000";
        }
        else{
            oper="000";
        }
    }
    
    else if(sym_tab.find(oper)!=sym_tab.end()){
        
            oper=sym_tab[oper];
        
        if(e=="1"){
            while(oper.length()<5){
                oper="0"+oper;
            }
        }
        else{
            while(oper.length()<3){
                oper="0"+oper;
            }
        }
    }
    else{
        oper=oper.substr(1,oper.length()-1);
        while(oper.length()<3){
            oper="0"+oper;
        }
    }
    a= HexToBin(a);
    a=a.substr(0,6);
    
    if(e=="1"){
        res=a+n+i+x+b+p+e;
        res+=HexToBin(oper);
        res=bToHexaDecimal(res);
        //cout<<res<<"\n";
        return res;
    }
    if(n=="0" && i=="1"){
        //cout<<a<<"\n";
        res=a+n+i+x+b+p+e;
        cout<<oper<<"\n";
        res+=HexToBin(oper);
        res=bToHexaDecimal(res);
        return res;
    }
    if(n=="1" && i=="0"){
        //cout<<5;
        res=a+n+i+x+b+"1"+e;
        string k=int_to_hex(hex_to_int(oper)-pc);
        while(k.length()<3){
            k="0"+k;
        }
        res+=HexToBin(k);
        res=bToHexaDecimal(res);
        return res;
    }
    if(n=="1" && i=="1"){
        p="1";
        res=a+n+i+x+b+p+e;
        int h=hex_to_int(oper)-pc;
        
        if(h<0){
            h+=4096;
        }
        string k=int_to_hex(h);
        if(k.length()>3){
            k=k.substr(k.length()-3,3);
        }
        while(k.length()<3){
            k="0"+k;
        }
        res+=HexToBin(k);
        res=bToHexaDecimal(res);
        
        return res;

    }
    return res;

    

}
int main(){
    unordered_map<string,pair<string,int>>op_tab;
    unordered_map<string,string>sym_tab;
    unordered_map<string,pair<string,int>>lit_tab;
    vector<string>prog_len;
    set<string>ref_var;
    vector<string>mod_rec;
    fill(op_tab);
    sym_tab["X"]="1";sym_tab["A"]="0";sym_tab["S"]="4";sym_tab["T"]="5";
    vector<string>temp;
    string l;
    ifstream input_file("input_assembler_sic_xe.txt");
    ofstream inter_file("intermediate.txt");
    getline(input_file,l);
    split(temp,l);
    //cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2];
    int locctr=0;
    if(temp[1]=="START"){
        string k=int_to_hex(locctr);
            while(k.length()<4){
                k="0"+k;
            }
        inter_file<<k<<"\t"<<l<<"\n";
        getline(input_file,l);
        split(temp,l);
    }
    while(temp[1]!="END"){
        if(temp[1]=="." || temp[0]=="."){
            inter_file<<"\t"<<l<<"\n";
        }
        else if(temp[1]=="EXTDEF" || temp[1]=="EXTREF"){
            inter_file<<"\t\t"<<l<<"\n";
        }
        else if(temp[1]=="CSECT"){
            prog_len.push_back(int_to_hex(locctr));
            locctr=0;
            string k=int_to_hex(locctr);
            while(k.length()<4){
                k="0"+k;
            }
            inter_file<<k<<"\t"<<l<<"\n";
        }
        else if(temp.size()==0){
            inter_file<<"\n";
        }
        else if(temp[1]=="LTORG"){
            
            inter_file<<"\t\t"<<l<<"\n";
            for(auto it:lit_tab){
                if(it.second.first==""){
                    string k=int_to_hex(locctr);
                    lit_tab[it.first]={k,it.second.second};
                    while(k.length()<4){
                        k="0"+k;
                    }
                    inter_file<<k<<"\t"<<"*"<<"\t\t"<<it.first<<"\n";
                    locctr+=it.second.second;
                }
            }

        }
        else{
            string k=int_to_hex(locctr);
            while(k.length()<4){
                k="0"+k;
            }
            inter_file<<k<<"\t"<<l<<"\n";
            if(temp[0]!="" && sym_tab.find(temp[0])==sym_tab.end()){
                if(temp[2][0]=='=' ){
                    if( lit_tab.find(temp[2])==lit_tab.end()){
                        int g=0;
                        if(temp[2][1]=='X'){
                            g=(temp[2].length()-4)/2;
                        }
                        else if(temp[2][1]=='C'){
                            g=(temp[2].length()-4);
                        }
                        lit_tab[temp[2]]={"",g};
                    }
                }
                sym_tab[temp[0]]=int_to_hex(locctr);
            } 
            else if(temp[0]!=""){
                sym_tab[temp[0]]=int_to_hex(locctr);
            }
            if(temp[1][0]=='+'){
                locctr++;
                temp[1]=temp[1].substr(1,temp[1].size()-1);
            }
            if(op_tab.find(temp[1])!=op_tab.end()){

                locctr+=op_tab[temp[1]].second;
            }          
            else if(temp[1]=="WORD"){
                locctr+=3;
            }
            else if(temp[1]=="RESW"){
                locctr+=(3*stoi(temp[2]));
            }
            else if(temp[1]=="RESB"){
                locctr+=(stoi(temp[2]));
            }
            else if(temp[1]=="BYTE"){
                if(temp[2][0]=='X'){
                    locctr+=(temp[2].length()-3)/2;
                }
                else if(temp[2][0]=='C'){
                    locctr+=(temp[2].length()-3);
                }
            }

        }
        getline(input_file,l);
        split(temp,l);
    }
    inter_file<<"\t\t"<<l<<"\n";
    for(auto it:lit_tab){
        if(it.second.first==""){
            string k=int_to_hex(locctr);
            lit_tab[it.first]={k,it.second.second};
            while(k.length()<4){
                k="0"+k;
            }
            inter_file<<k<<"\t"<<"*"<<"\t\t"<<it.first<<"\n";
            locctr+=it.second.second;
        }
    }
    prog_len.push_back(int_to_hex(locctr));
    input_file.close();
    inter_file.close();


    ifstream interfile("intermediate.txt");
    ofstream outputfile("output.txt");
    getline(interfile,l);
    split2(temp,l);
    //cout<<temp[0]<<" "<<temp[1]<<" "<<temp[2]<<" "<<temp[3];
    //cout<<prog_len[0]<<" "<<prog_len[1]<<" "<<prog_len[2];
    int prog_c=0;
    string rec="";
    string rec_st="000000";
    string rec_len="";
    string obj_code="";
    if(temp[2]=="START"){
        while(temp[3].length()<6){
            temp[3]="0"+temp[3];
        }
        while(prog_len[prog_c].length()<6){
            prog_len[prog_c]="0"+prog_len[prog_c];
        }
        while(temp[1].length()<6){
            temp[1]=temp[1]+" ";
        }
        outputfile<<"H"<<temp[1]<<temp[3]<<prog_len[prog_c]<<"\n";
        prog_c++;
        getline(interfile,l);
        split2(temp,l);
    }
    while(temp[2]!="END"){
        obj_code="";
        if(temp[2]=="."|| temp[0]=="."){
            getline(interfile,l);
            split2(temp,l);
            continue;
        }
        else if(temp.size()==0){
            getline(interfile,l);
            split2(temp,l);
            continue;    
        }
        else if(temp[2]=="EXTREF"){
            outputfile<<"R";
            string k=temp[3];
            int st=0;
            for(int i=0;i<k.length();i++){
                if(k[i]==','){
                    string p=k.substr(st,i-st);
                    ref_var.insert(p);
                    while(p.length()<6){
                        p+=" ";
                    }
                    outputfile<<p;
                    st=i+1;
                }
            }
            string p=k.substr(st,k.length()-st);
            ref_var.insert(p);
            while(p.length()<6){
                p+=" ";
            }
            outputfile<<p<<"\n";
            getline(interfile,l);
            split2(temp,l);
            continue;
        }
        else if(temp[2]=="EXTDEF"){
            outputfile<<"D";
            string k=temp[3];
            int st=0;
            for(int i=0;i<k.length();i++){
                if(k[i]==','){
                    string p=k.substr(st,i-st);
                    string y=sym_tab[p];
                    while(p.length()<6){
                        p+=" ";
                    }
                    while(y.length()<6){
                        y="0"+y;
                    }
                    outputfile<<p<<y;
                    st=i+1;
                }
            }
            string p=k.substr(st,k.length()-st);
            string y=sym_tab[p];
            while(p.length()<6){
                p+=" ";
            }
            while(y.length()<6){
                y="0"+y;
            }
            outputfile<<p<<y<<"\n";
            getline(interfile,l);
            split2(temp,l);
            continue;

        }
        else if(temp[2]=="CSECT"){
            //cout<<5;
            if(rec.length()>0){
                outputfile<<"T"<<rec_st;
                //cout<<rec_st<<"\n";
                rec_len=int_to_hex(rec.length()/2);
                while(rec_len.length()<2){
                    rec_len="0"+rec_len;
                }
                outputfile<<rec_len<<rec<<"\n";
               
            }
            for(int i=0;i<mod_rec.size();i++){
                outputfile<<mod_rec[i]<<"\n";
            }
            mod_rec.clear();
            rec="";
            rec_st="000000";
            //cout<<rec_st<<"\n";
            ref_var.clear();
            while(temp[3].length()<6){
                temp[3]="0"+temp[3];
            }
            while(prog_len[prog_c].length()<6){
                prog_len[prog_c]="0"+prog_len[prog_c];
            }
            while(temp[1].length()<6){
                temp[1]=temp[1]+" ";
            }
            outputfile<<"\n"<<"H"<<temp[1]<<temp[3]<<prog_len[prog_c]<<"\n";
            prog_c++;   
            getline(interfile,l);
            split2(temp,l);
            continue;
        }
        else if(temp[2]=="EQU"){
            getline(interfile,l);
            split2(temp,l);
            continue;    
        }
        else if(temp[2]=="RESW" || temp[2]=="RESB"  ){
            if(rec.length()>0){
                outputfile<<"T"<<rec_st;
                rec_len=int_to_hex(rec.length()/2);
                while(rec_len.length()<2){
                    rec_len="0"+rec_len;
                }
                outputfile<<rec_len<<rec<<"\n";
                rec="";
                rec_st="";
            }
            getline(interfile,l);
            split2(temp,l);
            continue;
        }
        else if(temp[2]=="BYTE"){
            if(temp[3][0]=='X'){
                obj_code=temp[3].substr(2,temp[3].length()-3);
            }
            else if(temp[3][0]=='C'){
                for(int i=2;i<temp[3].length()-1;i++){
                    obj_code+=int_to_hex(temp[3][i]);
                }
            }
        }
        else if(temp[2]=="WORD"){
            string k=temp[3];
            string t=temp[0];
            while(t.length()<6){
                t="0"+t;
            }
            t="M"+t;
            t+="06";
            string j=t+"+";
            int st=0;
            for(int i=0;i<k.size();i++){
                if(k[i]=='+'){
                    mod_rec.push_back(j+k.substr(st,i-st));
                    j=t+"+";
                    st=i+1;
                }
                else if(k[i]=='-'){
                    mod_rec.push_back(j+k.substr(st,i-st));
                    j=t+"-";
                    st=i+1;
                }
            }
            mod_rec.push_back(j+k.substr(st,k.length()-st));
            obj_code="000000";
            //cout<<temp[0]<<"\n";
        }
        else if(temp[2]=="RSUB"){
            obj_code="4F0000";
        }
        else if(temp[2]=="LTORG"){

        }
        else if(temp[2]=="*"){
            if(temp[3][1]=='X'){
                obj_code=temp[3].substr(3,temp[3].length()-4);
            }
            else if(temp[3][1]=='C'){
                for(int i=3;i<temp[3].length()-1;i++){
                    obj_code+=int_to_hex(temp[3][i]);
                }
            }   
        }
        else{
            obj_code= find_obj_code(op_tab,sym_tab,temp,ref_var,hex_to_int(temp[0])+op_tab[temp[2]].second,lit_tab,mod_rec);
        }
        if(rec.length()+obj_code.length()>60){
            outputfile<<"T"<<rec_st;
            rec_len=int_to_hex(rec.length()/2);
            while(rec_len.size()<2){
                rec_len="0"+rec_len;
            }
            outputfile<<rec_len<<rec<<"\n";
            rec=obj_code;
            rec_st=temp[0];
            while(rec_st.length()<6){
                rec_st="0"+rec_st;
            }
        }
        else if(obj_code.length()!=0){
            rec+=obj_code;
            if(rec_st==""){
                rec_st=temp[0];
                
                while(rec_st.length()<6){
                    rec_st="0"+rec_st;
                }
                
            }
            //cout<<obj_code<<"\n";
              //  cout<<rec_st<<"\n";
        }
        
        getline(interfile,l);
        split2(temp,l);
    }
    //cout<<sym_tab["INPUT"];
    getline(interfile,l);
    split2(temp,l);
    while(temp.size()!=0){

            if(temp[3][1]=='X'){
                obj_code=temp[3].substr(3,temp[3].length()-4);
                cout<<obj_code<<"\n";
            }
            else if(temp[3][1]=='C'){
                for(int i=3;i<temp[3].length()-1;i++){
                    obj_code+=int_to_hex(temp[3][i]);
                }
            }  

        if(rec.length()+obj_code.length()>60){
            outputfile<<"T"<<rec_st;
            rec_len=int_to_hex(rec.length()/2);
            while(rec_len.size()<2){
                rec_len="0"+rec_len;
            }
            outputfile<<rec_len<<rec<<"\n";
            rec=obj_code;
            rec_st=temp[0];
            while(rec_st.length()<6){
                rec_st="0"+rec_st;
            }
        }
        else if(obj_code.length()!=0){
            rec+=obj_code;
            if(rec_st==""){
                rec_st=temp[0];
                
                while(rec_st.length()<6){
                    rec_st="0"+rec_st;
                }
                
            }
            
        }
        
        getline(interfile,l);
        split2(temp,l);
    }
    outputfile<<"T"<<rec_st;
    rec_len=int_to_hex(rec.length()/2);
    while(rec_len.size()<2){
        rec_len="0"+rec_len;
    }
    outputfile<<rec_len<<rec<<"\n";
    for(int i=0;i<mod_rec.size();i++){
        outputfile<<mod_rec[i]<<"\n";
    }



}
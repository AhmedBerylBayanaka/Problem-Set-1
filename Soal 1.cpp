#include <iostream>

#include <stack>

using namespace std;



string check(string R){
    stack <char> c; //closed bracket
    stack <char> o; //open bracket
    stack <char> kc; //closed square bracket
    stack <char> ko; //open square bracket
	stack <char> cc; //close curly bracket
	stack <char> co; //open culry bracket
    stack <string> b; //begin
    stack <string> e; //end
	stack <string> bo; //komen open
	stack <string> bc; //komen close

    char x = ';'; 
    char y = ';';
    char a = ';'; 
    char d = ';';
	char g = '1';
	char j = '2';

	string t = "ente";
	string u = "preman brengsek";
    string q = "apa"; 
    string w = "apa";

    for (int i = 0; i < R.length(); i++){
        if(R[i] == ' ' || R[i] == ',') //kalau ada spasi atau tanda koma, di skip aja
            continue;
        
        if(R[i] == '('){
            o.push(y);
        }
        else if (R[i] == ')'){
            c.push(x);
        }
        else if(R[i] == '['){
            ko.push(a);
        }
        else if (R[i] == ']'){
            kc.push(d);
        }
        else if(R[i] == 'b' && R[i+1] == 'e' && R[i+2] == 'g' && R[i+3] == 'i'  && R[i+4] == 'n'){
            b.push(q);
        }
        else if(R[i] == 'e' && R[i+1] == 'n' && R[i+2] == 'd' ){
            e.push(w);
        }
		else if(R[i] == '{'){
			co.push(g);
		}else if(R[i] == '}'){
			cc.push(j);
		}else if(R[i] == '/' && R[i+1] == '*'){
			bo.push(t);
		}else if(R[i] == '*' && R[i+1] == '/'){
			bc.push(u);
		}
    }

	
    if (o.size() == c.size() && ko.size() == kc.size() && b.size() == e.size())
        return "balanced";

    if(o.size() <= c.size())
        return "wadoo, kurang nih open bracket nya";
    if(o.size() >= c.size())
        return "wadoo, kurang nih closed bracket nya";
    
    if(ko.size() <= kc.size())
        return "wadoo, kurang nih open bracket kotak nya";
    if(ko.size() >= kc.size())
        return "wadoo, kurang nih closed bracket kotak nya";
	
	if(bo.size() <= bc.size())
		return "kurang tuch /* nya";
	if(bo.size() >= bc.size())
		return "kurang tuch */ nya";

	if(cc.size() <= co.size())
		return "kurang tuh } nya";
	if(co.size() <= cc.size())
		return "kurang tuh { nya";
    
    if(b.size() <= e.size() && o.size() == c.size() && ko.size() == kc.size())
        return "wadoo, kurang nih begin-nya";
    if(b.size() >= e.size() && o.size() == c.size() && ko.size() == kc.size())
        return "wadoo, kurang nih end nya";
	
}
    /*for(int i = 0 ; i < R.length() ; i++){
        if(R[i] == ' ' || R[i] == ',') //kalau ada spasi atau tanda koma, di skip aja
            continue;
        
        if(isdigit(R[i]) == false){ // kalau angkanya bukan digit, simpen ke stack
            x = R[i];
            c.push(x);
        }
    }*/   



int main(){

    string R = "begin end () [] ][ {}";
    cout << check(R);
    return 0;
}
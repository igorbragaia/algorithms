string spaces(int count){
    string response="";
    for(int i=0;i<count;i++)    
        response += '\t';
    return response;
}

vector<string> Solution::prettyJSON(string A) {
    vector<string>answer;
    int count=0;
    string current="";
    for(int i=0;i<(int)A.size();i++){
        char c = A[i];
        
        if(c == ' '){
            
        } else if(c == '{' or c == '['){
            if(current != ""){
                answer.push_back(spaces(count)+current);
                current="";
            }    
            answer.push_back(spaces(count)+(c=='{'?"{":"["));
            count++;
        } else if(c == '}' or c==']'){
            if(current != ""){
                answer.push_back(spaces(count)+current);
                current="";
            }
            count--;
            if(i!=(int)A.size()-1 and A[i+1]==','){
                answer.push_back(spaces(count)+(c=='}'?"}":"]")+",");
                i++;
            } else
                answer.push_back(spaces(count)+(c=='}'?"}":"]"));
        } else if(c == ','){
            current+=c;
            answer.push_back(spaces(count)+current);
            current="";
        } else {
            current+=c;
        }
    }

    return answer;
}

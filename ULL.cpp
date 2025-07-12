#include "ULL.h"

Ull Ull::subtract(Ull num){
    Ull temp(this->val);
    Ull ans;
    int i=temp.val.size()-1,j=num.val.size()-1;
    while(j>=0){
        if(temp.val[i]-'0'>=num.val[j]-'0'){
            ans.val.push_back(temp.val[i]-num.val[j]+'0');
        }
        else{
            int k=i-1;
            while(temp.val[k]=='0'){
                temp.val[k]='9';
                k--;
            }
            temp.val[k]=char(temp.val[k]-1);
            ans.val.push_back((10+(temp.val[i]-'0')-(num.val[j]-'0'))+'0');
        }
        j--;
        i--;
    }
    while(i>=0){
        ans.val.push_back(temp.val[i]);
        i--;
    }
    int idx=ans.val.size()-1;
    while(idx>0 && ans.val[idx]=='0') idx--;
    ans.val=ans.val.substr(0,idx+1);
    reverse(ans.val.begin(),ans.val.end());
    return ans;
}

Ull Ull::add(Ull num){
    Ull ans;
    int n=num.val.size(),m=this->val.size(),j=n-1,i=m-1,c=0;
    while(i>=0 && j>=0){
        if((num.val[j]-'0')+(this->val[i]-'0')+c>9){
            ans.val.push_back(((num.val[j]-'0')+(this->val[i]-'0')+c)%10+'0');
            c=1;
        }
        else{
            ans.val.push_back((num.val[j]-'0')+(this->val[i]-'0')+c+'0');
            c=0;
        }
        i--;
        j--;
    }
    while(i>=0){
        if((this->val[i]-'0')+c>9){
            ans.val.push_back(((this->val[i]-'0')+c)%10+'0');
            c=1;
        }
        else{
            ans.val.push_back((this->val[i]-'0'+c)+'0');
            c=0;
        }
        i--;
    }
    while(j>=0){
        if((num.val[j]-'0')+c>9){
            ans.val.push_back(((num.val[j]-'0')+c)%10+'0');
            c=1;
        }
        else{
            ans.val.push_back((num.val[j]-'0'+c)+'0');
            c=0;
        }
        j--;
    }
    if(c) ans.val.push_back('1');
    reverse(ans.val.begin(),ans.val.end());
    return ans;
}

bool Ull::is_greater(Ull num){
    if(num.val.size()!=this->val.size()) return this->val.size()>num.val.size();
    int i=0,n=num.val.size()-1;
    while(i<n && num.val[i]==this->val[i]) i++;
    return this->val[i]>num.val[i];
}

bool Ull::is_lesser(Ull num){
    if(num.val.size()!=this->val.size()) return this->val.size()<num.val.size();
    int i=0,n=num.val.size()-1;
    while(i<n && num.val[i]==this->val[i]) i++;
    return this->val[i]<num.val[i];
}

bool Ull::is_greater_or_equal(Ull num){
    if(num.val.size()!=this->val.size()) return this->val.size()>num.val.size();
    int i=0,n=num.val.size()-1;
    while(i<n && num.val[i]==this->val[i]) i++;
    return this->val[i]>=num.val[i];
}

bool Ull::is_lesser_or_equal(Ull num){
    if(num.val.size()!=this->val.size()) return this->val.size()<num.val.size();
    int i=0,n=num.val.size()-1;
    while(i<n && num.val[i]==this->val[i]) i++;
    return this->val[i]<=num.val[i];
}

Ull::Ull(){
    is_negative = 0;
}

Ull::Ull(std::string str){
    this->is_negative=0;
    if(str[0]=='-'){
        str=str.substr(1);
        this->is_negative=1;
    }
    if(str[0]=='+') str=str.substr(1);
    int cnt=0;
    for(int i=0;i<str.size();i++){
        if(str[i]!='0') break;
        cnt++;
    }
    if(cnt==str.size()) this->val="0";
    else this->val=str.substr(cnt);
}

void Ull::print(){
    if(this->val=="0") std::cout<<"0";
    else if(this->is_negative) std::cout<<"-"<<this->val;
    else std::cout<<this->val;
}

void Ull::print(Ull num){
    if(num.val=="0") std::cout<<"0";
    else if(num < zero) std::cout<<"-"<<num.val;
    else std::cout<<num.val;
}

void Ull::operator=(Ull num){
    this->val=num.val;
    this->is_negative=num.is_negative;
}

bool Ull::operator==(Ull num){
    return num.val==this->val && num.is_negative==this->is_negative;
}

bool Ull::operator!=(Ull num){
    return num.val!=this->val || num.is_negative!=this->is_negative;
}

bool Ull::operator>(Ull num){
    if(this->is_negative && num.is_negative) return this->is_lesser(num);
    else if(this->is_negative && !num.is_negative) return false;
    else if(!this->is_negative && num.is_negative) return true;
    else return this->is_greater(num);
}

bool Ull::operator<(Ull num){
    if(this->is_negative && num.is_negative) return this->is_greater(num);
    else if(this->is_negative && !num.is_negative) return true;
    else if(!this->is_negative && num.is_negative) return false;
    else return this->is_lesser(num);
}

bool Ull::operator>=(Ull num){
    return (*this)==num || (*this)>num;
}

bool Ull::operator<=(Ull num){
    return (*this)==num || (*this)<num;
}

Ull Ull::operator+(Ull num){
    Ull ans;
    if(num==zero) return (*this);
    if((*this)==zero) return num;
    if(this->is_negative && num.is_negative){
        ans=(this->add(num));
        ans.is_negative=1;
    }
    else if(this->is_negative && !num.is_negative){
        if(this->is_greater(num)){
            ans=this->subtract(num);
            ans.is_negative=1;
        }
        else ans=num.subtract((*this));
    }
    else if(!this->is_negative && num.is_negative){
        if(this->is_greater(num)) ans=this->subtract(num);
        else{
            ans=num.subtract((*this));
            ans.is_negative=1;
        }
    }
    else ans=this->add(num);
    return ans;
}

Ull Ull::operator-(Ull num){
    Ull ans;
    if(num==zero) return (*this);
    if((*this)==zero){
        num.is_negative=!num.is_negative;
        return num;
    }
    if(this->is_negative && num.is_negative){
        if(this->is_greater(num)){
            ans=this->subtract(num);
            ans.is_negative=1;
        }
        else ans=num.subtract((*this));
    }
    else if(this->is_negative && !num.is_negative){
        ans=this->add(num);
        ans.is_negative=1;
    }
    else if(!this->is_negative && num.is_negative) ans=this->add(num);
    else{
        if(this->is_greater(num)) ans=this->subtract(num);
        else{
            ans=num.subtract((*this));
            ans.is_negative=1;
        }
    }
    return ans;
}
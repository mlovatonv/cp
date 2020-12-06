class mint {
  ll value;
  int mod;
public:
  mint(ll src=0,int m=1000000007):value((src%m+m)%m),mod(m){}
  ll v(){return value;}
  mint operator+(const mint rhs)const{return mint(*this)+=rhs;}
  mint operator-(const mint rhs)const{return mint(*this)-=rhs;}
  mint operator*(const mint rhs)const{return mint(*this)*=rhs;}
  mint operator/(const mint rhs)const{return mint(*this)/=rhs;}
  mint &operator+=(const mint rhs){ value+=rhs.value;
    if(value>=mod)value-=mod;
    return *this;
  }
  mint &operator-=(const mint rhs){
    if(value<rhs.value)value+=mod;
    value-=rhs.value;
    return *this;
  }
  mint &operator*=(const mint rhs){
    value=value*rhs.value%mod;
    return *this;
  }
  mint &operator/=(mint rhs){
    ll exp=mod-2;
    while(exp){
      if(exp%2)*this*=rhs;
      rhs*=rhs;
      exp/=2;
    }
    return *this;
  }
  mint pow(ll p){
    if(p==0)return 1;
    else if(p%2==1)return pow(p-1)*(*this);
    else{
			mint a=pow(p/2);
			return a*a;
		}
  }
	friend istream& operator>>(istream& is,mint& x) {
    is>>x.value;
    x.value%=x.mod;
    if (x.value<0)x.value+=x.mod;
    return is;
  }
	friend ostream& operator<<(ostream& os,const mint& x) {
    return os<<x.value;
  }
};
